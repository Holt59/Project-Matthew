#include "../include/paparazzi/Actuators.h"
#include "../include/paparazzi/Navdata.h"

#include <iostream>

#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <math.h>

#include <algorithm>

int main () {

        int udt ;

        if (!Navdata::init ()) {
                std::cerr << "Error initializing navdata." << std::endl ;
                return 1 ;
        }

        std::cout << "Starting loop... " << std::endl ;

        Navdata::AHRS::setSamplePeriod(4000) ;
		Navdata::AHRS::setKp(5.0) ;
		Navdata::AHRS::setKi(0.05) ;  // (0.002) ;

		int i = 1 ;
		bool init = false ;
		float gx = 0, gy = 0, gz = 0 ;
		float grx = 0, gry = 0, grz = 0 ;

		const int16_t OFFSET_X = -73 ;
		const int16_t OFFSET_Y =  14 ;
		const int16_t OFFSET_Z = -13 ;

		const int16_t NOISE_X = 35 ;
		const int16_t NOISE_Y = 35 ;
		const int16_t NOISE_Z = 15 ;

		const float SENSIBILITY = 0.0609 ;

        while (1) {/*

			Navdata::update () ;

			Navdata::IMU::update () ;

			gx += Navdata::IMU::Gyroscope::getX() * 0.002 * 180.0 / M_PI ;
			gy += Navdata::IMU::Gyroscope::getY() * 0.002 * 180.0 / M_PI  ;
			gz += Navdata::IMU::Gyroscope::getZ() * 0.002 * 180.0 / M_PI  ;

			int16_t vx = Navdata::IMU::Gyroscope::getRawX () - OFFSET_X ;
			int16_t vy = Navdata::IMU::Gyroscope::getRawY () - OFFSET_Y ;
			int16_t vz = Navdata::IMU::Gyroscope::getRawZ () - OFFSET_Z ;

			if (abs(vx) > NOISE_X) {
				grx += (float) vx * SENSIBILITY * 0.002 ; 
			}

			if (abs(vy) > NOISE_Y) {
				gry += (float) vy * SENSIBILITY * 0.002 ; 
			}

			if (abs(vz) > NOISE_Z) {
				grz += (float) vz * SENSIBILITY * 0.002 ; 
			}

			if (i++%250 == 0) {
				printf("\r%8f %8f - %8f %8f - %8f %8f", gx, grx, gy, gry, gz, grz) ;
				fflush(stdout) ;
			}

			usleep(2000) ;
			*/
			
				if (i%2500 == 0 && !init) {
					init = true ;
					printf("Initialization: OK\n") ;
					Navdata::AHRS::setKp(0.5) ; // (0.0368) ;
				}

                struct timeval start, end ;
                
                gettimeofday(&start, NULL) ;

                Navdata::update () ;

				if (i%2 == 0) {
					Navdata::IMU::update () ;
					Navdata::AHRS::updateWithMag () ;
				}

				if (i%250 == 0) {
					struct Navdata::AHRS::EulerAngles eangles  = Navdata::AHRS::getEulerAngles() ;
					printf("\r%8f %8f %8f", eangles.phi * 180.0 / M_PI, eangles.rho * 180.0 / M_PI, eangles.tetha * 180.0 / M_PI) ;
					fflush(stdout) ;
				}

				gettimeofday(&end, NULL) ;
				udt = ((float)(end.tv_sec - start.tv_sec)) * 1e6 + (end.tv_usec - start.tv_usec) ;

				if (udt < 2000) {
					usleep(2000 - udt) ;
				}

				i++ ;

        }
        
        return 0 ;

}
