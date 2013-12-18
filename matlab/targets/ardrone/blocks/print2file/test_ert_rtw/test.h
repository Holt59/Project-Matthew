/*
 * File: test.h
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

#ifndef RTW_HEADER_test_h_
#define RTW_HEADER_test_h_
#ifndef test_COMMON_INCLUDES_
# define test_COMMON_INCLUDES_
#include <stddef.h>
#include <math.h>
#include <string.h>
#include "rtwtypes.h"
#include "motor.h"
#include "led.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#endif                                 /* test_COMMON_INCLUDES_ */

#include "test_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
} DW_test_T;

/* Parameters (auto storage) */
struct P_test_T_ {
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;        /* Computed Parameter: PulseGenerator_Period
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty;          /* Computed Parameter: PulseGenerator_Duty
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator'
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
  uint8_T ARDrone_LED1_p1;             /* Computed Parameter: ARDrone_LED1_p1
                                        * Referenced by: '<S1>/ARDrone_LED1'
                                        */
  uint8_T ARDrone_LED2_p1;             /* Computed Parameter: ARDrone_LED2_p1
                                        * Referenced by: '<S1>/ARDrone_LED2'
                                        */
  uint8_T ARDrone_LED3_p1;             /* Computed Parameter: ARDrone_LED3_p1
                                        * Referenced by: '<S1>/ARDrone_LED3'
                                        */
  uint8_T ARDrone_LED4_p1;             /* Computed Parameter: ARDrone_LED4_p1
                                        * Referenced by: '<S1>/ARDrone_LED4'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_test_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
#ifdef __cplusplus

extern "C" {

#endif

  extern P_test_T test_P;

#ifdef __cplusplus

}
#endif

/* Block states (auto storage) */
extern DW_test_T test_DW;

#ifdef __cplusplus

extern "C" {

#endif

  /* Model entry point functions */
  extern void test_initialize(void);
  extern void test_step(void);
  extern void test_terminate(void);

#ifdef __cplusplus

}
#endif

/* Real-time Model object */
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_test_T *const test_M;

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
 * '<Root>' : 'test'
 * '<S1>'   : 'test/LEDS'
 * '<S2>'   : 'test/MOTORS'
 */
#endif                                 /* RTW_HEADER_test_h_ */

/* File trailer for generated code.
 *
 * [EOF]
 */
