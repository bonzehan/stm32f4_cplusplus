#include "AP_HAL.h"

#include "GPIO.h"
#include "stm32f4bsp.h"

using namespace AP_HAL_STM32F4_NS;

STM32F4GPIO::STM32F4GPIO()
{}

void STM32F4GPIO::init()
{}

void STM32F4GPIO::pinMode(uint8_t pin, uint8_t output)
{
		bspPinMode(pin, output);
}

uint8_t STM32F4GPIO::read(uint8_t pin) 
{
		if(pin >= BSP_GPIO_PIN_NUM)
				return 0xff;
		return GPIO_ReadInputDataBit(bsp_pin_map[pin].gpio_group, bsp_pin_map[pin].pin);
}

void STM32F4GPIO::write(uint8_t pin, uint8_t value)
{
		if(pin >= BSP_GPIO_PIN_NUM)
				return;
		if(value == 0)
				GPIO_ResetBits(bsp_pin_map[pin].gpio_group, bsp_pin_map[pin].pin);
		else
				GPIO_SetBits(bsp_pin_map[pin].gpio_group, bsp_pin_map[pin].pin);
}

void STM32F4GPIO::toggle(uint8_t pin)
{
		if(pin >= BSP_GPIO_PIN_NUM)
				return;
		GPIO_ToggleBits(bsp_pin_map[pin].gpio_group, bsp_pin_map[pin].pin);
}

/* Alternative interface: */
AP_HAL::DigitalSource* STM32F4GPIO::channel(uint16_t n) {
		if(n >= BSP_GPIO_PIN_NUM)
				return NULL;
		return new STM32F4DigitalSource(n);
}

void STM32F4DigitalSource::mode(uint8_t output)
{
		bspPinMode(_pin_num, output);
}

uint8_t STM32F4DigitalSource::read() {
		return GPIO_ReadInputDataBit(bsp_pin_map[_pin_num].gpio_group, bsp_pin_map[_pin_num].pin);
}

void STM32F4DigitalSource::write(uint8_t value) {
		if(value == 0)
				GPIO_ResetBits(bsp_pin_map[_pin_num].gpio_group, bsp_pin_map[_pin_num].pin);
		else
				GPIO_SetBits(bsp_pin_map[_pin_num].gpio_group, bsp_pin_map[_pin_num].pin);
}

void STM32F4DigitalSource::toggle() {
		GPIO_ToggleBits(bsp_pin_map[_pin_num].gpio_group, bsp_pin_map[_pin_num].pin);
}

