#include "HAL_STM32F4_Class.h"

STM32F4GPIO gpio_driver;

HAL_STM32F4::HAL_STM32F4()
{
		p_gpio_driver = &gpio_driver;
}

void HAL_STM32F4::init(void)
{
}

