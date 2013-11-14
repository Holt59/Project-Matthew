/* This file has been generated from /home/nicolas/paparazzi/conf/flight_plans/rotorcraft_basic2.xml */
/* Please DO NOT EDIT */

#ifndef FLIGHT_PLAN_H
#define FLIGHT_PLAN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../std.h"

//#include "autopilot.h"
#define FLIGHT_PLAN_NAME "Booz Test Enac"
#define NAV_UTM_EAST0 377349
#define NAV_UTM_NORTH0 4824583
#define NAV_UTM_ZONE0 31
#define NAV_LAT0 435641194 /* 1e7deg */
#define NAV_LON0 14812805 /* 1e7deg */
#define NAV_ALT0 147000 /* mm above msl */
#define NAV_MSL0 51850 /* mm, EGM96 geoid-height (msl) over ellipsoid */
#define QFU 0.0
#define WP_dummy 0
#define WP_HOME 1
#define WP_CLIMB 2
#define WP_STDBY 3
#define WP_p1 4
#define WP_p2 5
#define WP_p3 6
#define WP_p4 7
#define WP_CAM 8
#define WP_TD 9
#define WAYPOINTS { \
 {42.0, 42.0, 152},\
 {0.0, 0.0, 152},\
 {0.0, 5.0, 152},\
 {-2.0, -5.0, 152},\
 {3.6, -13.9, 152},\
 {27.5, -48.2, 152},\
 {16.7, -19.6, 152},\
 {13.7, -40.7, 152},\
 {-20.0, -50.0, 149.},\
 {5.6, -10.9, 152},\
};
#define WAYPOINTS_LLA { \
 {435645043, 14817909, 15200}, /* 1e7deg, 1e7deg, cm (hmsl=51.85m) */ \
 {435641194, 14812805, 15200}, /* 1e7deg, 1e7deg, cm (hmsl=51.85m) */ \
 {435641644, 14812794, 15200}, /* 1e7deg, 1e7deg, cm (hmsl=51.85m) */ \
 {435640741, 14812569, 15200}, /* 1e7deg, 1e7deg, cm (hmsl=51.85m) */ \
 {435639949, 14813282, 15200}, /* 1e7deg, 1e7deg, cm (hmsl=51.85m) */ \
 {435636901, 14816318, 15200}, /* 1e7deg, 1e7deg, cm (hmsl=51.85m) */ \
 {435639457, 14814917, 15200}, /* 1e7deg, 1e7deg, cm (hmsl=51.85m) */ \
 {435637553, 14814593, 15200}, /* 1e7deg, 1e7deg, cm (hmsl=51.85m) */ \
 {435636661, 14810443, 15200}, /* 1e7deg, 1e7deg, cm (hmsl=51.85m) */ \
 {435640222, 14813523, 15200}, /* 1e7deg, 1e7deg, cm (hmsl=51.85m) */ \
};
#define NB_WAYPOINT 10
#define NB_BLOCK 8
#define GROUND_ALT 147.
#define GROUND_ALT_CM 14700
#define SECURITY_HEIGHT 2.
#define SECURITY_ALT 149.
#define HOME_MODE_HEIGHT 2.
#define MAX_DIST_FROM_HOME 400.
#ifdef NAV_C

static inline void auto_nav(void) {
  switch (nav_block) {
    Block(0) // Holding point
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        if (! (NavKillThrottle()))
          NextStageAndBreak();
        break;
      Stage(1)
        if (FALSE) NextStageAndBreak() else {
          NavAttitude(RadOfDeg(0));
          NavVerticalAutoThrottleMode(RadOfDeg(0));
          NavVerticalThrottleMode(9600*(0));
        }
        break;
      default:
      Stage(2)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(1) // Start Engine
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        if (! (NavResurrect()))
          NextStageAndBreak();
        break;
      Stage(1)
        if (FALSE) NextStageAndBreak() else {
          NavAttitude(RadOfDeg(0));
          NavVerticalAutoThrottleMode(RadOfDeg(0));
          NavVerticalThrottleMode(9600*(0));
        }
        break;
      default:
      Stage(2)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(2) // Takeoff
    ; // pre_call
    if ((nav_block != 3) && ((stateGetPositionEnu_f())->z>2.000000)) { GotoBlock(3); return; }
    switch(nav_stage) {
      Stage(0)
        NavGotoWaypoint(2);
        NavVerticalAutoThrottleMode(RadOfDeg(0.000000));
        NavVerticalClimbMode(0.500000);
        break;
      default:
      Stage(1)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(3) // Standby
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        NavGotoWaypoint(3);
        NavVerticalAutoThrottleMode(RadOfDeg(0.000000));
        NavVerticalAltitudeMode(WaypointAlt(3), 0.);
        break;
      default:
      Stage(1)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(4) // land here
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        if (! (NavSetWaypointHere(WP_TD)))
          NextStageAndBreak();
        break;
      default:
      Stage(1)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(5) // land
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        if (NavApproaching(9,CARROT)) NextStageAndBreakFrom(9) else {
          NavGotoWaypoint(9);
          NavVerticalAutoThrottleMode(RadOfDeg(0.000000));
          NavVerticalAltitudeMode(WaypointAlt(9), 0.);
        }
        break;
      default:
      Stage(1)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(6) // flare
    ; // pre_call
    if ((nav_block != 0) && NavDetectGround()) { GotoBlock(0); return; }
    switch(nav_stage) {
      Stage(0)
        if (! (NavStartDetectGround()))
          NextStageAndBreak();
        break;
      Stage(1)
        NavGotoWaypoint(9);
        NavVerticalAutoThrottleMode(RadOfDeg(0.000000));
        NavVerticalClimbMode(-(0.800000));
        break;
      default:
      Stage(2)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(7) // HOME
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        nav_home();
        break;
      default:
      Stage(1)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    default: break;
  }
}
#endif // NAV_C

#ifdef __cplusplus
}
#endif

#endif // FLIGHT_PLAN_H
