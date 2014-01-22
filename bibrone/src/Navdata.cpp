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
#include <algorithm>
#include <stdio.h>

namespace Navdata {

    bool isInitialized = false ;

    const int NAVDATA_PACKET_SIZE = 60 ;
    const int NAVDATA_START_BYTE = 0x3a ;

    const int NAVDATA_BUFFER_SIZE = 60 ;

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
    
        if (isInitialized) {
            return true ;
        }

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
	    cfsetispeed(&options, 460800);
	    cfsetospeed(&options, 460800);

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
        
        isInitialized = true ;

        return true ;
    }

    void stop () {

        isInitialized = false ;
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

            /* D'après la doc du Invensense 3000 on a une "sensitivy" = 16.4 LSB/dps pour une FS de 2000 (d'après
            paparazzi, on a une FS de 2000, cf. je sais plus quel header... ). Si on a  16.4 LSB/dps, la valeur
            par laquelle il faut multiplier les données brutes c'est 1/16.4... Ce qui fait du 0.0609, ça me parait
            plus cohérent que le 4.359 ci-dessous. */
            const float Sensitivity[3] = {0.0609, 0.0609, 0.0609} ;
			const float Neutral[3] = {0.0, 0.0, 0.0} ;
			const int16_t Offset[3] = {-73, 14, -13} ;
			const int16_t Noises[3] = {35, 35, 15} ;
            
            int16_t getRawX () {
                return navdata.vx ;
            }
            
            int16_t getRawY () {
                return navdata.vy ;
            }
            
            int16_t getRawZ () {
                return navdata.vz ;
            }

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

            const float Sensitivity[3] = {0.001953125, 0.001953125, 0.001953125} ;
			const float Neutral[3] = {2048.0, 2048.0, 2048.0} ;
            
            int16_t getRawX () {
                return navdata.ax - Accelerometer::Neutral[0] ;
            }
            
            int16_t getRawY () {
                return (4096 - navdata.ay) - Accelerometer::Neutral[0] ;
            }
            
            int16_t getRawZ () {
                return (4096 - navdata.az) - Accelerometer::Neutral[0] ;
            }

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

			const float Sensitivity[3] = {0.0071492608, 0.0070882491, 0.0074057781} ;
			const float Neutral[3] = {118.0, -65.0, 110.0} ;

			const float Bias[3] = {0.253407, 13.703188, 235.300088} ;
			const float A[3][3] = {
				{0.0083769, 0.0001547, 0.0001820},
				{0.0001547, 0.0088271, 0.0000548},
				{0.0001820, 0.0000548, 0.0091108}
			} ;

			void update () {

				magnetometer[0] = - (float) navdata.mx ;
				magnetometer[1] =   (float) navdata.my ;
				magnetometer[2] = - (float) navdata.mz ;
		
				for (int i = 0 ; i < 3 ; ++i) {
					magnetometer[i] = (magnetometer[i] - Magnetometer::Neutral[i]) * Magnetometer::Sensitivity[i] ;
				}

				/*

				float magTmp[3] = {
					- navdata.vx - Bias[0],
					navdata.vy - Bias[1],
					- navdata.vz - Bias[2]
				};

				for (int i=0; i<3; i++) {
					magnetometer[i] = 0.0f ;
					for (int j=0; j<3; j++) {
						magnetometer[i] += A[i][j] * magTmp[j] ;
					}
				}
				
				magnetometer[0] = - magnetometer[0] ;
				magnetometer[2] = - magnetometer[2] ;

				*/
			
			}

            int16_t getRawX () {
                return navdata.mx ;
            }
            
            int16_t getRawY () {
                return navdata.my ;
            }
            
            int16_t getRawZ () {
                return navdata.mz ;
            }
            
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

			int16_t vRaws[3] = {
				Navdata::IMU::Gyroscope::getRawX (),
				Navdata::IMU::Gyroscope::getRawY (),
				Navdata::IMU::Gyroscope::getRawZ ()
			} ;

			for (int i = 0 ; i < 3 ; ++i) {
				gyroscope[i] = vRaws[i] * Gyroscope::Sensitivity[i] * M_PI / 180.0 ;
				/*
				int16_t vRaw = vRaws[i] - Gyroscope::Offset[i] ;
                if (abs(vRaw) > Gyroscope::Noises[i]) {
					gyroscope[i] = vRaw * Gyroscope::Sensitivity[i] * M_PI / 180.0 ;
				}*/
            }

            accelerometer[0] = (float) navdata.ax ;
            accelerometer[1] = 4096.0f - (float) navdata.ay ;
            accelerometer[2] = 4096.0f - (float) navdata.az ;

			Magnetometer::update() ;
			
            for (int i = 0 ; i < 3 ; ++i) {
                accelerometer[i] = (accelerometer[i] - Accelerometer::Neutral[i]) * Accelerometer::Sensitivity[i] ;
            }

        }

    }

    namespace AHRS {

		float quaternion[4] = {1.0f, 0.0f, 0.0f, 0.0f} ;
        float samplePeriod = 1.0f ;

        float intErrors[3] = {0.0f, 0.0f, 0.0f} ;

        float Kpx = 1.0f, Kpy = 1.0f, Kpz = 1.0f,
            Kix = 0.02f, Kiy = 0.02f, Kiz = 0.02f ;

        void setSamplePeriod (uint32_t dt) {
            samplePeriod = ((float) dt) / 1e6 ;
        }

        void setKps (float kpx, float kpy, float kpz) { Kpx = kpx ; Kpy = kpy ; Kpz = kpz ; }
        void setKi (float kix, float kiy, float kiz) { Kix = kix ; Kiy = kiy ; Kiz = kiz ; }

		float b_x = 1, b_z = 0; // reference direction of flux in earth frame

		void update () {

			float w_x = IMU::gyroscope[0],
                w_y = IMU::gyroscope[1],
                w_z = IMU::gyroscope[2],
                a_x = IMU::accelerometer[0],
                a_y = IMU::accelerometer[1],
                a_z = IMU::accelerometer[2] ;

			// Local system variables
			float norm; // vector norm
			float SEqDot_omega_1, SEqDot_omega_2, SEqDot_omega_3, SEqDot_omega_4; // quaternion derrivative from gyroscopes elements
			float f_1, f_2, f_3; // objective function elements
			float J_11or24, J_12or23, J_13or22, J_14or21, J_32, J_33; // objective function Jacobian elements
			float SEqHatDot_1, SEqHatDot_2, SEqHatDot_3, SEqHatDot_4; // estimated direction of the gyroscope error
			// Axulirary variables to avoid reapeated calcualtions
			float halfSEq_1 = 0.5f * quaternion[0] ;
			float halfSEq_2 = 0.5f * quaternion[1] ;
			float halfSEq_3 = 0.5f * quaternion[2] ;
			float halfSEq_4 = 0.5f * quaternion[3] ;
			float twoSEq_1 = 2.0f * quaternion[0] ;
			float twoSEq_2 = 2.0f * quaternion[1] ;
			float twoSEq_3 = 2.0f * quaternion[2] ;

			// Normalise the accelerometer measurement
			norm = sqrt(a_x * a_x + a_y * a_y + a_z * a_z);
			a_x /= norm;
			a_y /= norm;
			a_z /= norm;
			// Compute the objective function and Jacobian
			f_1 = twoSEq_2 * quaternion[3] - twoSEq_1 * quaternion[2] - a_x;
			f_2 = twoSEq_1 * quaternion[1] + twoSEq_3 * quaternion[3] - a_y;
			f_3 = 1.0f - twoSEq_2 * quaternion[1] - twoSEq_3 * quaternion[2] - a_z;
			J_11or24 = twoSEq_3; // J_11 negated in matrix multiplication
			J_12or23 = 2.0f * quaternion[3];
			J_13or22 = twoSEq_1; // J_12 negated in matrix multiplication
			J_14or21 = twoSEq_2;
			J_32 = 2.0f * J_14or21; // negated in matrix multiplication
			J_33 = 2.0f * J_11or24; // negated in matrix multiplication
			// Compute the gradient (matrix multiplication)
			SEqHatDot_1 = J_14or21 * f_2 - J_11or24 * f_1;
			SEqHatDot_2 = J_12or23 * f_1 + J_13or22 * f_2 - J_32 * f_3;
			SEqHatDot_3 = J_12or23 * f_2 - J_33 * f_3 - J_13or22 * f_1;
			SEqHatDot_4 = J_14or21 * f_1 + J_11or24 * f_2;
			// Normalise the gradient
			norm = sqrt(SEqHatDot_1 * SEqHatDot_1 + SEqHatDot_2 * SEqHatDot_2 + SEqHatDot_3 * SEqHatDot_3 + SEqHatDot_4 * SEqHatDot_4);
			SEqHatDot_1 /= norm;
			SEqHatDot_2 /= norm;
			SEqHatDot_3 /= norm;
			SEqHatDot_4 /= norm;
			// Compute the quaternion derrivative measured by gyroscopes
			SEqDot_omega_1 = -halfSEq_2 * Kpx *  w_x - halfSEq_3 * Kpy * w_y - halfSEq_4 * Kpz * w_z;
			SEqDot_omega_2 = halfSEq_1 * Kpx * w_x + halfSEq_3 * Kpz * w_z - halfSEq_4 * Kpy * w_y;
			SEqDot_omega_3 = halfSEq_1 * Kpy * w_y - halfSEq_2 * Kpz * w_z + halfSEq_4 * Kpx * w_x;
			SEqDot_omega_4 = halfSEq_1 * Kpz * w_z + halfSEq_2 * Kpy * w_y - halfSEq_3 * Kpx * w_x;
			// Compute then integrate the estimated quaternion derrivative
			quaternion[0] += (SEqDot_omega_1 - SEqHatDot_1) * samplePeriod;
			quaternion[1] += (SEqDot_omega_2 - SEqHatDot_2) * samplePeriod;
			quaternion[2] += (SEqDot_omega_3 - SEqHatDot_3) * samplePeriod;
			quaternion[3] += (SEqDot_omega_4 - SEqHatDot_4) * samplePeriod;
			// Normalise quaternion
			norm = sqrt(quaternion[0] * quaternion[0] + quaternion[1] * quaternion[1] + quaternion[2] * quaternion[2] + quaternion[3] * quaternion[3]);
			quaternion[0] /= norm;
			quaternion[1] /= norm;
			quaternion[2] /= norm;
			quaternion[3] /= norm;

		}

        void updateWithMag () {

			float gx = IMU::gyroscope[0],
                gy = IMU::gyroscope[1],
                gz = IMU::gyroscope[2],
                ax = IMU::accelerometer[0],
                ay = IMU::accelerometer[1],
                az = IMU::accelerometer[2],
                mx = IMU::magnetometer[0],
                my = IMU::magnetometer[1],
                mz = IMU::magnetometer[2] ;

			float norm; // vector norm
			float SEqDot_omega_1, SEqDot_omega_2, SEqDot_omega_3, SEqDot_omega_4; // quaternion rate from gyroscopes elements
			float f_1, f_2, f_3, f_4, f_5, f_6; // objective function elements
			float J_11or24, J_12or23, J_13or22, J_14or21, J_32, J_33, // objective function Jacobian elements
			J_41, J_42, J_43, J_44, J_51, J_52, J_53, J_54, J_61, J_62, J_63, J_64; //
			float SEqHatDot_1, SEqHatDot_2, SEqHatDot_3, SEqHatDot_4; // estimated direction of the gyroscope error
			float w_err_x, w_err_y, w_err_z; // estimated direction of the gyroscope error (angular)
			float h_x, h_y, h_z; // computed flux in the earth frame
			// axulirary variables to avoid reapeated calcualtions
			float halfSEq_1 = 0.5f * quaternion[0];
			float halfSEq_2 = 0.5f * quaternion[1];
			float halfSEq_3 = 0.5f * quaternion[2];
			float halfSEq_4 = 0.5f * quaternion[3];
			float twoSEq_1 = 2.0f * quaternion[0];
			float twoSEq_2 = 2.0f * quaternion[1];
			float twoSEq_3 = 2.0f * quaternion[2];
			float twoSEq_4 = 2.0f * quaternion[3];
			float twob_x = 2.0f * b_x;
			float twob_z = 2.0f * b_z;
			float twob_xSEq_1 = 2.0f * b_x * quaternion[0];
			float twob_xSEq_2 = 2.0f * b_x * quaternion[1];
			float twob_xSEq_3 = 2.0f * b_x * quaternion[2];
			float twob_xSEq_4 = 2.0f * b_x * quaternion[3];
			float twob_zSEq_1 = 2.0f * b_z * quaternion[0];
			float twob_zSEq_2 = 2.0f * b_z * quaternion[1];
			float twob_zSEq_3 = 2.0f * b_z * quaternion[2];
			float twob_zSEq_4 = 2.0f * b_z * quaternion[3];
			float SEq_1SEq_2;
			float SEq_1SEq_3 = quaternion[0] * quaternion[2];
			float SEq_1SEq_4;
			float SEq_2SEq_3;
			float SEq_2SEq_4 = quaternion[1] * quaternion[3];
			float SEq_3SEq_4;
			float twom_x = 2.0f * mx;
			float twom_y = 2.0f * my;
			float twom_z = 2.0f * mz;
			// normalise the accelerometer measurement
			norm = sqrt(ax * ax + ay * ay + az * az);
			ax /= norm;
			ay /= norm;
			az /= norm;
			// normalise the magnetometer measurement
			norm = sqrt(mx * mx + my * my + mz * mz);
			mx /= norm;
			my /= norm;
			mz /= norm;
			// compute the objective function and Jacobian
			f_1 = twoSEq_2 * quaternion[3] - twoSEq_1 * quaternion[2] -ax;
			f_2 = twoSEq_1 * quaternion[1] + twoSEq_3 * quaternion[3] - ay;
			f_3 = 1.0f - twoSEq_2 * quaternion[1] - twoSEq_3 * quaternion[2] - az;
			f_4 = twob_x * (0.5f - quaternion[2] * quaternion[2] - quaternion[3] * quaternion[3]) + twob_z * (SEq_2SEq_4 - SEq_1SEq_3) - mx;
			f_5 = twob_x * (quaternion[1] * quaternion[2] - quaternion[0] * quaternion[3]) + twob_z * (quaternion[0] * quaternion[1] + quaternion[2] * quaternion[3]) - my;
			f_6 = twob_x * (SEq_1SEq_3 + SEq_2SEq_4) + twob_z * (0.5f - quaternion[1] * quaternion[1] - quaternion[2] * quaternion[2]) - mz;
			J_11or24 = twoSEq_3; // J_11 negated in matrix multiplication
			J_12or23 = 2.0f * quaternion[3];
			J_13or22 = twoSEq_1; // J_12 negated in matrix multiplication
			J_14or21 = twoSEq_2;
			J_32 = 2.0f * J_14or21; // negated in matrix multiplication
			J_33 = 2.0f * J_11or24; // negated in matrix multiplication
			J_41 = twob_zSEq_3; // negated in matrix multiplication
			J_42 = twob_zSEq_4;
			J_43 = 2.0f * twob_xSEq_3 + twob_zSEq_1; // negated in matrix multiplication
			J_44 = 2.0f * twob_xSEq_4 - twob_zSEq_2; // negated in matrix multiplication
			J_51 = twob_xSEq_4 - twob_zSEq_2; // negated in matrix multiplication
			J_52 = twob_xSEq_3 + twob_zSEq_1;
			J_53 = twob_xSEq_2 + twob_zSEq_4;
			J_54 = twob_xSEq_1 - twob_zSEq_3; // negated in matrix multiplication
			J_61 = twob_xSEq_3;
			J_62 = twob_xSEq_4 - 2.0f * twob_zSEq_2;
			J_63 = twob_xSEq_1 - 2.0f * twob_zSEq_3;
			J_64 = twob_xSEq_2;
			// compute the gradient (matrix multiplication)
			SEqHatDot_1 = J_14or21 * f_2 - J_11or24 * f_1 - J_41 * f_4 - J_51 * f_5 + J_61 * f_6;
			SEqHatDot_2 = J_12or23 * f_1 + J_13or22 * f_2 - J_32 * f_3 + J_42 * f_4 + J_52 * f_5 + J_62 * f_6;
			SEqHatDot_3 = J_12or23 * f_2 - J_33 * f_3 - J_13or22 * f_1 - J_43 * f_4 + J_53 * f_5 + J_63 * f_6;
			SEqHatDot_4 = J_14or21 * f_1 + J_11or24 * f_2 - J_44 * f_4 - J_54 * f_5 + J_64 * f_6;
			// normalise the gradient to estimate direction of the gyroscope error
			norm = sqrt(SEqHatDot_1 * SEqHatDot_1 + SEqHatDot_2 * SEqHatDot_2 + SEqHatDot_3 * SEqHatDot_3 + SEqHatDot_4 * SEqHatDot_4);
			SEqHatDot_1 = SEqHatDot_1 / norm;
			SEqHatDot_2 = SEqHatDot_2 / norm;

			SEqHatDot_3 = SEqHatDot_3 / norm;
			SEqHatDot_4 = SEqHatDot_4 / norm;
			// compute angular estimated direction of the gyroscope error
			w_err_x = twoSEq_1 * SEqHatDot_2 - twoSEq_2 * SEqHatDot_1 - twoSEq_3 * SEqHatDot_4 + twoSEq_4 * SEqHatDot_3;
			w_err_y = twoSEq_1 * SEqHatDot_3 + twoSEq_2 * SEqHatDot_4 - twoSEq_3 * SEqHatDot_1 - twoSEq_4 * SEqHatDot_2;
			w_err_z = twoSEq_1 * SEqHatDot_4 - twoSEq_2 * SEqHatDot_3 + twoSEq_3 * SEqHatDot_2 - twoSEq_4 * SEqHatDot_1;
			// compute and remove the gyroscope baises
			intErrors[0] += w_err_x * samplePeriod * Kix;
			intErrors[1] += w_err_y * samplePeriod * Kiy;
			intErrors[2] += w_err_z * samplePeriod * Kiz;
			gx -= intErrors[0];
			gy -= intErrors[1];
			gz -= intErrors[2];
			// compute the quaternion rate measured by gyroscopes
			SEqDot_omega_1 = -halfSEq_2 * Kpx * gx - halfSEq_3 * Kpy * gy - halfSEq_4 * Kpz * gz;
			SEqDot_omega_2 = halfSEq_1 * Kpx * gx + halfSEq_3 * Kpz * gz - halfSEq_4 * Kpy * gy;
			SEqDot_omega_3 = halfSEq_1 * Kpy * gy - halfSEq_2 * Kpz * gz + halfSEq_4 * Kpx * gx;
			SEqDot_omega_4 = halfSEq_1 * Kpz * gz + halfSEq_2 * Kpy * gy - halfSEq_3 * Kpx * gx;
			// compute then integrate the estimated quaternion rate
			quaternion[0] += (SEqDot_omega_1 - SEqHatDot_1) * samplePeriod;
			quaternion[1] += (SEqDot_omega_2 - SEqHatDot_2) * samplePeriod;
			quaternion[2] += (SEqDot_omega_3 - SEqHatDot_3) * samplePeriod;
			quaternion[3] += (SEqDot_omega_4 - SEqHatDot_4) * samplePeriod;
			// normalise quaternion
			norm = sqrt(quaternion[0] * quaternion[0] + quaternion[1] * quaternion[1] + quaternion[2] * quaternion[2] + quaternion[3] * quaternion[3]);
			quaternion[0] /= norm;
			quaternion[1] /= norm;
			quaternion[2] /= norm;
			quaternion[3] /= norm;
			// compute flux in the earth frame
			SEq_1SEq_2 = quaternion[0] * quaternion[1]; // recompute axulirary variables
			SEq_1SEq_3 = quaternion[0] * quaternion[2];
			SEq_1SEq_4 = quaternion[0] * quaternion[3];
			SEq_3SEq_4 = quaternion[2] * quaternion[3];
			SEq_2SEq_3 = quaternion[1] * quaternion[2];
			SEq_2SEq_4 = quaternion[1] * quaternion[3];
			h_x = twom_x * (0.5f - quaternion[2] * quaternion[2] - quaternion[3] * quaternion[3]) + twom_y * (SEq_2SEq_3 - SEq_1SEq_4) + twom_z * (SEq_2SEq_4 + SEq_1SEq_3);
			h_y = twom_x * (SEq_2SEq_3 + SEq_1SEq_4) + twom_y * (0.5f - quaternion[1] * quaternion[1] - quaternion[3] * quaternion[3]) + twom_z * (SEq_3SEq_4 - SEq_1SEq_2);
			h_z = twom_x * (SEq_2SEq_4 - SEq_1SEq_3) + twom_y * (SEq_3SEq_4 + SEq_1SEq_2) + twom_z * (0.5f - quaternion[1] * quaternion[1] - quaternion[2] * quaternion[2]);
			// normalise the flux vector to have only components in the x and z
			b_x = sqrt((h_x * h_x) + (h_y * h_y));
			b_z = h_z;

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