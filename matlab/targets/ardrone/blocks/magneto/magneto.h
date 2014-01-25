#ifndef _MAGNETO_H
#define _MAGNETO_H

#include <stdint.h>

#ifndef MATLAB_MEX_FILE

#include <bibrone/Navdata.h>

#endif

void Magneto_Initialization();

float Magneto_Get_X ();
float Magneto_Get_Y ();
float Magneto_Get_Z ();

#endif
