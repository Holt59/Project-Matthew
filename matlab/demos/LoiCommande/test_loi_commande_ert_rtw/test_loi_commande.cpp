/*
 * File: test_loi_commande.cpp
 *
 * Code generated for Simulink model 'test_loi_commande'.
 *
 * Model version                  : 1.61
 * Simulink Coder version         : 8.4 (R2013a) 13-Feb-2013
 * TLC version                    : 8.4 (Jan 18 2013)
 * C/C++ source code generated on : Fri Jan 17 11:12:22 2014
 *
 * Target selection: ardrone.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "test_loi_commande.h"
#include "test_loi_commande_private.h"

/* Real-time model */
RT_MODEL_test_loi_commande_T test_loi_commande_M_;
RT_MODEL_test_loi_commande_T *const test_loi_commande_M = &test_loi_commande_M_;

/* Model step function */
void test_loi_commande_step(void)
{
  /* local block i/o variables */
  real32_T rtb_netsum;
  real32_T rtb_netsum1;
  real32_T rtb_netsum2;
  real32_T rtb_netsum3;
  real32_T rtb_ARDrone_Acc_Z;
  real32_T rtb_Gain;
  real32_T rtb_Gain1;

  /* Gain: '<Root>/Gain' incorporates:
   *  S-Function (ARDrone_Acc_X): '<S1>/ARDrone_Acc_X'
   */
  rtb_Gain = test_loi_commande_P.Gain_Gain * Accelero_Get_X();

  /* Gain: '<Root>/Gain1' incorporates:
   *  S-Function (ARDrone_Acc_Y): '<S1>/ARDrone_Acc_Y'
   */
  rtb_Gain1 = test_loi_commande_P.Gain1_Gain * Accelero_Get_Y();

  /* Sum: '<Root>/netsum' incorporates:
   *  Constant: '<Root>/Constant'
   */
  rtb_netsum = (rtb_Gain1 - rtb_Gain) + test_loi_commande_P.Constant_Value;

  /* S-Function (ARDrone_Motor): '<S2>/ARDrone_Motor' */
  Motor_Set( (real32_T)rtb_netsum, (uint8_T)test_loi_commande_P.ARDrone_Motor_p1);

  /* Sum: '<Root>/netsum1' incorporates:
   *  Constant: '<Root>/Constant'
   */
  rtb_netsum1 = (test_loi_commande_P.Constant_Value - rtb_Gain) - rtb_Gain1;

  /* S-Function (ARDrone_Motor): '<S2>/ARDrone_Motor1' */
  Motor_Set( (real32_T)rtb_netsum1, (uint8_T)
            test_loi_commande_P.ARDrone_Motor1_p1);

  /* Sum: '<Root>/netsum2' incorporates:
   *  Constant: '<Root>/Constant'
   */
  rtb_netsum2 = (rtb_Gain - rtb_Gain1) + test_loi_commande_P.Constant_Value;

  /* S-Function (ARDrone_Motor): '<S2>/ARDrone_Motor2' */
  Motor_Set( (real32_T)rtb_netsum2, (uint8_T)
            test_loi_commande_P.ARDrone_Motor2_p1);

  /* Sum: '<Root>/netsum3' incorporates:
   *  Constant: '<Root>/Constant'
   */
  rtb_netsum3 = (rtb_Gain + rtb_Gain1) + test_loi_commande_P.Constant_Value;

  /* S-Function (ARDrone_Motor): '<S2>/ARDrone_Motor3' */
  Motor_Set( (real32_T)rtb_netsum3, (uint8_T)
            test_loi_commande_P.ARDrone_Motor3_p1);

  /* S-Function (ARDrone_Acc_Z): '<S1>/ARDrone_Acc_Z' */
  rtb_ARDrone_Acc_Z = Accelero_Get_Z();
}

/* Model initialize function */
void test_loi_commande_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(test_loi_commande_M, (NULL));

  /* S-Function (ARDrone_Acc_X): <S1>/ARDrone_Acc_X */
  Accelero_Initialization();

  /* S-Function (ARDrone_Acc_Y): <S1>/ARDrone_Acc_Y */
  Accelero_Initialization();

  /* S-Function (ARDrone_Motor): <S2>/ARDrone_Motor */
  Motor_Initialization();

  /* S-Function (ARDrone_Motor): <S2>/ARDrone_Motor1 */
  Motor_Initialization();

  /* S-Function (ARDrone_Motor): <S2>/ARDrone_Motor2 */
  Motor_Initialization();

  /* S-Function (ARDrone_Motor): <S2>/ARDrone_Motor3 */
  Motor_Initialization();

  /* S-Function (ARDrone_Acc_Z): <S1>/ARDrone_Acc_Z */
  Accelero_Initialization();
}

/* Model terminate function */
void test_loi_commande_terminate(void)
{
  /* (no terminate code required) */
}

/* File trailer for generated code.
 *
 * [EOF]
 */
