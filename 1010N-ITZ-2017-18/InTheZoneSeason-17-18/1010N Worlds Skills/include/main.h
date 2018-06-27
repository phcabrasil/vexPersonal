#ifndef MAIN_H_
#define MAIN_H_

#include <API.h>

#ifdef __cplusplus
extern "C" {
#endif

//Motor Ports
#define DRIVE_RF 9
#define DRIVE_RB 3 //Power Expander D
#define DRIVE_LF 8
#define DRIVE_LB 2
#define ARM_L 5 //Power Expander A
#define ARM_RL 4
#define INTAKE 10
#define CHAINBAR 7 //Power Expander B
#define MOGO_R 1
#define MOGO_L 6

//Sensors
Encoder encoderL; //Ports 5&6
Encoder encoderR; //Ports 2&1
Ultrasonic sonar; //Ports 3&4
Gyro gyro; //Port 3

//Sensor Ports
#define GYRO 3
#define ARMPOT 5
#define CHAINPOT 1
#define MOGOPOT 4
#define ULTRASONIC_L 3
#define ULTRASONIC_R 4
#define BUTTON 7

//LED Ports
#define LED_STRP 9
#define LED_RED 10
#define LED_YLW 11
#define LED_GRN 12

int autostack;
int myauto;
int armtargetValue;

void autonomous();
void initializeIO();
void initialize();
void operatorControl();

#ifdef __cplusplus
}
#endif

#endif
