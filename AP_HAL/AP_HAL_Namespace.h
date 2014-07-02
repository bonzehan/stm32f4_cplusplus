
#ifndef __AP_HAL_NAMESPACE_H__
#define __AP_HAL_NAMESPACE_H__

#include "string.h"

namespace AP_HAL {
    /* Toplevel pure virtual class Hal.*/
    class HAL;

    class DigitalSource;
    class GPIO;
    class Scheduler;

    /* Typdefs for function pointers (Procedure, Member Procedure) 

       For member functions we use the FastDelegate delegates class
       which allows us to encapculate a member function as a type
     */
    typedef void(*Proc)(void);
}

#endif // __AP_HAL_NAMESPACE_H__
