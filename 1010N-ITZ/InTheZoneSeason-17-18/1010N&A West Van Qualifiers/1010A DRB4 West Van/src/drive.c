#include "main.h"

void moveDrive(int left, int right){

  motorSet(DRIVE_LF, (left));
  motorSet(DRIVE_LB, (left));

  motorSet(DRIVE_RF, -(right));
  motorSet(DRIVE_RB, -(right));

}
