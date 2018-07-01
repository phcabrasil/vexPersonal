#include "main.h"
#include "autofunctions.h"
#include "lcdfunctions.h"
#include "ports.h"
#include "arm.h"
#include "drive.h"
#include "intake.h"
#include "chainbar.h"
#include "mblift.h"

void skills() {
}

void mobilered() {
  delay(1000);
  lowerPylon(2000);
 driveForward(1,2000,10000);
 liftPylon(1750);
  turnRight(160);
  driveForward(1,2000,10000);
  turnRight(20);
  driveForward(1,300,10000);
  lowerPylon(1500);
  moveDrive(-127,-127);
  delay(1500);
  moveDrive(0,0);
}

void mobileblue() {
  delay(1000);
  lowerPylon(2000);
 driveForward(1,2000,10000);
 liftPylon(1750);
  turnLeft(160);
  driveForward(1,2000,10000);
  turnLeft(20);
  driveForward(1,400,10000);
  lowerPylon(1500);
  moveDrive(-127,-127);
  delay(1500);
  moveDrive(0,0);
}

void pointblue() {
  delay(1000);
  lowerPylon(2000);
 driveForward(1,2000,10000);
 liftPylon(1750);
  turnLeft(175);
  driveForward(1,1750,10000);
  lowerPylon(1500);
  moveDrive(-127,-127);
  delay(1500);
  moveDrive(0,0);
}

void cuberight() {

}

void drivef() {

}

void backsandpright() {

}

void backsandpleft() {

}

void noauto() {

}

void autonomous() {


switch(myauto){

    case -1:
      noauto();
    break;

    case 0:
      skills();
    break;

    case 1:
      mobilered();
    break;

    case 2:
      mobileblue();
    break;

    case 3:
      pointblue();
    break;

    case 4:

    break;

    case 5:
      drivef();
    break;

    case 6:
      backsandpright();
    break;

    case 7:
      backsandpleft();
    break;

 }
}
