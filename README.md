# PWM
# Controle de Servomotor por PWM com Raspberry Pi Pico W

Este projeto demonstra o controle de um servomotor usando o módulo PWM do Raspberry Pi Pico W. O código foi desenvolvido em C utilizando o Pico SDK e simulado no Wokwi.

#Funções Gerais
##1. setup_pwm(uint pin)
Motivo: Configura o PWM no pino especificado para controlar o servomotor com uma frequência de 50Hz (período de 20ms).
Uso: Inicializa o PWM no pino do servomotor.

##2. move_servo(uint pin, uint pulse_width_us)
Motivo: Move o servomotor para uma posição específica, ajustando o ciclo ativo do PWM.
Uso: Controla a posição do servomotor (0°, 90°, 180°) com base na largura do pulso em microssegundos.

##3. main()
Motivo: Função principal que coordena a movimentação do servomotor e o controle do LED RGB.
Uso: Inicializa o hardware, move o servomotor para posições específicas e realiza uma movimentação periódica suave entre 0° e 180°.

#Motivos das Funções
Controle de Servomotor: O servomotor é controlado por PWM, onde a largura do pulso define a posição do braço. As funções garantem que o servomotor se mova de forma precisa e suave.

Integração com LED RGB: O LED RGB é utilizado para fornecer feedback visual durante a movimentação do servomotor, alternando seu estado conforme a posição do motor.

Simulação no Wokwi: O código foi projetado para ser simulado no Wokwi, permitindo testes e validação sem a necessidade de hardware físico.
