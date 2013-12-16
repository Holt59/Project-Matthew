#include "Actuators.h"
#include "Navdata.h"

#include <iostream>

#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <math.h>

int main () {

	/*

	if (!Actuators::init()) {
		std::cerr << "Error initializing actuators." << std::endl ;
		return 1 ;
	}

	while (1) {
		Actuators::setPWM(0x1ff, 0x1ff, 0x1ff, 0x1ff) ;
		usleep(10000) ;
	}

	return 0 ;

	*/

	const int dt = 10000 ;
	int udt ;

	if (!Navdata::init ()) {
		std::cerr << "Error initializing navdata." << std::endl ;
		return 1 ;
	}

	std::cout << "Starting loop... " << std::endl ;

	Navdata::AHRS::setSamplePeriod(dt) ;

	int cmp = 0 ;

	while (1) {

		struct Navdata::AHRS::EulerAngles eangles ;
		struct timeval start, end ;
		
		gettimeofday(&start, NULL) ;

		Navdata::update () ;
		
		Navdata::IMU::update () ;
		// Navdata::AHRS::update () ;

		// eangles = Navdata::AHRS::getEulerAngles() ;

		// printf("\r%8f %8f %8f", eangles.phi * 180.0 / M_PI, eangles.rho * 180.0 / M_PI, eangles.tetha * 180.0 / M_PI) ;

		if (cmp++ % 50 == 0) {

			printf("\r%8f %8f %8f", Navdata::IMU::Accelerometer::getX (), Navdata::IMU::Accelerometer::getY (), Navdata::IMU::Accelerometer::getZ ()) ;
			fflush(stdout) ;
		}

		usleep(1000) ;

		/*
		gettimeofday(&end, NULL) ;

		udt = ((float)(end.tv_sec - start.tv_sec)) * 1e6 - (end.tv_usec - start.tv_usec) ;

		// std::cout << udt << std::endl ;
		
		usleep(dt - (int)udt) ; */

	}
	
	return 0 ;

}