
#ifndef _PROS_MAIN_H_
#define _PROS_MAIN_H_

#define PROS_USE_SIMPLE_NAMES

#define PROS_USE_LITERALS

#include "api.h" //Pros Lib
#include "okapi/api.hpp" //Okapi Lib

//#include "pros/api_legacy.h"

//using namespace pros;
// using namespace pros::literals;
// using namespace okapi;



//Sensors Ports
#define GYRO_PORT 1

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
