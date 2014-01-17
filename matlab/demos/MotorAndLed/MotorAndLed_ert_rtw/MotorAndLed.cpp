/*
 * File: MotorAndLed.cpp
 *
 * Code generated for Simulink model 'MotorAndLed'.
 *
 * Model version                  : 1.19
 * Simulink Coder version         : 8.4 (R2013a) 13-Feb-2013
 * TLC version                    : 8.4 (Jan 18 2013)
 * C/C++ source code generated on : Thu Jan 16 15:52:04 2014
 *
 * Target selection: ardrone.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "MotorAndLed.h"
#include "MotorAndLed_private.h"

/* Real-time model */
RT_MODEL_MotorAndLed_T MotorAndLed_M_;
RT_MODEL_MotorAndLed_T *const MotorAndLed_M = &MotorAndLed_M_;

/* Model step function */
void MotorAndLed_step(void)
{
  /* local block i/o variables */
  real32_T rtb_DataTypeConversion3;
  int16_T rtb_Height;
  int8_T rtb_DataTypeConversion3_a;
  int32_T rtb_MultiportSwitch;

  /* S-Function (ARDrone_Height): '<Root>/Height' */
  rtb_Height = Height_Get();

  /* MultiPortSwitch: '<S1>/Multiport Switch' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/Constant2'
   *  Constant: '<S1>/Constant3'
   */
  switch (rtb_Height) {
   case 0:
   case 1:
   case 2:
   case 3:
   case 4:
   case 5:
   case 6:
   case 7:
   case 8:
   case 9:
   case 10:
   case 11:
   case 12:
   case 13:
   case 14:
   case 15:
   case 16:
   case 17:
   case 18:
   case 19:
   case 20:
   case 21:
   case 22:
   case 23:
   case 24:
   case 25:
    rtb_MultiportSwitch = MotorAndLed_P.Constant_Value;
    break;

   case 26:
   case 27:
   case 28:
   case 29:
   case 30:
   case 31:
   case 32:
   case 33:
   case 34:
   case 35:
   case 36:
   case 37:
   case 38:
   case 39:
   case 40:
   case 41:
   case 42:
   case 43:
   case 44:
   case 45:
   case 46:
   case 47:
   case 48:
   case 49:
   case 50:
    rtb_MultiportSwitch = MotorAndLed_P.Constant1_Value;
    break;

   case 51:
   case 52:
   case 53:
   case 54:
   case 55:
   case 56:
   case 57:
   case 58:
   case 59:
   case 60:
   case 61:
   case 62:
   case 63:
   case 64:
   case 65:
   case 66:
   case 67:
   case 68:
   case 69:
   case 70:
   case 71:
   case 72:
   case 73:
   case 74:
   case 75:
    rtb_MultiportSwitch = MotorAndLed_P.Constant2_Value;
    break;

   case 76:
   case 77:
   case 78:
   case 79:
   case 80:
   case 81:
   case 82:
   case 83:
   case 84:
   case 85:
   case 86:
   case 87:
   case 88:
   case 89:
   case 90:
   case 91:
   case 92:
   case 93:
   case 94:
   case 95:
   case 96:
   case 97:
   case 98:
   case 99:
   case 100:
    rtb_MultiportSwitch = MotorAndLed_P.Constant3_Value;
    break;

   default:
    rtb_MultiportSwitch = MotorAndLed_P.Constant_Value;
    break;
  }

  /* End of MultiPortSwitch: '<S1>/Multiport Switch' */

  /* DataTypeConversion: '<S2>/Data Type Conversion' */
  rtb_DataTypeConversion3_a = (int8_T)rtb_MultiportSwitch;

  /* S-Function (ARDrone_LED): '<S2>/ARDrone_LED' */
  LED_Set( (int8_T)rtb_DataTypeConversion3_a, (uint8_T)
          MotorAndLed_P.ARDrone_LED_p1);

  /* DataTypeConversion: '<S2>/Data Type Conversion1' */
  rtb_DataTypeConversion3_a = (int8_T)rtb_MultiportSwitch;

  /* S-Function (ARDrone_LED): '<S2>/ARDrone_LED1' */
  LED_Set( (int8_T)rtb_DataTypeConversion3_a, (uint8_T)
          MotorAndLed_P.ARDrone_LED1_p1);

  /* DataTypeConversion: '<S2>/Data Type Conversion2' */
  rtb_DataTypeConversion3_a = (int8_T)rtb_MultiportSwitch;

  /* S-Function (ARDrone_LED): '<S2>/ARDrone_LED2' */
  LED_Set( (int8_T)rtb_DataTypeConversion3_a, (uint8_T)
          MotorAndLed_P.ARDrone_LED2_p1);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  rtb_DataTypeConversion3_a = (int8_T)rtb_MultiportSwitch;

  /* S-Function (ARDrone_LED): '<S2>/ARDrone_LED3' */
  LED_Set( (int8_T)rtb_DataTypeConversion3_a, (uint8_T)
          MotorAndLed_P.ARDrone_LED3_p1);

  /* DataTypeConversion: '<S3>/Data Type Conversion' */
  rtb_DataTypeConversion3 = rtb_Height;

  /* S-Function (ARDrone_Motor): '<S3>/ARDrone_Motor' */
  Motor_Set( (real32_T)rtb_DataTypeConversion3, (uint8_T)
            MotorAndLed_P.ARDrone_Motor_p1);

  /* DataTypeConversion: '<S3>/Data Type Conversion1' */
  rtb_DataTypeConversion3 = rtb_Height;

  /* S-Function (ARDrone_Motor): '<S3>/ARDrone_Motor1' */
  Motor_Set( (real32_T)rtb_DataTypeConversion3, (uint8_T)
            MotorAndLed_P.ARDrone_Motor1_p1);

  /* DataTypeConversion: '<S3>/Data Type Conversion2' */
  rtb_DataTypeConversion3 = rtb_Height;

  /* S-Function (ARDrone_Motor): '<S3>/ARDrone_Motor2' */
  Motor_Set( (real32_T)rtb_DataTypeConversion3, (uint8_T)
            MotorAndLed_P.ARDrone_Motor2_p1);

  /* DataTypeConversion: '<S3>/Data Type Conversion3' */
  rtb_DataTypeConversion3 = rtb_Height;

  /* S-Function (ARDrone_Motor): '<S3>/ARDrone_Motor3' */
  Motor_Set( (real32_T)rtb_DataTypeConversion3, (uint8_T)
            MotorAndLed_P.ARDrone_Motor3_p1);
}

/* Model initialize function */
void MotorAndLed_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(MotorAndLed_M, (NULL));

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

  /* S-Function (ARDrone_Motor): <S3>/ARDrone_Motor */
  Motor_Initialization();

  /* S-Function (ARDrone_Motor): <S3>/ARDrone_Motor1 */
  Motor_Initialization();

  /* S-Function (ARDrone_Motor): <S3>/ARDrone_Motor2 */
  Motor_Initialization();

  /* S-Function (ARDrone_Motor): <S3>/ARDrone_Motor3 */
  Motor_Initialization();
}

/* Model terminate function */
void MotorAndLed_terminate(void)
{
  /* (no terminate code required) */
}

/* File trailer for generated code.
 *
 * [EOF]
 */
