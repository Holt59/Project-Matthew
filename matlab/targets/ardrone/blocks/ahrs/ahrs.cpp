#include "ahrs.h"
#include <math.h>

void Ahrs_Initialization ()
{
#ifndef MATLAB_MEX_FILE
    Navdata::init () ;
#endif
}

float Ahrs_Get_Roll ()
{
#ifndef MATLAB_MEX_FILE
    struct Navdata::AHRS::EulerAngles eangles = Navdata::AHRS::getEulerAngles() ;
    eangles.phi += M_PI;
    if(eangles.phi > M_PI)
    	eangles.phi -= 2.0*M_PI;
	return eangles.phi * 180.0 / M_PI;
#endif
}

float Ahrs_Get_Yaw ()
{
#ifndef MATLAB_MEX_FILE
    struct Navdata::AHRS::EulerAngles eangles = Navdata::AHRS::getEulerAngles() ;
	return eangles.rho * 180.0 / M_PI;
#endif
}

float Ahrs_Get_Pitch ()
{
#ifndef MATLAB_MEX_FILE
    struct Navdata::AHRS::EulerAngles eangles = Navdata::AHRS::getEulerAngles() ;
	return eangles.tetha * 180.0 / M_PI;
#endif
}