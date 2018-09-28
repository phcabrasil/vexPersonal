#ifndef DRIVE_H_
#define DRIVE_H_

#include "main.h"

void moveDrive(int left, int right); // Move Drive

void moveDriveAim(int left, int right, int cap); // Move Drive Slowly

void drive(int direction, int target); //Drive Function

void drivePID(int direction, int target, int kp, int ki, int kd, int timeout); //Drive PID Function

void turn(int direction, int targetTurn, int timeout, float kp, float kd); //Turn Relative Function

void turnBack(int direction, int timeout, float kp, float kd); //Turn Back Absolute Function

#endif
