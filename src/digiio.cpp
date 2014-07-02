#include "digiio.h"
#include "stm32f4bsp.h"

void DigitalSource::mode(uint8_t output)
{
		bspPinMode(_pin_num, output);
}

uint8_t DigitalSource::read() {
		return GPIO_ReadInputDataBit(bsp_pin_map[_pin_num].gpio_group, bsp_pin_map[_pin_num].pin);
}

void DigitalSource::write(uint8_t value) {
		if(value == 0)
				GPIO_ResetBits(bsp_pin_map[_pin_num].gpio_group, bsp_pin_map[_pin_num].pin);
		else
				GPIO_SetBits(bsp_pin_map[_pin_num].gpio_group, bsp_pin_map[_pin_num].pin);
}

void DigitalSource::toggle() {
		GPIO_ToggleBits(bsp_pin_map[_pin_num].gpio_group, bsp_pin_map[_pin_num].pin);
}

