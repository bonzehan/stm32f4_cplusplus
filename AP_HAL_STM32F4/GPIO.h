#ifndef _GPIO_H_
#define _GPIO_H_

#include <stdint.h>
#include "virgpio.h"

class STM32F4DigitalSource : public VirtualDigitalSource{
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

class STM32F4GPIO : public VirtualGPIO
{
public:
    STM32F4GPIO();
    void    init();
    void    pinMode(uint8_t pin, uint8_t output);
    uint8_t read(uint8_t pin);
    void    write(uint8_t pin, uint8_t value);
    void    toggle(uint8_t pin);

    /* Alternative interface: */
    VirtualDigitalSource* channel(uint16_t n);
};

#endif
