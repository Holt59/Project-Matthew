/*
 * Copyright (C) 2012 TU Delft Quatrotor Team 1
 *
 * This file is part of Paparazzi.
 *
 * Paparazzi is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * Paparazzi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Paparazzi; see the file COPYING.  If not, write to
 * the Free Software Foundation, 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

/**
 * @file boards/ardrone/baro_board.c
 * Paparazzi AR Drone 2 Baro Sensor implementation:.
 *
 * These functions are mostly empty because of the calibration and calculations
 * done by the Parrot Navigation board.
 */

#include "baro_board.h"

struct Baro baro;
int baro_data_available;

void baro_init(void) {
  baro.status = BS_UNINITIALIZED;
  baro.absolute     = 0;
  baro.differential = 0;
  baro_data_available = 0;
}

int16_t get_temp(uint32_t ut){
	int16_t temperature;
	int32_t x1,x2;
	uint16_t ac6 = 23153;
	uint16_t ac5 = 32757;
	int16_t mc = -8711;
	int16_t md = 2868;
	int32_t param_b5;
	x1 = (((long) ut - (long) ac6) * (long) ac5) >> 15;
		x2 = ((long) mc << 11) / (x1 + md);
		param_b5 = x1 + x2;
   temperature = ((param_b5 + 8) >> 4);  /* temperature in 0.1 deg C*/
		
	return temperature;
}

int32_t get_pressure(uint32_t up){
	return 0;
}
void baro_periodic(void) {
  baro.status = BS_RUNNING;
  if(navdata_baro_available == 1) {
    navdata_baro_available = 0;
	int16_t temp = get_temp(navdata->temperature_pressure);
	//printf("temp %lu %u°C\n",navdata->temperature_pressure,temp);// baro.absolute = navdata->pressure; // When this is un-commented the ardrone gets a pressure
    // TODO do the right calculations for the right absolute pressure
	
    baro.absolute = 0;
    baro_data_available = TRUE;
  }
  else {
    baro_data_available = FALSE;
  }
}
