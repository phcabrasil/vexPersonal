#include "C:\Users\Curia\Documents\GitHub\vexPersonal\1010N-TP\1010N - BC Season Opener\include\main.h"

int calculateSpeed(){
  int currValue = encoderGet(encoderF);
  int lastValue;
}

void moveFlywheel(int speed){
  motorSet(mtrFlywheelT, -speed);
  motorSet(mtrFlywheelB, -speed);
}

void flywheelSpeed(void*parameter){
  moveFlywheel(fwSpeed);
}

void moveIntake(int speed){
  motorSet(mtrBallIntake, speed);
}
