#include "HAL_STM32F4_Class.h"

static STM32F4GPIO gpioDriver;

HAL_STM32F4::HAL_STM32F4() : _gpio_driver(&gpioDriver)
{}

void HAL_STM32F4::init(int argc,char* const argv[]) const 
{
}

const HAL_STM32F4 AP_HAL_STM32F4;

