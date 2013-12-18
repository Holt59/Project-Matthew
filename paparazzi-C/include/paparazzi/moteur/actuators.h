/*
 * (c) 2003-2005 Pascal Brisset, Antoine Drouin
 * (c) 2012 Gautier Hattenberger
 * adapted by Nicolas Kniebihli INP-T ENSEEIHT
 *
 * This file is part of paparazzi.
 *
 * paparazzi is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * paparazzi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with paparazzi; see the file COPYING.  If not, write to
 * the Free Software Foundation, 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

/** @file actuators.h
 *  Hardware independent API for actuators (servos, motor controllers).
 *
 */
#ifndef ACTUATORS_H
#define ACTUATORS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../std.h"
#include "conf_moteur.h"

#define OFF    0
#define RED    1
#define GREEN  2
#define ORANGE 3

/* Initialisation moteur */
extern void actuators_init(void);

/* Envoie de l'information moteur au moteur */
extern void actuators_commit(void);

/** Actuators array.
 * Temporary storage (for debugging purpose, downlinked via telemetry)
 * */
extern int16_t actuators[ACTUATORS_NB];

/* Mise a jour des valeurs moteurs 
 * valeur de values de 0 a 9600
 * values[0] = COMMAND_PITCH
 * values[1] = COMMAND_ROLL
 * values[2] = COMMAND_YAW
 * values[3] = COMMAND_THRUST
 */
extern void actuators_set(int16_t values[]);

/* Mise à jour des leds moteurs */
extern void actuators_led_set(uint8_t led0, uint8_t led1, uint8_t led2, uint8_t led3);

extern void actuators_close(void);

#ifdef __cplusplus
}
#endif

#endif /* ACTUATORS_H */
