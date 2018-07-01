#include "main.h"
#include "ports.h"

void moveLift(int speed){

  motorSet(LIFT_L, speed);
  motorSet(LIFT_R, -speed);

}
