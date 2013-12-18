/*
 * Copyright (C) 2006 Pascal Brisset, Antoine Drouin
 * Copyright (C) 2012 Gautier Hattenberger
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

/** @file actuators.c
 *  Hardware independent actuators code.
 *
 */
#include "actuators.h"

#if ACTUATORS_NB
#include "actuators_ardrone2_raw.h"
#include "motor_mixing.h"

int16_t actuators[ACTUATORS_NB];

void actuators_init(void) {

  actuators_ardrone_init();
  motor_mixing_init();
}

void actuators_commit(){
	actuators_ardrone_commit();
}

void set_TOP_RIGHT_Servo(int32_t _v) { 
  actuators[SERVO_TOP_RIGHT_IDX] = Chop(_v, SERVO_TOP_RIGHT_MIN, SERVO_TOP_RIGHT_MAX); 
  ActuatorArdroneSet(SERVO_TOP_RIGHT, actuators[SERVO_TOP_RIGHT_IDX]); 
}

void set_TOP_LEFT_Servo(int32_t _v) { \
  actuators[SERVO_TOP_LEFT_IDX] = Chop(_v, SERVO_TOP_LEFT_MIN, SERVO_TOP_LEFT_MAX); \
  ActuatorArdroneSet(SERVO_TOP_LEFT, actuators[SERVO_TOP_LEFT_IDX]); \
}

void set_BOTTOM_RIGHT_Servo(int32_t _v) { \
  actuators[SERVO_BOTTOM_RIGHT_IDX] = Chop(_v, SERVO_BOTTOM_RIGHT_MIN, SERVO_BOTTOM_RIGHT_MAX); \
  ActuatorArdroneSet(SERVO_BOTTOM_RIGHT, actuators[SERVO_BOTTOM_RIGHT_IDX]); \
}

void set_BOTTOM_LEFT_Servo(int32_t _v) { \
  actuators[SERVO_BOTTOM_LEFT_IDX] = Chop(_v, SERVO_BOTTOM_LEFT_MIN, SERVO_BOTTOM_LEFT_MAX); \
  ActuatorArdroneSet(SERVO_BOTTOM_LEFT, actuators[SERVO_BOTTOM_LEFT_IDX]); \
}


void actuators_set(int16_t values[]) { 
  int32_t servo_value;
  int32_t command_value;

  motor_mixing_run(TRUE,FALSE,values); 

  command_value = motor_mixing.commands[SERVO_TOP_LEFT]; 
  command_value *= command_value>0 ? SERVO_TOP_LEFT_TRAVEL_UP_NUM : SERVO_TOP_LEFT_TRAVEL_DOWN_NUM; 
  command_value /= command_value>0 ? SERVO_TOP_LEFT_TRAVEL_UP_DEN : SERVO_TOP_LEFT_TRAVEL_DOWN_DEN; 
  servo_value = SERVO_TOP_LEFT_NEUTRAL + command_value; 
  set_TOP_LEFT_Servo(servo_value); 

  command_value = motor_mixing.commands[SERVO_TOP_RIGHT]; 
  command_value *= command_value>0 ? SERVO_TOP_RIGHT_TRAVEL_UP_NUM : SERVO_TOP_RIGHT_TRAVEL_DOWN_NUM; 
  command_value /= command_value>0 ? SERVO_TOP_RIGHT_TRAVEL_UP_DEN : SERVO_TOP_RIGHT_TRAVEL_DOWN_DEN; 
  servo_value = SERVO_TOP_RIGHT_NEUTRAL + command_value; 
  set_TOP_RIGHT_Servo(servo_value); 

  command_value = motor_mixing.commands[SERVO_BOTTOM_LEFT]; 
  command_value *= command_value>0 ? SERVO_BOTTOM_LEFT_TRAVEL_UP_NUM : SERVO_BOTTOM_LEFT_TRAVEL_DOWN_NUM; 
  command_value /= command_value>0 ? SERVO_BOTTOM_LEFT_TRAVEL_UP_DEN : SERVO_BOTTOM_LEFT_TRAVEL_DOWN_DEN; 
  servo_value = SERVO_BOTTOM_LEFT_NEUTRAL + command_value; 
  set_BOTTOM_LEFT_Servo(servo_value); 

  command_value = motor_mixing.commands[SERVO_BOTTOM_RIGHT]; 
  command_value *= command_value>0 ? SERVO_BOTTOM_RIGHT_TRAVEL_UP_NUM : SERVO_BOTTOM_RIGHT_TRAVEL_DOWN_NUM; 
  command_value /= command_value>0 ? SERVO_BOTTOM_RIGHT_TRAVEL_UP_DEN : SERVO_BOTTOM_RIGHT_TRAVEL_DOWN_DEN; 
  servo_value = SERVO_BOTTOM_RIGHT_NEUTRAL + command_value; 
  set_BOTTOM_RIGHT_Servo(servo_value); 
}

void actuators_close(void) {
  actuators_ardrone_close();
}

void actuators_led_set(uint8_t led0, uint8_t led1, uint8_t led2, uint8_t led3){
  actuators_ardrone_set_leds(led0, led1, led2, led3);
}

#endif
