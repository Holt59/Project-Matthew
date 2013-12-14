#include "Navdata.h"

#include <stdio.h>   /* Standard input/output definitions */
#include <string.h>  /* String function definitions */
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */
#include <stdint.h>
#include <math.h>

#include <iostream>
#include <stdio.h>

namespace Navdata {

    const int NAVDATA_PACKET_SIZE = 60 ;
    const int NAVDATA_START_BYTE = 0x3a ;

    const int NAVDATA_BUFFER_SIZE = 80 ;

    struct NavdataPort {
        bool isInitialized;
        uint16_t bytesRead;
        uint32_t totalBytesRead;
        uint32_t packetsRead;
        uint32_t checksum_errors;
        uint8_t buffer[NAVDATA_BUFFER_SIZE];
    };

    struct BaroCalibration {
        int16_t ac1;
        int16_t ac2;
        int16_t ac3;
        uint16_t ac4;
        uint16_t ac5;
        uint16_t ac6;
        int16_t b1;
        int16_t b2;
        int16_t mb;
        int16_t mc;
        int16_t md;

        // These values are calculated
        int32_t b5;
    } ;

    struct Measure {
        uint16_t taille;
        uint16_t nu_trame;

        uint16_t ax;
        uint16_t ay;
        uint16_t az;

        int16_t vx;
        int16_t vy;
        int16_t vz;
        uint16_t temperature_acc;
        uint16_t temperature_gyro;

        uint16_t ultrasound;

        uint16_t us_debut_echo;
        uint16_t us_fin_echo;
        uint16_t us_association_echo;
        uint16_t us_distance_echo;

        uint16_t us_curve_time;
        uint16_t us_curve_value;
        uint16_t us_curve_ref;

        uint16_t nb_echo;

        uint32_t sum_echo; //unsigned long
        int16_t gradient;

        uint16_t flag_echo_ini;

        int32_t pressure;
        uint16_t temperature_pressure;

        int16_t my;
        int16_t mx;
        int16_t mz;

        uint16_t chksum;

    } __attribute__ ((packed)) ;

    struct NavdataPort port ;
    struct Measure navdata ;
    struct BaroCalibration baroCalibration ;

    int fd ; // file descriptor

    /* Some global value. */

    bool baroCalibrated = false ;
    bool baroAvailable = false ;
    bool imuAvailable = false ;

    int16_t previousUltrasoundHeight ;

    bool acquireBaroCalibration () ;

    bool init () {

        fd = open ("/dev/ttyO1", O_RDWR | O_NOCTTY | O_NONBLOCK) ;

        if (fd < 0) {
            return false ;
        }

		int flags = fcntl(fd, F_GETFL, 0) ;
	    fcntl(fd, F_SETFL, flags | O_NONBLOCK); //read calls are non blocking
	    //set port options
	    struct termios options;
	    //Get the current options for the port
	    tcgetattr(fd, &options);
	    //Set the baud rates to 460800
	    cfsetispeed(&options, B460800);
	    cfsetospeed(&options, B460800);

	    options.c_cflag |= (CLOCAL | CREAD); //Enable the receiver and set local mode
	    options.c_iflag = 0; //clear input options
	    options.c_lflag = 0; //clear local options
	    options.c_oflag &= ~OPOST; //clear output options (raw output)

	    //Set the new options for the port
	    tcsetattr(fd, TCSANOW, &options);

        // stop acquisition
        uint8_t cmd = 0x02;
        write (fd, &cmd, 1);
		
        // read some potential dirt (retry alot of times)
        char tmp[100];
        for (int i = 0; i < 100; i++) {
            uint16_t dirt = read (fd, tmp, sizeof tmp);
            (void) dirt;

            cmd = 0x02;
            write (fd, &cmd, 1);
            usleep (200);
        }
		
        baroCalibrated = false ;
        if (!acquireBaroCalibration ())
            return false;

        // start acquisition
        cmd = 0x01;
        write (fd, &cmd, 1);

        imuAvailable = false ;
        baroAvailable = false ;

        previousUltrasoundHeight = 0;
        port.checksum_errors = 0;
        port.bytesRead = 0;
        port.totalBytesRead = 0;
        port.packetsRead = 0;
        port.isInitialized = true;

		/*

		std::cout << "AC6: " << baroCalibration.ac6 << std::endl ;
		std::cout << "AC5: " << baroCalibration.ac5  << std::endl ;
		std::cout << "MC: " << baroCalibration.md << std::endl ;
		std::cout << "MD: " << baroCalibration.mc << std::endl ;

		
		baroCalibration.ac6 = 23153;
		baroCalibration.ac5 = 32757;
		baroCalibration.mc = -8711;
		baroCalibration.md = 2868;
		*/

        return true ;
    }

