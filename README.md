# Controle de Servo Motor (PWM)
Este projeto implementa o controle de um servo motor utilizando a Raspberry Pi Pico. O código configura o PWM para controlar a posição do servo.

---

## **Configuração dos Pinos GPIO**

Os pinos GPIO da Raspberry Pi Pico estão configurados conforme a tabela abaixo:

| GPIO  | Componente     | Função                           |
|-------|---------------|---------------------------------|
| **22** | Servo Motor   | Controle de posição do servo motor via PWM    |

---

## **Funcionamento do Código**

1. **Inicialização do PWM**: O GPIO 22 é configurado para funcionar como saída PWM, com divisor de clock e valores de wrap adequados para gerar um sinal de controle com frência de 50 Hz.
2. **Movimento Inicial**: O servo motor é movido para 90°, depois para 180° e, por fim, para 0°, com intervalos de 5 segundos entre cada movimento.
3. **Movimento Contínuo**: O servo oscila continuamente entre as posições de 0° e 180°, aumentando ou diminuindo a largura do pulso PWM gradativamente a cada 10 ms.

---

## **Vídeo Demonstrativo**

Link do vídeo:
https://youtu.be/vpNvRYcoCJQ



