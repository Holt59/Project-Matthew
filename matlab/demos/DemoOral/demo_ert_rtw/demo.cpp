/*
 * File: demo.cpp
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

#include "demo.h"
#include "demo_private.h"

/* Real-time model */
RT_MODEL_demo_T demo_M_;
RT_MODEL_demo_T *const demo_M = &demo_M_;

/* Model step function */
void demo_step(void)
{
  /* local block i/o variables */
  real32_T rtb_DataTypeConversion3;
  int32_T rtb_UDP_Receive_Int1;
  int8_T rtb_DataTypeConversion3_o;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  boolean_T guard4 = FALSE;

  /* MultiPortSwitch: '<S1>/Multiport Switch' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/Constant2'
   *  Constant: '<S1>/Constant3'
   *  S-Function (ARDrone_Height): '<Root>/Height'
   */
  guard1 = FALSE;
  guard2 = FALSE;
  guard3 = FALSE;
  guard4 = FALSE;
  switch (((int16_T)Height_Get())) {
   case 0:
    guard1 = TRUE;
    break;

   case 1:
    guard1 = TRUE;
    break;

   case 2:
    guard1 = TRUE;
    break;

   case 3:
    guard1 = TRUE;
    break;

   case 4:
    guard1 = TRUE;
    break;

   case 5:
    guard1 = TRUE;
    break;

   case 6:
    guard1 = TRUE;
    break;

   case 7:
    guard1 = TRUE;
    break;

   case 8:
    guard1 = TRUE;
    break;

   case 9:
    guard1 = TRUE;
    break;

   case 10:
    guard1 = TRUE;
    break;

   case 11:
    guard1 = TRUE;
    break;

   case 12:
    guard1 = TRUE;
    break;

   case 13:
    guard1 = TRUE;
    break;

   case 14:
    guard1 = TRUE;
    break;

   case 15:
    guard1 = TRUE;
    break;

   case 16:
    guard1 = TRUE;
    break;

   case 17:
    guard1 = TRUE;
    break;

   case 18:
    guard1 = TRUE;
    break;

   case 19:
    guard1 = TRUE;
    break;

   case 20:
    guard1 = TRUE;
    break;

   case 21:
    guard1 = TRUE;
    break;

   case 22:
    guard1 = TRUE;
    break;

   case 23:
    guard1 = TRUE;
    break;

   case 24:
    guard1 = TRUE;
    break;

   case 25:
    guard1 = TRUE;
    break;

   case 26:
    guard2 = TRUE;
    break;

   case 27:
    guard2 = TRUE;
    break;

   case 28:
    guard2 = TRUE;
    break;

   case 29:
    guard2 = TRUE;
    break;

   case 30:
    guard2 = TRUE;
    break;

   case 31:
    guard2 = TRUE;
    break;

   case 32:
    guard2 = TRUE;
    break;

   case 33:
    guard2 = TRUE;
    break;

   case 34:
    guard2 = TRUE;
    break;

   case 35:
    guard2 = TRUE;
    break;

   case 36:
    guard2 = TRUE;
    break;

   case 37:
    guard2 = TRUE;
    break;

   case 38:
    guard2 = TRUE;
    break;

   case 39:
    guard2 = TRUE;
    break;

   case 40:
    guard2 = TRUE;
    break;

   case 41:
    guard2 = TRUE;
    break;

   case 42:
    guard2 = TRUE;
    break;

   case 43:
    guard2 = TRUE;
    break;

   case 44:
    guard2 = TRUE;
    break;

   case 45:
    guard2 = TRUE;
    break;

   case 46:
    guard2 = TRUE;
    break;

   case 47:
    guard2 = TRUE;
    break;

   case 48:
    guard2 = TRUE;
    break;

   case 49:
    guard2 = TRUE;
    break;

   case 50:
    guard2 = TRUE;
    break;

   case 51:
    guard3 = TRUE;
    break;

   case 52:
    guard3 = TRUE;
    break;

   case 53:
    guard3 = TRUE;
    break;

   case 54:
    guard3 = TRUE;
    break;

   case 55:
    guard3 = TRUE;
    break;

   case 56:
    guard3 = TRUE;
    break;

   case 57:
    guard3 = TRUE;
    break;

   case 58:
    guard3 = TRUE;
    break;

   case 59:
    guard3 = TRUE;
    break;

   case 60:
    guard3 = TRUE;
    break;

   case 61:
    guard3 = TRUE;
    break;

   case 62:
    guard3 = TRUE;
    break;

   case 63:
    guard3 = TRUE;
    break;

   case 64:
    guard3 = TRUE;
    break;

   case 65:
    guard3 = TRUE;
    break;

   case 66:
    guard3 = TRUE;
    break;

   case 67:
    guard3 = TRUE;
    break;

   case 68:
    guard3 = TRUE;
    break;

   case 69:
    guard3 = TRUE;
    break;

   case 70:
    guard3 = TRUE;
    break;

   case 71:
    guard3 = TRUE;
    break;

   case 72:
    guard3 = TRUE;
    break;

   case 73:
    guard3 = TRUE;
    break;

   case 74:
    guard3 = TRUE;
    break;

   case 75:
    guard3 = TRUE;
    break;

   case 76:
    guard4 = TRUE;
    break;

   case 77:
    guard4 = TRUE;
    break;

   case 78:
    guard4 = TRUE;
    break;

   case 79:
    guard4 = TRUE;
    break;

   case 80:
    guard4 = TRUE;
    break;

   case 81:
    guard4 = TRUE;
    break;

   case 82:
    guard4 = TRUE;
    break;

   case 83:
    guard4 = TRUE;
    break;

   case 84:
    guard4 = TRUE;
    break;

   case 85:
    guard4 = TRUE;
    break;

   case 86:
    guard4 = TRUE;
    break;

   case 87:
    guard4 = TRUE;
    break;

   case 88:
    guard4 = TRUE;
    break;

   case 89:
    guard4 = TRUE;
    break;

   case 90:
    guard4 = TRUE;
    break;

   case 91:
    guard4 = TRUE;
    break;

   case 92:
    guard4 = TRUE;
    break;

   case 93:
    guard4 = TRUE;
    break;

   case 94:
    guard4 = TRUE;
    break;

   case 95:
    guard4 = TRUE;
    break;

   case 96:
    guard4 = TRUE;
    break;

   case 97:
    guard4 = TRUE;
    break;

   case 98:
    guard4 = TRUE;
    break;

   case 99:
    guard4 = TRUE;
    break;

   case 100:
    guard4 = TRUE;
    break;

   default:
    rtb_UDP_Receive_Int1 = demo_P.Constant_Value;
    break;
  }

  if (guard4 == TRUE) {
    rtb_UDP_Receive_Int1 = demo_P.Constant3_Value;
  }

  if (guard3 == TRUE) {
    rtb_UDP_Receive_Int1 = demo_P.Constant2_Value;
  }

  if (guard2 == TRUE) {
    rtb_UDP_Receive_Int1 = demo_P.Constant1_Value;
  }

  if (guard1 == TRUE) {
    rtb_UDP_Receive_Int1 = demo_P.Constant_Value;
  }

  /* End of MultiPortSwitch: '<S1>/Multiport Switch' */

  /* DataTypeConversion: '<S2>/Data Type Conversion' */
  rtb_DataTypeConversion3_o = (int8_T)rtb_UDP_Receive_Int1;

  /* S-Function (ARDrone_LED): '<S2>/ARDrone_LED' */
  LED_Set( (int8_T)rtb_DataTypeConversion3_o, (uint8_T)demo_P.ARDrone_LED_p1);

  /* DataTypeConversion: '<S2>/Data Type Conversion1' */
  rtb_DataTypeConversion3_o = (int8_T)rtb_UDP_Receive_Int1;

  /* S-Function (ARDrone_LED): '<S2>/ARDrone_LED1' */
  LED_Set( (int8_T)rtb_DataTypeConversion3_o, (uint8_T)demo_P.ARDrone_LED1_p1);

  /* DataTypeConversion: '<S2>/Data Type Conversion2' */
  rtb_DataTypeConversion3_o = (int8_T)rtb_UDP_Receive_Int1;

  /* S-Function (ARDrone_LED): '<S2>/ARDrone_LED2' */
  LED_Set( (int8_T)rtb_DataTypeConversion3_o, (uint8_T)demo_P.ARDrone_LED2_p1);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  rtb_DataTypeConversion3_o = (int8_T)rtb_UDP_Receive_Int1;

  /* S-Function (ARDrone_LED): '<S2>/ARDrone_LED3' */
  LED_Set( (int8_T)rtb_DataTypeConversion3_o, (uint8_T)demo_P.ARDrone_LED3_p1);

  /* S-Function (UDP_Receive_Int32): '<S4>/UDP_Receive_Int1' */
  rtb_UDP_Receive_Int1 = udp_recv_int32();

  /* DataTypeConversion: '<S3>/Data Type Conversion' */
  rtb_DataTypeConversion3 = (real32_T)rtb_UDP_Receive_Int1;

  /* S-Function (ARDrone_Motor): '<S3>/ARDrone_Motor' */
  Motor_Set( (real32_T)rtb_DataTypeConversion3, (uint8_T)demo_P.ARDrone_Motor_p1);

  /* DataTypeConversion: '<S3>/Data Type Conversion1' */
  rtb_DataTypeConversion3 = (real32_T)rtb_UDP_Receive_Int1;

  /* S-Function (ARDrone_Motor): '<S3>/ARDrone_Motor1' */
  Motor_Set( (real32_T)rtb_DataTypeConversion3, (uint8_T)
            demo_P.ARDrone_Motor1_p1);

  /* DataTypeConversion: '<S3>/Data Type Conversion2' */
  rtb_DataTypeConversion3 = (real32_T)rtb_UDP_Receive_Int1;

  /* S-Function (ARDrone_Motor): '<S3>/ARDrone_Motor2' */
  Motor_Set( (real32_T)rtb_DataTypeConversion3, (uint8_T)
            demo_P.ARDrone_Motor2_p1);

  /* DataTypeConversion: '<S3>/Data Type Conversion3' */
  rtb_DataTypeConversion3 = (real32_T)rtb_UDP_Receive_Int1;

  /* S-Function (ARDrone_Motor): '<S3>/ARDrone_Motor3' */
  Motor_Set( (real32_T)rtb_DataTypeConversion3, (uint8_T)
            demo_P.ARDrone_Motor3_p1);

  /* S-Function (UDP_Send_Int32): '<S4>/UDP_Send_Int32' */
  udp_send_int32( (int32_T)rtb_UDP_Receive_Int1);
}

