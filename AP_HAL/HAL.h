
#ifndef __AP_HAL_HAL_H__
#define __AP_HAL_HAL_H__

#include "AP_HAL_Namespace.h"

#include "../AP_HAL/GPIO.h"

class AP_HAL::HAL {
public:
    HAL(AP_HAL::GPIO*       _gpio)
        :
        gpio(_gpio)
    {}

    virtual void init(int argc, char * const argv[]) const = 0;

    AP_HAL::GPIO*       gpio;
};

#endif // __AP_HAL_HAL_H__

