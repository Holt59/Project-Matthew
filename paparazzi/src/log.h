/* Nicolas Kniebihli INP-T ENSEEIHT
*/
#ifndef LOG_H_
#define LOG_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdio.h>

FILE* fichier;

void log_init();
void log_close();
void log_add(const char * string);

#ifdef __cplusplus
}
#endif

#endif
