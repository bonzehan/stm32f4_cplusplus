#include "HAL_STM32F4_Class.h"
#include <stdio.h>

static STM32F4GPIO gpio_driver;

HAL_STM32F4::HAL_STM32F4()
{
		printf("call HAL constructor\n");
		p_gpio_driver = &gpio_driver;
		a = 10;
		b = 25;
}

void HAL_STM32F4::init(void)
{
}

HAL_STM32F4 AP_HAL_STM32F4;

