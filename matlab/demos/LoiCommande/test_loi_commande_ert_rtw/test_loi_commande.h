/*
 * File: test_loi_commande.h
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

#ifndef RTW_HEADER_test_loi_commande_h_
#define RTW_HEADER_test_loi_commande_h_
#ifndef test_loi_commande_COMMON_INCLUDES_
# define test_loi_commande_COMMON_INCLUDES_
#include <stddef.h>
#include "rtwtypes.h"
#include "accelero.h"
#include "motor.h"
#endif                                 /* test_loi_commande_COMMON_INCLUDES_ */

#include "test_loi_commande_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Parameters (auto storage) */
struct P_test_loi_commande_T_ {
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<Root>/Gain'
                                        */
  real32_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real32_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<Root>/Constant'
                                        */
  uint8_T ARDrone_Motor_p1;            /* Computed Parameter: ARDrone_Motor_p1
                                        * Referenced by: '<S2>/ARDrone_Motor'
                                        */
  uint8_T ARDrone_Motor1_p1;           /* Computed Parameter: ARDrone_Motor1_p1
                                        * Referenced by: '<S2>/ARDrone_Motor1'
                                        */
  uint8_T ARDrone_Motor2_p1;           /* Computed Parameter: ARDrone_Motor2_p1
                                        * Referenced by: '<S2>/ARDrone_Motor2'
                                        */
  uint8_T ARDrone_Motor3_p1;           /* Computed Parameter: ARDrone_Motor3_p1
                                        * Referenced by: '<S2>/ARDrone_Motor3'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_test_loi_commande_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
#ifdef __cplusplus

extern "C" {

#endif

  extern P_test_loi_commande_T test_loi_commande_P;

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  /* Model entry point functions */
  extern void test_loi_commande_initialize(void);
  extern void test_loi_commande_step(void);
  extern void test_loi_commande_terminate(void);

#ifdef __cplusplus

}
#endif

/* Real-time Model object */
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_test_loi_commande_T *const test_loi_commande_M;

#ifdef __cplusplus

}
#endif

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'test_loi_commande'
 * '<S1>'   : 'test_loi_commande/Accelerometer'
 * '<S2>'   : 'test_loi_commande/Motors'
 */
#endif                                 /* RTW_HEADER_test_loi_commande_h_ */

/* File trailer for generated code.
 *
 * [EOF]
 */
