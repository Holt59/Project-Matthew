#ifndef _MOTOR_H
#define _MOTOR_H

#include <stdint.h>

#ifndef MATLAB_MEX_FILE

#include <bibrone/Actuators.h>

#endif

void Motor_Initialization();

void Motor_Set (float pwm, uint8_t motor);

#endif
