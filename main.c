#include "pico/stdlib.h"
#include "hardware/pwm.h"

int main() {
    // Configuração da GPIO 22 como PWM
    gpio_set_function(22, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(22);

    // Configuração da frequência do PWM para 50Hz
    pwm_set_clkdiv(slice_num, 125); // Divisor de clock para 50Hz
    pwm_set_wrap(slice_num, 20000); // Período de 20ms
    pwm_set_enabled(slice_num, true);

    // Defina o ciclo ativo inicial para 2.400µs (180 graus)
    pwm_set_gpio_level(22, 2400);
    sleep_ms(5000); // Aguarda 5 segundos

    // Defina o ciclo ativo para 1.470µs (90 graus)
    pwm_set_gpio_level(22, 1470);
    sleep_ms(5000); // Aguarda 5 segundos

    // Defina o ciclo ativo para 500µs (0 graus)
    pwm_set_gpio_level(22, 500);
    sleep_ms(5000); // Aguarda 5 segundos

    // Movimentação periódica do braço do servomotor entre 0 e 180 graus
    while (true) {
        for (int i = 500; i <= 2400; i += 5) {
            pwm_set_gpio_level(22, i);
            sleep_ms(10); // Atraso de ajuste de 10ms
        }
        for (int i = 2400; i >= 500; i -= 5) {
            pwm_set_gpio_level(22, i);
            sleep_ms(10); // Atraso de ajuste de 10ms
        }
    }
}
