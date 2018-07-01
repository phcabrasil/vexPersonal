#include "main.h"
#include "ports.h"

void moveArm(int speed){

 motorSet(ARM_R, speed);
  motorSet(ARM_L, -speed);

}
