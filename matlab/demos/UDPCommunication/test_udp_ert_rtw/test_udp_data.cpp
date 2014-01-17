/*
 * File: test_udp_data.cpp
 *
 * Code generated for Simulink model 'test_udp'.
 *
 * Model version                  : 1.23
 * Simulink Coder version         : 8.4 (R2013a) 13-Feb-2013
 * TLC version                    : 8.4 (Jan 18 2013)
 * C/C++ source code generated on : Fri Jan 17 11:58:55 2014
 *
 * Target selection: ardrone.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "test_udp.h"
#include "test_udp_private.h"

/* Block parameters (auto storage) */
P_test_udp_T test_udp_P = {
  8.0,                                 /* Expression: 8
                                        * Referenced by: '<Root>/Constant'
                                        */
  9000,                                /* Computed Parameter: UDP_Receive_Int1_p1
                                        * Referenced by: '<S2>/UDP_Receive_Int1'
                                        */
  3,                                   /* Computed Parameter: Saturation_UpperSat
                                        * Referenced by: '<Root>/Saturation'
                                        */
  0,                                   /* Computed Parameter: Saturation_LowerSat
                                        * Referenced by: '<Root>/Saturation'
                                        */
  9000,                                /* Computed Parameter: UDP_Send_Int32_p1
                                        * Referenced by: '<S2>/UDP_Send_Int32'
                                        */
  0U,                                  /* Computed Parameter: ARDrone_LED_p1
                                        * Referenced by: '<S1>/ARDrone_LED'
                                        */
  1U,                                  /* Computed Parameter: ARDrone_LED1_p1
                                        * Referenced by: '<S1>/ARDrone_LED1'
                                        */
  2U,                                  /* Computed Parameter: ARDrone_LED2_p1
                                        * Referenced by: '<S1>/ARDrone_LED2'
                                        */
  3U                                   /* Computed Parameter: ARDrone_LED3_p1
                                        * Referenced by: '<S1>/ARDrone_LED3'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