    void stop () {

        close (fd) ;

    }

    bool acquireBaroCalibration () {
        // start baro calibration acquisition
        uint8_t cmd = 0x17; // send cmd 23
        write (fd, &cmd, 1);

		usleep(1000) ;

        uint8_t calibBuffer[22];

        if (read (fd, calibBuffer, sizeof calibBuffer) < 0) {
            perror ("acquire_baro_calibration: read failed");
            return false ;
        }

        baroCalibration.ac1 = calibBuffer[0] << 8 | calibBuffer[1];
        baroCalibration.ac2 = calibBuffer[2] << 8 | calibBuffer[3];
        baroCalibration.ac3 = calibBuffer[4] << 8 | calibBuffer[5];
        baroCalibration.ac4 = calibBuffer[6] << 8 | calibBuffer[7];
        baroCalibration.ac5 = calibBuffer[8] << 8 | calibBuffer[9];
        baroCalibration.ac6 = calibBuffer[10] << 8 | calibBuffer[11];
        baroCalibration.b1 = calibBuffer[12] << 8 | calibBuffer[13];
        baroCalibration.b2 = calibBuffer[14] << 8 | calibBuffer[15];
        baroCalibration.mb = calibBuffer[16] << 8 | calibBuffer[17];
        baroCalibration.mc = calibBuffer[18] << 8 | calibBuffer[19];
        baroCalibration.md = calibBuffer[20] << 8 | calibBuffer[21];

        baroCalibrated = true ;
        return true ;
    }

    void acquire () {
        int newbytes = read (fd, port.buffer + port.bytesRead, NAVDATA_BUFFER_SIZE - port.bytesRead);

        // because non-blocking read returns -1 when no bytes available
        if (newbytes > 0) {
            port.bytesRead += newbytes;
            port.totalBytesRead += newbytes;
        }
    }

    static void cropbuffer (int cropsize) {

        if (port.bytesRead - cropsize < 0) {
            // TODO think about why the amount of bytes read minus the cropsize gets below zero
            printf ("BytesRead(=%d) - Cropsize(=%d) may not be below zero. port->buffer=%p\n", port.bytesRead, cropsize, port.buffer);
            return;
        }

        memmove (port.buffer, port.buffer + cropsize, NAVDATA_BUFFER_SIZE - cropsize);
        port.bytesRead -= cropsize;
    }

    static void baroUpdateLogic (void) {

        static int32_t lastpressval = 0;
        static uint16_t lasttempval = 0;
        static bool temp_or_press_was_updated_last = 0; // 0 = press, so we now wait for temp, 1 = temp so we now wait for press

        static int sync_errors;

        if (temp_or_press_was_updated_last == 0)  // Last update was press so we are now waiting for temp
        {
            // temp was updated
            temp_or_press_was_updated_last = true ;

            // This means that press must remain constant
            if (lastpressval != 0) {
                // If pressure was updated: this is a sync error
                if (lastpressval != navdata.pressure) {
                    // wait for temp again
                    temp_or_press_was_updated_last = false ;
                    sync_errors++;
                    baroAvailable = true ;
                }
            }
        }
        else {
            // press was updated
            temp_or_press_was_updated_last = false ;

            // This means that temp must remain constant
            if (lasttempval != 0) {
                // If temp was updated: this is a sync error
                if (lasttempval != navdata.temperature_pressure) {
                    // wait for press again
                    temp_or_press_was_updated_last = true ;
                    sync_errors++;
                }
            }

            baroAvailable = true ;
        }

        lastpressval = navdata.pressure;
        lasttempval = navdata.temperature_pressure;
    }

