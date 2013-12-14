#include <stdio.h>   /* Standard input/output definitions */
#include <stdbool.h> /* C99 boolean definitions */
#include <string.h>  /* String function definitions */
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */
#include <stdint.h>
#include <float.h>

#include <paparazzi/conf.h> /* 2 variables de conf !!! STAGIAIRE !!! */
#include <paparazzi/sys_time.h>
#include <paparazzi/state.h>
#include <paparazzi/commands.h>

//bloc capteur
#include <paparazzi/capteur/baro_board.h>
#include <paparazzi/capteur/imu.h>
#include <paparazzi/capteur/ahrs.h>
#include <paparazzi/capteur/ahrs/ahrs_int_cmpl_quat.h>
#include <paparazzi/capteur/ahrs/ahrs_aligner.h>
#include <paparazzi/capteur/ins.h>
#include <paparazzi/capteur/ins_int.h>


static inline void on_accel_event( void )
{
  ImuScaleAccel(imu);

  if (ahrs.status != AHRS_UNINIT) {
    ahrs_update_accel();
  }
}

static inline void on_gyro_event( void )
{
  ImuScaleGyro(imu);
  if (ahrs.status == AHRS_UNINIT) {
    ahrs_aligner_run();
    if (ahrs_aligner.status == AHRS_ALIGNER_LOCKED)
      ahrs_align();
  }
  else {
    ahrs_propagate();
    ins_propagate();
  }
}

static inline void on_mag_event(void)
{
  ImuScaleMag(imu);
  if (ahrs.status == AHRS_RUNNING) {
    ahrs_update_mag();
  }
}

tid_t main_tid;
tid_t main_periodic_tid;
tid_t main_display_tid;

int main(){
  
  printf("Initialisation\n");

  sys_time_init();
  stateInit();
	
  imu_init();
  ahrs_aligner_init();
  ahrs_init();
 
  main_tid = sys_time_register_timer(40,NULL);
  main_periodic_tid = sys_time_register_timer((1./PERIODIC_FREQUENCY), NULL);
  main_display_tid = sys_time_register_timer(2, NULL);

  struct Int32Eulers * eangles;

  while(!sys_time_check_and_ack_timer(main_tid))
  {
    if(sys_time_check_and_ack_timer(main_periodic_tid)){
      eangles = stateSetNedToBodyEulers_i();
      imu_periodic(); //On regarde si des nouvelles valeurs ont été reçues
    }
    //event
    imu_event(on_gyro_event, on_accel_event, on_mag_event);

    if(sys_time_check_and_ack_timer(main_display_tid)){
      printf("%d %d %d\n", eangles->phi, eangles->theta, eangles->psi);
    }
  }

  printf("Fin acquisition\n");
}
