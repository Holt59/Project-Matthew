#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "print2file.h"

FILE *f;
        
void print2file_Init(const char *name)
{
    f = fopen(name, "a") ;
    if (f == NULL) {
        fprintf(stderr, "Error openning file %s: %s", name, strerror(errno)) ;
    }
}

void print2file (int a)
{
    fprintf(f, "LOG: %d\n", a);
}

void print2file_Close()
{
    fclose(f) ;
}
