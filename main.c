#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/gpio.h"

// Definição dos pinos
#define SERVO_PIN 22  // GPIO 22 para o servomotor
#define LED_PIN 12    // GPIO 12 para o LED RGB

// Função para configurar o PWM no pino especificado
void setup_pwm(uint pin) {
    gpio_set_function(pin, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(pin);
    pwm_set_clkdiv(slice_num, 125);  // Divisor de clock para 50Hz
    pwm_set_wrap(slice_num, 20000); // Período de 20ms
    pwm_set_enabled(slice_num, true);
}

// Função para mover o servomotor para uma posição específica
void move_servo(uint pin, uint pulse_width_us) {
    pwm_set_gpio_level(pin, pulse_width_us);
}

// Função principal
int main() {
    // Inicialização do hardware
    stdio_init_all();
    setup_pwm(SERVO_PIN);
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    // Movimentação do servomotor para 180 graus (2.400µs)
    move_servo(SERVO_PIN, 2400);
    gpio_put(LED_PIN, 1);  // Liga o LED RGB
    sleep_ms(5000);        // Aguarda 5 segundos

    // Movimentação do servomotor para 90 graus (1.470µs)
    move_servo(SERVO_PIN, 1470);
    gpio_put(LED_PIN, 0);  // Desliga o LED RGB
    sleep_ms(5000);        // Aguarda 5 segundos

    // Movimentação do servomotor para 0 graus (500µs)
    move_servo(SERVO_PIN, 500);
    gpio_put(LED_PIN, 1);  // Liga o LED RGB
    sleep_ms(5000);        // Aguarda 5 segundos

    // Movimentação periódica do servomotor entre 0 e 180 graus
    while (true) {
        // Movimentação de 0 a 180 graus
        for (int i = 500; i <= 2400; i += 5) {
            move_servo(SERVO_PIN, i);
            gpio_put(LED_PIN, i % 2);  // Alterna o LED RGB
            sleep_ms(10);              // Atraso de ajuste de 10ms
        }

        // Movimentação de 180 a 0 graus
        for (int i = 2400; i >= 500; i -= 5) {
            move_servo(SERVO_PIN, i);
            gpio_put(LED_PIN, i % 2);  // Alterna o LED RGB
            sleep_ms(10);              // Atraso de ajuste de 10ms
        }
    }
}
