
#ifndef _PROS_MAIN_H_
#define _PROS_MAIN_H_

#define PROS_USE_SIMPLE_NAMES

#define PROS_USE_LITERALS

#include "api.h"
#include "okapi/api.hpp"
//#include "pros/api_legacy.h"

// using namespace pros;
// using namespace pros::literals;
// using namespace okapi;

//Motors
//Left
#define driveLF 1 //Drive Left Front
#define driveLM 3 //Drive Left Middle
#define driveLB -2 //Drive Left Back
//Right
#define driveRF -10 //Drive Right Front
#define driveRM -8 //Drive Right Middle
#define driveRB 9 //Drive Right Back

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

//#include <iostream>

#endif

#endif  // _PROS_MAIN_H_
