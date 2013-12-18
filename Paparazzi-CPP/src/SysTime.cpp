#include "SysTime.h"

#include <sys/time.h>
#include <signal.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

SysTime *SysTime::m_systime = 0 ;

SysTime* SysTime::getSysTime () {
    if (m_systime == 0) {
        m_systime = new SysTime () ;
    }
    return m_systime ;
}

SysTime::SysTime () {

    this->nb_sec     = 0;
    this->nb_sec_rem = 0;
    this->nb_tick    = 0;

    this->ticks_per_sec = SYS_TIME_FREQUENCY;
    this->resolution = 1.0 / this->ticks_per_sec;
	unsigned int i;
    for (i=0; i<SYS_TIME_NB_TIMER; i++) {
        this->timer[i].in_use     = false;
        this->timer[i].cb         = NULL;
        this->timer[i].elapsed    = false;
        this->timer[i].end_time   = 0;
        this->timer[i].duration   = 0;
    }

    this->cpu_ticks_per_sec = 1e6;
    this->resolution_cpu_ticks = (uint32_t)(this->resolution * this->cpu_ticks_per_sec + 0.5);

    struct sigaction sa;
    struct itimerval timer;

    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = &SysTime::sysTickHandler;
    sigaction(SIGALRM, &sa, 0);

    // timer expires after this->resolution sec
    timer.it_value.tv_sec = 0;
    timer.it_value.tv_usec = this->resolution * 1e6 ;
    // and every SYS_TIME_RESOLUTION sec after that
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = this->resolution * 1e6 ;

    setitimer(ITIMER_REAL, &timer, 0);
}

int SysTime::registerTimer (float duration, SysTimeCB cb) {
    uint32_t start_time = this->nb_tick;
    int i;
    for (i = 0; i< SYS_TIME_NB_TIMER; i++) {
        if (!this->timer[i].in_use) {
            this->timer[i].cb         = cb;
            this->timer[i].elapsed    = false;
            this->timer[i].end_time   = start_time + this->ticksOfSec (duration);
            this->timer[i].duration   = this->ticksOfSec (duration);
            this->timer[i].in_use     = true;
            return i;
        }
    }
    return -1;
}
    
bool SysTime::checkAndAckTimer (tid_t id) {
    if (this->timer[id].elapsed) {
        this->timer[id].elapsed = false;
        return true;
    }
    return false;
}

void SysTime::sysTickHandler (int signum) {

    m_systime->nb_tick++;
    m_systime->nb_sec_rem += m_systime->resolution_cpu_ticks;;
    if (m_systime->nb_sec_rem >= m_systime->cpu_ticks_per_sec) {
        m_systime->nb_sec_rem -= m_systime->cpu_ticks_per_sec;
        m_systime->nb_sec++;
    }
    unsigned int i;
    for (i=0; i < SysTime::SYS_TIME_NB_TIMER; i++) {
        if (m_systime->timer[i].in_use &&
            m_systime->nb_tick >= m_systime->timer[i].end_time) {
            m_systime->timer[i].end_time += m_systime->timer[i].duration;
            m_systime->timer[i].elapsed = true;
            if (m_systime->timer[i].cb) {
                m_systime->timer[i].cb(i);
            }
        }
    }
}