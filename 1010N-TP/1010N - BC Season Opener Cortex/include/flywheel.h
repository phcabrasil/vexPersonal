#ifndef FLYWHEEL_H_
#define FLYWHEEL_H_

#include "main.h"

extern int fwVoltage;
extern int fwSpeed;

int calculateSpeed();

void moveFlywheel(int speed);

void fwControl();

void stopFwControl();

void startFwControl();

void moveIntake(int speed);

#endif
