#include "imu.h"

void IMU_Initialization ()
{
#ifndef MATLAB_MEX_FILE
    Navdata::init () ;
#endif
}

int16_t IMU_Get_Acceleration_X ()
{
#ifndef MATLAB_MEX_FILE
    return (Navdata::IMU::Accelerometer::getRawX());
#else 
    return 0;
#endif
}

int16_t IMU_Get_Acceleration_Y ()
{
#ifndef MATLAB_MEX_FILE
    return (Navdata::IMU::Accelerometer::getRawY());
#else 
    return 0;
#endif
}

int16_t IMU_Get_Acceleration_Z ()
{
#ifndef MATLAB_MEX_FILE
    return (Navdata::IMU::Accelerometer::getRawZ());
#else 
    return 0;
#endif
}