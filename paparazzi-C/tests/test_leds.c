#include <stdio.h>   /* Standard input/output definitions */
#include <stdbool.h> /* C99 boolean definitions */
#include <string.h>  /* String function definitions */
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */
#include <stdint.h>
#include <float.h>
#include <time.h>

#include <paparazzi/sys_time.h> /* Timers PAPARAZZI */
#include <paparazzi/log.h> /* ajouter des logs !!! STAGIAIRE !!! */
#include <paparazzi/state.h> /* Pour obtenir pas mal de positions et de mesures */
#include <paparazzi/commands.h> /* Paramétrage des commandes PAPARAZZI mais aussi !!! STAGIAIRE !!! */
#include <paparazzi/conf.h> /* 2 variables de conf !!! STAGIAIRE !!! */

//bloc capteur
#include <paparazzi/capteur/baro_board.h>
#include <paparazzi/capteur/imu.h>
#include <paparazzi/capteur/ahrs.h>
#include <paparazzi/capteur/ahrs/ahrs_int_cmpl_quat.h>
#include <paparazzi/capteur/ahrs/ahrs_aligner.h>
#include <paparazzi/capteur/ins.h>
#include <paparazzi/capteur/ins_int.h>

//bloc asservisement 

#include <paparazzi/stabilization/stabilization_attitude_quat_int.h>
#include <paparazzi/stabilization/guidance_v.h>

//bloc moteur
#include <paparazzi/moteur/actuators.h>

tid_t main_tid;
tid_t leds_tid;

int main()
{
    int i = 0;
    printf("Initialisation\n");
    actuators_init();
    actuators_led_set(RED,RED,RED,RED);
    
    sys_time_init();
    log_init();
    stateInit();
    
    imu_init();
    ahrs_aligner_init();
    ahrs_init();
    
    stabilization_attitude_init();
    guidance_v_init();
    ins_init();
    
    main_tid = sys_time_register_timer(40,NULL);
    leds_tid = sys_time_register_timer((0.2),NULL);
    
    printf("Update imu\n");
    actuators_led_set(GREEN,GREEN,GREEN,GREEN);
    while(!sys_time_check_and_ack_timer(main_tid)){//periodic
        if(sys_time_check_and_ack_timer(leds_tid))
        {
            i++;
            actuators_led_set((i==1)?GREEN:RED,(i==2)?GREEN:RED,(i==3)?GREEN:RED,(i==4)?GREEN:RED);
            printf("LED %d\n",i);
            if (i==4)
                i=0;
        }
    }
    
    actuators_close();

    return 0;
}
