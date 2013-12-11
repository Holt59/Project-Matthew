#include "led.h"

#ifndef MATLAB_MEX_FILE

#include <sys/time.h>

#else

#define RED 1

#endif

static int LED_Init = 0 ;

static int LED_States[] = {
	RED, RED, RED, RED
} ;

unsigned long getTimePeriod () {

#ifndef MATLAB_MEX_FILE

    static double last = 0.0 ;
    double current = 0.0 ;
    struct timeval tim ;
    unsigned long diff ;
    gettimeofday(&tim, NULL) ;
    current = ((double)tim.tv_sec) * 10e6 + (double)tim.tv_usec ;
    diff = current - last ;
    last = current ;
    return diff ;

#else

    return 1 ;

#endif 

}

void LED_SetLed (int num, int color)
{
	printf("LED=%d COLOR=%d\n", num, color);
	LED_States[num] = color ;
}

void LED_SetLeds () {
	printf("LEDS=%d,%d,%d,%d\n", LED_States[0], LED_States[1], LED_States[2], LED_States[3]);
    printf("Time=%lu\n", getTimePeriod());

#ifndef MATLAB_MEX_FILE
	actuators_led_set(LED_States[0], LED_States[1], LED_States[2], LED_States[3]);
#endif
}

void LED_Initialization ()
{
#ifndef MATLAB_MEX_FILE
    actuators_init();
    actuators_led_set(RED,RED,RED,RED);
    
    sys_time_init();
    log_init();
    stateInit();
#endif
    LED_Init = 1 ;
}

void led (int couleur, int led)
{ 
	LED_SetLed(led, couleur) ;
    LED_SetLeds() ;

    // actuators_close();
}