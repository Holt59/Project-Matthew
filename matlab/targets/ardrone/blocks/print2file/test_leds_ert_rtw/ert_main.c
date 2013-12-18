/*
 * File: ert_main.c
 *
 * Code generated for Simulink model 'test_leds'.
 *
 * Model version                  : 1.21
 * Simulink Coder version         : 8.4 (R2013a) 13-Feb-2013
 * TLC version                    : 8.4 (Jan 18 2013)
 * C/C++ source code generated on : Mon Dec 16 17:21:48 2013
 *
 * Target selection: ardrone.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "test_leds.h"
#include <paparazzi/sys_time.h>        /* Timers PAPARAZZI */
#include <sys/time.h>

void __cxa_pure_virtual(void)
{
}

#define STEP_SIZE                      (0.1)
#define STOP_TIME                      (5.0)

tid_t main_periodic_tid;
tid_t main_tid;
unsigned long getTimePeriod ()
{
  static double last = 0.0 ;
  double current = 0.0 ;
  struct timeval tim ;
  unsigned long diff ;
  gettimeofday(&tim, NULL) ;
  current = (double)tim.tv_usec ;
  diff = current - last ;
  last = current ;
  return diff ;
}

int_T main(int_T argc, const char *argv[])
{
  /* Unused arguments */
  (void)(argc);
  (void)(argv);

  /* Initialize model */
  test_leds_initialize();

  /*Initialize periodic timer */
  main_periodic_tid = sys_time_register_timer(STEP_SIZE,NULL);
  main_tid = sys_time_register_timer(STOP_TIME,NULL);

  /* Associate rt_OneStep() with a timer that executes at the base rate of the model */
  while (!sys_time_check_and_ack_timer(main_tid)) {
    if (sys_time_check_and_ack_timer(main_periodic_tid)) {
      printf("PERIOD=%lu\n", getTimePeriod());
      test_leds_step();

      /* Get model outputs here */
    }
  }

  test_leds_terminate();
  return 0;
}

/* File trailer for generated code.
 *
 * [EOF]
 */
