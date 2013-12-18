#include "motor.h"

void Motor_Initialization ()
{
#ifndef MATLAB_MEX_FILE
    Actuators::init () ;
#endif
}

void Motor_Set (int pwm, int motor)
{
#ifndef MATLAB_MEX_FILE
    Actuators::setPWM (motor, pwm) ;
#endif
}
