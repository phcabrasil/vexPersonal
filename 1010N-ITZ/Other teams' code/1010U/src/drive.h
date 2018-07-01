#include "main.h"


//function for left half of the drive
void leftDrive(int driveSpeed) {
  motorSet(2, driveSpeed);
  motorSet(3, driveSpeed);
}

//function for the right half of the drive
void rightDrive(int driveSpeed) {
  motorSet(8, driveSpeed);
  motorSet(9, driveSpeed);
}

//auto drive function for front or back
void drive_auto(int driveSpeed, int driveTime){
  rightDrive(driveSpeed);
  leftDrive(driveSpeed);
  wait (driveTime);
  leftDrive(0);
  rightDrive(0);
}

//127 for right turn -127 for left turn
//probably wont work tbh
void turn_auto(int turnSpeed, int turnTime) {
  rightDrive(turnSpeed);
  leftDrive(turnSpeed);
}
