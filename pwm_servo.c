#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERVO 13

void configura_pwm(void){

    gpio_set_function(SERVO, GPIO_FUNC_PWM); //habilitar o pino GPIO como PWM

    uint slice = pwm_gpio_to_slice_num(SERVO); //obter o canal PWM da GPIO

    pwm_set_clkdiv(slice, 125.0); //define o divisor de clock do PWM

    pwm_set_wrap(slice, 19999); //definir o valor de wrap

    pwm_set_gpio_level(SERVO, 1000); //definir o cico de trabalho (duty cycle) do pwm

    pwm_set_enabled(slice, true); //habilita o pwm no slice correspondente

}

int main()
{
    configura_pwm();


    while (true) {
        pwm_set_gpio_level(SERVO, 1470);
        sleep_ms(1000);
        pwm_set_gpio_level(SERVO, 2400);
        sleep_ms(1000);
        pwm_set_gpio_level(SERVO, 500);
        sleep_ms(1000);
    }
}
