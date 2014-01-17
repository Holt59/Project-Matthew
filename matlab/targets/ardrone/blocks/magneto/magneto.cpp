#include "magneto.h"

void Magneto_Initialization ()
{
#ifndef MATLAB_MEX_FILE
    Navdata::init () ;
#endif
}

float Magneto_Get_X ()
{
#ifndef MATLAB_MEX_FILE
    return (Navdata::IMU::Magnetometer::getX());
#else 
    return 0;
#endif
}

float Magneto_Get_Y ()
{
#ifndef MATLAB_MEX_FILE
    return (Navdata::IMU::Magnetometer::getY());
#else 
    return 0;
#endif
}

float Magneto_Get_Z ()
{
#ifndef MATLAB_MEX_FILE
    return (Navdata::IMU::Magnetometer::getZ());
#else 
    return 0;
#endif
}