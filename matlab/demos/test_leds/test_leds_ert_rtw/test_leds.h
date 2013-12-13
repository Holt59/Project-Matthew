/*
 * File: test_leds.h
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

#ifndef RTW_HEADER_test_leds_h_
#define RTW_HEADER_test_leds_h_
#ifndef test_leds_COMMON_INCLUDES_
# define test_leds_COMMON_INCLUDES_
#include <stddef.h>
#include <string.h>
#include "rtwtypes.h"
#include "led.h"
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
  int32_T clockTickCounter;            /* '<S6>/Pulse Generator' */
  int32_T clockTickCounter_f;          /* '<S6>/Pulse Generator1' */
  int32_T clockTickCounter_g;          /* '<S6>/Pulse Generator2' */
  int32_T clockTickCounter_e;          /* '<S6>/Pulse Generator3' */
  int32_T clockTickCounter_gm;         /* '<S7>/Pulse Generator' */
  int32_T clockTickCounter_k;          /* '<S7>/Pulse Generator1' */
  int32_T clockTickCounter_c;          /* '<S7>/Pulse Generator2' */
  int32_T clockTickCounter_gr;         /* '<S7>/Pulse Generator3' */
  int32_T clockTickCounter_j;          /* '<S8>/Pulse Generator' */
  int32_T clockTickCounter_kn;         /* '<S8>/Pulse Generator1' */
  int32_T clockTickCounter_f0;         /* '<S8>/Pulse Generator2' */
  int32_T clockTickCounter_jh;         /* '<S8>/Pulse Generator3' */
  int32_T clockTickCounter_gh;         /* '<S9>/Pulse Generator' */
  int32_T clockTickCounter_kh;         /* '<S9>/Pulse Generator1' */
  int32_T clockTickCounter_b;          /* '<S9>/Pulse Generator2' */
  int32_T clockTickCounter_p;          /* '<S9>/Pulse Generator3' */
} DW_test_leds_T;

