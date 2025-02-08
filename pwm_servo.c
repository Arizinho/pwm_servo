#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

//define macros
#define SERVO 22
#define MAX_LEVEL 2400
#define MIN_LEVEL 500

//configurações do pwm
void configura_pwm(void){

    gpio_set_function(SERVO, GPIO_FUNC_PWM); //habilitar o pino GPIO como PWM

    uint slice = pwm_gpio_to_slice_num(SERVO); //obter o canal PWM da GPIO

    pwm_set_clkdiv(slice, 125.0); //define o divisor de clock do PWM 

    pwm_set_wrap(slice, 19999); //definir o valor de wrap (vai contar até 20000 ciclos -> 19999 + 1)

    pwm_set_gpio_level(SERVO, 0); //defini o valor do comparador de nível (inicialmente em 0)

    pwm_set_enabled(slice, true); //habilita o pwm no slice correspondente

}

//função para rotações iniciais do servo (90, 180 e 0 graus)
void inializa_servo(void){
    //gira servo em 90 graus
    pwm_set_gpio_level(SERVO, 1470);
    sleep_ms(5000);

    //gira servo em 180 graus
    pwm_set_gpio_level(SERVO, 2400);
    sleep_ms(5000);

    //gira servo em 0 graus
    pwm_set_gpio_level(SERVO, 500);
    sleep_ms(5000);
}

int main()
{
    configura_pwm();
    inializa_servo();

    //variável para guardar o valor do comparador de nível (inicialmente em 500)
    uint16_t t_ciclo = 500;
    
    while (true) {
        //incrementa o valor de T_ON até 2400 us (5 us de incremento e intervalo de 10 ms)
        for (t_ciclo; t_ciclo < MAX_LEVEL; t_ciclo += 5){
            sleep_ms(10);
            pwm_set_gpio_level(SERVO, t_ciclo);
        }

        //decrementa o valor de T_ON até 500 us (5 us de decremento e intervalo de 10 ms)
        for (t_ciclo; t_ciclo > MIN_LEVEL; t_ciclo -= 5){
            sleep_ms(10);
            pwm_set_gpio_level(SERVO, t_ciclo);
        }
    }
}
