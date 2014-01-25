#ifndef _AHRS_H
#define _AHRS_H

#include <stdint.h>

#ifndef MATLAB_MEX_FILE

#include <bibrone/Navdata.h>

#endif

void Ahrs_Initialization ();

float Ahrs_Get_Pitch ();

float Ahrs_Get_Roll ();

float Ahrs_Get_Yaw ();

#endif
