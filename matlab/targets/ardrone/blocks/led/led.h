#ifndef _LED_H
#define _LED_H

#ifndef MATLAB_MEX_FILE

#include <paparazzi/Actuators.h>

#endif

void LED_Initialization () ;

void LED_Set(int color, int led);

#endif
