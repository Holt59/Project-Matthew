#include "../include/paparazzi/Actuators.h"
#include "../include/paparazzi/Navdata.h"

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

        int udt ;

        if (!Navdata::init ()) {
                std::cerr << "Error initializing navdata." << std::endl ;
                return 1 ;
        }

        std::cout << "Starting loop... " << std::endl ;

        Navdata::AHRS::setSamplePeriod(6000) ;
		Navdata::AHRS::setKp(2.0) ;

		int i = 0 ;

        while (1) {

                struct timeval start, end ;
                
                gettimeofday(&start, NULL) ;

                Navdata::update () ;

				/*

				if ((i++ % 100) == 0) {
					printf("\r%5f %5f %5f | %5f %5f %5f | %5f %5f %5f",
						Navdata::IMU::Gyroscope::getX(), Navdata::IMU::Gyroscope::getY(), Navdata::IMU::Gyroscope::getZ(), 
						Navdata::IMU::Accelerometer::getX(), Navdata::IMU::Accelerometer::getY(), Navdata::IMU::Accelerometer::getZ(), 
						Navdata::IMU::Magnetometer::getX(), Navdata::IMU::Magnetometer::getY(), Navdata::IMU::Magnetometer::getZ()) ;
					fflush(stdout) ;
				}

				usleep(2000) ;

                */

				if (i%1000 == 0) {
					Navdata::AHRS::setKp(0.5) ;
				}

				if (i++%3 == 0) {
					Navdata::IMU::update () ;
					Navdata::AHRS::update () ;
				}

				if (i%250 == 0) {
					struct Navdata::AHRS::EulerAngles eangles  = Navdata::AHRS::getEulerAngles() ;
					printf("\r%8f %8f %8f", eangles.phi * 180.0 / M_PI, eangles.rho * 180.0 / M_PI, eangles.tetha * 180.0 / M_PI) ;
					fflush(stdout) ;
				}

				gettimeofday(&end, NULL) ;
				udt = ((float)(end.tv_sec - start.tv_sec)) * 1e6 - (end.tv_usec - start.tv_usec) ;

				if (udt < 2000) {
					usleep(2000 - udt) ;
				}

        }
        
        return 0 ;

}
