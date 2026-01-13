#include "debounce4.h"
#ifdef MODULE_2_6_T4
#pragma message "Task 4 selected"

const char *TAG = "Debounce button Task4: ";
static uint64_t lastInterruptTime = 0;
static const uint64_t debounce_delay_us    = 10000;
enum Button_State { IDLE, DEBOUNCE, ACTION } btn_state = IDLE;
void IRAM_ATTR btn_pressed_hdlr(void *arg) { }

void main_task()
{   
    gpio_intr_disable(BTN_PIN1);
    bool doLogging = false;
    long counter = 0;

    while(true) {
        switch (btn_state) {
            case IDLE:
                if  (!gpio_get_level(BTN_PIN1)) {                    
                    lastInterruptTime = esp_timer_get_time();
                    btn_state = DEBOUNCE;
                }
            break;
            case DEBOUNCE:
                if (esp_timer_get_time() - lastInterruptTime > debounce_delay_us) {
                    if (gpio_get_level(BTN_PIN1)) {
                        btn_state = ACTION;
                    } else {
                        btn_state = IDLE;
                    }
                }
            break;
            case ACTION:
                counter++;
                doLogging = true;                
                btn_state = IDLE;
        }

       if (doLogging) 
       {
           ESP_LOGI(TAG, "counter %d",counter);
           doLogging=false;
       }
        
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}
#endif