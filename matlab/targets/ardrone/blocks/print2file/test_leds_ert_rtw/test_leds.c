/*
 * File: test_leds.c
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
#include "test_leds_private.h"

/* Block states (auto storage) */
DW_test_leds_T test_leds_DW;

/* Real-time model */
RT_MODEL_test_leds_T test_leds_M_;
RT_MODEL_test_leds_T *const test_leds_M = &test_leds_M_;

/* Model step function */
void test_leds_step(void)
{
  /* local block i/o variables */
  int32_T rtb_DataTypeConversion3;
  real_T rtb_PulseGenerator3;
  real_T rtb_PulseGenerator2;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator3' */
  rtb_PulseGenerator3 = (test_leds_DW.clockTickCounter <
    test_leds_P.PulseGenerator3_Duty) && (test_leds_DW.clockTickCounter >= 0) ?
    test_leds_P.PulseGenerator3_Amp : 0.0;
  if (test_leds_DW.clockTickCounter >= test_leds_P.PulseGenerator3_Period - 1.0)
  {
    test_leds_DW.clockTickCounter = 0;
  } else {
    test_leds_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator3' */

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  rtb_PulseGenerator2 = floor(rtb_PulseGenerator3);
  if (rtIsNaN(rtb_PulseGenerator2) || rtIsInf(rtb_PulseGenerator2)) {
    rtb_PulseGenerator2 = 0.0;
  } else {
    rtb_PulseGenerator2 = fmod(rtb_PulseGenerator2, 4.294967296E+9);
  }

  rtb_DataTypeConversion3 = rtb_PulseGenerator2 < 0.0 ? -(int32_T)(uint32_T)
    -rtb_PulseGenerator2 : (int32_T)(uint32_T)rtb_PulseGenerator2;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion' */

  /* S-Function (ARDrone_PRINT2FILE): '<Root>/ARDrone_PRINT2FILE' */
  print2file( (int32_T)rtb_DataTypeConversion3);

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator2 = (test_leds_DW.clockTickCounter_e <
    test_leds_P.PulseGenerator_Duty) && (test_leds_DW.clockTickCounter_e >= 0) ?
    test_leds_P.PulseGenerator_Amp : 0.0;
  if (test_leds_DW.clockTickCounter_e >= test_leds_P.PulseGenerator_Period - 1.0)
  {
    test_leds_DW.clockTickCounter_e = 0;
  } else {
    test_leds_DW.clockTickCounter_e++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  rtb_PulseGenerator2 = floor(rtb_PulseGenerator2);
  if (rtIsNaN(rtb_PulseGenerator2) || rtIsInf(rtb_PulseGenerator2)) {
    rtb_PulseGenerator2 = 0.0;
  } else {
    rtb_PulseGenerator2 = fmod(rtb_PulseGenerator2, 4.294967296E+9);
  }

  rtb_DataTypeConversion3 = rtb_PulseGenerator2 < 0.0 ? -(int32_T)(uint32_T)
    -rtb_PulseGenerator2 : (int32_T)(uint32_T)rtb_PulseGenerator2;

  /* End of DataTypeConversion: '<S1>/Data Type Conversion' */

  /* S-Function (ARDrone_LED): '<S1>/ARDrone_LED' */
  led( (int32_T)rtb_DataTypeConversion3, (uint8_T)test_leds_P.ARDrone_LED_p1);

  /* DiscretePulseGenerator: '<Root>/Pulse Generator1' */
  rtb_PulseGenerator2 = (test_leds_DW.clockTickCounter_a <
    test_leds_P.PulseGenerator1_Duty) && (test_leds_DW.clockTickCounter_a >= 0) ?
    test_leds_P.PulseGenerator1_Amp : 0.0;
  if (test_leds_DW.clockTickCounter_a >= test_leds_P.PulseGenerator1_Period -
      1.0) {
    test_leds_DW.clockTickCounter_a = 0;
  } else {
    test_leds_DW.clockTickCounter_a++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator1' */

  /* DataTypeConversion: '<S1>/Data Type Conversion1' */
  rtb_PulseGenerator2 = floor(rtb_PulseGenerator2);
  if (rtIsNaN(rtb_PulseGenerator2) || rtIsInf(rtb_PulseGenerator2)) {
    rtb_PulseGenerator2 = 0.0;
  } else {
    rtb_PulseGenerator2 = fmod(rtb_PulseGenerator2, 4.294967296E+9);
  }

  rtb_DataTypeConversion3 = rtb_PulseGenerator2 < 0.0 ? -(int32_T)(uint32_T)
    -rtb_PulseGenerator2 : (int32_T)(uint32_T)rtb_PulseGenerator2;

  /* End of DataTypeConversion: '<S1>/Data Type Conversion1' */

  /* S-Function (ARDrone_LED): '<S1>/ARDrone_LED1' */
  led( (int32_T)rtb_DataTypeConversion3, (uint8_T)test_leds_P.ARDrone_LED1_p1);

  /* DiscretePulseGenerator: '<Root>/Pulse Generator2' */
  rtb_PulseGenerator2 = (test_leds_DW.clockTickCounter_h <
    test_leds_P.PulseGenerator2_Duty) && (test_leds_DW.clockTickCounter_h >= 0) ?
    test_leds_P.PulseGenerator2_Amp : 0.0;
  if (test_leds_DW.clockTickCounter_h >= test_leds_P.PulseGenerator2_Period -
      1.0) {
    test_leds_DW.clockTickCounter_h = 0;
  } else {
    test_leds_DW.clockTickCounter_h++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator2' */

  /* DataTypeConversion: '<S1>/Data Type Conversion2' */
  rtb_PulseGenerator2 = floor(rtb_PulseGenerator2);
  if (rtIsNaN(rtb_PulseGenerator2) || rtIsInf(rtb_PulseGenerator2)) {
    rtb_PulseGenerator2 = 0.0;
  } else {
    rtb_PulseGenerator2 = fmod(rtb_PulseGenerator2, 4.294967296E+9);
  }

  rtb_DataTypeConversion3 = rtb_PulseGenerator2 < 0.0 ? -(int32_T)(uint32_T)
    -rtb_PulseGenerator2 : (int32_T)(uint32_T)rtb_PulseGenerator2;

  /* End of DataTypeConversion: '<S1>/Data Type Conversion2' */

  /* S-Function (ARDrone_LED): '<S1>/ARDrone_LED2' */
  led( (int32_T)rtb_DataTypeConversion3, (uint8_T)test_leds_P.ARDrone_LED2_p1);

  /* DataTypeConversion: '<S1>/Data Type Conversion3' */
  rtb_PulseGenerator2 = floor(rtb_PulseGenerator3);
  if (rtIsNaN(rtb_PulseGenerator2) || rtIsInf(rtb_PulseGenerator2)) {
    rtb_PulseGenerator2 = 0.0;
  } else {
    rtb_PulseGenerator2 = fmod(rtb_PulseGenerator2, 4.294967296E+9);
  }

  rtb_DataTypeConversion3 = rtb_PulseGenerator2 < 0.0 ? -(int32_T)(uint32_T)
    -rtb_PulseGenerator2 : (int32_T)(uint32_T)rtb_PulseGenerator2;

  /* End of DataTypeConversion: '<S1>/Data Type Conversion3' */

  /* S-Function (ARDrone_LED): '<S1>/ARDrone_LED3' */
  led( (int32_T)rtb_DataTypeConversion3, (uint8_T)test_leds_P.ARDrone_LED3_p1);
}

/* Model initialize function */
void test_leds_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(test_leds_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&test_leds_DW, 0,
                sizeof(DW_test_leds_T));

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator3' */
  test_leds_DW.clockTickCounter = 0;

  /* S-Function (ARDrone_PRINT2FILE): <Root>/ARDrone_PRINT2FILE */
  print2fileInit( (uint8_T*)test_leds_P.ARDrone_PRINT2FILE_p1);

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  test_leds_DW.clockTickCounter_e = 0;

  /* S-Function (ARDrone_LED): <S1>/ARDrone_LED */
  LED_Initialization();

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator1' */
  test_leds_DW.clockTickCounter_a = 0;

  /* S-Function (ARDrone_LED): <S1>/ARDrone_LED1 */
  LED_Initialization();

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator2' */
  test_leds_DW.clockTickCounter_h = 0;

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
