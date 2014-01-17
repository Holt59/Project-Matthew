#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "print2file.h"

FILE *f;
        
void print2file_Init(int8_t *name)
{
#ifndef MATLAB_MEX_FILE
    f = fopen((const char *)name, "a") ;
    if (f == NULL) {
        fprintf(stderr, "Error openning file %s: %s", name, strerror(errno)) ;
    }
#endif
}

void print2file (int a)
{
#ifndef MATLAB_MEX_FILE
    fprintf(f, "LOG: %d\n", a);
#endif
}

void print2file_Close()
{
#ifndef MATLAB_MEX_FILE
    fclose(f) ;
#endif
}
