#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN_R = 28;
const int BTN_PIN_G = 26;
const int LED_PIN_R = 4;
const int LED_PIN_G = 6;

int main() {
  stdio_init_all();

  int ligado_r = 0;
  int ligado_g = 0;

  gpio_init(BTN_PIN_R);
  gpio_set_dir(BTN_PIN_R, GPIO_IN);
  gpio_pull_up(BTN_PIN_R);

  gpio_init(BTN_PIN_G);
  gpio_set_dir(BTN_PIN_G, GPIO_IN);
  gpio_pull_up(BTN_PIN_G);

  gpio_init(LED_PIN_R);
  gpio_set_dir(LED_PIN_R, GPIO_OUT);

  gpio_init(LED_PIN_G);
  gpio_set_dir(LED_PIN_G, GPIO_OUT);

  while (true) {
     if (!gpio_get(BTN_PIN_R)) {
      if (ligado_r) {
        gpio_put(LED_PIN_R, 0);
        ligado_r = 0;
      } else {
        gpio_put(LED_PIN_R, 1);
        ligado_r = 1;
      }
      while (!gpio_get(BTN_PIN_R)) {
      };
    }

    if (!gpio_get(BTN_PIN_G)) {
      if (ligado_g) {
        gpio_put(LED_PIN_G, 0);
        ligado_g = 0;
      } else {
        gpio_put(LED_PIN_G, 1);
        ligado_g = 1;
      }
      while (!gpio_get(BTN_PIN_G)) {
      };
    }
  }
}
