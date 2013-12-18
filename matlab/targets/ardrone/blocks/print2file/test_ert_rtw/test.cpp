/*
 * File: test.cpp
 *
 * Code generated for Simulink model 'test'.
 *
 * Model version                  : 1.27
 * Simulink Coder version         : 8.4 (R2013a) 13-Feb-2013
 * TLC version                    : 8.4 (Jan 18 2013)
 * C/C++ source code generated on : Wed Dec 18 13:55:05 2013
 *
 * Target selection: ardrone.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "test.h"
#include "test_private.h"

/* Block states (auto storage) */
DW_test_T test_DW;

/* Real-time model */
RT_MODEL_test_T test_M_;
RT_MODEL_test_T *const test_M = &test_M_;

/* Model step function */
void test_step(void)
{
  /* local block i/o variables */
  real32_T rtb_DataTypeConversion3;
  int8_T rtb_DataTypeConversion3_m;
  real_T rtb_PulseGenerator;
  real_T tmp;

  /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant'
   */
  rtb_DataTypeConversion3 = (real32_T)test_P.Constant_Value;

  /* S-Function (ARDrone_Motor): '<S2>/ARDrone_Motor' */
  Motor_Set( (real32_T)rtb_DataTypeConversion3, (uint8_T)test_P.ARDrone_Motor_p1);

  /* DataTypeConversion: '<S2>/Data Type Conversion1' incorporates:
   *  Constant: '<Root>/Constant'
   */
  rtb_DataTypeConversion3 = (real32_T)test_P.Constant_Value;

  /* S-Function (ARDrone_Motor): '<S2>/ARDrone_Motor1' */
  Motor_Set( (real32_T)rtb_DataTypeConversion3, (uint8_T)
            test_P.ARDrone_Motor1_p1);

  /* DataTypeConversion: '<S2>/Data Type Conversion2' incorporates:
   *  Constant: '<Root>/Constant'
   */
  rtb_DataTypeConversion3 = (real32_T)test_P.Constant_Value;

  /* S-Function (ARDrone_Motor): '<S2>/ARDrone_Motor2' */
  Motor_Set( (real32_T)rtb_DataTypeConversion3, (uint8_T)
            test_P.ARDrone_Motor2_p1);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Constant: '<Root>/Constant'
   */
  rtb_DataTypeConversion3 = (real32_T)test_P.Constant_Value;

  /* S-Function (ARDrone_Motor): '<S2>/ARDrone_Motor3' */
  Motor_Set( (real32_T)rtb_DataTypeConversion3, (uint8_T)
            test_P.ARDrone_Motor3_p1);

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (test_DW.clockTickCounter < test_P.PulseGenerator_Duty) &&
    (test_DW.clockTickCounter >= 0) ? test_P.PulseGenerator_Amp : 0.0;
  if (test_DW.clockTickCounter >= test_P.PulseGenerator_Period - 1.0) {
    test_DW.clockTickCounter = 0;
  } else {
    test_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  tmp = floor(rtb_PulseGenerator);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  rtb_DataTypeConversion3_m = (int8_T)(tmp < 0.0 ? (int32_T)(int8_T)-(int8_T)
    (uint8_T)-tmp : (int32_T)(int8_T)(uint8_T)tmp);

  /* End of DataTypeConversion: '<S1>/Data Type Conversion' */

  /* S-Function (ARDrone_LED): '<S1>/ARDrone_LED1' */
  LED_Set( (int8_T)rtb_DataTypeConversion3_m, (uint8_T)test_P.ARDrone_LED1_p1);

  /* DataTypeConversion: '<S1>/Data Type Conversion1' */
  tmp = floor(rtb_PulseGenerator);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  rtb_DataTypeConversion3_m = (int8_T)(tmp < 0.0 ? (int32_T)(int8_T)-(int8_T)
    (uint8_T)-tmp : (int32_T)(int8_T)(uint8_T)tmp);

  /* End of DataTypeConversion: '<S1>/Data Type Conversion1' */

  /* S-Function (ARDrone_LED): '<S1>/ARDrone_LED2' */
  LED_Set( (int8_T)rtb_DataTypeConversion3_m, (uint8_T)test_P.ARDrone_LED2_p1);

  /* DataTypeConversion: '<S1>/Data Type Conversion2' */
  tmp = floor(rtb_PulseGenerator);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  rtb_DataTypeConversion3_m = (int8_T)(tmp < 0.0 ? (int32_T)(int8_T)-(int8_T)
    (uint8_T)-tmp : (int32_T)(int8_T)(uint8_T)tmp);

  /* End of DataTypeConversion: '<S1>/Data Type Conversion2' */

  /* S-Function (ARDrone_LED): '<S1>/ARDrone_LED3' */
  LED_Set( (int8_T)rtb_DataTypeConversion3_m, (uint8_T)test_P.ARDrone_LED3_p1);

  /* DataTypeConversion: '<S1>/Data Type Conversion3' */
  tmp = floor(rtb_PulseGenerator);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  rtb_DataTypeConversion3_m = (int8_T)(tmp < 0.0 ? (int32_T)(int8_T)-(int8_T)
    (uint8_T)-tmp : (int32_T)(int8_T)(uint8_T)tmp);

  /* End of DataTypeConversion: '<S1>/Data Type Conversion3' */

  /* S-Function (ARDrone_LED): '<S1>/ARDrone_LED4' */
  LED_Set( (int8_T)rtb_DataTypeConversion3_m, (uint8_T)test_P.ARDrone_LED4_p1);
}

/* Model initialize function */
void test_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(test_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&test_DW, 0,
                sizeof(DW_test_T));

  /* S-Function (ARDrone_Motor): <S2>/ARDrone_Motor */
  Motor_Initialization();

  /* S-Function (ARDrone_Motor): <S2>/ARDrone_Motor1 */
  Motor_Initialization();

  /* S-Function (ARDrone_Motor): <S2>/ARDrone_Motor2 */
  Motor_Initialization();

  /* S-Function (ARDrone_Motor): <S2>/ARDrone_Motor3 */
  Motor_Initialization();

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  test_DW.clockTickCounter = 0;

  /* S-Function (ARDrone_LED): <S1>/ARDrone_LED1 */
  LED_Initialization();

  /* S-Function (ARDrone_LED): <S1>/ARDrone_LED2 */
  LED_Initialization();

  /* S-Function (ARDrone_LED): <S1>/ARDrone_LED3 */
  LED_Initialization();

  /* S-Function (ARDrone_LED): <S1>/ARDrone_LED4 */
  LED_Initialization();
}

/* Model terminate function */
void test_terminate(void)
{
  /* (no terminate code required) */
}

/* File trailer for generated code.
 *
 * [EOF]
 */
