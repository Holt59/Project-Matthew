#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "print2file.h"

void print2function (int a) {
    FILE *f = fopen(OUTPUT_FILENAME, "a") ;
    if (f == NULL) {
	fprintf(stderr, "Error openning file %s: %s", OUTPUT_FILENAME, strerror(errno)) ;
    }
    fprintf(f, "LOG: %d\n", a) ;
    fclose(f) ;
}
