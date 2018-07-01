#include "main.h"

//function for mobile goal lift
//wire on opposite to the other
void goalLift(int liftSpeed) {
  motorSet(6, liftSpeed);
}

void goalLift_auto(int liftSpeed, int liftTime) {
  goalLift(liftSpeed);
  wait (liftTime);
  goalLift(0);
}
