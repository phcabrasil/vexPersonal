#ifndef LCDFUNCTIONS_H_
#define LCDFUNCTIONS_H_

#include "main.h"

void disablelcd(void*ignore);
TaskHandle disablelcd_task;

void opcontrollcd(void*ignore);
TaskHandle opcontrollcd_task;

void autolcd(void*ignore);
TaskHandle autolcd_task;

extern int myauto; //was int

#endif
