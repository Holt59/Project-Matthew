#ifndef _ACTUATORS_H
#define _ACTUATORS_H

#include <stdint.h>

/**
 * Actuators module : Utility functions to control
 * motors and LEDs for the AR.Drone.
**/
namespace Actuators {

    /**
     * 
     * Initialize the Actuators module.
     * This function should be could one as the beginning of your
     * program.
     * 
    **/
    bool init () ;
    
    /**
     * 
     * Stop the Actuators module.
     * 
    **/
    void stop () ;
    
    /**
     * 
     * Commit the current PWMs value to the actuators.
     * You need to call this function once in a while if you want
     * to keep the actuators running.
     * Calling this function is equivalent to call setPWM with the
     * latest value(s) used.
     * 
     * @return true if the values were commited, false otherwise
     * 
    **/
    bool commit() ;

    /**
     * 
     * Set the PWM value (0 .. 100) for the specified motor. This function
     * call commit after setting the PWM value.
     * 
     * @param motor The identifier (from 0 to 3) the motor to be set.
     * @param pwm The PWM value (0 is OFF, 100 is full power).
     * 
     * @return true if the PWM was commited, false otherwise
     * 
    **/
    bool setPWM (uint8_t motor, uint16_t pwm) ;
    
    /**
     * 
     * Set the PWM values for the all motors. This function
     * call commit after setting the PWM values.
     * 
     * @param pwm0, pwm1, pwm2, pwm3 The PWM values (0 is OFF, 100 is full power).
     * 
     * @return true if PWMs were commited, false otherwise
     * 
    **/
    bool setPWM (uint16_t pwm0, uint16_t pwm1, uint16_t pwm2, uint16_t pwm3) ;

    namespace Led {

        /** Available values to LED. **/
        const uint8_t OFF    = 0x0 ;
        const uint8_t RED    = 0x1 ;
        const uint8_t GREEN  = 0x2 ;
        const uint8_t ORANGE = 0x3 ;

        /**
         * 
         * Set the specified LED value. Unlike the actuators, the LED value
         * remains until a new Led::set call and there is no need to call Actuators::commit
         * to maintain the LED up.
         * 
         * @param led The identifier (from 0 to 3) of the LED to be set.
         * @param value The value to set (OFF / RED / GREEN / ORANGE).
         * 
         * @return true if the value was set correclty, false otherwise.
         * 
        **/
        bool set (uint8_t led, uint8_t value) ;
        
        /**
         * 
         * Set all LEDs values. Unlike the actuators, the LED values
         * remain until a new Led::set call and there is no need to call Actuators::commit
         * to maintain the LED up.
         * 
         * @param led0, led1, led2, led3 Values to set (OFF / RED / GREEN / ORANGE).
         * 
         * @return true if values were set correclty, false otherwise.
         * 
        **/
        bool set (uint8_t led0, uint8_t led1, uint8_t led2, uint8_t led3) ;

    }

}

#endif
