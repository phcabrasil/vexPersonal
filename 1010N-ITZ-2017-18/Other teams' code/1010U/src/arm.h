#include "main.h"

//Wire whcihever motor is on the same side as port 4 as the opposite of the other on the Y cable of 5
void armLift(int liftSpeed) {
  motorSet(5, liftSpeed);
  motorSet(4, -liftSpeed);
  motorSet(7, liftSpeed);
}

//auto
void armLift_auto(int liftSpeed, int liftTime) {
  armLift(liftSpeed);
  wait (liftTime);
  armLift(0);
}
