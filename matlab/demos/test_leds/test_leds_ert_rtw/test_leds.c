/*
 * File: test_leds.c
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

/* Block states (auto storage) */
DW_test_leds_T test_leds_DW;

/* Real-time model */
RT_MODEL_test_leds_T test_leds_M_;
RT_MODEL_test_leds_T *const test_leds_M = &test_leds_M_;

/* Model step function */
void test_leds_step(void)
{
  /* local block i/o variables */
  int32_T rtb_Sum;
  int32_T rtb_Sum_n;
  int32_T rtb_Sum_k;
  int32_T rtb_Sum_p;
  int32_T rtb_PulseGenerator3;
  int32_T rtb_PulseGenerator2;
  int32_T rtb_PulseGenerator1;
  int32_T rtb_PulseGenerator;

  /* DiscretePulseGenerator: '<S6>/Pulse Generator' */
  rtb_PulseGenerator3 = (test_leds_DW.clockTickCounter <
    test_leds_P.PulseGenerator_Duty) && (test_leds_DW.clockTickCounter >= 0) ?
    test_leds_P.PulseGenerator_Amp : 0;
  if (test_leds_DW.clockTickCounter >= test_leds_P.PulseGenerator_Period - 1.0)
  {
    test_leds_DW.clockTickCounter = 0;
  } else {
    test_leds_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S6>/Pulse Generator' */

  /* DiscretePulseGenerator: '<S6>/Pulse Generator1' */
  rtb_PulseGenerator2 = (test_leds_DW.clockTickCounter_f <
    test_leds_P.PulseGenerator1_Duty) && (test_leds_DW.clockTickCounter_f >= 0) ?
    test_leds_P.PulseGenerator1_Amp : 0;
  if (test_leds_DW.clockTickCounter_f >= test_leds_P.PulseGenerator1_Period -
      1.0) {
    test_leds_DW.clockTickCounter_f = 0;
  } else {
    test_leds_DW.clockTickCounter_f++;
  }

  /* End of DiscretePulseGenerator: '<S6>/Pulse Generator1' */

  /* DiscretePulseGenerator: '<S6>/Pulse Generator2' */
  rtb_PulseGenerator1 = (test_leds_DW.clockTickCounter_g <
    test_leds_P.PulseGenerator2_Duty) && (test_leds_DW.clockTickCounter_g >= 0) ?
    test_leds_P.PulseGenerator2_Amp : 0;
  if (test_leds_DW.clockTickCounter_g >= test_leds_P.PulseGenerator2_Period -
      1.0) {
    test_leds_DW.clockTickCounter_g = 0;
  } else {
    test_leds_DW.clockTickCounter_g++;
  }

  /* End of DiscretePulseGenerator: '<S6>/Pulse Generator2' */

  /* DiscretePulseGenerator: '<S6>/Pulse Generator3' */
  rtb_PulseGenerator = (test_leds_DW.clockTickCounter_e <
                        test_leds_P.PulseGenerator3_Duty) &&
    (test_leds_DW.clockTickCounter_e >= 0) ? test_leds_P.PulseGenerator3_Amp : 0;
  if (test_leds_DW.clockTickCounter_e >= test_leds_P.PulseGenerator3_Period -
      1.0) {
    test_leds_DW.clockTickCounter_e = 0;
  } else {
    test_leds_DW.clockTickCounter_e++;
  }

  /* End of DiscretePulseGenerator: '<S6>/Pulse Generator3' */

  /* Sum: '<S2>/Sum' */
  rtb_Sum = ((rtb_PulseGenerator3 + rtb_PulseGenerator2) + rtb_PulseGenerator1)
    + rtb_PulseGenerator;

  /* S-Function (ARDrone_LED): '<Root>/ARDrone_LED' */
  led( (int32_T)rtb_Sum, (uint8_T)test_leds_P.ARDrone_LED_p1);

  /* DiscretePulseGenerator: '<S7>/Pulse Generator' */
  rtb_PulseGenerator = (test_leds_DW.clockTickCounter_gm <
                        test_leds_P.PulseGenerator_Duty_m) &&
    (test_leds_DW.clockTickCounter_gm >= 0) ? test_leds_P.PulseGenerator_Amp_k :
    0;
  if (test_leds_DW.clockTickCounter_gm >= test_leds_P.PulseGenerator_Period_h -
      1.0) {
    test_leds_DW.clockTickCounter_gm = 0;
  } else {
    test_leds_DW.clockTickCounter_gm++;
  }

  /* End of DiscretePulseGenerator: '<S7>/Pulse Generator' */

  /* DiscretePulseGenerator: '<S7>/Pulse Generator1' */
  rtb_PulseGenerator1 = (test_leds_DW.clockTickCounter_k <
    test_leds_P.PulseGenerator1_Duty_n) && (test_leds_DW.clockTickCounter_k >= 0)
    ? test_leds_P.PulseGenerator1_Amp_p : 0;
  if (test_leds_DW.clockTickCounter_k >= test_leds_P.PulseGenerator1_Period_o -
      1.0) {
    test_leds_DW.clockTickCounter_k = 0;
  } else {
    test_leds_DW.clockTickCounter_k++;
  }

  /* End of DiscretePulseGenerator: '<S7>/Pulse Generator1' */

  /* DiscretePulseGenerator: '<S7>/Pulse Generator2' */
  rtb_PulseGenerator2 = (test_leds_DW.clockTickCounter_c <
    test_leds_P.PulseGenerator2_Duty_c) && (test_leds_DW.clockTickCounter_c >= 0)
    ? test_leds_P.PulseGenerator2_Amp_j : 0;
  if (test_leds_DW.clockTickCounter_c >= test_leds_P.PulseGenerator2_Period_o -
      1.0) {
    test_leds_DW.clockTickCounter_c = 0;
  } else {
    test_leds_DW.clockTickCounter_c++;
  }

  /* End of DiscretePulseGenerator: '<S7>/Pulse Generator2' */

  /* DiscretePulseGenerator: '<S7>/Pulse Generator3' */
  rtb_PulseGenerator3 = (test_leds_DW.clockTickCounter_gr <
    test_leds_P.PulseGenerator3_Duty_c) && (test_leds_DW.clockTickCounter_gr >=
    0) ? test_leds_P.PulseGenerator3_Amp_c : 0;
  if (test_leds_DW.clockTickCounter_gr >= test_leds_P.PulseGenerator3_Period_c -
      1.0) {
    test_leds_DW.clockTickCounter_gr = 0;
  } else {
    test_leds_DW.clockTickCounter_gr++;
  }

  /* End of DiscretePulseGenerator: '<S7>/Pulse Generator3' */

  /* Sum: '<S3>/Sum' */
  rtb_Sum_n = ((rtb_PulseGenerator + rtb_PulseGenerator1) + rtb_PulseGenerator2)
    + rtb_PulseGenerator3;

  /* S-Function (ARDrone_LED): '<Root>/ARDrone_LED1' */
  led( (int32_T)rtb_Sum_n, (uint8_T)test_leds_P.ARDrone_LED1_p1);

  /* DiscretePulseGenerator: '<S8>/Pulse Generator' */
  rtb_PulseGenerator = (test_leds_DW.clockTickCounter_j <
                        test_leds_P.PulseGenerator_Duty_m4) &&
    (test_leds_DW.clockTickCounter_j >= 0) ? test_leds_P.PulseGenerator_Amp_c :
    0;
  if (test_leds_DW.clockTickCounter_j >= test_leds_P.PulseGenerator_Period_b -
      1.0) {
    test_leds_DW.clockTickCounter_j = 0;
  } else {
    test_leds_DW.clockTickCounter_j++;
  }

  /* End of DiscretePulseGenerator: '<S8>/Pulse Generator' */

  /* DiscretePulseGenerator: '<S8>/Pulse Generator1' */
  rtb_PulseGenerator1 = (test_leds_DW.clockTickCounter_kn <
    test_leds_P.PulseGenerator1_Duty_c) && (test_leds_DW.clockTickCounter_kn >=
    0) ? test_leds_P.PulseGenerator1_Amp_l : 0;
  if (test_leds_DW.clockTickCounter_kn >= test_leds_P.PulseGenerator1_Period_l -
      1.0) {
    test_leds_DW.clockTickCounter_kn = 0;
  } else {
    test_leds_DW.clockTickCounter_kn++;
  }

  /* End of DiscretePulseGenerator: '<S8>/Pulse Generator1' */

  /* DiscretePulseGenerator: '<S8>/Pulse Generator2' */
  rtb_PulseGenerator2 = (test_leds_DW.clockTickCounter_f0 <
    test_leds_P.PulseGenerator2_Duty_m) && (test_leds_DW.clockTickCounter_f0 >=
    0) ? test_leds_P.PulseGenerator2_Amp_k : 0;
  if (test_leds_DW.clockTickCounter_f0 >= test_leds_P.PulseGenerator2_Period_os
      - 1.0) {
    test_leds_DW.clockTickCounter_f0 = 0;
  } else {
    test_leds_DW.clockTickCounter_f0++;
  }

  /* End of DiscretePulseGenerator: '<S8>/Pulse Generator2' */

  /* DiscretePulseGenerator: '<S8>/Pulse Generator3' */
  rtb_PulseGenerator3 = (test_leds_DW.clockTickCounter_jh <
    test_leds_P.PulseGenerator3_Duty_j) && (test_leds_DW.clockTickCounter_jh >=
    0) ? test_leds_P.PulseGenerator3_Amp_n : 0;
  if (test_leds_DW.clockTickCounter_jh >= test_leds_P.PulseGenerator3_Period_p -
      1.0) {
    test_leds_DW.clockTickCounter_jh = 0;
  } else {
    test_leds_DW.clockTickCounter_jh++;
  }

  /* End of DiscretePulseGenerator: '<S8>/Pulse Generator3' */

  /* Sum: '<S4>/Sum' */
  rtb_Sum_k = ((rtb_PulseGenerator + rtb_PulseGenerator1) + rtb_PulseGenerator2)
    + rtb_PulseGenerator3;

  /* S-Function (ARDrone_LED): '<Root>/ARDrone_LED2' */
  led( (int32_T)rtb_Sum_k, (uint8_T)test_leds_P.ARDrone_LED2_p1);

  /* DiscretePulseGenerator: '<S9>/Pulse Generator' */
  rtb_PulseGenerator = (test_leds_DW.clockTickCounter_gh <
                        test_leds_P.PulseGenerator_Duty_h) &&
    (test_leds_DW.clockTickCounter_gh >= 0) ? test_leds_P.PulseGenerator_Amp_k2 :
    0;
  if (test_leds_DW.clockTickCounter_gh >= test_leds_P.PulseGenerator_Period_bq -
      1.0) {
    test_leds_DW.clockTickCounter_gh = 0;
  } else {
    test_leds_DW.clockTickCounter_gh++;
  }

  /* End of DiscretePulseGenerator: '<S9>/Pulse Generator' */

  /* DiscretePulseGenerator: '<S9>/Pulse Generator1' */
  rtb_PulseGenerator1 = (test_leds_DW.clockTickCounter_kh <
    test_leds_P.PulseGenerator1_Duty_j) && (test_leds_DW.clockTickCounter_kh >=
    0) ? test_leds_P.PulseGenerator1_Amp_d : 0;
  if (test_leds_DW.clockTickCounter_kh >= test_leds_P.PulseGenerator1_Period_c -
      1.0) {
    test_leds_DW.clockTickCounter_kh = 0;
  } else {
    test_leds_DW.clockTickCounter_kh++;
  }

  /* End of DiscretePulseGenerator: '<S9>/Pulse Generator1' */

  /* DiscretePulseGenerator: '<S9>/Pulse Generator2' */
  rtb_PulseGenerator2 = (test_leds_DW.clockTickCounter_b <
    test_leds_P.PulseGenerator2_Duty_j) && (test_leds_DW.clockTickCounter_b >= 0)
    ? test_leds_P.PulseGenerator2_Amp_i : 0;
  if (test_leds_DW.clockTickCounter_b >= test_leds_P.PulseGenerator2_Period_p -
      1.0) {
    test_leds_DW.clockTickCounter_b = 0;
  } else {
    test_leds_DW.clockTickCounter_b++;
  }

  /* End of DiscretePulseGenerator: '<S9>/Pulse Generator2' */

  /* DiscretePulseGenerator: '<S9>/Pulse Generator3' */
  rtb_PulseGenerator3 = (test_leds_DW.clockTickCounter_p <
    test_leds_P.PulseGenerator3_Duty_m) && (test_leds_DW.clockTickCounter_p >= 0)
    ? test_leds_P.PulseGenerator3_Amp_e : 0;
  if (test_leds_DW.clockTickCounter_p >= test_leds_P.PulseGenerator3_Period_b -
      1.0) {
    test_leds_DW.clockTickCounter_p = 0;
  } else {
    test_leds_DW.clockTickCounter_p++;
  }

  /* End of DiscretePulseGenerator: '<S9>/Pulse Generator3' */

  /* Sum: '<S5>/Sum' */
  rtb_Sum_p = ((rtb_PulseGenerator + rtb_PulseGenerator1) + rtb_PulseGenerator2)
    + rtb_PulseGenerator3;

  /* S-Function (ARDrone_LED): '<Root>/ARDrone_LED3' */
  led( (int32_T)rtb_Sum_p, (uint8_T)test_leds_P.ARDrone_LED3_p1);
}

/* Model initialize function */
void test_leds_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(test_leds_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&test_leds_DW, 0,
                sizeof(DW_test_leds_T));

  /* Start for DiscretePulseGenerator: '<S6>/Pulse Generator' */
  test_leds_DW.clockTickCounter = 0;

  /* Start for DiscretePulseGenerator: '<S6>/Pulse Generator1' */
  test_leds_DW.clockTickCounter_f = -1000;

  /* Start for DiscretePulseGenerator: '<S6>/Pulse Generator2' */
  test_leds_DW.clockTickCounter_g = -3000;

  /* Start for DiscretePulseGenerator: '<S6>/Pulse Generator3' */
  test_leds_DW.clockTickCounter_e = -2000;

  /* S-Function (ARDrone_LED): <Root>/ARDrone_LED */
  LED_Initialization();

  /* Start for DiscretePulseGenerator: '<S7>/Pulse Generator' */
  test_leds_DW.clockTickCounter_gm = 0;

  /* Start for DiscretePulseGenerator: '<S7>/Pulse Generator1' */
  test_leds_DW.clockTickCounter_k = -1000;

  /* Start for DiscretePulseGenerator: '<S7>/Pulse Generator2' */
  test_leds_DW.clockTickCounter_c = -3000;

  /* Start for DiscretePulseGenerator: '<S7>/Pulse Generator3' */
  test_leds_DW.clockTickCounter_gr = -2000;

  /* S-Function (ARDrone_LED): <Root>/ARDrone_LED1 */
  LED_Initialization();

  /* Start for DiscretePulseGenerator: '<S8>/Pulse Generator' */
  test_leds_DW.clockTickCounter_j = 0;

  /* Start for DiscretePulseGenerator: '<S8>/Pulse Generator1' */
  test_leds_DW.clockTickCounter_kn = -1000;

  /* Start for DiscretePulseGenerator: '<S8>/Pulse Generator2' */
  test_leds_DW.clockTickCounter_f0 = -3000;

  /* Start for DiscretePulseGenerator: '<S8>/Pulse Generator3' */
  test_leds_DW.clockTickCounter_jh = -2000;

  /* S-Function (ARDrone_LED): <Root>/ARDrone_LED2 */
  LED_Initialization();

  /* Start for DiscretePulseGenerator: '<S9>/Pulse Generator' */
  test_leds_DW.clockTickCounter_gh = 0;

  /* Start for DiscretePulseGenerator: '<S9>/Pulse Generator1' */
  test_leds_DW.clockTickCounter_kh = -1000;

  /* Start for DiscretePulseGenerator: '<S9>/Pulse Generator2' */
  test_leds_DW.clockTickCounter_b = -3000;

  /* Start for DiscretePulseGenerator: '<S9>/Pulse Generator3' */
  test_leds_DW.clockTickCounter_p = -2000;

  /* S-Function (ARDrone_LED): <Root>/ARDrone_LED3 */
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
