#ifndef AUTOFUNCTIONS_H_
#define AUTOFUNCTIONS_H_

#include "main.h"

void turn_pid();

void turnRight();

void pointblue();

void turnLeft();

void drive_encoder();

void stopEverything();

void driveForward();

void driveBack();

void turn();

void liftArm();

void lowerArm();

void liftPylon();

void lowerPylon();

void getCone();

void dropCone();

void chainIn();

void chainOut();

int motorcap(int value);

float kp;

float ki;

float kd;

long runTime;

long startTime;

int diff;

int totalError;

int lastError;

int currError;

long runTime;

long startTime;


#endif