/* Parameters (auto storage) */
struct P_test_leds_T_ {
  real_T PulseGenerator_Period;        /* Computed Parameter: PulseGenerator_Period
                                        * Referenced by: '<S6>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty;          /* Computed Parameter: PulseGenerator_Duty
                                        * Referenced by: '<S6>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0*periode
                                        * Referenced by: '<S6>/Pulse Generator'
                                        */
  real_T PulseGenerator1_Period;       /* Computed Parameter: PulseGenerator1_Period
                                        * Referenced by: '<S6>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Duty;         /* Computed Parameter: PulseGenerator1_Duty
                                        * Referenced by: '<S6>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_PhaseDelay;   /* Expression: 1*periode
                                        * Referenced by: '<S6>/Pulse Generator1'
                                        */
  real_T PulseGenerator2_Period;       /* Computed Parameter: PulseGenerator2_Period
                                        * Referenced by: '<S6>/Pulse Generator2'
                                        */
  real_T PulseGenerator2_Duty;         /* Computed Parameter: PulseGenerator2_Duty
                                        * Referenced by: '<S6>/Pulse Generator2'
                                        */
  real_T PulseGenerator2_PhaseDelay;   /* Expression: 3*periode
                                        * Referenced by: '<S6>/Pulse Generator2'
                                        */
  real_T PulseGenerator3_Period;       /* Computed Parameter: PulseGenerator3_Period
                                        * Referenced by: '<S6>/Pulse Generator3'
                                        */
  real_T PulseGenerator3_Duty;         /* Computed Parameter: PulseGenerator3_Duty
                                        * Referenced by: '<S6>/Pulse Generator3'
                                        */
  real_T PulseGenerator3_PhaseDelay;   /* Expression: 2*periode
                                        * Referenced by: '<S6>/Pulse Generator3'
                                        */
  real_T PulseGenerator_Period_h;      /* Computed Parameter: PulseGenerator_Period_h
                                        * Referenced by: '<S7>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty_m;        /* Computed Parameter: PulseGenerator_Duty_m
                                        * Referenced by: '<S7>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay_e;  /* Expression: 0*periode
                                        * Referenced by: '<S7>/Pulse Generator'
                                        */
  real_T PulseGenerator1_Period_o;     /* Computed Parameter: PulseGenerator1_Period_o
                                        * Referenced by: '<S7>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Duty_n;       /* Computed Parameter: PulseGenerator1_Duty_n
                                        * Referenced by: '<S7>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_PhaseDelay_m; /* Expression: 1*periode
                                        * Referenced by: '<S7>/Pulse Generator1'
                                        */
  real_T PulseGenerator2_Period_o;     /* Computed Parameter: PulseGenerator2_Period_o
                                        * Referenced by: '<S7>/Pulse Generator2'
                                        */
  real_T PulseGenerator2_Duty_c;       /* Computed Parameter: PulseGenerator2_Duty_c
                                        * Referenced by: '<S7>/Pulse Generator2'
                                        */
  real_T PulseGenerator2_PhaseDelay_i; /* Expression: 3*periode
                                        * Referenced by: '<S7>/Pulse Generator2'
                                        */
  real_T PulseGenerator3_Period_c;     /* Computed Parameter: PulseGenerator3_Period_c
                                        * Referenced by: '<S7>/Pulse Generator3'
                                        */
  real_T PulseGenerator3_Duty_c;       /* Computed Parameter: PulseGenerator3_Duty_c
                                        * Referenced by: '<S7>/Pulse Generator3'
                                        */
  real_T PulseGenerator3_PhaseDelay_c; /* Expression: 2*periode
                                        * Referenced by: '<S7>/Pulse Generator3'
                                        */
  real_T PulseGenerator_Period_b;      /* Computed Parameter: PulseGenerator_Period_b
                                        * Referenced by: '<S8>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty_m4;       /* Computed Parameter: PulseGenerator_Duty_m4
                                        * Referenced by: '<S8>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay_a;  /* Expression: 0*periode
                                        * Referenced by: '<S8>/Pulse Generator'
                                        */
  real_T PulseGenerator1_Period_l;     /* Computed Parameter: PulseGenerator1_Period_l
                                        * Referenced by: '<S8>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Duty_c;       /* Computed Parameter: PulseGenerator1_Duty_c
                                        * Referenced by: '<S8>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_PhaseDelay_a; /* Expression: 1*periode
                                        * Referenced by: '<S8>/Pulse Generator1'
                                        */
  real_T PulseGenerator2_Period_os;    /* Computed Parameter: PulseGenerator2_Period_os
                                        * Referenced by: '<S8>/Pulse Generator2'
                                        */
  real_T PulseGenerator2_Duty_m;       /* Computed Parameter: PulseGenerator2_Duty_m
                                        * Referenced by: '<S8>/Pulse Generator2'
                                        */
  real_T PulseGenerator2_PhaseDelay_m; /* Expression: 3*periode
                                        * Referenced by: '<S8>/Pulse Generator2'
                                        */
  real_T PulseGenerator3_Period_p;     /* Computed Parameter: PulseGenerator3_Period_p
                                        * Referenced by: '<S8>/Pulse Generator3'
                                        */
  real_T PulseGenerator3_Duty_j;       /* Computed Parameter: PulseGenerator3_Duty_j
                                        * Referenced by: '<S8>/Pulse Generator3'
                                        */
  real_T PulseGenerator3_PhaseDelay_l; /* Expression: 2*periode
                                        * Referenced by: '<S8>/Pulse Generator3'
                                        */
  real_T PulseGenerator_Period_bq;     /* Computed Parameter: PulseGenerator_Period_bq
                                        * Referenced by: '<S9>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty_h;        /* Computed Parameter: PulseGenerator_Duty_h
                                        * Referenced by: '<S9>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay_c;  /* Expression: 0*periode
                                        * Referenced by: '<S9>/Pulse Generator'
                                        */
  real_T PulseGenerator1_Period_c;     /* Computed Parameter: PulseGenerator1_Period_c
                                        * Referenced by: '<S9>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Duty_j;       /* Computed Parameter: PulseGenerator1_Duty_j
                                        * Referenced by: '<S9>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_PhaseDelay_mg;/* Expression: 1*periode
                                        * Referenced by: '<S9>/Pulse Generator1'
                                        */
  real_T PulseGenerator2_Period_p;     /* Computed Parameter: PulseGenerator2_Period_p
                                        * Referenced by: '<S9>/Pulse Generator2'
                                        */
  real_T PulseGenerator2_Duty_j;       /* Computed Parameter: PulseGenerator2_Duty_j
                                        * Referenced by: '<S9>/Pulse Generator2'
                                        */
  real_T PulseGenerator2_PhaseDelay_c; /* Expression: 3*periode
                                        * Referenced by: '<S9>/Pulse Generator2'
                                        */
  real_T PulseGenerator3_Period_b;     /* Computed Parameter: PulseGenerator3_Period_b
                                        * Referenced by: '<S9>/Pulse Generator3'
                                        */
  real_T PulseGenerator3_Duty_m;       /* Computed Parameter: PulseGenerator3_Duty_m
                                        * Referenced by: '<S9>/Pulse Generator3'
                                        */
  real_T PulseGenerator3_PhaseDelay_g; /* Expression: 2*periode
                                        * Referenced by: '<S9>/Pulse Generator3'
                                        */
  int32_T PulseGenerator_Amp;          /* Expression: amplitude0
                                        * Referenced by: '<S6>/Pulse Generator'
                                        */
  int32_T PulseGenerator1_Amp;         /* Expression: amplitude1
                                        * Referenced by: '<S6>/Pulse Generator1'
                                        */
  int32_T PulseGenerator2_Amp;         /* Expression: amplitude3
                                        * Referenced by: '<S6>/Pulse Generator2'
                                        */
  int32_T PulseGenerator3_Amp;         /* Expression: amplitude2
                                        * Referenced by: '<S6>/Pulse Generator3'
                                        */
  int32_T PulseGenerator_Amp_k;        /* Expression: amplitude1
                                        * Referenced by: '<S7>/Pulse Generator'
                                        */
  int32_T PulseGenerator1_Amp_p;       /* Expression: amplitude2
                                        * Referenced by: '<S7>/Pulse Generator1'
                                        */
  int32_T PulseGenerator2_Amp_j;       /* Expression: amplitude0
                                        * Referenced by: '<S7>/Pulse Generator2'
                                        */
  int32_T PulseGenerator3_Amp_c;       /* Expression: amplitude3
                                        * Referenced by: '<S7>/Pulse Generator3'
                                        */
  int32_T PulseGenerator_Amp_c;        /* Expression: amplitude2
                                        * Referenced by: '<S8>/Pulse Generator'
                                        */
  int32_T PulseGenerator1_Amp_l;       /* Expression: amplitude3
                                        * Referenced by: '<S8>/Pulse Generator1'
                                        */
  int32_T PulseGenerator2_Amp_k;       /* Expression: amplitude1
                                        * Referenced by: '<S8>/Pulse Generator2'
                                        */
  int32_T PulseGenerator3_Amp_n;       /* Expression: amplitude0
                                        * Referenced by: '<S8>/Pulse Generator3'
                                        */
  int32_T PulseGenerator_Amp_k2;       /* Expression: amplitude3
                                        * Referenced by: '<S9>/Pulse Generator'
                                        */
  int32_T PulseGenerator1_Amp_d;       /* Expression: amplitude0
                                        * Referenced by: '<S9>/Pulse Generator1'
                                        */
  int32_T PulseGenerator2_Amp_i;       /* Expression: amplitude2
                                        * Referenced by: '<S9>/Pulse Generator2'
                                        */
  int32_T PulseGenerator3_Amp_e;       /* Expression: amplitude1
                                        * Referenced by: '<S9>/Pulse Generator3'
                                        */
  uint8_T ARDrone_LED_p1;              /* Computed Parameter: ARDrone_LED_p1
                                        * Referenced by: '<Root>/ARDrone_LED'
                                        */
  uint8_T ARDrone_LED1_p1;             /* Computed Parameter: ARDrone_LED1_p1
                                        * Referenced by: '<Root>/ARDrone_LED1'
                                        */
  uint8_T ARDrone_LED2_p1;             /* Computed Parameter: ARDrone_LED2_p1
                                        * Referenced by: '<Root>/ARDrone_LED2'
                                        */
  uint8_T ARDrone_LED3_p1;             /* Computed Parameter: ARDrone_LED3_p1
                                        * Referenced by: '<Root>/ARDrone_LED3'
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
 * '<S1>'   : 'test_leds/Led_blinking'
 * '<S2>'   : 'test_leds/Led_blinking/Subsystem1'
 * '<S3>'   : 'test_leds/Led_blinking/Subsystem2'
 * '<S4>'   : 'test_leds/Led_blinking/Subsystem3'
 * '<S5>'   : 'test_leds/Led_blinking/Subsystem4'
 * '<S6>'   : 'test_leds/Led_blinking/Subsystem1/Subsystem'
 * '<S7>'   : 'test_leds/Led_blinking/Subsystem2/Subsystem'
 * '<S8>'   : 'test_leds/Led_blinking/Subsystem3/Subsystem'
 * '<S9>'   : 'test_leds/Led_blinking/Subsystem4/Subsystem'
 */
#endif                                 /* RTW_HEADER_test_leds_h_ */

/* File trailer for generated code.
 *
 * [EOF]
 */