    bool update () {

        static bool last_checksum_wrong = false ;
		bool checkSumOk = true ;

        // Start reading
        Navdata::acquire ();

        // while there is something interesting to do...
        while (port.bytesRead >= NAVDATA_PACKET_SIZE) {
            if (port.buffer[0] == NAVDATA_START_BYTE) {

                memcpy (&navdata, port.buffer, NAVDATA_PACKET_SIZE);

                // Calculating the checksum
                uint16_t checksum = 0;
                for (int i = 2; i < NAVDATA_PACKET_SIZE - 2; i += 2) {
                    checksum += port.buffer[i] + (port.buffer[i + 1] << 8);
                }

                // When checksum is incorrect
                if (navdata.chksum != checksum) {
                    printf ("Checksum error [calculated: %d] [packet: %d] [diff: %d]\n", checksum, navdata.chksum, checksum - navdata.chksum);
                    port.checksum_errors++;
					checkSumOk = false ;
                }

                // When we already dropped a packet or checksum is correct
                if (last_checksum_wrong || navdata.chksum == checksum) {
                    // Invert byte order so that TELEMETRY works better
                    uint8_t tmp;
                    uint8_t* p = (uint8_t*) &(navdata.pressure);
                    tmp = p[0];
                    p[0] = p[1];
                    p[1] = tmp;
                    p = (uint8_t*) &(navdata.temperature_pressure);
                    tmp = p[0];
                    p[0] = p[1];
                    p[1] = tmp;

                    baroUpdateLogic ();

                    imuAvailable = true ;
                    last_checksum_wrong = false ;
                    port.packetsRead++;
                }

                // Crop the buffer
                cropbuffer (NAVDATA_PACKET_SIZE);
            }
            else {
                // find start byte, copy all data from startbyte to buffer origin, update bytesread
                uint8_t * pint;
                pint = (uint8_t*) memchr (port.buffer, NAVDATA_START_BYTE, port.bytesRead);

                if (pint != NULL) {
                    cropbuffer (pint - port.buffer);
                }
                else {
                    // if the start byte was not found, it means there is junk in the buffer
                    port.bytesRead = 0;
                }
            }
        }

		return checkSumOk ;
    }

    int16_t height () {
        if (navdata.ultrasound > 10000) {
            return previousUltrasoundHeight;
        }
        int16_t ultrasoundHeight = 0;
        ultrasoundHeight = (navdata.ultrasound - 880) / 26.553;
        previousUltrasoundHeight = ultrasoundHeight;
        return ultrasoundHeight;
    }

    namespace Barometer {

        const int BMP180_OSS = 0 ;

        bool isBaroAvailable () {
            return baroAvailable ;
        }

        int32_t getPressure () {

            int32_t raw = navdata.pressure ;

            int32_t b6 = ((int32_t) baroCalibration.b5) - 4000L;
            int32_t x1 = (((int32_t) baroCalibration.b2) * (b6 * b6 >> 12)) >> 11;
            int32_t x2 = ((int32_t) baroCalibration.ac2) * b6 >> 11;
            int32_t x3 = x1 + x2;
            int32_t b3 = (((((int32_t) baroCalibration.ac1) * 4 + x3) << BMP180_OSS) + 2) / 4;
            x1 = ((int32_t) baroCalibration.ac3) * b6 >> 13;
            x2 = (((int32_t) baroCalibration.b1) * (b6 * b6 >> 12)) >> 16;
            x3 = ((x1 + x2) + 2) >> 2;
            uint32_t b4 = (((int32_t) baroCalibration.ac4) * (uint32_t) (x3 + 32768L)) >> 15;
            uint32_t b7 = (raw - b3) * (50000L >> BMP180_OSS);
            int32_t p = b7 < 0x80000000L ? (b7 * 2) / b4 : (b7 / b4) * 2;
            x1 = (p >> 8) * (p >> 8);
            x1 = (x1 * 3038UL) >> 16;
            x2 = (-7357L * p) >> 16;
            int32_t press = p + ((x1 + x2 + 3791L) >> 4);

            return press;
        }

        int32_t getTemperature () {

            int32_t tmp_raw = navdata.temperature_pressure ;

            int32_t x1 = ((tmp_raw - ((int32_t) baroCalibration.ac6)) * ((int32_t) baroCalibration.ac5)) >> 15;
            int32_t x2 = (((int32_t) baroCalibration.mc) << 11) / (x1 + ((int32_t) baroCalibration.md));
            baroCalibration.b5 = x1 + x2;

            return (baroCalibration.b5 + 8) >> 4;
        }

    }

    namespace IMU {

        float gyroscope[3] = {0.0, 0.0, 0.0}, 
            accelerometer[3] = {0.0, 0.0, 0.0},
            magnetometer[3] = {0.0, 0.0, 0.0} ;

