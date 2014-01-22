#include "../include/paparazzi/Navdata.h"

#include <iostream>
#include <algorithm>
#include <unistd.h>

const int NB_SAMPLES = 10000 ;

int main (int argc, char *argv[]) {

    struct {
        int16_t x, y, z ;
    } samples[NB_SAMPLES] = {0} ;

    if (!Navdata::init ()) {
        std::cerr << "Error initializing navdata." << std::endl ;
        return 1 ;
    }

    for (int i = 0 ; i < NB_SAMPLES ; ++i) {
		Navdata::update () ;
        samples[i].x = Navdata::IMU::Gyroscope::getRawX () ;
		samples[i].y = Navdata::IMU::Gyroscope::getRawY () ;
		samples[i].z = Navdata::IMU::Gyroscope::getRawZ () ;
        usleep (2000) ;
    }

    int32_t offX = 0, offY = 0, offZ = 0 ;

    for (int i = 0; i < NB_SAMPLES ; ++i) {
        offX += samples[i].x ;
        offY += samples[i].y ;
        offZ += samples[i].z ;
    }

    offX /= NB_SAMPLES ;
    offY /= NB_SAMPLES ;
    offZ /= NB_SAMPLES ;

    struct {
        struct {
            int16_t min ;
            int16_t max ;
            int32_t avg ;
        } x, y, z ;
    } noises ;

	noises.x.min = noises.y.min = noises.z.min = 32735 ;
	noises.x.max = noises.y.max = noises.z.max = 0 ;
	noises.x.avg = noises.y.avg = noises.z.avg = 0 ;

    for (int i = 0; i < NB_SAMPLES; i++) {

        int16_t noiseX = (int16_t) (samples[i].x - offX) ;
        int16_t absNoiseX = (int16_t) abs (noiseX) ;
        noises.x.min = std::min (noises.x.min, absNoiseX) ;
        noises.x.max = std::max (noises.x.max, absNoiseX) ;
        noises.x.avg += noiseX ;

        int16_t noiseY = (int16_t) (samples[i].y - offY) ;
        int16_t absNoiseY = (int16_t) abs (noiseY) ;
        noises.y.min = std::min (noises.y.min, absNoiseY) ;
        noises.y.max = std::max (noises.y.max, absNoiseY) ;
        noises.y.avg += noiseY ;

        int16_t noiseZ = (int16_t) (samples[i].z - offZ) ;
        int16_t absNoiseZ = (int16_t) abs (noiseZ) ;
        noises.z.min = std::min (noises.z.min, absNoiseZ) ;
        noises.z.max = std::max (noises.z.max, absNoiseZ) ;
        noises.z.avg += noiseZ ;
    }

    noises.z.avg /= NB_SAMPLES ;
    noises.x.avg /= NB_SAMPLES ;
    noises.y.avg /= NB_SAMPLES ;

	std::cout << "Offsets: " << offX << " " << offY << " " << offZ << std::endl ;

	std::cout << "Noises: " << std::endl ;
	std::cout << "  Min: " << noises.x.min << " " << noises.y.min << " " << noises.z.min << std::endl ;
	std::cout << "  Max: " << noises.x.max << " " << noises.y.max << " " << noises.z.max << std::endl ;
	std::cout << "  Avg: " << noises.x.avg << " " << noises.y.avg << " " << noises.z.avg << std::endl ;

    return 0 ;

}