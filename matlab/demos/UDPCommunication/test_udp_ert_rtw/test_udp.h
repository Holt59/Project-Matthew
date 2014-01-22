/*
 * File: test_udp.h
 *
 * Code generated for Simulink model 'test_udp'.
 *
 * Model version                  : 1.52
 * Simulink Coder version         : 8.4 (R2013a) 13-Feb-2013
 * TLC version                    : 8.4 (Jan 18 2013)
 * C/C++ source code generated on : Wed Jan 22 22:55:51 2014
 *
 * Target selection: ardrone.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_test_udp_h_
#define RTW_HEADER_test_udp_h_
#ifndef test_udp_COMMON_INCLUDES_
# define test_udp_COMMON_INCLUDES_
#include <stddef.h>
#include <math.h>
#include "rtwtypes.h"
#include "udp_multi.h"
#include "led.h"
#include "motor.h"
#include "accelero.h"
#include "gyro.h"
#include "baro.h"
#include "magneto.h"
#include "height.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#endif                                 /* test_udp_COMMON_INCLUDES_ */

#include "test_udp_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Parameters (auto storage) */
struct P_test_udp_T_ {
  int32_T UDPM_Receive_Int32_p1;       /* Computed Parameter: UDPM_Receive_Int32_p1
                                        * Referenced by: '<S10>/UDPM_Receive_Int32'
                                        */
  int32_T UDPM_Receive_Int32_p1_b;     /* Computed Parameter: UDPM_Receive_Int32_p1_b
                                        * Referenced by: '<S12>/UDPM_Receive_Int32'
                                        */
  int32_T UDPM_Receive_Int32_p1_l;     /* Computed Parameter: UDPM_Receive_Int32_p1_l
                                        * Referenced by: '<S13>/UDPM_Receive_Int32'
                                        */
  int32_T UDPM_Receive_Int32_p1_l3;    /* Computed Parameter: UDPM_Receive_Int32_p1_l3
                                        * Referenced by: '<S14>/UDPM_Receive_Int32'
                                        */
  int32_T UDPM_Receive_Int32_p1_m;     /* Computed Parameter: UDPM_Receive_Int32_p1_m
                                        * Referenced by: '<S7>/UDPM_Receive_Int32'
                                        */
  int32_T UDPM_Send_Int32_p1;          /* Computed Parameter: UDPM_Send_Int32_p1
                                        * Referenced by: '<S7>/UDPM_Send_Int32'
                                        */
  int32_T UDPM_Receive_Int32_p1_c;     /* Computed Parameter: UDPM_Receive_Int32_p1_c
                                        * Referenced by: '<S8>/UDPM_Receive_Int32'
                                        */
  int32_T UDPM_Send_Int32_p1_d;        /* Computed Parameter: UDPM_Send_Int32_p1_d
                                        * Referenced by: '<S8>/UDPM_Send_Int32'
                                        */
  int32_T UDPM_Send_Int32_p1_g;        /* Computed Parameter: UDPM_Send_Int32_p1_g
                                        * Referenced by: '<S10>/UDPM_Send_Int32'
                                        */
  int32_T UDPM_Send_Int32_p1_gv;       /* Computed Parameter: UDPM_Send_Int32_p1_gv
                                        * Referenced by: '<S12>/UDPM_Send_Int32'
                                        */
  int32_T UDPM_Send_Int32_p1_m;        /* Computed Parameter: UDPM_Send_Int32_p1_m
                                        * Referenced by: '<S13>/UDPM_Send_Int32'
                                        */
  int32_T UDPM_Send_Int32_p1_n;        /* Computed Parameter: UDPM_Send_Int32_p1_n
                                        * Referenced by: '<S14>/UDPM_Send_Int32'
                                        */
  int32_T UDPM_Receive_Int32_p1_bv;    /* Computed Parameter: UDPM_Receive_Int32_p1_bv
                                        * Referenced by: '<S9>/UDPM_Receive_Int32'
                                        */
  int32_T UDPM_Send_Int32_p1_g1;       /* Computed Parameter: UDPM_Send_Int32_p1_g1
                                        * Referenced by: '<S9>/UDPM_Send_Int32'
                                        */
  int32_T UDPM_Receive_Int32_p1_o;     /* Computed Parameter: UDPM_Receive_Int32_p1_o
                                        * Referenced by: '<S18>/UDPM_Receive_Int32'
                                        */
  int32_T UDPM_Send_Int32_p1_mg;       /* Computed Parameter: UDPM_Send_Int32_p1_mg
                                        * Referenced by: '<S18>/UDPM_Send_Int32'
                                        */
  int32_T UDPM_Receive_Int32_p1_l4;    /* Computed Parameter: UDPM_Receive_Int32_p1_l4
                                        * Referenced by: '<S11>/UDPM_Receive_Int32'
                                        */
  int32_T UDPM_Send_Int32_p1_i;        /* Computed Parameter: UDPM_Send_Int32_p1_i
                                        * Referenced by: '<S11>/UDPM_Send_Int32'
                                        */
  int32_T UDPM_Receive_Int32_p1_k;     /* Computed Parameter: UDPM_Receive_Int32_p1_k
                                        * Referenced by: '<S15>/UDPM_Receive_Int32'
                                        */
  int32_T UDPM_Send_Int32_p1_m2;       /* Computed Parameter: UDPM_Send_Int32_p1_m2
                                        * Referenced by: '<S15>/UDPM_Send_Int32'
                                        */
  int32_T UDPM_Receive_Int32_p1_g;     /* Computed Parameter: UDPM_Receive_Int32_p1_g
                                        * Referenced by: '<S16>/UDPM_Receive_Int32'
                                        */
  int32_T UDPM_Send_Int32_p1_h;        /* Computed Parameter: UDPM_Send_Int32_p1_h
                                        * Referenced by: '<S16>/UDPM_Send_Int32'
                                        */
  int32_T UDPM_Receive_Int32_p1_c2;    /* Computed Parameter: UDPM_Receive_Int32_p1_c2
                                        * Referenced by: '<S17>/UDPM_Receive_Int32'
                                        */
  int32_T UDPM_Send_Int32_p1_gi;       /* Computed Parameter: UDPM_Send_Int32_p1_gi
                                        * Referenced by: '<S17>/UDPM_Send_Int32'
                                        */
  int8_T UDPM_Receive_Int32_p2;        /* Computed Parameter: UDPM_Receive_Int32_p2
                                        * Referenced by: '<S10>/UDPM_Receive_Int32'
                                        */
  int8_T UDPM_Receive_Int32_p2_d;      /* Computed Parameter: UDPM_Receive_Int32_p2_d
                                        * Referenced by: '<S12>/UDPM_Receive_Int32'
                                        */
  int8_T UDPM_Receive_Int32_p2_f;      /* Computed Parameter: UDPM_Receive_Int32_p2_f
                                        * Referenced by: '<S13>/UDPM_Receive_Int32'
                                        */
  int8_T UDPM_Receive_Int32_p2_p;      /* Computed Parameter: UDPM_Receive_Int32_p2_p
                                        * Referenced by: '<S14>/UDPM_Receive_Int32'
                                        */
  int8_T UDPM_Receive_Int32_p2_j;      /* Computed Parameter: UDPM_Receive_Int32_p2_j
                                        * Referenced by: '<S7>/UDPM_Receive_Int32'
                                        */
  int8_T UDPM_Send_Int32_p2;           /* Computed Parameter: UDPM_Send_Int32_p2
                                        * Referenced by: '<S7>/UDPM_Send_Int32'
                                        */
  int8_T UDPM_Receive_Int32_p2_m;      /* Computed Parameter: UDPM_Receive_Int32_p2_m
                                        * Referenced by: '<S8>/UDPM_Receive_Int32'
                                        */
  int8_T UDPM_Send_Int32_p2_j;         /* Computed Parameter: UDPM_Send_Int32_p2_j
                                        * Referenced by: '<S8>/UDPM_Send_Int32'
                                        */
  int8_T UDPM_Send_Int32_p2_h;         /* Computed Parameter: UDPM_Send_Int32_p2_h
                                        * Referenced by: '<S10>/UDPM_Send_Int32'
                                        */
  int8_T UDPM_Send_Int32_p2_p;         /* Computed Parameter: UDPM_Send_Int32_p2_p
                                        * Referenced by: '<S12>/UDPM_Send_Int32'
                                        */
  int8_T UDPM_Send_Int32_p2_i;         /* Computed Parameter: UDPM_Send_Int32_p2_i
                                        * Referenced by: '<S13>/UDPM_Send_Int32'
                                        */
  int8_T UDPM_Send_Int32_p2_js;        /* Computed Parameter: UDPM_Send_Int32_p2_js
                                        * Referenced by: '<S14>/UDPM_Send_Int32'
                                        */
  int8_T UDPM_Receive_Int32_p2_g;      /* Computed Parameter: UDPM_Receive_Int32_p2_g
                                        * Referenced by: '<S9>/UDPM_Receive_Int32'
                                        */
  int8_T UDPM_Send_Int32_p2_k;         /* Computed Parameter: UDPM_Send_Int32_p2_k
                                        * Referenced by: '<S9>/UDPM_Send_Int32'
                                        */
  int8_T UDPM_Receive_Int32_p2_c;      /* Computed Parameter: UDPM_Receive_Int32_p2_c
                                        * Referenced by: '<S18>/UDPM_Receive_Int32'
                                        */
  int8_T UDPM_Send_Int32_p2_o;         /* Computed Parameter: UDPM_Send_Int32_p2_o
                                        * Referenced by: '<S18>/UDPM_Send_Int32'
                                        */
  int8_T UDPM_Receive_Int32_p2_a;      /* Computed Parameter: UDPM_Receive_Int32_p2_a
                                        * Referenced by: '<S11>/UDPM_Receive_Int32'
                                        */
  int8_T UDPM_Send_Int32_p2_oz;        /* Computed Parameter: UDPM_Send_Int32_p2_oz
                                        * Referenced by: '<S11>/UDPM_Send_Int32'
                                        */
  int8_T UDPM_Receive_Int32_p2_gb;     /* Computed Parameter: UDPM_Receive_Int32_p2_gb
                                        * Referenced by: '<S15>/UDPM_Receive_Int32'
                                        */
  int8_T UDPM_Send_Int32_p2_n;         /* Computed Parameter: UDPM_Send_Int32_p2_n
                                        * Referenced by: '<S15>/UDPM_Send_Int32'
                                        */
  int8_T UDPM_Receive_Int32_p2_dn;     /* Computed Parameter: UDPM_Receive_Int32_p2_dn
                                        * Referenced by: '<S16>/UDPM_Receive_Int32'
                                        */
  int8_T UDPM_Send_Int32_p2_d;         /* Computed Parameter: UDPM_Send_Int32_p2_d
                                        * Referenced by: '<S16>/UDPM_Send_Int32'
                                        */
  int8_T UDPM_Receive_Int32_p2_pv;     /* Computed Parameter: UDPM_Receive_Int32_p2_pv
                                        * Referenced by: '<S17>/UDPM_Receive_Int32'
                                        */
  int8_T UDPM_Send_Int32_p2_kb;        /* Computed Parameter: UDPM_Send_Int32_p2_kb
                                        * Referenced by: '<S17>/UDPM_Send_Int32'
                                        */
  uint8_T ARDrone_LED_p1;              /* Computed Parameter: ARDrone_LED_p1
                                        * Referenced by: '<S4>/ARDrone_LED'
                                        */
  uint8_T ARDrone_LED1_p1;             /* Computed Parameter: ARDrone_LED1_p1
                                        * Referenced by: '<S4>/ARDrone_LED1'
                                        */
  uint8_T ARDrone_LED2_p1;             /* Computed Parameter: ARDrone_LED2_p1
                                        * Referenced by: '<S4>/ARDrone_LED2'
                                        */
  uint8_T ARDrone_LED3_p1;             /* Computed Parameter: ARDrone_LED3_p1
                                        * Referenced by: '<S4>/ARDrone_LED3'
                                        */
  uint8_T ARDrone_Motor_p1;            /* Computed Parameter: ARDrone_Motor_p1
                                        * Referenced by: '<S6>/ARDrone_Motor'
                                        */
  uint8_T ARDrone_Motor1_p1;           /* Computed Parameter: ARDrone_Motor1_p1
                                        * Referenced by: '<S6>/ARDrone_Motor1'
                                        */
  uint8_T ARDrone_Motor2_p1;           /* Computed Parameter: ARDrone_Motor2_p1
                                        * Referenced by: '<S6>/ARDrone_Motor2'
                                        */
  uint8_T ARDrone_Motor3_p1;           /* Computed Parameter: ARDrone_Motor3_p1
                                        * Referenced by: '<S6>/ARDrone_Motor3'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_test_udp_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
#ifdef __cplusplus

extern "C" {

#endif

  extern P_test_udp_T test_udp_P;

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  /* Model entry point functions */
  extern void test_udp_initialize(void);
  extern void test_udp_step(void);
  extern void test_udp_terminate(void);

#ifdef __cplusplus

}
#endif

