#include "height.h"

void Height_Initialization ()
{
#ifndef MATLAB_MEX_FILE
    Navdata::init () ;
#endif
}


int16_t Height_Get ()
{
#ifndef MATLAB_MEX_FILE
    return Navdata::height();
#else
    return 0;
#endif
}
