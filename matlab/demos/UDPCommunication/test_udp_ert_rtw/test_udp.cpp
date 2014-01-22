/*
 * File: test_udp.cpp
 *
 * Code generated for Simulink model 'test_udp'.
 *
 * Model version                  : 1.35
 * Simulink Coder version         : 8.4 (R2013a) 13-Feb-2013
 * TLC version                    : 8.4 (Jan 18 2013)
 * C/C++ source code generated on : Wed Jan 22 13:34:25 2014
 *
 * Target selection: ardrone.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "test_udp.h"
#include "test_udp_private.h"

/* Real-time model */
RT_MODEL_test_udp_T test_udp_M_;
RT_MODEL_test_udp_T *const test_udp_M = &test_udp_M_;

/* Model step function */
void test_udp_step(void)
{
  /* local block i/o variables */
  int32_T rtb_UDP_Receive_Int1;
  int32_T rtb_DataTypeConversion;
  int16_T rtb_Height;

  /* S-Function (ARDrone_Height): '<Root>/Height' */
  rtb_Height = Height_Get();

  /* S-Function (UDP_Receive_Int32): '<S1>/UDP_Receive_Int1' */
  rtb_UDP_Receive_Int1 = udp_recv_int32();

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  rtb_DataTypeConversion = rtb_Height;

  /* S-Function (UDP_Send_Int32): '<S1>/UDP_Send_Int32' */
  udp_send_int32( (int32_T)rtb_DataTypeConversion);
}

/* Model initialize function */
void test_udp_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(test_udp_M, (NULL));

  /* S-Function (ARDrone_Height): <Root>/Height */
  Height_Initialization();

  /* S-Function (UDP_Receive_Int32): <S1>/UDP_Receive_Int1 */
  udp_reception_init( (int32_T)test_udp_P.UDP_Receive_Int1_p1);

  /* S-Function (UDP_Send_Int32): <S1>/UDP_Send_Int32 */
  udp_emission_init( (int32_T)test_udp_P.UDP_Send_Int32_p1);
}

/* Model terminate function */
void test_udp_terminate(void)
{
  /* S-Function (UDP_Receive_Int32): <S1>/UDP_Receive_Int1 */
  udp_reception_terminate();

  /* S-Function (UDP_Send_Int32): <S1>/UDP_Send_Int32 */
  udp_emission_terminate();
}

/* File trailer for generated code.
 *
 * [EOF]
 */
