/*
 * File: test_leds.h
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

#ifndef RTW_HEADER_test_leds_h_
#define RTW_HEADER_test_leds_h_
#ifndef test_leds_COMMON_INCLUDES_
# define test_leds_COMMON_INCLUDES_
#include <stddef.h>
#include <math.h>
#include <string.h>
#include "rtwtypes.h"
#include "print2file.h"
#include "led.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#endif                                 /* test_leds_COMMON_INCLUDES_ */

#include "test_leds_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator3' */
  int32_T clockTickCounter_e;          /* '<Root>/Pulse Generator' */
  int32_T clockTickCounter_a;          /* '<Root>/Pulse Generator1' */
  int32_T clockTickCounter_h;          /* '<Root>/Pulse Generator2' */
} DW_test_leds_T;

/* Parameters (auto storage) */
struct P_test_leds_T_ {
  real_T PulseGenerator3_Amp;          /* Expression: 2
                                        * Referenced by: '<Root>/Pulse Generator3'
                                        */
  real_T PulseGenerator3_Period;       /* Computed Parameter: PulseGenerator3_Period
                                        * Referenced by: '<Root>/Pulse Generator3'
                                        */
  real_T PulseGenerator3_Duty;         /* Computed Parameter: PulseGenerator3_Duty
                                        * Referenced by: '<Root>/Pulse Generator3'
                                        */
  real_T PulseGenerator3_PhaseDelay;   /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator3'
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
  real_T PulseGenerator1_Amp;          /* Expression: 2
                                        * Referenced by: '<Root>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Period;       /* Computed Parameter: PulseGenerator1_Period
                                        * Referenced by: '<Root>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Duty;         /* Computed Parameter: PulseGenerator1_Duty
                                        * Referenced by: '<Root>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_PhaseDelay;   /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator1'
                                        */
  real_T PulseGenerator2_Amp;          /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator2'
                                        */
  real_T PulseGenerator2_Period;       /* Computed Parameter: PulseGenerator2_Period
                                        * Referenced by: '<Root>/Pulse Generator2'
                                        */
  real_T PulseGenerator2_Duty;         /* Computed Parameter: PulseGenerator2_Duty
                                        * Referenced by: '<Root>/Pulse Generator2'
                                        */
  real_T PulseGenerator2_PhaseDelay;   /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator2'
                                        */
  uint8_T ARDrone_PRINT2FILE_p1[8];    /* Expression: SParameter1
                                        * Referenced by: '<Root>/ARDrone_PRINT2FILE'
                                        */
  uint8_T ARDrone_LED_p1;              /* Computed Parameter: ARDrone_LED_p1
                                        * Referenced by: '<S1>/ARDrone_LED'
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
};

/* Real-time Model Data Structure */
struct tag_RTM_test_leds_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_test_leds_T test_leds_P;

/* Block states (auto storage) */
extern DW_test_leds_T test_leds_DW;

/* Model entry point functions */
extern void test_leds_initialize(void);
extern void test_leds_step(void);
extern void test_leds_terminate(void);

/* Real-time Model object */
extern RT_MODEL_test_leds_T *const test_leds_M;

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
 * '<Root>' : 'test_leds'
 * '<S1>'   : 'test_leds/LEDS'
 */
#endif                                 /* RTW_HEADER_test_leds_h_ */

/* File trailer for generated code.
 *
 * [EOF]
 */
