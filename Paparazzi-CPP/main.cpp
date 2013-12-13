#include "Actuators.h"
#include "Navdata.h"

#include <iostream>

#include <unistd.h>

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

	

	if (!Navdata::init ()) {
		std::cerr << "Error initializing navdata." << std::endl ;
		return 1 ;
	}*/

	std::cout << "Starting loop... " << std::endl ;

	while (1) {
		
		std::cout << "TOP LOOP: " << std::endl ;

		std::cout << Navdata::update () << std::endl ;
		
		if (Navdata::IMU::isIMUAvailable()) {
			std::cout << "IMU OK !" << std::endl ;
			Navdata::IMU::update () ;
			std::cout << Navdata::IMU::Accelerometer::getX () << std::endl ;
			std::cout << Navdata::IMU::Accelerometer::getY () << std::endl ;
			std::cout << Navdata::IMU::Accelerometer::getZ () << std::endl ;
		}
		/*
		if (Navdata::Barometer::isBaroAvailable()) {
			std::cout << "Baro OK !" << std::endl ;
			std::cout << Navdata::Barometer::getTemperature() << std::endl ;
			std::cout << Navdata::Barometer::getPressure() << std::endl ;
		}
	
		Navdata::height ()  ;
		*/
		usleep(1000000) ; 

	}
	
	return 0 ;

}