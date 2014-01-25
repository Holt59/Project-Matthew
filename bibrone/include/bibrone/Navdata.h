#ifndef _NAVDATA_H
#define _NAVDATA_H

#include <stdint.h>

namespace Navdata {

    bool init () ;

    bool update () ;

    int16_t height () ;

    void stop () ;

    namespace Barometer {

        bool isBaroAvailable () ;

        int32_t getTemperature () ;

        int32_t getPressure () ;

    }

    namespace IMU {

		bool isIMUAvailable () ;

        void update () ;

        namespace Gyroscope {
        
            int16_t getRawX () ;
            int16_t getRawY () ;
            int16_t getRawZ () ;

            float getX () ;
            float getY () ;
            float getZ () ;

        }

        namespace Accelerometer {
        
            int16_t getRawX () ;
            int16_t getRawY () ;
            int16_t getRawZ () ;

            float getX () ;
            float getY () ;
            float getZ () ;

        }

        namespace Magnetometer {
        
            int16_t getRawX () ;
            int16_t getRawY () ;
            int16_t getRawZ () ;

            float getX () ;
            float getY () ;
            float getZ () ;

        }

    }

    namespace AHRS {

        struct EulerAngles {

            float phi, rho, tetha ;

        };

        /* Set the sample period in us. */
        void setSamplePeriod (uint32_t dt) ;

        void setKp (float) ;
        void setKis (float, float, float) ;

		void update () ;
        void updateWithMag () ;

        struct EulerAngles getEulerAngles () ;
        
    }

}

#endif