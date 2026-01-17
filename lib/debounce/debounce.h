#ifndef DEBOUNCE_H
#define DEBOUNCE_H

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_timer.h"
#include "esp_log.h"

#define LED_PIN1 18
#define BTN_PIN1 0

extern const char *TAG;
extern void btn_pressed_hdlr(void *arg);
extern void setup();

#endif // DEBOUNCE_H