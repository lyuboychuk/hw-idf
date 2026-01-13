#include "debounce.h"

void setup() {
    gpio_config_t led_conf = {
        .pin_bit_mask = 1ULL << LED_PIN1,
        .mode         = GPIO_MODE_OUTPUT,
        .pull_up_en   = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type    = GPIO_INTR_DISABLE
    };

    gpio_config_t btn1_config = {
        .pin_bit_mask = 1ULL << BTN_PIN1,
        .mode         = GPIO_MODE_INPUT,
        .pull_up_en   = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type    = GPIO_INTR_NEGEDGE
    };
    gpio_config(&led_conf);
    gpio_config(&btn1_config);

    gpio_set_level((gpio_num_t)LED_PIN1, true); 
    gpio_install_isr_service(ESP_INTR_FLAG_IRAM);
    gpio_isr_handler_add((gpio_num_t)BTN_PIN1, btn_pressed_hdlr, NULL);
    
    
    ESP_LOGI(TAG, "Buttons + LED initialized");
}