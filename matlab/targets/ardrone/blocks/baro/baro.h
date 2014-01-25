#ifndef _BARO_H
#define _BARO_H

#include <stdint.h>

#ifndef MATLAB_MEX_FILE

#include <bibrone/Navdata.h>

#endif

void Barometer_Initialization();

int32_t Barometer_Get_Pressure ();

int32_t Barometer_Get_Temperature ();

#endif
