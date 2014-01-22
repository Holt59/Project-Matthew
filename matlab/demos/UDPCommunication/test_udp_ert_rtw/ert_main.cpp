/*
 * File: ert_main.cpp
 *
 * Code generated for Simulink model 'test_udp'.
 *
 * Model version                  : 1.52
 * Simulink Coder version         : 8.4 (R2013a) 13-Feb-2013
 * TLC version                    : 8.4 (Jan 18 2013)
 * C/C++ source code generated on : Wed Jan 22 22:55:51 2014
 *
 * Target selection: ardrone.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "test_udp.h"
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
#define ACTUATORS_PERIOD               (0.01)
#define SENSORS_PERIOD                 (0.001)
#define AHRS_PERIOD                    (0.004)

void step_handler(uint8_t timerID)
{
  test_udp_step();

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

void ahrs_handler(uint8_t timerID)
{
  static int compteur = 0;
  if (compteur == 0) {
    Navdata::AHRS::setSamplePeriod(4000) ;
    Navdata::AHRS::setKp(5.0);
    Navdata::AHRS::setKis(0.1, 0.1, 0.1);
  }

  if (compteur <= 1000) {
    compteur++;
  } else {
    Navdata::AHRS::setKp(0.5);
  }

  Navdata::AHRS::update();
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
  test_udp_initialize();

  /* Initialize the timers */
  tid_t step_tid = systime->registerTimer (STEP_SIZE, step_handler) ;
  tid_t sensors_tid = systime->registerTimer (SENSORS_PERIOD, sensors_handler);
  tid_t actuators_tid = systime->registerTimer (ACTUATORS_PERIOD,
    actuators_handler) ;
  tid_t ahrs_tid = systime->registerTimer (AHRS_PERIOD, ahrs_handler);

  /* Associate rt_OneStep() with a timer that executes at the base rate of the model */
  while (1) {
    usleep(100);
  }

  test_udp_terminate();
  return 0;
}

/* File trailer for generated code.
 *
 * [EOF]
 */
