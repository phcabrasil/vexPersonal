<<<<<<< HEAD
#include "main.h"
#include "ports.h"

void moveArm(int speed){

 motorSet(ARM_R, speed);
  motorSet(ARM_L1, -speed);
  motorSet(ARM_L2, -speed);

}
=======
#include "main.h"
#include "ports.h"

void moveArm(int speed){

 motorSet(ARM_R, speed);
  motorSet(ARM_L1, -speed);
  motorSet(ARM_L2, -speed);

}
>>>>>>> 3637b237cd0a7285710378320fffdecb427b5c2a
