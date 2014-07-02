
#ifndef __AP_HAL_SCHEDULER_H__
#define __AP_HAL_SCHEDULER_H__

#include "AP_HAL_Namespace.h"

#include <stdint.h>

class AP_HAL::Scheduler {
public:
    Scheduler() {}
    virtual void     init(void* implspecific) = 0;
    virtual void     delay(uint16_t ms) = 0;
    virtual uint32_t millis() = 0;
    virtual uint32_t micros() = 0;
    virtual void     delay_microseconds(uint16_t us) = 0;
    virtual void     register_delay_callback(AP_HAL::Proc,
                                             uint16_t min_time_ms) = 0;

    // suspend and resume both timer and IO processes
    virtual void     suspend_timer_procs() = 0;
    virtual void     resume_timer_procs() = 0;

    virtual bool     in_timerprocess() = 0;
    
    virtual void     register_timer_failsafe(AP_HAL::Proc,
                                             uint32_t period_us) = 0;

    virtual bool     system_initializing() = 0;
    virtual void     system_initialized() = 0;

    virtual void     panic(const char *errormsg) = 0;
    virtual void     reboot(bool hold_in_bootloader) = 0;

    /**
       optional function to set timer speed in Hz
     */
    virtual void     set_timer_speed(uint16_t speed_hz) {}

    /**
       optional function to stop clock at a given time, used by log replay
     */
    virtual void     stop_clock(uint64_t time_usec) {}
};

#endif // __AP_HAL_SCHEDULER_H__

