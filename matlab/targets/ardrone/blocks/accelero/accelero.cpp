#include "accelero.h"

void Accelero_Initialization ()
{
#ifndef MATLAB_MEX_FILE
    Navdata::init () ;
#endif
}

float Accelero_Get_X ()
{
#ifndef MATLAB_MEX_FILE
    return (Navdata::IMU::Accelerometer::getX());
#else 
    return 0;
#endif
}

float Accelero_Get_Y ()
{
#ifndef MATLAB_MEX_FILE
    return (Navdata::IMU::Accelerometer::getY());
#else 
    return 0;
#endif
}

float Accelero_Get_Z ()
{
#ifndef MATLAB_MEX_FILE
    return (Navdata::IMU::Accelerometer::getZ());
#else 
    return 0;
#endif
}