#ifndef __PRINT2FILE_H
#define __PRINT2FILE_H

#include <stdio.h>
#include <string.h>
#include <errno.h>

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

void led(int couleur, int led);

#endif
