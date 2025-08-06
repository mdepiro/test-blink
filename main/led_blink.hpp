#ifndef LED_BLINK_HPP
#define LED_BLINK_HPP

#include "driver/gpio.h"
#include "state.hpp"

class LedBlink {
  public:
    explicit LedBlink(int pin); 
    void runBlink(int rate, int duty_cycle);
  
  private:
    void led_control(bool led_status);

    void ledOff();

    int timer(int duty_cycle, bool led_status);
    
    int pin_;
    //static bool setStatus(bool led_status);

};

#endif // LED_BLINK_HPP


