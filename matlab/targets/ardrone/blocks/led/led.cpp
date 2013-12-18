#include "led.h"

void LED_Initialization ()
{
#ifndef MATLAB_MEX_FILE
    Actuators::init () ;
#endif
}

<<<<<<< HEAD
void LED_Set (int couleur, int led)
{
=======
void LED_Set (int color, int led) {
>>>>>>> cd56867bccda67bc3ea9913e6d148eefbb7176fe
#ifndef MATLAB_MEX_FILE
    Actuators::Led::set (led, color) ;
#endif
}
