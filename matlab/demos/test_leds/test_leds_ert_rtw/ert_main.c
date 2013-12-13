/*
 * File: ert_main.c
 *
 * Code generated for Simulink model 'test_leds'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 8.4 (R2013a) 13-Feb-2013
 * TLC version                    : 8.4 (Jan 18 2013)
 * C/C++ source code generated on : Thu Dec 12 10:39:04 2013
 *
 * Target selection: ardrone.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "test_leds.h"
#include <sys/time.h>

void __cxa_pure_virtual(void)
{
}

#define STEP_SIZE_MICRO                ((unsigned long)(0.1*1000*1000))

int_T main(int_T argc, const char *argv[])
{
  /* Unused arguments */
  (void)(argc);
  (void)(argv);

  /* Initialize model */
  printf("INIT\n");
  test_leds_initialize();
  printf("INIT OK\n");

  /* Associate rt_OneStep() with a timer that executes at the base rate of the model */
  while (1) {
    test_leds_step();

    /* Get model outputs here */
    usleep(STEP_SIZE_MICRO);
  }

  test_leds_terminate();
  return 0;
}

/* File trailer for generated code.
 *
 * [EOF]
 */
