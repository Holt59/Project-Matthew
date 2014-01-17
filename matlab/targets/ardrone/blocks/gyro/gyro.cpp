#include "gyro.h"

void Gyro_Initialization ()
{
#ifndef MATLAB_MEX_FILE
    Navdata::init () ;
#endif
}

float Gyro_Get_X ()
{
#ifndef MATLAB_MEX_FILE
    return (Navdata::IMU::Gyroscope::getX());
#else 
    return 0;
#endif
}

float Gyro_Get_Y ()
{
#ifndef MATLAB_MEX_FILE
    return (Navdata::IMU::Gyroscope::getY());
#else 
    return 0;
#endif
}

float Gyro_Get_Z ()
{
#ifndef MATLAB_MEX_FILE
    return (Navdata::IMU::Gyroscope::getZ());
#else 
    return 0;
#endif
}