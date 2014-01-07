#include <iostream>

#include <unistd.h>
#include <stdlib.h>

#include "../include/paparazzi/Navdata.h"

int main (int argc, char *argv[]) {

	if (argc != 2) {
		std::cerr << "Missing arguments." << std::endl ;
		return 1 ;
	}

	Navdata::init() ;

	int N = atoi(argv[1]) ;
	
	for (int i=0; i<N; i++) {
		Navdata::update() ;
		Navdata::IMU::update() ;
		std::cout << Navdata::IMU::Magnetometer::getX() << " " ;
		std::cout << Navdata::IMU::Magnetometer::getY() << " " ;
		std::cout << Navdata::IMU::Magnetometer::getZ() << std::endl ;
		usleep(2000) ;
	}

}