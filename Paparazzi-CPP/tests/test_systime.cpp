#include "../src/SysTime.h"

#include <unistd.h>
#include <iostream>

void printCallBack (uint8_t a) {
    std::cout << "Call !" << std::endl ;
}

int main () {

    SysTime *systime = SysTime::getSysTime () ;
    
    tid_t mainID = systime->registerTimer (0.5, printCallBack);
    tid_t stopID = systime->registerTimer (10, 0) ;
    
    while (!systime->checkAndAckTimer(stopID)) {
        usleep(10) ;
    }
    
    return 0 ;
    
}