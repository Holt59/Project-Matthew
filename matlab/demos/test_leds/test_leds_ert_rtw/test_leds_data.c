/*
 * File: test_leds_data.c
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
#include "test_leds_private.h"

/* Block parameters (auto storage) */
P_test_leds_T test_leds_P = {
  4000.0,                              /* Computed Parameter: PulseGenerator_Period
                                        * Referenced by: '<S6>/Pulse Generator'
                                        */
  1000.0,                              /* Computed Parameter: PulseGenerator_Duty
                                        * Referenced by: '<S6>/Pulse Generator'
                                        */
  0.0,                                 /* Expression: 0*periode
                                        * Referenced by: '<S6>/Pulse Generator'
                                        */
  4000.0,                              /* Computed Parameter: PulseGenerator1_Period
                                        * Referenced by: '<S6>/Pulse Generator1'
                                        */
  1000.0,                              /* Computed Parameter: PulseGenerator1_Duty
                                        * Referenced by: '<S6>/Pulse Generator1'
                                        */
  100.0,                               /* Expression: 1*periode
                                        * Referenced by: '<S6>/Pulse Generator1'
                                        */
  4000.0,                              /* Computed Parameter: PulseGenerator2_Period
                                        * Referenced by: '<S6>/Pulse Generator2'
                                        */
  1000.0,                              /* Computed Parameter: PulseGenerator2_Duty
                                        * Referenced by: '<S6>/Pulse Generator2'
                                        */
  300.0,                               /* Expression: 3*periode
                                        * Referenced by: '<S6>/Pulse Generator2'
                                        */
  4000.0,                              /* Computed Parameter: PulseGenerator3_Period
                                        * Referenced by: '<S6>/Pulse Generator3'
                                        */
  1000.0,                              /* Computed Parameter: PulseGenerator3_Duty
                                        * Referenced by: '<S6>/Pulse Generator3'
                                        */
  200.0,                               /* Expression: 2*periode
                                        * Referenced by: '<S6>/Pulse Generator3'
                                        */
  4000.0,                              /* Computed Parameter: PulseGenerator_Period_h
                                        * Referenced by: '<S7>/Pulse Generator'
                                        */
  1000.0,                              /* Computed Parameter: PulseGenerator_Duty_m
                                        * Referenced by: '<S7>/Pulse Generator'
                                        */
  0.0,                                 /* Expression: 0*periode
                                        * Referenced by: '<S7>/Pulse Generator'
                                        */
  4000.0,                              /* Computed Parameter: PulseGenerator1_Period_o
                                        * Referenced by: '<S7>/Pulse Generator1'
                                        */
  1000.0,                              /* Computed Parameter: PulseGenerator1_Duty_n
                                        * Referenced by: '<S7>/Pulse Generator1'
                                        */
  100.0,                               /* Expression: 1*periode
                                        * Referenced by: '<S7>/Pulse Generator1'
                                        */
  4000.0,                              /* Computed Parameter: PulseGenerator2_Period_o
                                        * Referenced by: '<S7>/Pulse Generator2'
                                        */
  1000.0,                              /* Computed Parameter: PulseGenerator2_Duty_c
                                        * Referenced by: '<S7>/Pulse Generator2'
                                        */
  300.0,                               /* Expression: 3*periode
                                        * Referenced by: '<S7>/Pulse Generator2'
                                        */
  4000.0,                              /* Computed Parameter: PulseGenerator3_Period_c
                                        * Referenced by: '<S7>/Pulse Generator3'
                                        */
  1000.0,                              /* Computed Parameter: PulseGenerator3_Duty_c
                                        * Referenced by: '<S7>/Pulse Generator3'
                                        */
  200.0,                               /* Expression: 2*periode
                                        * Referenced by: '<S7>/Pulse Generator3'
                                        */
  4000.0,                              /* Computed Parameter: PulseGenerator_Period_b
                                        * Referenced by: '<S8>/Pulse Generator'
                                        */
  1000.0,                              /* Computed Parameter: PulseGenerator_Duty_m4
                                        * Referenced by: '<S8>/Pulse Generator'
                                        */
  0.0,                                 /* Expression: 0*periode
                                        * Referenced by: '<S8>/Pulse Generator'
                                        */
  4000.0,                              /* Computed Parameter: PulseGenerator1_Period_l
                                        * Referenced by: '<S8>/Pulse Generator1'
                                        */
  1000.0,                              /* Computed Parameter: PulseGenerator1_Duty_c
                                        * Referenced by: '<S8>/Pulse Generator1'
                                        */
  100.0,                               /* Expression: 1*periode
                                        * Referenced by: '<S8>/Pulse Generator1'
                                        */
  4000.0,                              /* Computed Parameter: PulseGenerator2_Period_os
                                        * Referenced by: '<S8>/Pulse Generator2'
                                        */
  1000.0,                              /* Computed Parameter: PulseGenerator2_Duty_m
                                        * Referenced by: '<S8>/Pulse Generator2'
                                        */
  300.0,                               /* Expression: 3*periode
                                        * Referenced by: '<S8>/Pulse Generator2'
                                        */
  4000.0,                              /* Computed Parameter: PulseGenerator3_Period_p
                                        * Referenced by: '<S8>/Pulse Generator3'
                                        */
  1000.0,                              /* Computed Parameter: PulseGenerator3_Duty_j
                                        * Referenced by: '<S8>/Pulse Generator3'
                                        */
  200.0,                               /* Expression: 2*periode
                                        * Referenced by: '<S8>/Pulse Generator3'
                                        */
  4000.0,                              /* Computed Parameter: PulseGenerator_Period_bq
                                        * Referenced by: '<S9>/Pulse Generator'
                                        */
  1000.0,                              /* Computed Parameter: PulseGenerator_Duty_h
                                        * Referenced by: '<S9>/Pulse Generator'
                                        */
  0.0,                                 /* Expression: 0*periode
                                        * Referenced by: '<S9>/Pulse Generator'
                                        */
  4000.0,                              /* Computed Parameter: PulseGenerator1_Period_c
                                        * Referenced by: '<S9>/Pulse Generator1'
                                        */
  1000.0,                              /* Computed Parameter: PulseGenerator1_Duty_j
                                        * Referenced by: '<S9>/Pulse Generator1'
                                        */
  100.0,                               /* Expression: 1*periode
                                        * Referenced by: '<S9>/Pulse Generator1'
                                        */
  4000.0,                              /* Computed Parameter: PulseGenerator2_Period_p
                                        * Referenced by: '<S9>/Pulse Generator2'
                                        */
  1000.0,                              /* Computed Parameter: PulseGenerator2_Duty_j
                                        * Referenced by: '<S9>/Pulse Generator2'
                                        */
  300.0,                               /* Expression: 3*periode
                                        * Referenced by: '<S9>/Pulse Generator2'
                                        */
  4000.0,                              /* Computed Parameter: PulseGenerator3_Period_b
                                        * Referenced by: '<S9>/Pulse Generator3'
                                        */
  1000.0,                              /* Computed Parameter: PulseGenerator3_Duty_m
                                        * Referenced by: '<S9>/Pulse Generator3'
                                        */
  200.0,                               /* Expression: 2*periode
                                        * Referenced by: '<S9>/Pulse Generator3'
                                        */
  0,                                   /* Expression: amplitude0
                                        * Referenced by: '<S6>/Pulse Generator'
                                        */
  1,                                   /* Expression: amplitude1
                                        * Referenced by: '<S6>/Pulse Generator1'
                                        */
  3,                                   /* Expression: amplitude3
                                        * Referenced by: '<S6>/Pulse Generator2'
                                        */
  2,                                   /* Expression: amplitude2
                                        * Referenced by: '<S6>/Pulse Generator3'
                                        */
  1,                                   /* Expression: amplitude1
                                        * Referenced by: '<S7>/Pulse Generator'
                                        */
  2,                                   /* Expression: amplitude2
                                        * Referenced by: '<S7>/Pulse Generator1'
                                        */
  0,                                   /* Expression: amplitude0
                                        * Referenced by: '<S7>/Pulse Generator2'
                                        */
  3,                                   /* Expression: amplitude3
                                        * Referenced by: '<S7>/Pulse Generator3'
                                        */
  2,                                   /* Expression: amplitude2
                                        * Referenced by: '<S8>/Pulse Generator'
                                        */
  3,                                   /* Expression: amplitude3
                                        * Referenced by: '<S8>/Pulse Generator1'
                                        */
  1,                                   /* Expression: amplitude1
                                        * Referenced by: '<S8>/Pulse Generator2'
                                        */
  0,                                   /* Expression: amplitude0
                                        * Referenced by: '<S8>/Pulse Generator3'
                                        */
  3,                                   /* Expression: amplitude3
                                        * Referenced by: '<S9>/Pulse Generator'
                                        */
  0,                                   /* Expression: amplitude0
                                        * Referenced by: '<S9>/Pulse Generator1'
                                        */
  2,                                   /* Expression: amplitude2
                                        * Referenced by: '<S9>/Pulse Generator2'
                                        */
  1,                                   /* Expression: amplitude1
                                        * Referenced by: '<S9>/Pulse Generator3'
                                        */
  1U,                                  /* Computed Parameter: ARDrone_LED_p1
                                        * Referenced by: '<Root>/ARDrone_LED'
                                        */
  2U,                                  /* Computed Parameter: ARDrone_LED1_p1
                                        * Referenced by: '<Root>/ARDrone_LED1'
                                        */
  3U,                                  /* Computed Parameter: ARDrone_LED2_p1
                                        * Referenced by: '<Root>/ARDrone_LED2'
                                        */
  0U                                   /* Computed Parameter: ARDrone_LED3_p1
                                        * Referenced by: '<Root>/ARDrone_LED3'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
