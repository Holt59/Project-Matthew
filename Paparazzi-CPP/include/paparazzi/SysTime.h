#ifndef _SYSTIME_H
#define _SYSTIME_H

#include <stdint.h>

typedef uint8_t tid_t ;
typedef void (*SysTimeCB) (uint8_t id);


class SysTime {

public:

    static SysTime *getSysTime () ;

public:

    static const int SYS_TIME_NB_TIMER = 8 ;
    static const int SYS_TIME_FREQUENCY = 1000 ;
    
    /**
     * Register a new system timer.
     * @param duration Duration in seconds until the timer elapses.
     * @param cb Callback function that is called from the ISR when timer elapses, or NULL
     * @return -1 if it failed, the timer id otherwise
     */
    int registerTimer (float duration, SysTimeCB cb);
    
    /**
     * Check if timer has elapsed.
     * @param id Timer id
     * @return true if timer has elapsed
     */
    bool checkAndAckTimer (tid_t id);

private:

    static SysTime *m_systime ;
    
    static void sysTickHandler (int signum) ;

    SysTime () ;

    /*
     * Convenience functions to convert between seconds and sys_time ticks.
     */
    inline uint32_t ticksOfSec (float seconds) {
        return (uint32_t)(seconds * this->ticks_per_sec + 0.5);
    }
    
    struct Timer {
        bool          in_use;
        SysTimeCB     cb;
        volatile bool elapsed;
        uint32_t        end_time; ///< in SYS_TIME_TICKS
        uint32_t        duration; ///< in SYS_TIME_TICKS
    };

    volatile uint32_t nb_sec;       ///< full seconds since startup
    volatile uint32_t nb_sec_rem;   ///< remainder of seconds since startup in CPU_TICKS
    volatile uint32_t nb_tick;      ///< SYS_TIME_TICKS since startup
    struct SysTime::Timer timer[SysTime::SYS_TIME_NB_TIMER];

    float resolution;               ///< sys_time_timer resolution in seconds
    uint32_t ticks_per_sec;         ///< sys_time ticks per second (SYS_TIME_FREQUENCY)
    uint32_t resolution_cpu_ticks;  ///< sys_time_timer resolution in cpu ticks
    uint32_t cpu_ticks_per_sec;     ///< cpu ticks per second


} ;

#endif