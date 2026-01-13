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

/* Only one maybe uncommented at a time*/
// #define MODULE_2_6_T1 //- task 1 for 2.6 module
#define MODULE_2_6_T2 //- task 2 for 2.6 module
// #define MODULE_2_6_T3 //- task 3 for 2.6 module
// #define MODULE_2_6_T4 //- task 3 for 2.6 module    

extern const char *TAG;
extern void btn_pressed_hdlr(void *arg);
extern void setup();

#endif // DEBOUNCE_H