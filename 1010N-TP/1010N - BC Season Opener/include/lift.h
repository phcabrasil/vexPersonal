#ifndef LIFT_H_
#define LIFT_H_

#include "main.h"

void moveLift(int speed);

void lift(int direction, int targetHeight, int timeout, float kp, float kd); //Lift Function PID

void liftPID(void*parameter);

void liftDown(void*parameter);

void capIntake(int direction, int targetHeight, int timeout); //Cap Intake Function PD

#endif
