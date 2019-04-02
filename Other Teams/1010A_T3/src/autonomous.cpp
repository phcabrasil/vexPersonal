#include "main.h"
#include "functions.hpp"
#include "lcd.h"
using namespace okapi;
void autonomous() {
  Functions autoDrive; //creates a new instance of our functions class
  auto angleController = okapi::AsyncControllerFactory::posIntegrated(AnglerPORT); //creates a new angle controller
  double AngleTarget = angleController.getTarget(); //gets targetvalue of the angle controller
  //sensors
  auto startingPosition = angler.get_position(); //gets position of the angle controller
  int currentTime = 0;

/*  if(currentAuto == 3){ //see lcd.cpp for how the currentAuto is selected
    //RED CAPS
  angleController.setMaxVelocity(100);
  angleController.setTarget(startingPosition - 62);
  angleController.waitUntilSettled();
  delay(600);
  LinearLeft.move(127);
  LinearRight.move(127);
  delay(800);
  autoDrive.stopEverything();
  angleController.setTarget(startingPosition);
  autoDrive.turnValue(DIRECTION_RIGHT, 310, 1000, 0.8, 0.34237);
  autoDrive.stopDriving();
  Roller.move(127);
  autoDrive.driveValue(DIRECTION_FORWARD, 1150, 1100, 0.8, 0.7);
  autoDrive.stopDriving();
  delay(300);
  Roller.move(0);
  autoDrive.driveValue(DIRECTION_BACKWARD, 350, 850, 0.8, 0.7);
  autoDrive.stopEverything();
  Roller.move(-127);
  autoDrive.strafeValue(DIRECTION_RIGHT, 770, 1100, 0.8, 0.7);
  autoDrive.stopDriving();
  delay(100);
  autoDrive.driveValue(0.7, 645, 1000, 0.8, 0.7);
  autoDrive.stopEverything();
  autoDrive.driveValue(DIRECTION_BACKWARD, 352, 1000, 0.8, 0.7);
  autoDrive.stopEverything();
  autoDrive.turnValue(DIRECTION_LEFT, 450, 1000, 0.8, 0.7);
  autoDrive.stopEverything();
//  autoDrive.driveValue(DIRECTION_BACKWARD, 400, 1000, 0.8, 0.7);
  Roller.move(127);
  autoDrive.driveValue(1, 1950, 3000, 0.8, 0.7);
  autoDrive.stopDriving();
  autoDrive.turnValue(DIRECTION_RIGHT, 100, 750, 0.8, 0.7);
  //Roller.move(127);
*/

//  else if(currentAuto == 1 || (currentAuto == 0)){ //or conditional for default auto
    //BLUE CAPS
    angleController.setMaxVelocity(100);
    angleController.setTarget(startingPosition - 62);
    angleController.waitUntilSettled();
    delay(600);
    LinearLeft.move(127);
    LinearRight.move(127);
    delay(600);
    autoDrive.stopEverything();
    angleController.setTarget(startingPosition);
    autoDrive.turnValue(DIRECTION_LEFT, 300, 1000, 0.8, 0.7);
    autoDrive.stopDriving();
    Roller.move(127);
    autoDrive.driveValue(DIRECTION_FORWARD, 1150, 1100, 0.8, 0.7);
    autoDrive.stopDriving();
    delay(300);
    Roller.move(0);
    autoDrive.driveValue(DIRECTION_BACKWARD, 350, 850, 0.8, 0.7);
    autoDrive.stopEverything();
    Roller.move(-127);
    autoDrive.strafeValue(DIRECTION_LEFT, 770, 1100, 0.8, 0.7);
    //autoDrive.stopEverything();
    delay(100);
    //Roller.move(-127);
    autoDrive.driveValue(0.7, 620, 1000, 0.8, 0.7);
    autoDrive.stopEverything();
    autoDrive.driveValue(DIRECTION_BACKWARD, 320, 1000, 0.8, 0.7);
    autoDrive.stopEverything();
    autoDrive.turnValue(DIRECTION_RIGHT, 405, 1000, 0.8, 0.7);
    autoDrive.stopEverything();
    Roller.move(127);
  //  autoDrive.driveValue(DIRECTION_BACKWARD, 400, 1000, 0.8, 0.7);
      autoDrive.driveValue(DIRECTION_FORWARD, 1900, 3000, 0.8, 0.7);
    autoDrive.stopDriving();
//    autoDrive.turnValue(DIRECTION_LEFT, 100, 750, 0.8, 0.7);
    // Roller.move(127);
  /*}
  else if(currentAuto == 4){


  }
  else if(currentAuto == 5){
    //Skills
    angleController.setMaxVelocity(300);
    angleController.setTarget(startingPosition - 62);
    angleController.waitUntilSettled();
    delay(600);
    LinearLeft.move(127);
    LinearRight.move(127);
    delay(800);
    autoDrive.stopEverything();
    angleController.setTarget(startingPosition);
    autoDrive.turnValue(DIRECTION_LEFT, 315, 1000, 0.8, 0.7);
    autoDrive.stopDriving();
    Roller.move(-127);
    autoDrive.driveValue(DIRECTION_FORWARD, 1150, 1100, 0.8, 0.7);
    autoDrive.stopDriving();
    delay(300);
    Roller.move(0);
    autoDrive.driveValue(DIRECTION_BACKWARD, 270, 850, 0.8, 0.7);
    autoDrive.stopEverything();
    autoDrive.strafeValue(DIRECTION_LEFT, 700, 1100, 0.8, 0.7);
    autoDrive.stopEverything();
    delay(100);
    Roller.move(-127);
    autoDrive.driveValue(0.5, 620, 1000, 0.8, 0.7);
    autoDrive.stopEverything();
    autoDrive.driveValue(DIRECTION_BACKWARD, 225, 1000, 0.8, 0.7);
    autoDrive.stopEverything();
    autoDrive.turnValue(DIRECTION_RIGHT, 470, 1000, 0.8, 0.7);
    autoDrive.stopEverything();
    Roller.move(127);
  //  autoDrive.driveValue(DIRECTION_BACKWARD, 400, 1000, 0.8, 0.7);
    autoDrive.driveValue(1, 1950, 3000, 0.8, 0.7);
    autoDrive.stopDriving();
    autoDrive.turnValue(DIRECTION_LEFT, 100, 750, 0.8, 0.7);
    // Roller.move(127);

  }*/
}
