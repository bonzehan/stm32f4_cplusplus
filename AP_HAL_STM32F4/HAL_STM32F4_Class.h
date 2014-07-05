#ifndef _HAL_STM32F4_CLASS_H__
#define _HAL_STM32F4_CLASS_H__

#include "GPIO.h"

class HAL_STM32F4{
public:
    HAL_STM32F4();
    void init(void);

	STM32F4GPIO* p_gpio_driver;
};

extern const HAL_STM32F4 AP_HAL_STM32F4;

#endif // _HAL_STM32F4_CLASS_H__

