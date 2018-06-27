#ifndef AUTOFUNCTIONS_H_
#define AUTOFUNCTIONS_H_

#include "main.h"

extern int armTarget;

extern int currentChain;

void stopEverything(); //Fucntion to Stop Everything

void motorCap(int what, int speed); //Motor Cap

void drive(int direction, int target); //Autonomous Drive Function

void turn(int direction, int targetTurn, int timeout, float kp, float kd); //Autonomous Turn Function

#endif
