/*
 * File: LedAccelerometre.h
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

#ifndef RTW_HEADER_LedAccelerometre_h_
#define RTW_HEADER_LedAccelerometre_h_
#ifndef LedAccelerometre_COMMON_INCLUDES_
# define LedAccelerometre_COMMON_INCLUDES_
#include <stddef.h>
#include "rtwtypes.h"
#include "accelero.h"
#include "led.h"
#endif                                 /* LedAccelerometre_COMMON_INCLUDES_ */

#include "LedAccelerometre_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Parameters (auto storage) */
struct P_LedAccelerometre_T_ {
  real32_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S4>/Constant'
                                        */
  real32_T Constant_Value_o;           /* Computed Parameter: Constant_Value_o
                                        * Referenced by: '<S5>/Constant'
                                        */
  uint8_T Constant_Value_d;            /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S2>/Constant'
                                        */
  uint8_T ARDrone_LED_p1;              /* Computed Parameter: ARDrone_LED_p1
                                        * Referenced by: '<S3>/ARDrone_LED'
                                        */
  uint8_T ARDrone_LED1_p1;             /* Computed Parameter: ARDrone_LED1_p1
                                        * Referenced by: '<S3>/ARDrone_LED1'
                                        */
  uint8_T ARDrone_LED2_p1;             /* Computed Parameter: ARDrone_LED2_p1
                                        * Referenced by: '<S3>/ARDrone_LED2'
                                        */
  uint8_T ARDrone_LED3_p1;             /* Computed Parameter: ARDrone_LED3_p1
                                        * Referenced by: '<S3>/ARDrone_LED3'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_LedAccelerometre_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
#ifdef __cplusplus

extern "C" {

#endif

  extern P_LedAccelerometre_T LedAccelerometre_P;

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  /* Model entry point functions */
  extern void LedAccelerometre_initialize(void);
  extern void LedAccelerometre_step(void);
  extern void LedAccelerometre_terminate(void);

#ifdef __cplusplus

}
#endif

/* Real-time Model object */
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_LedAccelerometre_T *const LedAccelerometre_M;

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
 * '<Root>' : 'LedAccelerometre'
 * '<S1>'   : 'LedAccelerometre/Accelerometer'
 * '<S2>'   : 'LedAccelerometre/LedWithMotor'
 * '<S3>'   : 'LedAccelerometre/Leds'
 * '<S4>'   : 'LedAccelerometre/LedWithMotor/Compare To Constant'
 * '<S5>'   : 'LedAccelerometre/LedWithMotor/Compare To Constant1'
 */
#endif                                 /* RTW_HEADER_LedAccelerometre_h_ */

/* File trailer for generated code.
 *
 * [EOF]
 */
