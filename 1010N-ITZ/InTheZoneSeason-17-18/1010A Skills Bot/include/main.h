#ifndef MAIN_H_
#define MAIN_H_

#include <API.h>

#ifdef __cplusplus
extern "C" {
#endif

//Motor Ports
#define DRIVE_RF 3
#define DRIVE_RB 5 //Power Expander D
#define DRIVE_LF 8 //Power Expander C
#define DRIVE_LB 6
#define DRIVE_RM 4
#define DRIVE_LM 7
#define MOGO_R 2
#define MOGO_L 9
#define INTAKE 1

//Sensor Ports
Encoder encoderL;
Encoder encoderR;

Gyro gyro;
#define GYRO 3
#define ARMPOT 2
#define CHAINPOT 1
#define MOGOPOT 1

int myauto;
void autonomous();
void initializeIO();
void initialize();
void operatorControl();

#ifdef __cplusplus
}
#endif

#endif
