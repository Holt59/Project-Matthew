#include "../include/paparazzi/Navdata.h"

#include <iostream>
#include <algorithm>
#include <unistd.h>
#include <stdio.h>

const int NB_SAMPLES = 10000 ;

const int16_t OFFSET_X = -73 ;
const int16_t OFFSET_Y =  14 ;
const int16_t OFFSET_Z = -13 ;

const int16_t NOISE_X = 35 ;
const int16_t NOISE_Y = 35 ;
const int16_t NOISE_Z = 15 ;

const float SENSIBILITY = 0.0609 ;

int main (int argc, char *argv[]) {

    if (!Navdata::init ()) {
        std::cerr << "Error initializing navdata." << std::endl ;
        return 1 ;
    }

	float gx, gy, gz ;
	gx = gy = gz = 0.0 ;

	int udt = 2000 ;

	int cmp = 0 ;

	while (1) {

		Navdata::update () ;

		int16_t vx = Navdata::IMU::Gyroscope::getRawX () - OFFSET_X ;
		int16_t vy = Navdata::IMU::Gyroscope::getRawY () - OFFSET_Y ;
		int16_t vz = Navdata::IMU::Gyroscope::getRawZ () - OFFSET_Z ;

		if (abs(vx) > NOISE_X) {
			gx += (float) vx * SENSIBILITY * udt / 1e6 ; 
		}

		if (abs(vy) > NOISE_Y) {
			gy += (float) vy * SENSIBILITY * udt / 1e6 ; 
		}

		if (abs(vz) > NOISE_Z) {
			gz += (float) vz * SENSIBILITY * udt / 1e6 ; 
		}

		if (cmp++ % 250 == 0) {
			printf("\r%8f %8f %8f", gx, gy, gz) ;
			fflush(stdout) ;
		}

		usleep(udt) ;

	}

    return 0 ;

}