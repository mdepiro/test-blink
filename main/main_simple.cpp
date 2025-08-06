#include <iostream>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/ledc.h"
#include "driver/rmt.h"
#include "esp_err.h"


#define LED_pin GPIO_NUM_3

extern "C" void app_main() {
    std::cout << "Hello from C++!" << std::endl;
    //configure the LED pin as a digitial output
    /* gpio_config_t io_conf = {};
    io_conf.intr_type = GPIO_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pin_bit_mask = (1ULL << LED_pin);
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.pull_up_en = GPIO_PULLUP_DISABLE;
    gpio_config(&io_conf);
    */
    gpio_reset_pin(LED_pin);
    gpio_set_direction(LED_pin, GPIO_MODE_OUTPUT);

    xTaskCreate([](void*) {
        while (true) {
            gpio_set_level(LED_pin, 1);
            std::cout << "LED ON..." << std::endl;
            vTaskDelay(pdMS_TO_TICKS(1000));
            gpio_set_level(LED_pin, 0);
            std::cout << "LED OFF..." << std::endl;
            vTaskDelay(pdMS_TO_TICKS(1000));
        }
    }, "cpp_task", 2048, nullptr, 1, nullptr);
}

