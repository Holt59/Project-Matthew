#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "print2file.h"

void print2file (int a, const char *name) {
    FILE *f = fopen(name, "w") ;
    if (f == NULL) {
	fprintf(stderr, "Error openning file %s: %s", name, strerror(errno)) ;
    }
    fprintf(f, "LOG: %d\n", a) ;
    fclose(f) ;
}
