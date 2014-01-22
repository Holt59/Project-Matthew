/*
 * File: test_udp.cpp
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

#include "test_udp.h"
#include "test_udp_private.h"

/* Real-time model */
RT_MODEL_test_udp_T test_udp_M_;
RT_MODEL_test_udp_T *const test_udp_M = &test_udp_M_;

/* Model step function */
void test_udp_step(void)
{
  /* local block i/o variables */
  real32_T rtb_ARDrone_Acc_Y;
  real32_T rtb_ARDrone_Acc_Z;
  real32_T rtb_ARDrone_Acc_X;
  real32_T rtb_ARDrone_Magneto_X;
  int32_T rtb_UDPM_Receive_Int32;
  int32_T rtb_UDPM_Receive_Int32_h;
  int32_T rtb_UDPM_Receive_Int32_n;
  int32_T rtb_UDPM_Receive_Int32_a;
  int32_T rtb_UDPM_Receive_Int32_i;
  int32_T rtb_UDPM_Receive_Int32_l;
  int32_T rtb_UDPM_Receive_Int32_ac;
  int32_T rtb_DataTypeConversion2;
  int32_T rtb_DataTypeConversion3;
  int32_T rtb_DataTypeConversion12;
  int32_T rtb_DataTypeConversion11;
  int32_T rtb_DataTypeConversion9;
  int32_T rtb_DataTypeConversion1;
  int16_T rtb_Height;
  int8_T rtb_DataTypeConversion3_h;
  real32_T tmp;

  /* S-Function (UDPM_Receive_Int32): '<S10>/UDPM_Receive_Int32' */
  rtb_DataTypeConversion1 = udp_recv_int32( (int8_T)
    test_udp_P.UDPM_Receive_Int32_p2);

  /* DataTypeConversion: '<S4>/Data Type Conversion' */
  rtb_DataTypeConversion3_h = (int8_T)rtb_DataTypeConversion1;

  /* S-Function (ARDrone_LED): '<S4>/ARDrone_LED' */
  LED_Set( (int8_T)rtb_DataTypeConversion3_h, (uint8_T)test_udp_P.ARDrone_LED_p1);

  /* S-Function (UDPM_Receive_Int32): '<S12>/UDPM_Receive_Int32' */
  rtb_DataTypeConversion1 = udp_recv_int32( (int8_T)
    test_udp_P.UDPM_Receive_Int32_p2_d);

  /* DataTypeConversion: '<S4>/Data Type Conversion1' */
  rtb_DataTypeConversion3_h = (int8_T)rtb_DataTypeConversion1;

  /* S-Function (ARDrone_LED): '<S4>/ARDrone_LED1' */
  LED_Set( (int8_T)rtb_DataTypeConversion3_h, (uint8_T)
          test_udp_P.ARDrone_LED1_p1);

  /* S-Function (UDPM_Receive_Int32): '<S13>/UDPM_Receive_Int32' */
  rtb_DataTypeConversion1 = udp_recv_int32( (int8_T)
    test_udp_P.UDPM_Receive_Int32_p2_f);

  /* DataTypeConversion: '<S4>/Data Type Conversion2' */
  rtb_DataTypeConversion3_h = (int8_T)rtb_DataTypeConversion1;

  /* S-Function (ARDrone_LED): '<S4>/ARDrone_LED2' */
  LED_Set( (int8_T)rtb_DataTypeConversion3_h, (uint8_T)
          test_udp_P.ARDrone_LED2_p1);

  /* S-Function (UDPM_Receive_Int32): '<S14>/UDPM_Receive_Int32' */
  rtb_DataTypeConversion1 = udp_recv_int32( (int8_T)
    test_udp_P.UDPM_Receive_Int32_p2_p);

  /* DataTypeConversion: '<S4>/Data Type Conversion3' */
  rtb_DataTypeConversion3_h = (int8_T)rtb_DataTypeConversion1;

  /* S-Function (ARDrone_LED): '<S4>/ARDrone_LED3' */
  LED_Set( (int8_T)rtb_DataTypeConversion3_h, (uint8_T)
          test_udp_P.ARDrone_LED3_p1);

  /* S-Function (UDPM_Receive_Int32): '<S7>/UDPM_Receive_Int32' */
  rtb_DataTypeConversion1 = udp_recv_int32( (int8_T)
    test_udp_P.UDPM_Receive_Int32_p2_j);

  /* DataTypeConversion: '<S6>/Data Type Conversion' */
  rtb_ARDrone_Acc_X = (real32_T)rtb_DataTypeConversion1;

  /* S-Function (ARDrone_Motor): '<S6>/ARDrone_Motor' */
  Motor_Set( (real32_T)rtb_ARDrone_Acc_X, (uint8_T)test_udp_P.ARDrone_Motor_p1);

  /* DataTypeConversion: '<S6>/Data Type Conversion1' */
  rtb_ARDrone_Acc_X = (real32_T)rtb_DataTypeConversion1;

  /* S-Function (ARDrone_Motor): '<S6>/ARDrone_Motor1' */
  Motor_Set( (real32_T)rtb_ARDrone_Acc_X, (uint8_T)test_udp_P.ARDrone_Motor1_p1);

  /* DataTypeConversion: '<S6>/Data Type Conversion2' */
  rtb_ARDrone_Acc_X = (real32_T)rtb_DataTypeConversion1;

  /* S-Function (ARDrone_Motor): '<S6>/ARDrone_Motor2' */
  Motor_Set( (real32_T)rtb_ARDrone_Acc_X, (uint8_T)test_udp_P.ARDrone_Motor2_p1);

  /* DataTypeConversion: '<S6>/Data Type Conversion3' */
  rtb_ARDrone_Acc_X = (real32_T)rtb_DataTypeConversion1;

  /* S-Function (ARDrone_Motor): '<S6>/ARDrone_Motor3' */
  Motor_Set( (real32_T)rtb_ARDrone_Acc_X, (uint8_T)test_udp_P.ARDrone_Motor3_p1);

  /* S-Function (ARDrone_Acc_X): '<S1>/ARDrone_Acc_X' */
  rtb_ARDrone_Acc_X = Accelero_Get_X();

  /* S-Function (ARDrone_Acc_Y): '<S1>/ARDrone_Acc_Y' */
  rtb_ARDrone_Acc_Y = Accelero_Get_Y();

  /* S-Function (ARDrone_Acc_Z): '<S1>/ARDrone_Acc_Z' */
  rtb_ARDrone_Acc_Z = Accelero_Get_Z();

  /* S-Function (ARDrone_Gyro_X): '<S3>/ARDrone_Gyro_X' */
  rtb_ARDrone_Magneto_X = Gyro_Get_X();

  /* DataTypeConversion: '<Root>/Data Type Conversion1' */
  tmp = (real32_T)floor(rtb_ARDrone_Magneto_X);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 4.2949673E+9F);
  }

  rtb_DataTypeConversion1 = tmp < 0.0F ? -(int32_T)(uint32_T)-tmp : (int32_T)
    (uint32_T)tmp;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion1' */

  /* S-Function (ARDrone_Gyro_Y): '<S3>/ARDrone_Gyro_Y' */
  rtb_ARDrone_Magneto_X = Gyro_Get_Y();

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  tmp = (real32_T)floor(rtb_ARDrone_Magneto_X);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 4.2949673E+9F);
  }

  rtb_DataTypeConversion2 = tmp < 0.0F ? -(int32_T)(uint32_T)-tmp : (int32_T)
    (uint32_T)tmp;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion2' */

  /* S-Function (ARDrone_Gyro_Z): '<S3>/ARDrone_Gyro_Z' */
  rtb_ARDrone_Magneto_X = Gyro_Get_Z();

  /* DataTypeConversion: '<Root>/Data Type Conversion3' */
  tmp = (real32_T)floor(rtb_ARDrone_Magneto_X);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 4.2949673E+9F);
  }

  rtb_DataTypeConversion3 = tmp < 0.0F ? -(int32_T)(uint32_T)-tmp : (int32_T)
    (uint32_T)tmp;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion3' */

  /* DataTypeConversion: '<Root>/Data Type Conversion4' */
  tmp = (real32_T)floor(rtb_ARDrone_Acc_X);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 4.2949673E+9F);
  }

  rtb_DataTypeConversion12 = tmp < 0.0F ? -(int32_T)(uint32_T)-tmp : (int32_T)
    (uint32_T)tmp;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion4' */

  /* DataTypeConversion: '<Root>/Data Type Conversion5' */
  tmp = (real32_T)floor(rtb_ARDrone_Acc_Y);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 4.2949673E+9F);
  }

  rtb_DataTypeConversion11 = tmp < 0.0F ? -(int32_T)(uint32_T)-tmp : (int32_T)
    (uint32_T)tmp;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion5' */

  /* DataTypeConversion: '<Root>/Data Type Conversion6' */
  tmp = (real32_T)floor(rtb_ARDrone_Acc_Z);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 4.2949673E+9F);
  }

  rtb_DataTypeConversion9 = tmp < 0.0F ? -(int32_T)(uint32_T)-tmp : (int32_T)
    (uint32_T)tmp;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion6' */

  /* S-Function (UDPM_Send_Int32): '<S7>/UDPM_Send_Int32' */
  udp_send_int32( (int32_T)rtb_DataTypeConversion11, (int8_T)
                 test_udp_P.UDPM_Send_Int32_p2);

  /* S-Function (UDPM_Receive_Int32): '<S8>/UDPM_Receive_Int32' */
  rtb_UDPM_Receive_Int32 = udp_recv_int32( (int8_T)
    test_udp_P.UDPM_Receive_Int32_p2_m);

  /* S-Function (UDPM_Send_Int32): '<S8>/UDPM_Send_Int32' */
  udp_send_int32( (int32_T)rtb_DataTypeConversion9, (int8_T)
                 test_udp_P.UDPM_Send_Int32_p2_j);

  /* S-Function (UDPM_Send_Int32): '<S10>/UDPM_Send_Int32' */
  udp_send_int32( (int32_T)rtb_DataTypeConversion1, (int8_T)
                 test_udp_P.UDPM_Send_Int32_p2_h);

  /* S-Function (UDPM_Send_Int32): '<S12>/UDPM_Send_Int32' */
  udp_send_int32( (int32_T)rtb_DataTypeConversion2, (int8_T)
                 test_udp_P.UDPM_Send_Int32_p2_p);

  /* S-Function (UDPM_Send_Int32): '<S13>/UDPM_Send_Int32' */
  udp_send_int32( (int32_T)rtb_DataTypeConversion3, (int8_T)
                 test_udp_P.UDPM_Send_Int32_p2_i);

  /* S-Function (UDPM_Send_Int32): '<S14>/UDPM_Send_Int32' */
  udp_send_int32( (int32_T)rtb_DataTypeConversion12, (int8_T)
                 test_udp_P.UDPM_Send_Int32_p2_js);

  /* S-Function (UDPM_Receive_Int32): '<S9>/UDPM_Receive_Int32' */
  rtb_UDPM_Receive_Int32_h = udp_recv_int32( (int8_T)
    test_udp_P.UDPM_Receive_Int32_p2_g);

  /* S-Function (UDPM_Send_Int32): '<S9>/UDPM_Send_Int32' incorporates:
   *  S-Function (ARDrone_Temperature): '<S2>/ARDrone_Temperature'
   */
  udp_send_int32( (int32_T)Barometer_Get_Temperature(), (int8_T)
                 test_udp_P.UDPM_Send_Int32_p2_k);

  /* S-Function (UDPM_Receive_Int32): '<S18>/UDPM_Receive_Int32' */
  rtb_UDPM_Receive_Int32_n = udp_recv_int32( (int8_T)
    test_udp_P.UDPM_Receive_Int32_p2_c);

  /* S-Function (UDPM_Send_Int32): '<S18>/UDPM_Send_Int32' incorporates:
   *  S-Function (ARDrone_Pressure): '<S2>/ARDrone_Pressure'
   */
  udp_send_int32( (int32_T)Barometer_Get_Pressure(), (int8_T)
                 test_udp_P.UDPM_Send_Int32_p2_o);

  /* S-Function (ARDrone_Magneto_Z): '<S5>/ARDrone_Magneto_Z' */
  rtb_ARDrone_Magneto_X = Magneto_Get_Z();

  /* DataTypeConversion: '<Root>/Data Type Conversion10' */
  tmp = (real32_T)floor(rtb_ARDrone_Magneto_X);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 4.2949673E+9F);
  }

  rtb_DataTypeConversion9 = tmp < 0.0F ? -(int32_T)(uint32_T)-tmp : (int32_T)
    (uint32_T)tmp;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion10' */

  /* S-Function (ARDrone_Magneto_Y): '<S5>/ARDrone_Magneto_Y' */
  rtb_ARDrone_Magneto_X = Magneto_Get_Y();

  /* DataTypeConversion: '<Root>/Data Type Conversion11' */
  tmp = (real32_T)floor(rtb_ARDrone_Magneto_X);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 4.2949673E+9F);
  }

  rtb_DataTypeConversion11 = tmp < 0.0F ? -(int32_T)(uint32_T)-tmp : (int32_T)
    (uint32_T)tmp;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion11' */

  /* S-Function (ARDrone_Magneto_X): '<S5>/ARDrone_Magneto_X' */
  rtb_ARDrone_Magneto_X = Magneto_Get_X();

  /* DataTypeConversion: '<Root>/Data Type Conversion12' */
  tmp = (real32_T)floor(rtb_ARDrone_Magneto_X);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 4.2949673E+9F);
  }

  rtb_DataTypeConversion12 = tmp < 0.0F ? -(int32_T)(uint32_T)-tmp : (int32_T)
    (uint32_T)tmp;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion12' */

  /* S-Function (UDPM_Receive_Int32): '<S11>/UDPM_Receive_Int32' */
  rtb_UDPM_Receive_Int32_a = udp_recv_int32( (int8_T)
    test_udp_P.UDPM_Receive_Int32_p2_a);

  /* S-Function (UDPM_Send_Int32): '<S11>/UDPM_Send_Int32' */
  udp_send_int32( (int32_T)rtb_DataTypeConversion12, (int8_T)
                 test_udp_P.UDPM_Send_Int32_p2_oz);

  /* S-Function (UDPM_Receive_Int32): '<S15>/UDPM_Receive_Int32' */
  rtb_UDPM_Receive_Int32_i = udp_recv_int32( (int8_T)
    test_udp_P.UDPM_Receive_Int32_p2_gb);

  /* S-Function (UDPM_Send_Int32): '<S15>/UDPM_Send_Int32' */
  udp_send_int32( (int32_T)rtb_DataTypeConversion11, (int8_T)
                 test_udp_P.UDPM_Send_Int32_p2_n);

  /* S-Function (UDPM_Receive_Int32): '<S16>/UDPM_Receive_Int32' */
  rtb_UDPM_Receive_Int32_l = udp_recv_int32( (int8_T)
    test_udp_P.UDPM_Receive_Int32_p2_dn);

  /* S-Function (UDPM_Send_Int32): '<S16>/UDPM_Send_Int32' */
  udp_send_int32( (int32_T)rtb_DataTypeConversion9, (int8_T)
                 test_udp_P.UDPM_Send_Int32_p2_d);

  /* S-Function (ARDrone_Height): '<Root>/Height' */
  rtb_Height = Height_Get();

  /* DataTypeConversion: '<Root>/Data Type Conversion9' */
  rtb_DataTypeConversion9 = rtb_Height;

  /* S-Function (UDPM_Receive_Int32): '<S17>/UDPM_Receive_Int32' */
  rtb_UDPM_Receive_Int32_ac = udp_recv_int32( (int8_T)
    test_udp_P.UDPM_Receive_Int32_p2_pv);

  /* S-Function (UDPM_Send_Int32): '<S17>/UDPM_Send_Int32' */
  udp_send_int32( (int32_T)rtb_DataTypeConversion9, (int8_T)
                 test_udp_P.UDPM_Send_Int32_p2_kb);
}

