/*
 * Copyright (C) 2008-2012 The Paparazzi Team
 *
 * This file is part of paparazzi.
 *
 * paparazzi is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * paparazzi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with paparazzi; see the file COPYING.  If not, write to
 * the Free Software Foundation, 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

/**
 * @file subsystems/ahrs/ahrs_int_cmpl_quat.c
 *
 * Quaternion complementary filter (fixed-point).
 *
 * Estimate the attitude, heading and gyro bias.
 *
 */

#include "ahrs_int_cmpl_quat.h"
#include "ahrs_aligner.h"
#include "ahrs_int_utils.h"

#include "../../state.h"

#include "../imu.h"
#include "../../math/pprz_trig_int.h"
#include "../../math/pprz_algebra_int.h"

#include "../conf_capteur.h"

//#include "../../test/pprz_algebra_print.h"

//static inline void ahrs_update_mag_full(void);
//static inline void ahrs_update_mag_2d(void);

#ifdef AHRS_MAG_UPDATE_YAW_ONLY
#warning "AHRS_MAG_UPDATE_YAW_ONLY is deprecated, please remove it. This is the default behaviour. Define AHRS_MAG_UPDATE_ALL_AXES to use mag for all axes and not only yaw."
#endif

#if USE_MAGNETOMETER && AHRS_USE_GPS_HEADING
#warning "Using magnetometer and GPS course to update heading. Probably better to set USE_MAGNETOMETER=0 if you want to use GPS course."
#endif

#ifndef AHRS_PROPAGATE_FREQUENCY
#define AHRS_PROPAGATE_FREQUENCY PERIODIC_FREQUENCY
#endif

struct AhrsIntCmpl ahrs_impl;

static inline void set_body_state_from_quat(void);

void ahrs_init(void) {

  ahrs.status = AHRS_UNINIT;
  ahrs_impl.ltp_vel_norm_valid = FALSE;
  ahrs_impl.heading_aligned = FALSE;

  /* set ltp_to_imu so that body is zero */
  QUAT_COPY(ahrs_impl.ltp_to_imu_quat, imu.body_to_imu_quat);

  INT_RATES_ZERO(ahrs_impl.imu_rate);
  INT_RATES_ZERO(ahrs_impl.gyro_bias);
  INT_RATES_ZERO(ahrs_impl.rate_correction);
  INT_RATES_ZERO(ahrs_impl.high_rez_bias);

  ahrs_impl.correct_gravity = FALSE;
  ahrs_impl.use_gravity_heuristic = FALSE;

  VECT3_ASSIGN(ahrs_impl.mag_h, MAG_BFP_OF_REAL(AHRS_H_X), MAG_BFP_OF_REAL(AHRS_H_Y), MAG_BFP_OF_REAL(AHRS_H_Z));

}

void ahrs_align(void) {

  /* Compute an initial orientation from accel and mag directly as quaternion */
  ahrs_int_get_quat_from_accel_mag(&ahrs_impl.ltp_to_imu_quat, &ahrs_aligner.lp_accel, &ahrs_aligner.lp_mag);
  ahrs_impl.heading_aligned = TRUE;
  set_body_state_from_quat();

  /* Use low passed gyro value as initial bias */
  RATES_COPY( ahrs_impl.gyro_bias, ahrs_aligner.lp_gyro);
  RATES_COPY( ahrs_impl.high_rez_bias, ahrs_aligner.lp_gyro);
  INT_RATES_LSHIFT(ahrs_impl.high_rez_bias, ahrs_impl.high_rez_bias, 28);

  ahrs.status = AHRS_RUNNING;
}

void ahrs_propagate(void) {

  /* unbias gyro             */
  struct Int32Rates omega;
  RATES_DIFF(omega, imu.gyro_prev, ahrs_impl.gyro_bias);

  /* low pass rate */
  RATES_COPY(ahrs_impl.imu_rate, omega);

  /* add correction     */
  RATES_ADD(omega, ahrs_impl.rate_correction);
  /* and zeros it */
  INT_RATES_ZERO(ahrs_impl.rate_correction);

  /* integrate quaternion */
//pas inclu dans le traitement DIA/word
  INT32_QUAT_INTEGRATE_FI(ahrs_impl.ltp_to_imu_quat, ahrs_impl.high_rez_quat, omega, AHRS_PROPAGATE_FREQUENCY);
  INT32_QUAT_NORMALIZE(ahrs_impl.ltp_to_imu_quat);

  set_body_state_from_quat();
}

