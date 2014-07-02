#ifndef _DIGIIO_H_
#define _DIGIIO_H_

#include <stdint.h>

class DigitalSource{
public:
		DigitalSource(uint8_t pin_num) : _pin_num(pin_num)
		{}
    void    mode(uint8_t output);
    uint8_t read();
    void    write(uint8_t value); 
    void    toggle();

private:
    uint8_t _pin_num;
};

#endif

