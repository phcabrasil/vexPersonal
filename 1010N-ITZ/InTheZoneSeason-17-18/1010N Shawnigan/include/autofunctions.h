#ifndef AUTOFUNCTIONS_H_
#define AUTOFUNCTIONS_H_

#include "main.h"

void stopEverything(); //Fucntion to Stop Everything

void motorCap(int what, int speed); //Motor Cap

void drive(int direction, int target); //Autonomous Drive Function

void turn(int direction, int targetTurn, int timeout, float kp, float kd); //Autonomous Turn Function

void armPID(int targetValue, float kp, float kd); //ArmPID for OpControl

void arm(int direction, int targetValue, int timeout, float kp, float kd); //ArmPID for Autonomous

void barup(int direction, int targetValue, int timeout, float kp, float kd); //FourBarPID for Autonomous

void mogo(int direction, int timeout); //Mobile Goal Function

void bardown(int direction, int targetValue, int timeout, float kp, float kd);

void intake(int direction, int delay); //Intake Function

#endif
