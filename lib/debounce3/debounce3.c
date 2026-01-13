#include "debounce3.h"
#ifdef MODULE_2_6_T3
#pragma message "Task 3 selected"

const char *TAG = "Debounce button Task3: ";
static volatile bool btn3_triggered        = false; 
static volatile uint64_t lastInterruptTime = 0;
static const uint64_t debounce_delay_us    = 50000;
enum Button_State { IDLE, DEBOUNCE, ACTION } btn_state = IDLE;

void IRAM_ATTR btn_pressed_hdlr(void *arg) {
    btn3_triggered = true;
}
void main_task()
{   
    bool doLogging = false;
    long counter = 0;

    while(true) {     
        switch (btn_state) {
            case IDLE:
                if  (btn3_triggered) {
                    btn3_triggered = false;
                    lastInterruptTime = esp_timer_get_time();
                    btn_state = DEBOUNCE;
                }
            break;
            case DEBOUNCE:
                if (esp_timer_get_time() - lastInterruptTime > debounce_delay_us) {
                    if (gpio_get_level(BTN_PIN1) == 1) {
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
            break;            
        }
        if (doLogging) 
        {
            ESP_LOGI(TAG, "counter %d",counter);
            doLogging=false;
        }
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}
#endif // MODULE_2_6_T3