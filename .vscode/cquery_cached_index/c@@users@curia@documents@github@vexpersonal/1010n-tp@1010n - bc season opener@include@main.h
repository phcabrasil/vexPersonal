#ifndef MAIN_H_

#define MAIN_H_

#include "API.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "okapi\api.hpp"

// Motors
#define mtrDriveRF 3
#define mtrDriveLF 8 // D
#define mtrDriveRB 7 // A
#define mtrDriveLB 4
#define mtrElevatorR 2 // B
#define mtrElevatorL 9
#define mtrFlywheelT 5 // C
#define mtrFlywheelB 6
#define mtrBallIntake 1
#define mtrCapIntake 10

// Sensors
Encoder encoderL; //Ports 5&6 Digital
Encoder encoderR; //Ports 2&1 Digital
Encoder encoderA; //Ports 7&8 Digital
Encoder encoderF; //Port 9&10 Digital
Gyro relativeGyro; //Port 1 Analog
Gyro absoluteGyro; //Port 2 Analog

// Sensor Ports
#define RGYRO 3 //Analog
#define AGYRO 4 //Analog
#define CAPPOT 1 //Analog
#define ENCR1 2 //Digital
#define ENCR2 1 //Digital
#define ENCL1 8 //Digital
#define ENCL2 7 //Digital
#define ENCA1 6 //Digital
#define ENCA2 5 //Digital
#define ENCF1 9 //Digital
#define ENCF2 10 //Digital
#define BALLSLIMIT 3 //Digital
#define LIFTLIMIT 4 //Digital

// Variables
int myauto;
int fwVoltage;
int fwSpeed;

void autonomous();
void initializeIO();
void initialize();
void operatorControl();

#ifdef __cplusplus
}
#endif

#endif
