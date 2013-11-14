/*
 * Copyright (C) 2008-2010 The Paparazzi Team
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
 * @file subsystems/ins/ins_int.c
 *
 * INS for rotorcrafts combining vertical and horizontal filters.
 *
 */

#include "ins_int.h"

#include "imu.h"
#include "baro_board.h"

#include "conf_capteur.h"

#include "vf_float.h"

#if USE_HFF
#include "hf_float.h"
#endif

#include "../math/pprz_geodetic_int.h"

#include "../generated/flight_plan.h"
#ifndef USE_INS_NAV_INIT
#define USE_INS_NAV_INIT TRUE
PRINT_CONFIG_MSG("USE_INS_NAV_INIT defaulting to TRUE")
#endif

/* gps transformed to LTP-NED  */
struct LtpDef_i  ins_ltp_def;
         bool_t  ins_ltp_initialised;
struct NedCoor_i ins_gps_pos_cm_ned;
struct NedCoor_i ins_gps_speed_cm_s_ned;
#if USE_HFF
/* horizontal gps transformed to NED in meters as float */
struct FloatVect2 ins_gps_pos_m_ned;
struct FloatVect2 ins_gps_speed_m_s_ned;
#endif

/* barometer                   */

int32_t ins_qfe;
bool_t  ins_baro_initialised;
int32_t ins_baro_alt;


/* output                      */
struct NedCoor_i ins_ltp_pos;
struct NedCoor_i ins_ltp_speed;
struct NedCoor_i ins_ltp_accel;


void ins_init() {
#if USE_INS_NAV_INIT
  ins_ltp_initialised = TRUE;

  /** FIXME: should use the same code than MOVE_WP in firmwares/rotorcraft/datalink.c */
  struct LlaCoor_i llh_nav0; /* Height above the ellipsoid */
  llh_nav0.lat = INT32_RAD_OF_DEG(NAV_LAT0);
  llh_nav0.lon = INT32_RAD_OF_DEG(NAV_LON0);
  /* NAV_ALT0 = ground alt above msl, NAV_MSL0 = geoid-height (msl) over ellipsoid */
  llh_nav0.alt = NAV_ALT0 + NAV_MSL0;

  struct EcefCoor_i ecef_nav0;
  ecef_of_lla_i(&ecef_nav0, &llh_nav0);

  ltp_def_from_ecef_i(&ins_ltp_def, &ecef_nav0);
  ins_ltp_def.hmsl = NAV_ALT0;
  stateSetLocalOrigin_i(&ins_ltp_def);
#else
  ins_ltp_initialised  = FALSE;
#endif

  ins_baro_initialised = FALSE;
  vff_init(0., 0., 0.);
  ins.vf_realign = FALSE;
  ins.hf_realign = FALSE;
#if USE_HFF
  b2_hff_init(0., 0., 0., 0.);
#endif
  INT32_VECT3_ZERO(ins_ltp_pos);
  INT32_VECT3_ZERO(ins_ltp_speed);
  INT32_VECT3_ZERO(ins_ltp_accel);

  // TODO correct init
  ins.status = INS_RUNNING;

}

void ins_periodic( void ) {
}

void ins_realign_h(struct FloatVect2 pos __attribute__ ((unused)), struct FloatVect2 speed __attribute__ ((unused))) {
#if USE_HFF
  b2_hff_realign(pos, speed);
#endif /* USE_HFF */
}

void ins_realign_v(float z __attribute__ ((unused))) {
  vff_realign(z);
}

void ins_propagate() {
  /* untilt accels */
  struct Int32Vect3 accel_meas_body;
  INT32_RMAT_TRANSP_VMULT(accel_meas_body, imu.body_to_imu_rmat, imu.accel);
  struct Int32Vect3 accel_meas_ltp;
  INT32_RMAT_TRANSP_VMULT(accel_meas_ltp, (*stateGetNedToBodyRMat_i()), accel_meas_body);
  

  float z_accel_meas_float = ACCEL_FLOAT_OF_BFP(accel_meas_ltp.z);
  if (baro.status == BS_RUNNING && ins_baro_initialised) {
    vff_propagate(z_accel_meas_float);
    ins_ltp_accel.z = ACCEL_BFP_OF_REAL(vff_zdotdot);
    ins_ltp_speed.z = SPEED_BFP_OF_REAL(vff_zdot);
    ins_ltp_pos.z   = POS_BFP_OF_REAL(vff_z);
  }
  else { // feed accel from the sensors
    // subtract -9.81m/s2 (acceleration measured due to gravity, but vehivle not accelerating in ltp)
    ins_ltp_accel.z = accel_meas_ltp.z + ACCEL_BFP_OF_REAL(9.81);
  }


#if USE_HFF
  /* propagate horizontal filter */
  b2_hff_propagate();
#else
  ins_ltp_accel.x = accel_meas_ltp.x;
  ins_ltp_accel.y = accel_meas_ltp.y;
#endif /* USE_HFF */

//MAJ de accel/speed/pos dans state
  INS_NED_TO_STATE();
}

void ins_update_baro() {
  if (baro.status == BS_RUNNING) {
    if (!ins_baro_initialised) {
      ins_qfe = baro.absolute;
      ins_baro_initialised = TRUE;
    }
    if (ins.vf_realign) {
      ins.vf_realign = FALSE;
      ins_qfe = baro.absolute;

      vff_realign(0.);
      ins_ltp_accel.z = ACCEL_BFP_OF_REAL(vff_zdotdot);
      ins_ltp_speed.z = SPEED_BFP_OF_REAL(vff_zdot);
      ins_ltp_pos.z   = POS_BFP_OF_REAL(vff_z);
    }
    else { /* not realigning, so normal update with baro measurement */
      ins_baro_alt = ((baro.absolute - ins_qfe) * INS_BARO_SENS_NUM)/INS_BARO_SENS_DEN;
      float alt_float = POS_FLOAT_OF_BFP(ins_baro_alt);
      vff_update(alt_float);
    }
  }
  INS_NED_TO_STATE();
}

void ins_update_sonar() {
#if USE_SONAR && USE_VFF
  static int32_t sonar_filtered = 0;
  sonar_filtered = (sonar_meas + 2*sonar_filtered) / 3;
  /* update baro_qfe assuming a flat ground */
  if (ins_update_on_agl && baro.status == BS_RUNNING) {
    int32_t d_sonar = (((int32_t)sonar_filtered - ins_sonar_offset) * INS_SONAR_SENS_NUM) / INS_SONAR_SENS_DEN;
    ins_qfe = baro.absolute + (d_sonar * (INS_BARO_SENS_DEN))/INS_BARO_SENS_NUM;
  }
#endif
}
