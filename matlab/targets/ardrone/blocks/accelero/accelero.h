#ifndef _ACCELERO_H
#define _ACCELERO_H

#include <stdint.h>

#ifndef MATLAB_MEX_FILE

#include <paparazzi/Navdata.h>

#endif

void Accelero_Initialization();

float Accelero_Get_X ();
float Accelero_Get_Y ();
float Accelero_Get_Z ();

#endif
