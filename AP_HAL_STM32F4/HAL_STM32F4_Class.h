#ifndef __AP_HAL_STM32F4_CLASS_H__
#define __AP_HAL_STM32F4_CLASS_H__

#include "GPIO.h"

class HAL_STM32F4{
public:
    HAL_STM32F4();
    void init(int argc, char * const * argv) const;

	STM32F4GPIO *_gpio_driver;
};

extern const HAL_STM32F4 AP_HAL_STM32F4;

#endif // __AP_HAL_STM32F4_CLASS_H__

