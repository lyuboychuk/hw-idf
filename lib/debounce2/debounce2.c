#include "debounce2.h"
#ifdef MODULE_2_6_T2
#pragma message "Task 2 selected"

const char *TAG = "Debounce button Task2: ";
static portMUX_TYPE mux                    = portMUX_INITIALIZER_UNLOCKED;
static volatile long btn_counter           = 0;
static volatile bool btn_triggered         = false; 
static volatile uint64_t lastInterruptTime = 0;
static const uint64_t debounce_delay_us    = 50000;

void IRAM_ATTR btn_pressed_hdlr(void *arg) {
    uint64_t currentTime = esp_timer_get_time();

    portENTER_CRITICAL_ISR(&mux);
    if (currentTime-lastInterruptTime>debounce_delay_us) {
        btn_triggered = true;
        btn_counter++;
        lastInterruptTime = currentTime;
    }
    portEXIT_CRITICAL_ISR(&mux);
}

void main_task()
{
    bool doLogging = false;
    long counter = 0;
        
    while(true) {
        portENTER_CRITICAL_ISR(&mux);
        if (btn_triggered) {
            btn_triggered = false;
            doLogging = true;
            counter  = btn_counter;
        }
        portEXIT_CRITICAL_ISR(&mux); 
        if (doLogging) 
        {
            ESP_LOGI(TAG, "counter %d",counter);
            doLogging=false;
        }
            
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}
#endif // MODULE_2_6_T2