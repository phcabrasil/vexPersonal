
#ifndef MAIN_H_

#define MAIN_H_

#include <API.h>

#ifdef __cplusplus
extern "C" {
#endif

//Motors
#define frontLeft1 6
#define frontLeft2 7
#define frontRight1 8
#define frontRight2 9
#define backLeft1 2
#define backLeft2 3
#define backRight1 4
#define backRight2 5
#define armMotor 10
#define intakeMotor 1

//Encoders
#define encoderLeft1 1
#define encoderLeft2 2
#define encoderRight1 5
#define encoderRight2 6
Encoder encoderL;
Encoder encoderR;

//Potentiometer
#define catPot 1

//Ultrasonic Sensor
#define ultra1 3
#define ultra2 4
Ultrasonic ultra;

//Gyro
#define gyroP 3
Gyro gyro;

//Pneumatics
#define solenoid 7

//Get Functions
int getDistance = ultrasonicGet(ultra);
int getTicksL = encoderGet(encoderL);
int getTicksR = encoderGet(encoderR);
int getPosition = analogRead(catPot);
int getAngle = gyroGet(gyro);

void autonomous();
void initializeIO();
void initialize();
void operatorControl();

#ifdef __cplusplus
}
#endif

#endif
