#ifndef _VIRGPIO_H_
#define _VIRGPIO_H_

#define GPIO_INPUT  0
#define GPIO_OUTPUT 1
#define GPIO_INTERRUPT_LOW 0
#define GPIO_INTERRUPT_HIGH 1
#define GPIO_INTERRUPT_FALLING 2
#define GPIO_INTERRUPT_RISING 3

class VirtualDigitalSource {
public:
    virtual void    mode(uint8_t output) = 0;
    virtual uint8_t read() = 0;
    virtual void    write(uint8_t value) = 0;
    virtual void    toggle() = 0;
};

class VirtualGPIO {
public:
    VirtualGPIO(void) {}
    virtual void    init() = 0;
    virtual void    pinMode(uint8_t pin, uint8_t output) = 0;
    virtual uint8_t read(uint8_t pin) = 0;
    virtual void    write(uint8_t pin, uint8_t value) = 0;
    virtual void    toggle(uint8_t pin) = 0;

    /* Alternative interface: */
    virtual VirtualDigitalSource* channel(uint16_t n) = 0;
};

#endif

