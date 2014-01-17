#ifndef _GYRO_H
#define _GYRO_H

#include <stdint.h>

#ifndef MATLAB_MEX_FILE

#include <paparazzi/Navdata.h>

#endif

void Gyro_Initialization();

float Gyro_Get_X ();
float Gyro_Get_Y ();
float Gyro_Get_Z ();

#endif