/* Real-time Model object */
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_test_udp_T *const test_udp_M;

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
 * '<Root>' : 'test_udp'
 * '<S1>'   : 'test_udp/Accelerometer'
 * '<S2>'   : 'test_udp/Barometer'
 * '<S3>'   : 'test_udp/Gyroscope'
 * '<S4>'   : 'test_udp/Leds'
 * '<S5>'   : 'test_udp/Magnetometer'
 * '<S6>'   : 'test_udp/Motors'
 * '<S7>'   : 'test_udp/UDP Multi'
 * '<S8>'   : 'test_udp/UDP Multi1'
 * '<S9>'   : 'test_udp/UDP Multi10'
 * '<S10>'  : 'test_udp/UDP Multi11'
 * '<S11>'  : 'test_udp/UDP Multi2'
 * '<S12>'  : 'test_udp/UDP Multi3'
 * '<S13>'  : 'test_udp/UDP Multi4'
 * '<S14>'  : 'test_udp/UDP Multi5'
 * '<S15>'  : 'test_udp/UDP Multi6'
 * '<S16>'  : 'test_udp/UDP Multi7'
 * '<S17>'  : 'test_udp/UDP Multi8'
 * '<S18>'  : 'test_udp/UDP Multi9'
 */
#endif                                 /* RTW_HEADER_test_udp_h_ */

/* File trailer for generated code.
 *
 * [EOF]
 */