/* Model initialize function */
void demo_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(demo_M, (NULL));

  /* S-Function (ARDrone_Height): <Root>/Height */
  Height_Initialization();

  /* S-Function (ARDrone_LED): <S2>/ARDrone_LED */
  LED_Initialization();

  /* S-Function (ARDrone_LED): <S2>/ARDrone_LED1 */
  LED_Initialization();

  /* S-Function (ARDrone_LED): <S2>/ARDrone_LED2 */
  LED_Initialization();

  /* S-Function (ARDrone_LED): <S2>/ARDrone_LED3 */
  LED_Initialization();

  /* S-Function (UDP_Receive_Int32): <S4>/UDP_Receive_Int1 */
  udp_reception_init( (int32_T)demo_P.UDP_Receive_Int1_p1);

  /* S-Function (ARDrone_Motor): <S3>/ARDrone_Motor */
  Motor_Initialization();

  /* S-Function (ARDrone_Motor): <S3>/ARDrone_Motor1 */
  Motor_Initialization();

  /* S-Function (ARDrone_Motor): <S3>/ARDrone_Motor2 */
  Motor_Initialization();

  /* S-Function (ARDrone_Motor): <S3>/ARDrone_Motor3 */
  Motor_Initialization();

  /* S-Function (UDP_Send_Int32): <S4>/UDP_Send_Int32 */
  udp_emission_init( (int32_T)demo_P.UDP_Send_Int32_p1);
}

/* Model terminate function */
void demo_terminate(void)
{
  /* S-Function (UDP_Receive_Int32): <S4>/UDP_Receive_Int1 */
  udp_reception_terminate();

  /* S-Function (UDP_Send_Int32): <S4>/UDP_Send_Int32 */
  udp_emission_terminate();
}

/* File trailer for generated code.
 *
 * [EOF]
 */
