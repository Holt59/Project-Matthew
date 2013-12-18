#ifndef _ACTUATORS_H
#define _ACTUATORS_H

#include <stdint.h>

namespace Actuators {

    bool init () ;
    
    bool commit() ;

    bool setPWM (uint8_t motor, uint16_t pwm) ;
    bool setPWM (uint16_t pwm0, uint16_t pwm1, uint16_t pwm2, uint16_t pwm3) ;

    void stop () ;

    namespace Led {

        const uint8_t OFF = 0 ;
        const uint8_t RED = 1 ;
        const uint8_t GREEN = 2 ;
        const uint8_t ORANGE = 3 ;

        bool set (uint8_t led, uint8_t value) ;
        bool set (uint8_t led0, uint8_t led1, uint8_t led2, uint8_t led3) ;

    }

}

#endif