
#include "main.h"

#define FORWARD 1
#define BACK 1
#define LEFT 1
#define RIGHT 1
#define UP 1
#define DOWN 1

void drive(int direction, int timeout){
  motorSet(DRIVE_RB, 127*direction);
  motorSet(DRIVE_RF, 127*direction);
  motorSet(DRIVE_LB, 127*direction);
  motorSet(DRIVE_LF, 127*direction);
  delay(timeout);
  motorSet(DRIVE_RB, 0);
  motorSet(DRIVE_RF, 0);
  motorSet(DRIVE_LB, 0);
  motorSet(DRIVE_LF, 0);
}

void mogo(int direction, int timeout){
  motorSet(MOGO, 127*direction);
  motorSet(MOGO_A, 127*direction);
  delay(timeout);
  motorSet(MOGO, 0);
  motorSet(MOGO_A, 0);
}

void turn(int direction, int timeout){
  motorSet(DRIVE_RB, 127*direction);
  motorSet(DRIVE_RF, 127*direction);
  motorSet(DRIVE_LB, (-127)*direction);
  motorSet(DRIVE_LF, (-127)*direction);
  delay(timeout);
  motorSet(DRIVE_RB, 0);
  motorSet(DRIVE_RF, 0);
  motorSet(DRIVE_LB, 0);
  motorSet(DRIVE_LF, 0);
}

void autonomous() {
}