void ahrs_update_accel(void) {

  // c2 = ltp z-axis in imu-frame
  struct Int32RMat ltp_to_imu_rmat;
  INT32_RMAT_OF_QUAT(ltp_to_imu_rmat, ahrs_impl.ltp_to_imu_quat);
  struct Int32Vect3 c2 = { RMAT_ELMT(ltp_to_imu_rmat, 0,2),
                           RMAT_ELMT(ltp_to_imu_rmat, 1,2),
                           RMAT_ELMT(ltp_to_imu_rmat, 2,2)};
  struct Int32Vect3 residual;
 /* compute the residual of the pseudo gravity vector in imu frame */
  INT32_VECT3_CROSS_PRODUCT(residual, imu.accel, c2);
  

  // residual FRAC : ACCEL_FRAC + TRIG_FRAC = 10 + 14 = 24
  // rate_correction FRAC = RATE_FRAC = 12
  // 2^12 / 2^24 * 5e-2 = 1/81920
  ahrs_impl.rate_correction.p += -residual.x/82000;
  ahrs_impl.rate_correction.q += -residual.y/82000;
  ahrs_impl.rate_correction.r += -residual.z/82000;

  // residual FRAC = ACCEL_FRAC + TRIG_FRAC = 10 + 14 = 24
  // high_rez_bias = RATE_FRAC+28 = 40
  // 2^40 / 2^24 * 5e-6 = 1/3.05

  ahrs_impl.high_rez_bias.p += residual.x/(2);
  ahrs_impl.high_rez_bias.q += residual.y/(2);
  ahrs_impl.high_rez_bias.r += residual.z/(2);

  /*                        */
  INT_RATES_RSHIFT(ahrs_impl.gyro_bias, ahrs_impl.high_rez_bias, 28);

}

void ahrs_update_mag(void) {

  struct Int32RMat ltp_to_imu_rmat;
  INT32_RMAT_OF_QUAT(ltp_to_imu_rmat, ahrs_impl.ltp_to_imu_quat);

  struct Int32Vect3 measured_ltp;
  INT32_RMAT_TRANSP_VMULT(measured_ltp, ltp_to_imu_rmat, imu.mag);

  struct Int32Vect3 residual_ltp =
    { 0,
      0,
      (measured_ltp.x * ahrs_impl.mag_h.y - measured_ltp.y * ahrs_impl.mag_h.x)/(1<<5)};

  struct Int32Vect3 residual_imu;
  INT32_RMAT_VMULT(residual_imu, ltp_to_imu_rmat, residual_ltp);

  ahrs_impl.rate_correction.p += residual_imu.x/16;
  ahrs_impl.rate_correction.q += residual_imu.y/16;
  ahrs_impl.rate_correction.r += residual_imu.z/16;

  ahrs_impl.high_rez_bias.p -= residual_imu.x*1024;
  ahrs_impl.high_rez_bias.q -= residual_imu.y*1024;
  ahrs_impl.high_rez_bias.r -= residual_imu.z*1024;


  INT_RATES_RSHIFT(ahrs_impl.gyro_bias, ahrs_impl.high_rez_bias, 28);

}

/* Rotate angles and rates from imu to body frame and set state */
__attribute__ ((always_inline)) static inline void set_body_state_from_quat(void) {
  /* Compute LTP to BODY quaternion */
  struct Int32Quat ltp_to_body_quat;
  INT32_QUAT_COMP_INV(ltp_to_body_quat, ahrs_impl.ltp_to_imu_quat, imu.body_to_imu_quat);
  
  /* Set state */
  stateSetNedToBodyQuat_i(&ltp_to_body_quat);

  /* compute body rates */
  struct Int32Rates body_rate;
  INT32_RMAT_TRANSP_RATEMULT(body_rate, imu.body_to_imu_rmat, ahrs_impl.imu_rate);
  /* Set state */
  stateSetBodyRates_i(&body_rate);
}
