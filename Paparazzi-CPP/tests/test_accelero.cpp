#include "../src/SysTime.h"
#include "../src/Navdata.h"

#include <cmath>
#include <unistd.h>
#include <iostream>

void updateNavdata (uint8_t a) {
    Navdata::update () ;
}

using namespace Navdata::IMU ;

void updateAHRS (uint8_t a) {
	Navdata::IMU::update () ;
	Navdata::AHRS::update () ;
}

void printAHRS (uint8_t a) {
	struct Navdata::AHRS::EulerAngles eangles = Navdata::AHRS::getEulerAngles() ;
	std::cout << Navdata::height() << " " << eangles.phi * 180 / M_PI << " " << eangles.rho * 180 / M_PI << " " << eangles.tetha * 180 / M_PI  << std::endl ;
}

int main () {

    SysTime *systime = SysTime::getSysTime () ;

	if (!Navdata::init()) {
		std::cerr << "Error initializing navdata." << std::endl ;
		return 1 ;
	}

	Navdata::AHRS::setSamplePeriod (10000) ;
	Navdata::AHRS::setKp (0.2) ;
	Navdata::AHRS::setKi (0.0) ;

    systime->registerTimer (0.001, updateNavdata);	
	systime->registerTimer (0.01, updateAHRS);
    tid_t accID = systime->registerTimer (0.5, printAHRS);
    tid_t stopID = systime->registerTimer (30, 0) ;
    
    while (!systime->checkAndAckTimer(stopID)) {
        usleep(10) ;
    }
    
    return 0 ;
    
}
