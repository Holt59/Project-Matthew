#include "motor.h"

void Motor_Initialization ()
{
#ifndef MATLAB_MEX_FILE
    Actuators::init () ;
#endif
}

void Motor_Set (float pwm, uint8_t motor)
{
#ifndef MATLAB_MEX_FILE
    Actuators::setPWM (motor, (int16_t)((0x1ff*pwm)/100)) ;
#endif
}
