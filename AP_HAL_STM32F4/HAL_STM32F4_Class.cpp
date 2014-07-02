#include <AP_HAL.h>
#if CONFIG_HAL_BOARD == HAL_BOARD_STM32F4

#include "HAL_STM32F4_Class.h"
#include "AP_HAL_STM32F4_Private.h"

using namespace AP_HAL_STM32F4_NS;
static STM32F4GPIO gpioDriver;
 static STM32F4Scheduler schedulerInstance;

HAL_STM32F4::HAL_STM32F4() :
    AP_HAL::HAL(
		&gpioDriver,
		&schedulerInstance
	)
{}

void HAL_STM32F4::init(int argc,char* const argv[]) const {
    /* initialize all drivers and private members here.
     * up to the programmer to do this in the correct order.
     * Scheduler should likely come first. */
    scheduler->init(NULL);
}

const HAL_STM32F4 AP_HAL_STM32F4;

#endif
