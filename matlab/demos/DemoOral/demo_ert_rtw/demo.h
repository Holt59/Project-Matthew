/*
 * File: demo.h
 *
 * Code generated for Simulink model 'demo'.
 *
 * Model version                  : 1.19
 * Simulink Coder version         : 8.4 (R2013a) 13-Feb-2013
 * TLC version                    : 8.4 (Jan 18 2013)
 * C/C++ source code generated on : Wed Jan 22 14:10:36 2014
 *
 * Target selection: ardrone.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_demo_h_
#define RTW_HEADER_demo_h_
#ifndef demo_COMMON_INCLUDES_
# define demo_COMMON_INCLUDES_
#include <stddef.h>
#include "rtwtypes.h"
#include "height.h"
#include "led.h"
#include "udp.h"
#include "motor.h"
#endif                                 /* demo_COMMON_INCLUDES_ */

#include "demo_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Parameters (auto storage) */
struct P_demo_T_ {
  int32_T Constant3_Value;             /* Expression: int32(3)
                                        * Referenced by: '<S1>/Constant3'
                                        */
  int32_T Constant2_Value;             /* Expression: int32(2)
                                        * Referenced by: '<S1>/Constant2'
                                        */
  int32_T Constant1_Value;             /* Expression: int32(1)
                                        * Referenced by: '<S1>/Constant1'
                                        */
  int32_T Constant_Value;              /* Expression: int32(0)
                                        * Referenced by: '<S1>/Constant'
                                        */
  int32_T UDP_Receive_Int1_p1;         /* Computed Parameter: UDP_Receive_Int1_p1
                                        * Referenced by: '<S4>/UDP_Receive_Int1'
                                        */
  int32_T UDP_Send_Int32_p1;           /* Computed Parameter: UDP_Send_Int32_p1
                                        * Referenced by: '<S4>/UDP_Send_Int32'
                                        */
  uint8_T ARDrone_LED_p1;              /* Computed Parameter: ARDrone_LED_p1
                                        * Referenced by: '<S2>/ARDrone_LED'
                                        */
  uint8_T ARDrone_LED1_p1;             /* Computed Parameter: ARDrone_LED1_p1
                                        * Referenced by: '<S2>/ARDrone_LED1'
                                        */
  uint8_T ARDrone_LED2_p1;             /* Computed Parameter: ARDrone_LED2_p1
                                        * Referenced by: '<S2>/ARDrone_LED2'
                                        */
  uint8_T ARDrone_LED3_p1;             /* Computed Parameter: ARDrone_LED3_p1
                                        * Referenced by: '<S2>/ARDrone_LED3'
                                        */
  uint8_T ARDrone_Motor_p1;            /* Computed Parameter: ARDrone_Motor_p1
                                        * Referenced by: '<S3>/ARDrone_Motor'
                                        */
  uint8_T ARDrone_Motor1_p1;           /* Computed Parameter: ARDrone_Motor1_p1
                                        * Referenced by: '<S3>/ARDrone_Motor1'
                                        */
  uint8_T ARDrone_Motor2_p1;           /* Computed Parameter: ARDrone_Motor2_p1
                                        * Referenced by: '<S3>/ARDrone_Motor2'
                                        */
  uint8_T ARDrone_Motor3_p1;           /* Computed Parameter: ARDrone_Motor3_p1
                                        * Referenced by: '<S3>/ARDrone_Motor3'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_demo_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
#ifdef __cplusplus

extern "C" {

#endif

  extern P_demo_T demo_P;

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  /* Model entry point functions */
  extern void demo_initialize(void);
  extern void demo_step(void);
  extern void demo_terminate(void);

#ifdef __cplusplus

}
#endif

/* Real-time Model object */
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_demo_T *const demo_M;

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
 * '<Root>' : 'demo'
 * '<S1>'   : 'demo/LedWithMotor'
 * '<S2>'   : 'demo/Leds'
 * '<S3>'   : 'demo/Motors'
 * '<S4>'   : 'demo/UDP'
 */
#endif                                 /* RTW_HEADER_demo_h_ */

/* File trailer for generated code.
 *
 * [EOF]
 */
