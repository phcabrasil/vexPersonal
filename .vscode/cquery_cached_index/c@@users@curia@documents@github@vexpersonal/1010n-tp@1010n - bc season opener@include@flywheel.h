#ifndef FLYWHEEL_H_
#define FLYWHEEL_H_

#include "C:\Users\Curia\Documents\GitHub\vexPersonal\1010N-TP\1010N - BC Season Opener\include\main.h"

extern int fwVoltage;
extern int fwSpeed;

int calculateSpeed();

void moveFlywheel(int speed);

void fwControl();

void stopFwControl();

void startFwControl();

void moveIntake(int speed);

#endif
