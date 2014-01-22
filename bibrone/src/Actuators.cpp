#include "Actuators.h"

#include <stdio.h>   /* Standard input/output definitions */
#include <string.h>  /* String function definitions */
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */
#include <stdint.h>

#include "GPIO.h"

namespace Actuators {

    int fd ;
	bool isInitialized = false ;

    uint16_t PWMs[4] = {0, 0, 0, 0} ;

    int sendCmd (uint8_t cmd, uint8_t *reply, int replyLen) {
        write (fd, &cmd, 1) ;
        return read (fd, reply, replyLen) ;
    }

    bool init () {

		if (isInitialized) {
			return true ;
		}

        if (!GPIO::init ()) {
			return false ;
		}

        fd = open ("/dev/ttyO0", O_RDWR | O_NOCTTY | O_NDELAY) ;

        if (fd < 0) {
            return false ;
        }

        int flags = fcntl(fd, F_GETFL, 0) ;
	    fcntl(fd, F_SETFL, flags | O_NONBLOCK); //read calls are non blocking

        //set port options
        struct termios options;
        //Get the current options for the port
        tcgetattr (fd, &options);
        //Set the baud rates to 115200
        cfsetispeed (&options, B115200);
        cfsetospeed (&options, B115200);

        options.c_cflag |= (CLOCAL | CREAD); //Enable the receiver and set local mode
        options.c_iflag = 0; //clear input options
        options.c_lflag = 0; //clear local options
        options.c_oflag &= ~OPOST; //clear output options (raw output)

        //Set the new options for the port
        tcsetattr (fd, TCSANOW, &options);

        GPIO::setupInput (GPIO::Pin::IRQ::Input) ;

		GPIO::setupOutput (GPIO::Pin::IRQ::FlipFlop) ;
		GPIO::clear (GPIO::Pin::IRQ::FlipFlop) ;
		usleep (1000) ;
		GPIO::set (GPIO::Pin::IRQ::FlipFlop) ;
		
        GPIO::setupOutput (GPIO::Pin::Motor::Motor1);
        GPIO::setupOutput (GPIO::Pin::Motor::Motor2);
        GPIO::setupOutput (GPIO::Pin::Motor::Motor3);
        GPIO::setupOutput (GPIO::Pin::Motor::Motor4);
        GPIO::set (GPIO::Pin::Motor::Motor1) ;
        GPIO::set (GPIO::Pin::Motor::Motor2) ;
        GPIO::set (GPIO::Pin::Motor::Motor3) ;
        GPIO::set (GPIO::Pin::Motor::Motor4) ;

        //configure motors
        uint8_t reply[256];
        int m;
        for (m = 0; m < 4; m++) {
            GPIO::clear (GPIO::Pin::Motor::Motor1 + m);
            sendCmd (0xe0, reply, 2);
            if (reply[0] != 0xe0 || reply[1] != 0x00) {
                printf ("motor%d cmd=0x%02x reply=0x%02x\n", m + 1, (int) reply[0], (int) reply[1]);
            }
            sendCmd (m + 1, reply, 1);
            GPIO::set (GPIO::Pin::Motor::Motor1 + m);
        }

        //all select lines active
        GPIO::clear (GPIO::Pin::Motor::Motor1) ;
        GPIO::clear (GPIO::Pin::Motor::Motor2) ;
        GPIO::clear (GPIO::Pin::Motor::Motor3) ;
        GPIO::clear (GPIO::Pin::Motor::Motor4) ;

        //start multicast
		
        sendCmd (0xa0, reply, 1);
        sendCmd (0xa0, reply, 1);
        sendCmd (0xa0, reply, 1);
        sendCmd (0xa0, reply, 1);
        sendCmd (0xa0, reply, 1); 

        //reset IRQ flipflop - on error 176 reads 1, this code resets 176 to 0
        GPIO::clear (GPIO::Pin::IRQ::FlipFlop) ;
        GPIO::set (GPIO::Pin::IRQ::FlipFlop);

		Actuators::Led::set(Actuators::Led::GREEN, Actuators::Led::GREEN, 
							Actuators::Led::GREEN, Actuators::Led::GREEN) ;

		isInitialized = true ;
		return true ;

    }

    bool setPWM (uint8_t motor, uint16_t pwm) {
        if (motor < 4) {
            PWMs[motor] = pwm ;
        }
        return commit();
    }

    bool commit() {
        return setPWM (PWMs[0], PWMs[1], PWMs[2], PWMs[3]) ;
    }

    bool setPWM (uint16_t pwm0, uint16_t pwm1, uint16_t pwm2, uint16_t pwm3) {
        uint8_t cmd[5];
        PWMs[0] = pwm0 ; PWMs[1] = pwm1 ; PWMs[2] = pwm2 ; PWMs[3] = pwm3 ;
        cmd[0] = 0x20 | ((pwm0 & 0x1ff) >> 4);
        cmd[1] = ((pwm0 & 0x1ff) << 4) | ((pwm1 & 0x1ff) >> 5);
        cmd[2] = ((pwm1 & 0x1ff) << 3) | ((pwm2 & 0x1ff) >> 6);
        cmd[3] = ((pwm2 & 0x1ff) << 2) | ((pwm3 & 0x1ff) >> 7);
        cmd[4] = ((pwm3 & 0x1ff) << 1);
        return write (fd, cmd, 5) == 5;
    }

    void stop () {

		isInitialized = false ;
        close (fd) ;

    }

    namespace Led {

        uint8_t LEDs[4] = {OFF, OFF, OFF, OFF} ;

        bool set (uint8_t led, uint8_t value) {
            if (led < 4) {
                LEDs[led] = value ;
            }
            return Led::set (LEDs[0], LEDs[1], LEDs[2], LEDs[3]) ;
        }

        bool set (uint8_t led0, uint8_t led1, uint8_t led2, uint8_t led3) {
            uint8_t cmd[2];
            
            LEDs[0] = led0 ; LEDs[1] = led1 ; LEDs[2] = led2 ; LEDs[3] = led3 ;

            led0 &= 0x03;
            led1 &= 0x03;
            led2 &= 0x03;
            led3 &= 0x03;

            cmd[0] = 0x60 | ((led0 & 1) << 4) | ((led1 & 1) << 3) | ((led2 & 1) << 2) | ((led3 & 1) << 1);
            cmd[1] = ((led0 & 2) << 3) | ((led1 & 2) << 2) | ((led2 & 2) << 1) | ((led3 & 2) << 0);

            return write (Actuators::fd, cmd, 2) == 2;
        }

    }

}
