/*
 * File: ert_main.cpp
 *
 * Code generated for Simulink model 'MotorAndLed'.
 *
 * Model version                  : 1.19
 * Simulink Coder version         : 8.4 (R2013a) 13-Feb-2013
 * TLC version                    : 8.4 (Jan 18 2013)
 * C/C++ source code generated on : Thu Jan 16 15:52:04 2014
 *
 * Target selection: ardrone.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "MotorAndLed.h"
#include <paparazzi/SysTime.h>         // Timers PAPARAZZI
#include <paparazzi/Navdata.h>         // Données capteurs PAPARAZZI
#include <paparazzi/Actuators.h>       // LEDS Moteurs PAPARAZZI
#include <unistd.h>
#include <iostream>
#include <stdint.h>

void __cxa_pure_virtual(void)
{
}

#define STEP_SIZE                      (0.1)
#define STOP_TIME                      (30.0)
#define ACTUATORS_PERIOD               (0.01)
#define SENSORS_PERIOD                 (0.001)

void step_handler(uint8_t timerID)
{
  MotorAndLed_step();

  /* Get model outputs here */
}

void sensors_handler(uint8_t timerID)
{
  Navdata::update () ;
  Navdata::IMU::update () ;
}

void actuators_handler(uint8_t timerID)
{
  Actuators::commit();
}

int_T main(int_T argc, const char *argv[])
{
  /* Unused arguments */
  (void)(argc);
  (void)(argv);

  /*Initialize periodic timer */
  SysTime *systime = SysTime::getSysTime () ;

  /*Initialize sensors and actuators */
  if (!Actuators::init()) {
    std::cerr << "Error initializing actuators." << std::endl ;
    return 1 ;
  }

  if (!Navdata::init()) {
    std::cerr << "Error initializing sensors." << std::endl ;
    return 1 ;
  }

  /* Initialize model */
  MotorAndLed_initialize();

  /* Initialize the timers */
  tid_t main_tid = systime->registerTimer (STOP_TIME, 0);
  tid_t step_tid = systime->registerTimer (STEP_SIZE, step_handler) ;
  tid_t sensors_tid = systime->registerTimer (SENSORS_PERIOD, sensors_handler);
  tid_t actuators_tid = systime->registerTimer (ACTUATORS_PERIOD,
    actuators_handler) ;

  /* Associate rt_OneStep() with a timer that executes at the base rate of the model */
  while (!systime->checkAndAckTimer(main_tid)) {
    usleep(100);
  }

  MotorAndLed_terminate();
  return 0;
}

/* File trailer for generated code.
 *
 * [EOF]
 */
