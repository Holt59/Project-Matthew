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

            float getX () ;
            float getY () ;
            float getZ () ;

        }

        namespace Accelerometer {

            float getX () ;
            float getY () ;
            float getZ () ;

        }

        namespace Magnetometer {

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

        void setKp (float kp) ;
        void setKi (float ki) ;

        void update () ;

        struct EulerAngles getEulerAngles () ;
        
    }

}

#endif