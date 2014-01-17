/*
 * File: test_udp.cpp
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

/* Real-time model */
RT_MODEL_test_udp_T test_udp_M_;
RT_MODEL_test_udp_T *const test_udp_M = &test_udp_M_;

/* Model step function */
void test_udp_step(void)
{
  /* local block i/o variables */
  int32_T rtb_DataTypeConversion;
  int8_T rtb_DataTypeConversion3;
  real_T tmp;

  /* S-Function (UDP_Receive_Int32): '<S2>/UDP_Receive_Int1' */
  rtb_DataTypeConversion = udp_recv_int32();

  /* Saturate: '<Root>/Saturation' */
  if (rtb_DataTypeConversion >= test_udp_P.Saturation_UpperSat) {
    rtb_DataTypeConversion = test_udp_P.Saturation_UpperSat;
  } else {
    if (rtb_DataTypeConversion <= test_udp_P.Saturation_LowerSat) {
      rtb_DataTypeConversion = test_udp_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  rtb_DataTypeConversion3 = (int8_T)rtb_DataTypeConversion;

  /* S-Function (ARDrone_LED): '<S1>/ARDrone_LED' */
  LED_Set( (int8_T)rtb_DataTypeConversion3, (uint8_T)test_udp_P.ARDrone_LED_p1);

  /* DataTypeConversion: '<S1>/Data Type Conversion1' */
  rtb_DataTypeConversion3 = (int8_T)rtb_DataTypeConversion;

  /* S-Function (ARDrone_LED): '<S1>/ARDrone_LED1' */
  LED_Set( (int8_T)rtb_DataTypeConversion3, (uint8_T)test_udp_P.ARDrone_LED1_p1);

  /* DataTypeConversion: '<S1>/Data Type Conversion2' */
  rtb_DataTypeConversion3 = (int8_T)rtb_DataTypeConversion;

  /* S-Function (ARDrone_LED): '<S1>/ARDrone_LED2' */
  LED_Set( (int8_T)rtb_DataTypeConversion3, (uint8_T)test_udp_P.ARDrone_LED2_p1);

  /* DataTypeConversion: '<S1>/Data Type Conversion3' */
  rtb_DataTypeConversion3 = (int8_T)rtb_DataTypeConversion;

  /* S-Function (ARDrone_LED): '<S1>/ARDrone_LED3' */
  LED_Set( (int8_T)rtb_DataTypeConversion3, (uint8_T)test_udp_P.ARDrone_LED3_p1);

  /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant'
   */
  tmp = floor(test_udp_P.Constant_Value);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  rtb_DataTypeConversion = tmp < 0.0 ? -(int32_T)(uint32_T)-tmp : (int32_T)
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

  /* S-Function (UDP_Receive_Int32): <S2>/UDP_Receive_Int1 */
  udp_reception_init( (int32_T)test_udp_P.UDP_Receive_Int1_p1);

  /* S-Function (ARDrone_LED): <S1>/ARDrone_LED */
  LED_Initialization();

  /* S-Function (ARDrone_LED): <S1>/ARDrone_LED1 */
  LED_Initialization();

  /* S-Function (ARDrone_LED): <S1>/ARDrone_LED2 */
  LED_Initialization();

  /* S-Function (ARDrone_LED): <S1>/ARDrone_LED3 */
  LED_Initialization();

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
