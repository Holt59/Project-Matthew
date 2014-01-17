/*
 * File: LedAccelerometre.cpp
 *
 * Code generated for Simulink model 'LedAccelerometre'.
 *
 * Model version                  : 1.15
 * Simulink Coder version         : 8.4 (R2013a) 13-Feb-2013
 * TLC version                    : 8.4 (Jan 18 2013)
 * C/C++ source code generated on : Fri Jan 17 10:29:24 2014
 *
 * Target selection: ardrone.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "LedAccelerometre.h"
#include "LedAccelerometre_private.h"

/* Real-time model */
RT_MODEL_LedAccelerometre_T LedAccelerometre_M_;
RT_MODEL_LedAccelerometre_T *const LedAccelerometre_M = &LedAccelerometre_M_;

/* Model step function */
void LedAccelerometre_step(void)
{
  /* local block i/o variables */
  real32_T rtb_ARDrone_Acc_X;
  real32_T rtb_ARDrone_Acc_Y;
  real32_T rtb_ARDrone_Acc_Z;
  int8_T rtb_DataTypeConversion3;
  int32_T tmp;

  /* S-Function (ARDrone_Acc_Z): '<S1>/ARDrone_Acc_Z' */
  rtb_ARDrone_Acc_Z = Accelero_Get_Z();

  /* Sum: '<S2>/netsum' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S4>/Constant'
   *  Constant: '<S5>/Constant'
   *  RelationalOperator: '<S4>/Compare'
   *  RelationalOperator: '<S5>/Compare'
   */
  tmp = (int32_T)(((uint32_T)(rtb_ARDrone_Acc_Z >=
    LedAccelerometre_P.Constant_Value) + (rtb_ARDrone_Acc_Z >=
    LedAccelerometre_P.Constant_Value_o)) + LedAccelerometre_P.Constant_Value_d);
  if ((uint32_T)tmp > 255U) {
    tmp = 255;
  }

  /* DataTypeConversion: '<S3>/Data Type Conversion' incorporates:
   *  Sum: '<S2>/netsum'
   */
  rtb_DataTypeConversion3 = (int8_T)tmp;

  /* S-Function (ARDrone_LED): '<S3>/ARDrone_LED' */
  LED_Set( (int8_T)rtb_DataTypeConversion3, (uint8_T)
          LedAccelerometre_P.ARDrone_LED_p1);

  /* DataTypeConversion: '<S3>/Data Type Conversion1' incorporates:
   *  Sum: '<S2>/netsum'
   */
  rtb_DataTypeConversion3 = (int8_T)tmp;

  /* S-Function (ARDrone_LED): '<S3>/ARDrone_LED1' */
  LED_Set( (int8_T)rtb_DataTypeConversion3, (uint8_T)
          LedAccelerometre_P.ARDrone_LED1_p1);

  /* DataTypeConversion: '<S3>/Data Type Conversion2' incorporates:
   *  Sum: '<S2>/netsum'
   */
  rtb_DataTypeConversion3 = (int8_T)tmp;

  /* S-Function (ARDrone_LED): '<S3>/ARDrone_LED2' */
  LED_Set( (int8_T)rtb_DataTypeConversion3, (uint8_T)
          LedAccelerometre_P.ARDrone_LED2_p1);

  /* DataTypeConversion: '<S3>/Data Type Conversion3' incorporates:
   *  Sum: '<S2>/netsum'
   */
  rtb_DataTypeConversion3 = (int8_T)tmp;

  /* S-Function (ARDrone_LED): '<S3>/ARDrone_LED3' */
  LED_Set( (int8_T)rtb_DataTypeConversion3, (uint8_T)
          LedAccelerometre_P.ARDrone_LED3_p1);

  /* S-Function (ARDrone_Acc_X): '<S1>/ARDrone_Acc_X' */
  rtb_ARDrone_Acc_X = Accelero_Get_X();

  /* S-Function (ARDrone_Acc_Y): '<S1>/ARDrone_Acc_Y' */
  rtb_ARDrone_Acc_Y = Accelero_Get_Y();
}

/* Model initialize function */
void LedAccelerometre_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(LedAccelerometre_M, (NULL));

  /* S-Function (ARDrone_Acc_Z): <S1>/ARDrone_Acc_Z */
  Accelero_Initialization();

  /* S-Function (ARDrone_LED): <S3>/ARDrone_LED */
  LED_Initialization();

  /* S-Function (ARDrone_LED): <S3>/ARDrone_LED1 */
  LED_Initialization();

  /* S-Function (ARDrone_LED): <S3>/ARDrone_LED2 */
  LED_Initialization();

  /* S-Function (ARDrone_LED): <S3>/ARDrone_LED3 */
  LED_Initialization();

  /* S-Function (ARDrone_Acc_X): <S1>/ARDrone_Acc_X */
  Accelero_Initialization();

  /* S-Function (ARDrone_Acc_Y): <S1>/ARDrone_Acc_Y */
  Accelero_Initialization();
}

/* Model terminate function */
void LedAccelerometre_terminate(void)
{
  /* (no terminate code required) */
}

/* File trailer for generated code.
 *
 * [EOF]
 */
