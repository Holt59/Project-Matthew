#ifndef _IMU_H
#define _IMU_H

#include <stdint.h>

#ifndef MATLAB_MEX_FILE

#include <paparazzi/Navdata.h>

#endif

void IMU_Initialization();

int16_t IMU_Get_Acceleration_X ();
int16_t IMU_Get_Acceleration_Y ();
int16_t IMU_Get_Acceleration_Z ();

#endif
