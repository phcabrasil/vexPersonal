#ifndef MAIN_H_
#define MAIN_H_

#include <API.h>

#ifdef __cplusplus
extern "C" {
#endif

//Motor Ports
#define DRIVE_RF 3
#define DRIVE_RB 2 //Power Expander D
#define DRIVE_LF 8 //Power Expander C
#define DRIVE_LB 9
#define ARM_R 5
#define ARM_L 6 //Power Expander A
#define ARM_RL 7 //Y CABLE
#define MOGO 10
#define INTAKE 1
#define CHAINBAR 4 //Power Expander B //Y CABLE

//Sensor Ports
Encoder encoderL;
Encoder encoderR;

Gyro gyro;
#define GYRO 3
#define ARMPOT 2
#define CHAINPOT 1
#define MOGOPOT 4

int myauto;
void autonomous();
void initializeIO();
void initialize();
void operatorControl();

#ifdef __cplusplus
}
#endif

#endif
