#ifndef _PROS_MAIN_H_
#define _PROS_MAIN_H_
#define PROS_USE_SIMPLE_NAMES
#define PROS_USE_LITERALS

#include "api.h"
#include "robot_includes/robot_includes.hpp"
#include "pros/apix.h"
#include "okapi/api.hpp"

//Controllers
extern pros::Controller master;
extern pros::Controller partner;

//Motors
extern pros::Motor left_back_mtr;
extern pros::Motor left_front_mtr;
extern pros::Motor right_front_mtr;
extern pros::Motor arm_mtr;
extern pros::Motor right_back_mtr;
extern pros::Motor intake_mtr;
extern pros::Motor intake_mtr_two;
extern pros::Motor angler_mtr;

//Sensors
extern pros::Imu imu;
extern pros::ADIDigitalIn liftLim;
extern pros::ADIDigitalIn rampLim;
extern pros::ADIUltrasonic lUltra;
extern pros::ADIUltrasonic rUltra;

//Objects
extern Chassis chassis;
extern Lift lift;
extern PID drive_PID;
extern PID turn_PID;
extern PID pivot_PID;
extern PID fenceL_PID;
extern PID fenceR_PID;

extern PID outerCurve_PID;
extern PID innerCurve_PID;
extern PID ramp_PID;
extern PID lift_PID;

//Global Variables
extern int intake_state;
extern int lift_state;
extern int lift_target;
extern int auto_state;
extern int ramp_state;

//Lift States
#define INTAKING 0
#define SLOW_INTAKING 5500
#define TOWERMEME 298
#define LOW_TOWER 1
#define MID_TOWER 2
#define DEPLOY 4

//Drive States
#define FORWARD 1
#define BACKWARDS -1
#define RIGHT 1
#define LEFT -1

//Ramp States
#define SCORING 1
#define RETURN 2
#define LOCKED 69
#define SLOW_RETURN 420

//Intake States
#define SLOW 0
#define INTAKE 1
#define EXPEL 2
#define MANUAL 3
#define STOP 4

#ifdef __cplusplus
extern "C" {
#endif
void autonomous(void);
void initialize(void);
void disabled(void);
void competition_initialize(void);
void opcontrol(void);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
/**
 * You can add C++-only headers here
 */
//#include <iostream>
#endif

#endif  // _PROS_MAIN_H_