		bool isIMUAvailable () {
			return Navdata::imuAvailable ;
		}

        namespace Gyroscope {

            const float Sensitivity[3] = {4.359, 4.359, 4.359} ;
			const float Neutral[3] = {0.0, 0.0, 0.0} ;

            float getX () {
                return gyroscope[0] ;
            }

            float getY () {
                return gyroscope[1] ;
            }

            float getZ () {
                return gyroscope[2] ;
            }

        }

        namespace Accelerometer {

            const float Sensitivity[3] = {19.5, 19.5, 19.5} ;
			const float Neutral[3] = {2048.0, 2048.0, 2048.0} ;

            float getX () {
                return accelerometer[0] ;
            }

            float getY () {
                return accelerometer[1] ;
            }

            float getZ () {
                return accelerometer[2] ;
            }

        }

        namespace Magnetometer {

            const float Sensitivity[3] = {14.64, 14.51, 15.16} ;
			const float Neutral[3] = {0.0, 0.0, 0.0} ;

            float getX () {
                return magnetometer[0] ;
            }

            float getY () {
                return magnetometer[1] ;
            }

            float getZ () {
                return magnetometer[2] ;
            }

        }

        void update () {

			// printf("\r %5d %5d %6d", navdata.ax, navdata.ay, navdata.az) ;

            gyroscope[0] = (float) navdata.vx ;
            gyroscope[1] = - (float) navdata.vy ;
            gyroscope[2] = - (float) navdata.vz ;

            accelerometer[0] = (float) navdata.ax ;
            accelerometer[1] = 4096.0f - (float) navdata.ay ;
            accelerometer[2] = 4096.0f - (float) navdata.az ;

            magnetometer[0] = - (float) navdata.mx ;
            magnetometer[1] = - (float) navdata.my ;
            magnetometer[2] = - (float) navdata.mz ;
			
            for (int i = 0 ; i < 3 ; ++i) {
                gyroscope[i] = (gyroscope[i] - Gyroscope::Neutral[i]) * Gyroscope::Sensitivity[i] * M_PI / 180.0 ;
                accelerometer[i] = (accelerometer[i] - Accelerometer::Neutral[i]) * Accelerometer::Sensitivity[i] ;
                magnetometer[i] = (magnetometer[i] - Magnetometer::Neutral[i]) * Magnetometer::Sensitivity[i] ;
            }

        }

    }

    namespace AHRS {

		float quaternion[4] = {1.0f, 0.0f, 0.0f, 0.0f} ;
        float samplePeriod = 1.0f ;

        float intErrors[3] = {0.0f, 0.0f, 0.0f} ;

        float Kp = 1.0f, Ki = 0.02f ;

        void setSamplePeriod (uint32_t dt) {
            samplePeriod = ((float) dt) / 1e6 ;
        }

        void setKp (float kp) { Kp = kp ; }
        void setKi (float ki) { Ki = ki ; }

