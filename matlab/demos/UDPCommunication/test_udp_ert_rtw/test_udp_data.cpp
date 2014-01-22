/*
 * File: test_udp_data.cpp
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

/* Block parameters (auto storage) */
P_test_udp_T test_udp_P = {
  9500,                                /* Computed Parameter: UDPM_Receive_Int32_p1
                                        * Referenced by: '<S10>/UDPM_Receive_Int32'
                                        */
  9500,                                /* Computed Parameter: UDPM_Receive_Int32_p1_b
                                        * Referenced by: '<S12>/UDPM_Receive_Int32'
                                        */
  9500,                                /* Computed Parameter: UDPM_Receive_Int32_p1_l
                                        * Referenced by: '<S13>/UDPM_Receive_Int32'
                                        */
  9500,                                /* Computed Parameter: UDPM_Receive_Int32_p1_l3
                                        * Referenced by: '<S14>/UDPM_Receive_Int32'
                                        */
  9500,                                /* Computed Parameter: UDPM_Receive_Int32_p1_m
                                        * Referenced by: '<S7>/UDPM_Receive_Int32'
                                        */
  9500,                                /* Computed Parameter: UDPM_Send_Int32_p1
                                        * Referenced by: '<S7>/UDPM_Send_Int32'
                                        */
  1,                                   /* Computed Parameter: UDPM_Receive_Int32_p1_c
                                        * Referenced by: '<S8>/UDPM_Receive_Int32'
                                        */
  9500,                                /* Computed Parameter: UDPM_Send_Int32_p1_d
                                        * Referenced by: '<S8>/UDPM_Send_Int32'
                                        */
  9500,                                /* Computed Parameter: UDPM_Send_Int32_p1_g
                                        * Referenced by: '<S10>/UDPM_Send_Int32'
                                        */
  9500,                                /* Computed Parameter: UDPM_Send_Int32_p1_gv
                                        * Referenced by: '<S12>/UDPM_Send_Int32'
                                        */
  9500,                                /* Computed Parameter: UDPM_Send_Int32_p1_m
                                        * Referenced by: '<S13>/UDPM_Send_Int32'
                                        */
  9500,                                /* Computed Parameter: UDPM_Send_Int32_p1_n
                                        * Referenced by: '<S14>/UDPM_Send_Int32'
                                        */
  1,                                   /* Computed Parameter: UDPM_Receive_Int32_p1_bv
                                        * Referenced by: '<S9>/UDPM_Receive_Int32'
                                        */
  9500,                                /* Computed Parameter: UDPM_Send_Int32_p1_g1
                                        * Referenced by: '<S9>/UDPM_Send_Int32'
                                        */
  1,                                   /* Computed Parameter: UDPM_Receive_Int32_p1_o
                                        * Referenced by: '<S18>/UDPM_Receive_Int32'
                                        */
  9500,                                /* Computed Parameter: UDPM_Send_Int32_p1_mg
                                        * Referenced by: '<S18>/UDPM_Send_Int32'
                                        */
  1,                                   /* Computed Parameter: UDPM_Receive_Int32_p1_l4
                                        * Referenced by: '<S11>/UDPM_Receive_Int32'
                                        */
  9500,                                /* Computed Parameter: UDPM_Send_Int32_p1_i
                                        * Referenced by: '<S11>/UDPM_Send_Int32'
                                        */
  1,                                   /* Computed Parameter: UDPM_Receive_Int32_p1_k
                                        * Referenced by: '<S15>/UDPM_Receive_Int32'
                                        */
  9500,                                /* Computed Parameter: UDPM_Send_Int32_p1_m2
                                        * Referenced by: '<S15>/UDPM_Send_Int32'
                                        */
  1,                                   /* Computed Parameter: UDPM_Receive_Int32_p1_g
                                        * Referenced by: '<S16>/UDPM_Receive_Int32'
                                        */
  9500,                                /* Computed Parameter: UDPM_Send_Int32_p1_h
                                        * Referenced by: '<S16>/UDPM_Send_Int32'
                                        */
  1,                                   /* Computed Parameter: UDPM_Receive_Int32_p1_c2
                                        * Referenced by: '<S17>/UDPM_Receive_Int32'
                                        */
  9500,                                /* Computed Parameter: UDPM_Send_Int32_p1_gi
                                        * Referenced by: '<S17>/UDPM_Send_Int32'
                                        */
  0,                                   /* Computed Parameter: UDPM_Receive_Int32_p2
                                        * Referenced by: '<S10>/UDPM_Receive_Int32'
                                        */
  1,                                   /* Computed Parameter: UDPM_Receive_Int32_p2_d
                                        * Referenced by: '<S12>/UDPM_Receive_Int32'
                                        */
  2,                                   /* Computed Parameter: UDPM_Receive_Int32_p2_f
                                        * Referenced by: '<S13>/UDPM_Receive_Int32'
                                        */
  3,                                   /* Computed Parameter: UDPM_Receive_Int32_p2_p
                                        * Referenced by: '<S14>/UDPM_Receive_Int32'
                                        */
  4,                                   /* Computed Parameter: UDPM_Receive_Int32_p2_j
                                        * Referenced by: '<S7>/UDPM_Receive_Int32'
                                        */
  4,                                   /* Computed Parameter: UDPM_Send_Int32_p2
                                        * Referenced by: '<S7>/UDPM_Send_Int32'
                                        */
  1,                                   /* Computed Parameter: UDPM_Receive_Int32_p2_m
                                        * Referenced by: '<S8>/UDPM_Receive_Int32'
                                        */
  2,                                   /* Computed Parameter: UDPM_Send_Int32_p2_j
                                        * Referenced by: '<S8>/UDPM_Send_Int32'
                                        */
  0,                                   /* Computed Parameter: UDPM_Send_Int32_p2_h
                                        * Referenced by: '<S10>/UDPM_Send_Int32'
                                        */
  1,                                   /* Computed Parameter: UDPM_Send_Int32_p2_p
                                        * Referenced by: '<S12>/UDPM_Send_Int32'
                                        */
  2,                                   /* Computed Parameter: UDPM_Send_Int32_p2_i
                                        * Referenced by: '<S13>/UDPM_Send_Int32'
                                        */
  3,                                   /* Computed Parameter: UDPM_Send_Int32_p2_js
                                        * Referenced by: '<S14>/UDPM_Send_Int32'
                                        */
  1,                                   /* Computed Parameter: UDPM_Receive_Int32_p2_g
                                        * Referenced by: '<S9>/UDPM_Receive_Int32'
                                        */
  11,                                  /* Computed Parameter: UDPM_Send_Int32_p2_k
                                        * Referenced by: '<S9>/UDPM_Send_Int32'
                                        */
  1,                                   /* Computed Parameter: UDPM_Receive_Int32_p2_c
                                        * Referenced by: '<S18>/UDPM_Receive_Int32'
                                        */
  10,                                  /* Computed Parameter: UDPM_Send_Int32_p2_o
                                        * Referenced by: '<S18>/UDPM_Send_Int32'
                                        */
  1,                                   /* Computed Parameter: UDPM_Receive_Int32_p2_a
                                        * Referenced by: '<S11>/UDPM_Receive_Int32'
                                        */
  6,                                   /* Computed Parameter: UDPM_Send_Int32_p2_oz
                                        * Referenced by: '<S11>/UDPM_Send_Int32'
                                        */
  1,                                   /* Computed Parameter: UDPM_Receive_Int32_p2_gb
                                        * Referenced by: '<S15>/UDPM_Receive_Int32'
                                        */
  7,                                   /* Computed Parameter: UDPM_Send_Int32_p2_n
                                        * Referenced by: '<S15>/UDPM_Send_Int32'
                                        */
  1,                                   /* Computed Parameter: UDPM_Receive_Int32_p2_dn
                                        * Referenced by: '<S16>/UDPM_Receive_Int32'
                                        */
  8,                                   /* Computed Parameter: UDPM_Send_Int32_p2_d
                                        * Referenced by: '<S16>/UDPM_Send_Int32'
                                        */
  1,                                   /* Computed Parameter: UDPM_Receive_Int32_p2_pv
                                        * Referenced by: '<S17>/UDPM_Receive_Int32'
                                        */
  9,                                   /* Computed Parameter: UDPM_Send_Int32_p2_kb
                                        * Referenced by: '<S17>/UDPM_Send_Int32'
                                        */
  0U,                                  /* Computed Parameter: ARDrone_LED_p1
                                        * Referenced by: '<S4>/ARDrone_LED'
                                        */
  1U,                                  /* Computed Parameter: ARDrone_LED1_p1
                                        * Referenced by: '<S4>/ARDrone_LED1'
                                        */
  2U,                                  /* Computed Parameter: ARDrone_LED2_p1
                                        * Referenced by: '<S4>/ARDrone_LED2'
                                        */
  3U,                                  /* Computed Parameter: ARDrone_LED3_p1
                                        * Referenced by: '<S4>/ARDrone_LED3'
                                        */
  0U,                                  /* Computed Parameter: ARDrone_Motor_p1
                                        * Referenced by: '<S6>/ARDrone_Motor'
                                        */
  1U,                                  /* Computed Parameter: ARDrone_Motor1_p1
                                        * Referenced by: '<S6>/ARDrone_Motor1'
                                        */
  2U,                                  /* Computed Parameter: ARDrone_Motor2_p1
                                        * Referenced by: '<S6>/ARDrone_Motor2'
                                        */
  3U                                   /* Computed Parameter: ARDrone_Motor3_p1
                                        * Referenced by: '<S6>/ARDrone_Motor3'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
