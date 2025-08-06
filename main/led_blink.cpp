#include <iostream>
#include <string>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#include "led_blink.hpp"
//#include "state.hpp"
std::string INIT_STATE = "Running";

LedBlink::LedBlink(int pin) : pin_(pin) {
  gpio_reset_pin((gpio_num_t)pin_);
  gpio_set_direction((gpio_num_t)pin_, GPIO_MODE_OUTPUT);
}

void LedBlink::led_control(bool led_status) {
  gpio_set_level((gpio_num_t)pin_, led_status);
}

int LedBlink::timer(int duty_cycle, bool led_status) {
  int time_on = 10*duty_cycle*led_status; // *(1/rate) millisecondsint
  int time = (1000 - 10*duty_cycle)*(1-led_status) + time_on;
  return time; // must be divided by rate
}

void LedBlink::ledOff() {
  gpio_set_level((gpio_num_t)pin_, 0);
}

void LedBlink::runBlink(int rate, int duty_cycle) {
  std::string curr_state = INIT_STATE;
  bool LED_STATUS = true;
  int time_delay = timer(duty_cycle, LED_STATUS)/rate;
  //int time_on = (1000/rate)*duty_cycle/100; //milliseconds
  //int time_off = (1000/rate) - time_on;
  while (curr_state != "Error") {
    //curr_state = State::get_state();
    std::cout << "The current led State is: " << curr_state << "..." << LED_STATUS << std::endl;
    if (curr_state == "Running") {
      led_control(LED_STATUS);
      vTaskDelay(pdMS_TO_TICKS(time_delay));
      LED_STATUS = !LED_STATUS;
    }
    else { ledOff();
    }
  }
  ledOff();
}
