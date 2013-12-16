#include "led.h"

void LED_Initialization ()
{
#ifndef MATLAB_MEX_FILE
    Actuators::init () ;
#endif
}

void LED_Set (int couleur, int led) {
#ifndef MATLAB_MEX_FILE
    Actuators::Led::set (led, couleur) ;
#endif
}