/* Model initialize function */
void test_udp_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(test_udp_M, (NULL));

  /* S-Function (UDPM_Receive_Int32): <S10>/UDPM_Receive_Int32 */
  udp_reception_init( (int32_T)test_udp_P.UDPM_Receive_Int32_p1);

  /* S-Function (ARDrone_LED): <S4>/ARDrone_LED */
  LED_Initialization();

  /* S-Function (UDPM_Receive_Int32): <S12>/UDPM_Receive_Int32 */
  udp_reception_init( (int32_T)test_udp_P.UDPM_Receive_Int32_p1_b);

  /* S-Function (ARDrone_LED): <S4>/ARDrone_LED1 */
  LED_Initialization();

  /* S-Function (UDPM_Receive_Int32): <S13>/UDPM_Receive_Int32 */
  udp_reception_init( (int32_T)test_udp_P.UDPM_Receive_Int32_p1_l);

  /* S-Function (ARDrone_LED): <S4>/ARDrone_LED2 */
  LED_Initialization();

  /* S-Function (UDPM_Receive_Int32): <S14>/UDPM_Receive_Int32 */
  udp_reception_init( (int32_T)test_udp_P.UDPM_Receive_Int32_p1_l3);

  /* S-Function (ARDrone_LED): <S4>/ARDrone_LED3 */
  LED_Initialization();

  /* S-Function (UDPM_Receive_Int32): <S7>/UDPM_Receive_Int32 */
  udp_reception_init( (int32_T)test_udp_P.UDPM_Receive_Int32_p1_m);

  /* S-Function (ARDrone_Motor): <S6>/ARDrone_Motor */
  Motor_Initialization();

  /* S-Function (ARDrone_Motor): <S6>/ARDrone_Motor1 */
  Motor_Initialization();

  /* S-Function (ARDrone_Motor): <S6>/ARDrone_Motor2 */
  Motor_Initialization();

  /* S-Function (ARDrone_Motor): <S6>/ARDrone_Motor3 */
  Motor_Initialization();

  /* S-Function (ARDrone_Acc_X): <S1>/ARDrone_Acc_X */
  Accelero_Initialization();

  /* S-Function (ARDrone_Acc_Y): <S1>/ARDrone_Acc_Y */
  Accelero_Initialization();

  /* S-Function (ARDrone_Acc_Z): <S1>/ARDrone_Acc_Z */
  Accelero_Initialization();

  /* S-Function (ARDrone_Gyro_X): <S3>/ARDrone_Gyro_X */
  Gyro_Initialization();

  /* S-Function (ARDrone_Gyro_Y): <S3>/ARDrone_Gyro_Y */
  Gyro_Initialization();

  /* S-Function (ARDrone_Gyro_Z): <S3>/ARDrone_Gyro_Z */
  Gyro_Initialization();

  /* S-Function (UDPM_Send_Int32): <S7>/UDPM_Send_Int32 */
  udp_emission_init( (int32_T)test_udp_P.UDPM_Send_Int32_p1);

  /* S-Function (UDPM_Receive_Int32): <S8>/UDPM_Receive_Int32 */
  udp_reception_init( (int32_T)test_udp_P.UDPM_Receive_Int32_p1_c);

  /* S-Function (UDPM_Send_Int32): <S8>/UDPM_Send_Int32 */
  udp_emission_init( (int32_T)test_udp_P.UDPM_Send_Int32_p1_d);

  /* S-Function (UDPM_Send_Int32): <S10>/UDPM_Send_Int32 */
  udp_emission_init( (int32_T)test_udp_P.UDPM_Send_Int32_p1_g);

  /* S-Function (UDPM_Send_Int32): <S12>/UDPM_Send_Int32 */
  udp_emission_init( (int32_T)test_udp_P.UDPM_Send_Int32_p1_gv);

  /* S-Function (UDPM_Send_Int32): <S13>/UDPM_Send_Int32 */
  udp_emission_init( (int32_T)test_udp_P.UDPM_Send_Int32_p1_m);

  /* S-Function (UDPM_Send_Int32): <S14>/UDPM_Send_Int32 */
  udp_emission_init( (int32_T)test_udp_P.UDPM_Send_Int32_p1_n);

  /* S-Function (ARDrone_Pressure): <S2>/ARDrone_Pressure */
  Barometer_Initialization();

  /* S-Function (ARDrone_Temperature): <S2>/ARDrone_Temperature */
  Barometer_Initialization();

  /* S-Function (UDPM_Receive_Int32): <S9>/UDPM_Receive_Int32 */
  udp_reception_init( (int32_T)test_udp_P.UDPM_Receive_Int32_p1_bv);

  /* S-Function (UDPM_Send_Int32): <S9>/UDPM_Send_Int32 */
  udp_emission_init( (int32_T)test_udp_P.UDPM_Send_Int32_p1_g1);

  /* S-Function (UDPM_Receive_Int32): <S18>/UDPM_Receive_Int32 */
  udp_reception_init( (int32_T)test_udp_P.UDPM_Receive_Int32_p1_o);

  /* S-Function (UDPM_Send_Int32): <S18>/UDPM_Send_Int32 */
  udp_emission_init( (int32_T)test_udp_P.UDPM_Send_Int32_p1_mg);

  /* S-Function (ARDrone_Magneto_Z): <S5>/ARDrone_Magneto_Z */
  Magneto_Initialization();

  /* S-Function (ARDrone_Magneto_Y): <S5>/ARDrone_Magneto_Y */
  Magneto_Initialization();

  /* S-Function (ARDrone_Magneto_X): <S5>/ARDrone_Magneto_X */
  Magneto_Initialization();

  /* S-Function (UDPM_Receive_Int32): <S11>/UDPM_Receive_Int32 */
  udp_reception_init( (int32_T)test_udp_P.UDPM_Receive_Int32_p1_l4);

  /* S-Function (UDPM_Send_Int32): <S11>/UDPM_Send_Int32 */
  udp_emission_init( (int32_T)test_udp_P.UDPM_Send_Int32_p1_i);

  /* S-Function (UDPM_Receive_Int32): <S15>/UDPM_Receive_Int32 */
  udp_reception_init( (int32_T)test_udp_P.UDPM_Receive_Int32_p1_k);

  /* S-Function (UDPM_Send_Int32): <S15>/UDPM_Send_Int32 */
  udp_emission_init( (int32_T)test_udp_P.UDPM_Send_Int32_p1_m2);

  /* S-Function (UDPM_Receive_Int32): <S16>/UDPM_Receive_Int32 */
  udp_reception_init( (int32_T)test_udp_P.UDPM_Receive_Int32_p1_g);

  /* S-Function (UDPM_Send_Int32): <S16>/UDPM_Send_Int32 */
  udp_emission_init( (int32_T)test_udp_P.UDPM_Send_Int32_p1_h);

  /* S-Function (ARDrone_Height): <Root>/Height */
  Height_Initialization();

  /* S-Function (UDPM_Receive_Int32): <S17>/UDPM_Receive_Int32 */
  udp_reception_init( (int32_T)test_udp_P.UDPM_Receive_Int32_p1_c2);

  /* S-Function (UDPM_Send_Int32): <S17>/UDPM_Send_Int32 */
  udp_emission_init( (int32_T)test_udp_P.UDPM_Send_Int32_p1_gi);
}

