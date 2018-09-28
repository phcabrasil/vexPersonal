#ifndef FLYWHEEL_H_
#define FLYWHEEL_H_

#include "main.h"

extern int fwVoltage;
extern int fwSpeed;

int calculateSpeed();

void moveFlywheel(int speed);

void flywheelSpeed(void*parameter);
TaskHandle flywheelSpeedHandle;

void moveIntake(int speed);

#endif
