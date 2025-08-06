#include <iostream>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/ledc.h"
#include "esp_err.h"

#include "led_blink.hpp"

#define LED_pin GPIO_NUM_3

extern "C" void app_main() {
    std::cout << "Hello from C++!" << std::endl;

    xTaskCreate([](void*) {
        LedBlink led(3);
        led.runBlink(2, 25);
    }, "cpp_task", 2048, nullptr, 1, nullptr);
}

