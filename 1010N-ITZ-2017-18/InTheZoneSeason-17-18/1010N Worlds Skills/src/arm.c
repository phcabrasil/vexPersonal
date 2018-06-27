#include "main.h"

void moveArm(int speed){

  //motorSet(ARM_R, -speed);
  motorSet(ARM_L, speed);
  motorSet(ARM_RL, -speed);

}
