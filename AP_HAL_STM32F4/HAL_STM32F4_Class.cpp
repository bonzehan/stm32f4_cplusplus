#include "AP_HAL.h"

#include "HAL_STM32F4_Class.h"
#include "AP_HAL_STM32F4_Namespace.h"
#include "GPIO.h"

using namespace AP_HAL_STM32F4_NS;

static STM32F4GPIO gpioDriver;

HAL_STM32F4::HAL_STM32F4() :
    AP_HAL::HAL(
		&gpioDriver
	)
{}

void HAL_STM32F4::init(int argc,char* const argv[]) const {
}

const HAL_STM32F4 AP_HAL_STM32F4;