/* Model terminate function */
void test_udp_terminate(void)
{
  /* S-Function (UDPM_Receive_Int32): <S10>/UDPM_Receive_Int32 */
  udp_reception_terminate();

  /* S-Function (UDPM_Receive_Int32): <S12>/UDPM_Receive_Int32 */
  udp_reception_terminate();

  /* S-Function (UDPM_Receive_Int32): <S13>/UDPM_Receive_Int32 */
  udp_reception_terminate();

  /* S-Function (UDPM_Receive_Int32): <S14>/UDPM_Receive_Int32 */
  udp_reception_terminate();

  /* S-Function (UDPM_Receive_Int32): <S7>/UDPM_Receive_Int32 */
  udp_reception_terminate();

  /* S-Function (UDPM_Send_Int32): <S7>/UDPM_Send_Int32 */
  udp_emission_terminate();

  /* S-Function (UDPM_Receive_Int32): <S8>/UDPM_Receive_Int32 */
  udp_reception_terminate();

  /* S-Function (UDPM_Send_Int32): <S8>/UDPM_Send_Int32 */
  udp_emission_terminate();

  /* S-Function (UDPM_Send_Int32): <S10>/UDPM_Send_Int32 */
  udp_emission_terminate();

  /* S-Function (UDPM_Send_Int32): <S12>/UDPM_Send_Int32 */
  udp_emission_terminate();

  /* S-Function (UDPM_Send_Int32): <S13>/UDPM_Send_Int32 */
  udp_emission_terminate();

  /* S-Function (UDPM_Send_Int32): <S14>/UDPM_Send_Int32 */
  udp_emission_terminate();

  /* S-Function (UDPM_Receive_Int32): <S9>/UDPM_Receive_Int32 */
  udp_reception_terminate();

  /* S-Function (UDPM_Send_Int32): <S9>/UDPM_Send_Int32 */
  udp_emission_terminate();

  /* S-Function (UDPM_Receive_Int32): <S18>/UDPM_Receive_Int32 */
  udp_reception_terminate();

  /* S-Function (UDPM_Send_Int32): <S18>/UDPM_Send_Int32 */
  udp_emission_terminate();

  /* S-Function (UDPM_Receive_Int32): <S11>/UDPM_Receive_Int32 */
  udp_reception_terminate();

  /* S-Function (UDPM_Send_Int32): <S11>/UDPM_Send_Int32 */
  udp_emission_terminate();

  /* S-Function (UDPM_Receive_Int32): <S15>/UDPM_Receive_Int32 */
  udp_reception_terminate();

  /* S-Function (UDPM_Send_Int32): <S15>/UDPM_Send_Int32 */
  udp_emission_terminate();

  /* S-Function (UDPM_Receive_Int32): <S16>/UDPM_Receive_Int32 */
  udp_reception_terminate();

  /* S-Function (UDPM_Send_Int32): <S16>/UDPM_Send_Int32 */
  udp_emission_terminate();

  /* S-Function (UDPM_Receive_Int32): <S17>/UDPM_Receive_Int32 */
  udp_reception_terminate();

  /* S-Function (UDPM_Send_Int32): <S17>/UDPM_Send_Int32 */
  udp_emission_terminate();
}

/* File trailer for generated code.
 *
 * [EOF]
 */
