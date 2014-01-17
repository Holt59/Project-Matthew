/*
 * File: test_leds.cpp
 *
 * Code generated for Simulink model 'test_leds'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 8.4 (R2013a) 13-Feb-2013
 * TLC version                    : 8.4 (Jan 18 2013)
 * C/C++ source code generated on : Thu Jan 16 15:47:15 2014
 *
 * Target selection: ardrone.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "test_leds.h"
#include "test_leds_private.h"

/* Real-time model */
RT_MODEL_test_leds_T test_leds_M_;
RT_MODEL_test_leds_T *const test_leds_M = &test_leds_M_;

/* Model step function */
void test_leds_step(void)
{
  /* local block i/o variables */
  int8_T rtb_DataTypeConversion3;
  real_T tmp;

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant'
   */
  tmp = floor(test_leds_P.Constant_Value);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  rtb_DataTypeConversion3 = (int8_T)(tmp < 0.0 ? (int32_T)(int8_T)-(int8_T)
    (uint8_T)-tmp : (int32_T)(int8_T)(uint8_T)tmp);

  /* End of DataTypeConversion: '<S1>/Data Type Conversion' */

  /* S-Function (ARDrone_LED): '<S1>/ARDrone_LED' */
  LED_Set( (int8_T)rtb_DataTypeConversion3, (uint8_T)test_leds_P.ARDrone_LED_p1);

  /* DataTypeConversion: '<S1>/Data Type Conversion1' incorporates:
   *  Constant: '<Root>/Constant'
   */
  tmp = floor(test_leds_P.Constant_Value);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  rtb_DataTypeConversion3 = (int8_T)(tmp < 0.0 ? (int32_T)(int8_T)-(int8_T)
    (uint8_T)-tmp : (int32_T)(int8_T)(uint8_T)tmp);

  /* End of DataTypeConversion: '<S1>/Data Type Conversion1' */

  /* S-Function (ARDrone_LED): '<S1>/ARDrone_LED1' */
  LED_Set( (int8_T)rtb_DataTypeConversion3, (uint8_T)test_leds_P.ARDrone_LED1_p1);

  /* DataTypeConversion: '<S1>/Data Type Conversion2' incorporates:
   *  Constant: '<Root>/Constant'
   */
  tmp = floor(test_leds_P.Constant_Value);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  rtb_DataTypeConversion3 = (int8_T)(tmp < 0.0 ? (int32_T)(int8_T)-(int8_T)
    (uint8_T)-tmp : (int32_T)(int8_T)(uint8_T)tmp);

  /* End of DataTypeConversion: '<S1>/Data Type Conversion2' */

  /* S-Function (ARDrone_LED): '<S1>/ARDrone_LED2' */
  LED_Set( (int8_T)rtb_DataTypeConversion3, (uint8_T)test_leds_P.ARDrone_LED2_p1);

  /* DataTypeConversion: '<S1>/Data Type Conversion3' incorporates:
   *  Constant: '<Root>/Constant'
   */
  tmp = floor(test_leds_P.Constant_Value);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  rtb_DataTypeConversion3 = (int8_T)(tmp < 0.0 ? (int32_T)(int8_T)-(int8_T)
    (uint8_T)-tmp : (int32_T)(int8_T)(uint8_T)tmp);

  /* End of DataTypeConversion: '<S1>/Data Type Conversion3' */

  /* S-Function (ARDrone_LED): '<S1>/ARDrone_LED3' */
  LED_Set( (int8_T)rtb_DataTypeConversion3, (uint8_T)test_leds_P.ARDrone_LED3_p1);
}

/* Model initialize function */
void test_leds_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(test_leds_M, (NULL));

  /* S-Function (ARDrone_LED): <S1>/ARDrone_LED */
  LED_Initialization();

  /* S-Function (ARDrone_LED): <S1>/ARDrone_LED1 */
  LED_Initialization();

  /* S-Function (ARDrone_LED): <S1>/ARDrone_LED2 */
  LED_Initialization();

  /* S-Function (ARDrone_LED): <S1>/ARDrone_LED3 */
  LED_Initialization();
}

/* Model terminate function */
void test_leds_terminate(void)
{
  /* (no terminate code required) */
}

/* File trailer for generated code.
 *
 * [EOF]
 */
