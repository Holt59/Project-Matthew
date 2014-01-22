/*
 * File: test_udp.h
 *
 * Code generated for Simulink model 'test_udp'.
 *
 * Model version                  : 1.26
 * Simulink Coder version         : 8.4 (R2013a) 13-Feb-2013
 * TLC version                    : 8.4 (Jan 18 2013)
 * C/C++ source code generated on : Wed Jan 22 14:37:21 2014
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
#include "ahrs.h"
#include "udp.h"
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
  int32_T UDP_Receive_Int1_p1;         /* Computed Parameter: UDP_Receive_Int1_p1
                                        * Referenced by: '<S2>/UDP_Receive_Int1'
                                        */
  int32_T UDP_Send_Int32_p1;           /* Computed Parameter: UDP_Send_Int32_p1
                                        * Referenced by: '<S2>/UDP_Send_Int32'
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
 * '<S1>'   : 'test_udp/Euler Angles'
 * '<S2>'   : 'test_udp/UDP'
 */
#endif                                 /* RTW_HEADER_test_udp_h_ */

/* File trailer for generated code.
 *
 * [EOF]
 */
