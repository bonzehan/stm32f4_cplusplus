
#ifndef __AP_HAL_HAL_H__
#define __AP_HAL_HAL_H__

#include "AP_HAL_Namespace.h"

#include "../AP_HAL/GPIO.h"
#include "../AP_HAL/Scheduler.h"

class AP_HAL::HAL {
public:
    HAL(AP_HAL::GPIO*       _gpio,
        AP_HAL::Scheduler*  _scheduler)
        :
        gpio(_gpio),
        scheduler(_scheduler)
    {}

    virtual void init(int argc, char * const argv[]) const = 0;

    AP_HAL::GPIO*       gpio;
    AP_HAL::Scheduler*  scheduler;
};

#endif // __AP_HAL_HAL_H__

