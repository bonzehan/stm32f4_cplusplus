#ifndef __AP_HAL_STM32F4_GPIO_H__
#define __AP_HAL_STM32F4_GPIO_H__

#include "AP_HAL_STM32F4.h"

class AP_HAL_STM32F4_NS::STM32F4GPIO : public AP_HAL::GPIO {
public:
    STM32F4GPIO();
    void    init();
    void    pinMode(uint8_t pin, uint8_t output);
    uint8_t read(uint8_t pin);
    void    write(uint8_t pin, uint8_t value);
    void    toggle(uint8_t pin);

    /* Alternative interface: */
    AP_HAL::DigitalSource* channel(uint16_t n);
};

class AP_HAL_STM32F4_NS::STM32F4DigitalSource : public AP_HAL::DigitalSource {
public:
    STM32F4DigitalSource(uint8_t pin_num) : _pin_num(pin_num)
		{}
    void    mode(uint8_t output);
    uint8_t read();
    void    write(uint8_t value); 
    void    toggle();

private:
    uint8_t _pin_num;
};

#endif // __AP_HAL_STM32F4_GPIO_H__
