
#include "debounce1.h"
#ifdef MODULE_2_6_T1
#pragma message "Task 1 selected"

const char *TAG = "Debounce button Task1: ";
static portMUX_TYPE mux                    = portMUX_INITIALIZER_UNLOCKED;
static volatile long btn_counter           = 0;
static volatile bool btn_triggered         = false; 

void IRAM_ATTR btn_pressed_hdlr(void *arg) {
    portENTER_CRITICAL_ISR(&mux);
        btn_triggered = true;
        btn_counter++;
    portEXIT_CRITICAL_ISR(&mux);
}

void main_task()
{
    bool doLogging = false;
    long counter1 = 0;
    
    while(true) {
        portENTER_CRITICAL_ISR(&mux);
        if (btn_triggered) {
            btn_triggered = false;
            doLogging = true;
            counter1  = btn_counter;        
        }   
        portEXIT_CRITICAL_ISR(&mux); 
        if (doLogging) 
        {
            ESP_LOGI(TAG, "counter %d",counter1);
            doLogging=false;
        }
        
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}
#endif // MODULE_2_6_T1