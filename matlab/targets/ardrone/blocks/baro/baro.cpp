#include "baro.h"

void Barometer_Initialization ()
{
#ifndef MATLAB_MEX_FILE
    Navdata::init () ;
#endif
}

int32_t Barometer_Get_Pressure ()
{
#ifndef MATLAB_MEX_FILE
    return Navdata::Barometer::getPressure();
#endif
}

int32_t Barometer_Get_Temperature ()
{
#ifndef MATLAB_MEX_FILE
    return Navdata::Barometer::getTemperature();
#endif
}
