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

    this->nbSec     = 0;
    this->nbSecRem = 0;
    this->nbTicks    = 0;

    this->ticksPerSec = SYS_TIME_FREQUENCY;
    this->resolution = 1.0 / this->ticksPerSec;
	unsigned int i;
    for (i=0; i<SYS_TIME_NB_TIMER; i++) {
        this->timer[i].inUse     = false;
        this->timer[i].cb         = NULL;
        this->timer[i].elapsed    = false;
        this->timer[i].endTime   = 0;
        this->timer[i].duration   = 0;
    }

    this->cpuTicksPerSec = 1e6;
    this->resolutionCPUTicks = (uint32_t)(this->resolution * this->cpuTicksPerSec + 0.5);

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
    uint32_t start_time = this->nbTicks;
    int i;
    for (i = 0; i< SYS_TIME_NB_TIMER; i++) {
        if (!this->timer[i].inUse) {
            this->timer[i].cb         = cb;
            this->timer[i].elapsed    = false;
            this->timer[i].endTime   = start_time + this->ticksOfSec (duration);
            this->timer[i].duration   = this->ticksOfSec (duration);
            this->timer[i].inUse     = true;
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

    m_systime->nbTicks++;
    m_systime->nbSecRem += m_systime->resolutionCPUTicks;;
    if (m_systime->nbSecRem >= m_systime->cpuTicksPerSec) {
        m_systime->nbSecRem -= m_systime->cpuTicksPerSec;
        m_systime->nbSec++;
    }
    unsigned int i;
    for (i=0; i < SysTime::SYS_TIME_NB_TIMER; i++) {
        if (m_systime->timer[i].inUse &&
            m_systime->nbTicks >= m_systime->timer[i].endTime) {
            m_systime->timer[i].endTime += m_systime->timer[i].duration;
            m_systime->timer[i].elapsed = true;
            if (m_systime->timer[i].cb) {
                m_systime->timer[i].cb(i);
            }
        }
    }
}