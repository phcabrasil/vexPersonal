#ifndef AUTOFUNCTIONS_H_
#define AUTOFUNCTIONS_H_

#include "main.h"

extern int positionTarget;

//********************************
//       Functions
//********************************

void drive(int direction, int target); //Autonomous Drive Function

void drivePID(int direction, int target, int kp, int ki, int kd, int timeout); //Autonomous Drive PID Function

void stopEverything(); //Fucntion to Stop Everything

void motorCap(int what, int speed); //Motor Cap

void resetEverything();//Resetting Everything

void turn(int direction, int targetTurn, int timeout, float kp, float kd); //Autonomous Turn Function

void arm(void*parameter); //Arm Position Function
TaskHandle arm_position;

void intakeDistance(void*parameter); //Intake Function
TaskHandle intake;

void fourBar(void*parameter); //Pneumatic 4Bar Function
TaskHandle fourbar_position;

extern bool intakeposition;
extern bool barposition;
extern int armposition;

#endif