        void update () {

            float q1 = quaternion[0], q2 = quaternion[1], q3 = quaternion[2], q4 = quaternion[3];   // short name local variable for readability
            float norm;
            float hx, hy, bx, bz;
            float vx, vy, vz, wx, wy, wz;
            float ex, ey, ez;
            float pa, pb, pc;

            float gx = IMU::gyroscope[0],
                gy = IMU::gyroscope[1],
                gz = IMU::gyroscope[2],
                ax = IMU::accelerometer[0],
                ay = IMU::accelerometer[1],
                az = IMU::accelerometer[2],
                mx = IMU::magnetometer[0],
                my = IMU::magnetometer[1],
                mz = IMU::magnetometer[2] ;

            // Auxiliary variables to avoid repeated arithmetic
            float q1q1 = q1 * q1;
            float q1q2 = q1 * q2;
            float q1q3 = q1 * q3;
            float q1q4 = q1 * q4;
            float q2q2 = q2 * q2;
            float q2q3 = q2 * q3;
            float q2q4 = q2 * q4;
            float q3q3 = q3 * q3;
            float q3q4 = q3 * q4;
            float q4q4 = q4 * q4;

            // Normalise accelerometer measurement
            norm = (float) sqrt (ax * ax + ay * ay + az * az);

			// std::cout << "TOP: " << std::endl ;
            if (norm == 0.0f) return; // handle NaN
            norm = 1.0f / norm;        // use reciprocal for division
            ax *= norm;
            ay *= norm;
            az *= norm;

            // Normalise magnetometer measurement
            norm = (float) sqrt (mx * mx + my * my + mz * mz);
            if (norm == 0.0f) return; // handle NaN
            norm = 1.0f / norm;        // use reciprocal for division
            mx *= norm;
            my *= norm;
            mz *= norm;

            // Reference direction of Earth's magnetic field
            hx = 2.0f * mx * (0.5f - q3q3 - q4q4) + 2.0f * my * (q2q3 - q1q4) + 2.0f * mz * (q2q4 + q1q3);
            hy = 2.0f * mx * (q2q3 + q1q4) + 2.0f * my * (0.5f - q2q2 - q4q4) + 2.0f * mz * (q3q4 - q1q2);
            bx = (float) sqrt ((hx * hx) + (hy * hy));
			// std::cout << "BX: " << (hx * hx) + (hy * hy) << std::endl ;
            bz = 2.0f * mx * (q2q4 - q1q3) + 2.0f * my * (q3q4 + q1q2) + 2.0f * mz * (0.5f - q2q2 - q3q3);

            // Estimated direction of gravity and magnetic field
            vx = 2.0f * (q2q4 - q1q3);
            vy = 2.0f * (q1q2 + q3q4);
            vz = q1q1 - q2q2 - q3q3 + q4q4;
            wx = 2.0f * bx * (0.5f - q3q3 - q4q4) + 2.0f * bz * (q2q4 - q1q3);
            wy = 2.0f * bx * (q2q3 - q1q4) + 2.0f * bz * (q1q2 + q3q4);
            wz = 2.0f * bx * (q1q3 + q2q4) + 2.0f * bz * (0.5f - q2q2 - q3q3);

            // Error is cross product between estimated direction and measured direction of gravity
            ex = (ay * vz - az * vy) + (my * wz - mz * wy);
            ey = (az * vx - ax * vz) + (mz * wx - mx * wz);
            ez = (ax * vy - ay * vx) + (mx * wy - my * wx);
            if (Ki > 0.0f) {
                intErrors[0] += ex;      // accumulate integral error
                intErrors[1] += ey;
                intErrors[2] += ez;
            }
            else {
                intErrors[0] = 0.0f;     // prevent integral wind up
                intErrors[1] = 0.0f;
                intErrors[2] = 0.0f;
            }

            // Apply feedback terms
            gx = gx + Kp * ex + Ki * intErrors[0];
            gy = gy + Kp * ey + Ki * intErrors[1];
            gz = gz + Kp * ez + Ki * intErrors[2];

            // Integrate rate of change of quaternion
            pa = q2;
            pb = q3;
            pc = q4;
            q1 = q1 + (-q2 * gx - q3 * gy - q4 * gz) * (0.5f * samplePeriod);
            q2 = pa + (q1 * gx + pb * gz - pc * gy) * (0.5f * samplePeriod);
            q3 = pb + (q1 * gy - pa * gz + pc * gx) * (0.5f * samplePeriod);
            q4 = pc + (q1 * gz + pa * gy - pb * gx) * (0.5f * samplePeriod);

			// std::cout << q1 << ", " << q2 << ", " << q3 << ", " << q4 << std::endl ;

            // Normalise quaternion
            norm = (float) sqrt (q1 * q1 + q2 * q2 + q3 * q3 + q4 * q4);
			// std::cout << norm << std::endl ;

            norm = 1.0f / norm;
            quaternion[0] = q1 * norm;
            quaternion[1] = q2 * norm;
            quaternion[2] = q3 * norm;
            quaternion[3] = q4 * norm;
        }

        struct EulerAngles getEulerAngles () {
			struct EulerAngles eangles ;
			eangles.phi = atan2(2 * quaternion[2] * quaternion[3] - 2 * quaternion[0] * quaternion[1], 
					2 * quaternion[0] * quaternion[0] + 2 * quaternion[3] * quaternion[3] - 1) ;
			eangles.tetha = -asin(2 * quaternion[1] * quaternion[3] + 2 * quaternion[0] * quaternion[2]) ;
			eangles.rho = atan2(2 * quaternion[1] * quaternion[2] - 2 * quaternion[0] * quaternion[3], 
					2 * quaternion[0] * quaternion[0] + 2 * quaternion[1] * quaternion[1] - 1);
			return eangles ;
        }

    }

}