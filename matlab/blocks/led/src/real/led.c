#include "led.h"

static int LED_Init = 0 ;
static tid_t LED_MainTid;
static tid_t LED_LedsTid;

static int LED_States[] = {
	RED, RED, RED, RED
} ;

void LED_SetLed (int num, int color)
{
	printf("LED=%d COLOR=%d\n", num, color);
	LED_States[num] = color ;
}

void LED_SetLeds () {
	printf("LEDS=%d,%d,%d,%d\n", LED_States[0], LED_States[1], LED_States[2], LED_States[3]);
	actuators_led_set(LED_States[0], LED_States[1], LED_States[2], LED_States[3]) ;
}

void LED_Initialization () {
    actuators_init();
    actuators_led_set(RED,RED,RED,RED);
    
    sys_time_init();
    log_init();
    stateInit();
    
    /*
    imu_init();
    ahrs_aligner_init();
    ahrs_init();
    
    stabilization_attitude_init();
    guidance_v_init();
    ins_init();
    */
    
    LED_MainTid = sys_time_register_timer(40,NULL);
    LED_LedsTid = sys_time_register_timer((0.2),NULL);

    LED_Init = 1 ;
}

void led (int couleur, int led) { 

	if (!LED_Init) {
		printf("Init\n");
		LED_Initialization () ;
		printf("Fin Init\n");
	}

	LED_SetLed(led, couleur) ;
    LED_SetLeds() ;

    // actuators_close();
}