#ifndef _DRIVE_HPP_
#define _DRIVE_HPP_

#include "main.h"

class driveClass {

public:

void timeDrive (int speed, int delay);
void drive(int direction, int target, int timeout, float kp, float kd);
void strafe(int direction, int target, int timeout, float kp, float kd);
void turn(int direction, int target, int timeout, float kp, float kd);

};

#endif
