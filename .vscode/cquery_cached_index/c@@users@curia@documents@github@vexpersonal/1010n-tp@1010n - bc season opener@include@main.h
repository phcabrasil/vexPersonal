#ifndef MAIN_H_

#define MAIN_H_

#include "API.h"

#ifdef __cplusplus
extern "C" {
#endif

// Motors
#define mtrDriveRF 3
#define mtrDriveLF 4
#define mtrDriveRM 5
#define mtrDriveLM 6
#define mtrDriveRB 7
#define mtrDriveLB 8
#define mtrsElevator 2
#define mtrsFlywheel 9
#define mtrBallIntake 1
#define mtrCapIntake 10

// Sensors
Encoder encoderR;
Encoder encoderL;
Gyro gyro;


// Variables


void autonomous();
void initializeIO();
void initialize();
void operatorControl();

#ifdef __cplusplus
}
#endif

#endif
