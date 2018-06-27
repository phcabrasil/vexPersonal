#ifndef MAIN_H_

// This prevents multiple inclusion, which isn't bad for this file but is good practice
#define MAIN_H_

#include <API.h>

// Allow usage of this file in C++ programs
#ifdef __cplusplus
extern "C" {
#endif

// Gyro
Gyro gyro;

// Drive Encoders
Encoder encoder1;
Encoder encoder2;

// Claw and Arm Encoders
Encoder chainencoder;

// Main Program Variables
int program;

int myauto;

void autonomous();

void initializeIO();

void initialize();

void operatorControl();

#ifdef __cplusplus
}
#endif

#endif
