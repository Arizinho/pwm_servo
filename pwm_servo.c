#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERVO 13
#define MAX_LEVEL 2400
#define MIN_LEVEL 500

void configura_pwm(void){

    gpio_set_function(SERVO, GPIO_FUNC_PWM); //habilitar o pino GPIO como PWM

    uint slice = pwm_gpio_to_slice_num(SERVO); //obter o canal PWM da GPIO

    pwm_set_clkdiv(slice, 125.0); //define o divisor de clock do PWM

    pwm_set_wrap(slice, 19999); //definir o valor de wrap

    pwm_set_gpio_level(SERVO, 0); //definir o cico de trabalho (duty cycle) do pwm

    pwm_set_enabled(slice, true); //habilita o pwm no slice correspondente

}

void inializa_servo(void){
    pwm_set_gpio_level(SERVO, 1470);
        sleep_ms(5000);
        pwm_set_gpio_level(SERVO, 2400);
        sleep_ms(5000);
        pwm_set_gpio_level(SERVO, 500);
        sleep_ms(5000);
}

int main()
{
    configura_pwm();
    inializa_servo();
    uint16_t t_ciclo = 500;
    bool rise = 1;
    while (true) {
        if (rise){
            for (t_ciclo; t_ciclo < MAX_LEVEL; t_ciclo += 5){
                sleep_ms(10);
                pwm_set_gpio_level(SERVO, t_ciclo);
            }
            rise = 0;
        }
        else {
            for (t_ciclo; t_ciclo > MIN_LEVEL; t_ciclo -= 5){
                sleep_ms(10);
                pwm_set_gpio_level(SERVO, t_ciclo);
            }
            rise = 1;
        }
    }
}
