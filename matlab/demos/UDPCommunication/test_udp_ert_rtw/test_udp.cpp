/*
 * File: test_udp.cpp
 *
 * Code generated for Simulink model 'test_udp'.
 *
 * Model version                  : 1.26
 * Simulink Coder version         : 8.4 (R2013a) 13-Feb-2013
 * TLC version                    : 8.4 (Jan 18 2013)
 * C/C++ source code generated on : Wed Jan 22 14:37:21 2014
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
  real32_T rtb_ARDrone_Roll;
  real32_T rtb_ARDrone_Yaw;
  real32_T rtb_ARDrone_Pitch;
  int32_T rtb_UDP_Receive_Int1;
  int32_T rtb_DataTypeConversion;
  real32_T tmp;

  /* S-Function (ARDrone_Pitch): '<S1>/ARDrone_Pitch' */
  rtb_ARDrone_Pitch = Ahrs_Get_Pitch();

  /* S-Function (ARDrone_Roll): '<S1>/ARDrone_Roll' */
  rtb_ARDrone_Roll = Ahrs_Get_Roll();

  /* S-Function (ARDrone_Yaw): '<S1>/ARDrone_Yaw' */
  rtb_ARDrone_Yaw = Ahrs_Get_Yaw();

  /* S-Function (UDP_Receive_Int32): '<S2>/UDP_Receive_Int1' */
  rtb_UDP_Receive_Int1 = udp_recv_int32();

  /* DataTypeConversion: '<S2>/Data Type Conversion' */
  tmp = (real32_T)floor(rtb_ARDrone_Pitch);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 4.2949673E+9F);
  }

  rtb_DataTypeConversion = tmp < 0.0F ? -(int32_T)(uint32_T)-tmp : (int32_T)
    (uint32_T)tmp;

  /* End of DataTypeConversion: '<S2>/Data Type Conversion' */

  /* S-Function (UDP_Send_Int32): '<S2>/UDP_Send_Int32' */
  udp_send_int32( (int32_T)rtb_DataTypeConversion);
}

/* Model initialize function */
void test_udp_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(test_udp_M, (NULL));

  /* S-Function (ARDrone_Pitch): <S1>/ARDrone_Pitch */
  Ahrs_Initialization();

  /* S-Function (ARDrone_Roll): <S1>/ARDrone_Roll */
  Ahrs_Initialization();

  /* S-Function (ARDrone_Yaw): <S1>/ARDrone_Yaw */
  Ahrs_Initialization();

  /* S-Function (UDP_Receive_Int32): <S2>/UDP_Receive_Int1 */
  udp_reception_init( (int32_T)test_udp_P.UDP_Receive_Int1_p1);

  /* S-Function (UDP_Send_Int32): <S2>/UDP_Send_Int32 */
  udp_emission_init( (int32_T)test_udp_P.UDP_Send_Int32_p1);
}

/* Model terminate function */
void test_udp_terminate(void)
{
  /* S-Function (UDP_Receive_Int32): <S2>/UDP_Receive_Int1 */
  udp_reception_terminate();

  /* S-Function (UDP_Send_Int32): <S2>/UDP_Send_Int32 */
  udp_emission_terminate();
}

/* File trailer for generated code.
 *
 * [EOF]
 */
