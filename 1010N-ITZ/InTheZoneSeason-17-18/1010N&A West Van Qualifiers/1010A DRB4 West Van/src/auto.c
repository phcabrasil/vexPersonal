#include "main.h"
#include "autofunctions.h"
#include "lcdfunctions.h"
#include "drive.h"
#include "intake.h"
#include "chainbar.h"
#include "mogo.h"
#include "arm.h"

#define UP -1
#define DOWN 1
#define FORWARD 1
#define BACK -1
#define RIGHT 1
#define LEFT -1

void skills() {

  encoderReset(encoderL);
  encoderReset(encoderR);
  arm(UP, 15, 500, 1.5, 3); //ShakeArm
  arm(DOWN, 15, 500, 1.5, 3); //ShakeArm
  chainup(2500, 3000, 1.5, 6);
  moveMogo(-127);
  delay(500);
  drive(FORWARD,800);
  delay(200);
  moveMogo(127);
  delay(1500);
  moveMogo(0);
  turn(LEFT, 200, 2000, 1.5, 3);
  moveIntake(127);
  drive(FORWARD,750);
  moveIntake(0);
  turn(LEFT, 110, 1500, 1.5, 3);
  drive(FORWARD, 400);//WAS 275
  turn(RIGHT, 110, 1500, 1.5, 3);
  moveDrive(127,127);
  delay(2000);
  moveDrive(0,0);
  moveMogo(-127);
  delay(1500);
  moveDrive(-127,-127);
  delay(100);
  moveMogo(127);
  delay(400);
  moveMogo(0);
  delay(500);
  turn(LEFT,110,1500,1.5,3);
  drive(FORWARD, 300);
  turn(LEFT,110,1500,1.5,3);
  moveMogo(-127);
  drive(FORWARD,800);
  delay(200);
  moveMogo(127);
  delay(1500);
  moveMogo(0);
  turn(LEFT, 200, 2000, 1.5, 3);
  drive(FORWARD,800);
  moveMogo(-127); //Drop mobile goal
  delay(1300); //Timeout drop mobile goal
  moveDrive(-127,-127);
  delay(200);
  moveMogo(127);
  delay(400);
  stopEverything();
}

void mobileleftred() {

  encoderReset(encoderL);
  encoderReset(encoderR);
  moveIntake(127);
  delay(500);
  moveArm(-127);
  delay(500);
  chainup(400, 1500, 0.3, 9);
  moveArm(127); //Arm Up to open way for Mogo and Intake
  //arm(1, 700, 1500, 0.5 , 3);//
  delay(500);
  moveArm(0);
  moveMogo(127); //Mogo Down
  drive(FORWARD, 1300); //Drive Forward Towards MobileGoal
  moveMogo(0); //Mogo Stop
  delay(300); //Timeout break
  moveIntake(-127); //Let go of cone
  delay(500);
  moveIntake(0);
  moveMogo(-127); //Pick up mobile goal
  delay(2000); //Timeout pick up
  moveMogo(0); //Stop mobile goal
  turn(RIGHT,190,2700,1.5,4); //Turn right 210 degrees towards stationary goal
  drive(FORWARD, 1100); //Drive back to start
  turn(RIGHT,60,700,1.5,3); //Turn right towards scoring zones
  moveDrive(127,127); //Drive into 10 point zone
  delay(300); //Timeout drive over pipe
  moveDrive(0,0); //Stop drive
  moveMogo(127); //Drop mobile goal
  delay(1300); //Timeout drop mobile goal
  moveDrive(-127,-127);
  delay(200);
  moveMogo(-127);
  delay(400);
  stopEverything();
}

void mobilerightblue() {

  encoderReset(encoderL);
  encoderReset(encoderR);
  moveIntake(127);
  delay(500);
  moveArm(-127);
  delay(500);
  chainup(400, 1500, 0.3, 9);
  moveArm(127); //Arm Up to open way for Mogo and Intake
  //arm(1, 700, 1500, 0.5 , 3);//
  delay(500);
  moveArm(0);
  moveMogo(127); //Mogo Down
  drive(FORWARD, 1300); //Drive Forward Towards MobileGoal
  moveMogo(0); //Mogo Stop
  delay(300); //Timeout break
  moveIntake(-127); //Let go of cone
  delay(500);
  moveIntake(0);
  moveMogo(-127); //Pick up mobile goal
  delay(2000); //Timeout pick up
  moveMogo(0); //Stop mobile goal
  turn(LEFT,190,2700,1.5,4); //Turn right 210 degrees towards stationary goal
  drive(FORWARD, 1000); //Drive back to start
  turn(LEFT,60,700,1.5,3); //Turn right towards scoring zones
  moveMogo(127); //Drop mobile goal
  delay(1300); //Timeout drop mobile goal
  moveDrive(-127,-127);
  delay(200);
  moveMogo(-127);
  delay(400);
  stopEverything();

}

void mobilerightred() {

  encoderReset(encoderL);
  encoderReset(encoderR);
  moveIntake(-40); //Hold PreLoad until Mobile Goal
  arm(UP, 15, 500, 1.5, 3); //ShakeArm
  arm(DOWN, 15, 500, 1.5, 3); //ShakeArm
  chainup(2500, 1500, 1.5, 9); //Arm Up to open way for Mogo and Intake
  moveMogo(-127); //Mogo Down
  drive(FORWARD, 1300); //Drive Forward Towards MobileGoal
  moveMogo(0); //Mogo Stop
  delay(300); //Timeout break
  moveMogo(127); //Pick up mobile goal
  delay(1500); //Timeout pick up
  moveMogo(0); //Stop mobile goal
  moveIntake(127); //Let go of cone
  delay(1000); //Timeout rollers
  moveIntake(0); //Stop intake
  turn(RIGHT,210,2700,1.5,4); //Turn right 210 degrees towards stationary goal
  drive(FORWARD, 1000); //Drive back to start
  turn(RIGHT,55,700,1.5,3); //Turn right towards scoring zones
  moveDrive(127,127); //Drive into 10 point zone
  delay(450); //Timeout drive over pipe
  moveDrive(0,0); //Stop drive
  moveMogo(-127); //Drop mobile goal
  delay(1300); //Timeout drop mobile goal
  moveDrive(-127,-127);
  delay(200);
  moveMogo(127);
  delay(400);
  stopEverything();
}

void mobileleftblue() {

  encoderReset(encoderL);
  encoderReset(encoderR);
  moveIntake(127);
  delay(500);
  moveArm(-127);
  delay(500);
  chainup(400, 1500, 0.3, 9);
  moveArm(127); //Arm Up to open way for Mogo and Intake
  //arm(1, 700, 1500, 0.5 , 3);//
  delay(500);
  moveArm(0);
  moveMogo(127); //Mogo Down
  drive(FORWARD, 1300); //Drive Forward Towards MobileGoal
  moveMogo(0); //Mogo Stop
  delay(300); //Timeout break
  moveIntake(-127); //Let go of cone
  delay(500);
  moveIntake(0);
  moveMogo(-127); //Pick up mobile goal
  delay(2000); //Timeout pick up
  moveMogo(0); //Stop mobile goal
  turn(RIGHT,190,2700,1.5,4); //Turn right 210 degrees towards stationary goal
  drive(FORWARD, 1100); //Drive back to start
  turn(RIGHT,60,700,1.5,3); //Turn right towards scoring zones
  moveDrive(127,127); //Drive into 10 point zone
  delay(300); //Timeout drive over pipe
  moveDrive(0,0); //Stop drive
  moveMogo(127); //Drop mobile goal
  delay(1300); //Timeout drop mobile goal
  moveDrive(-127,-127);
  delay(200);
  moveMogo(-127);
  delay(400);
  stopEverything();
}

void stationarygoalred() {

  encoderReset(encoderL);
  encoderReset(encoderR);
  moveIntake(-40);
  moveChainBar(127);
  arm(UP, 60, 1000,1.5,3);//100
  moveChainBar(0);
  drive(FORWARD,525);
  //delay(300);
  arm(DOWN,20,1000,1.5,3);
  moveIntake(127);//2
  delay(100);
  arm(UP, 40, 1000,1.5,3);
  drive(BACK,250);
  moveIntake(-127);
  delay(200);
  moveArm(127);
  turn(RIGHT,105,1000,1.5,3);
  moveArm(0);
  drive(FORWARD,30);//was 40
  /*moveArm(127);
  delay(500);//500
  moveArm(0);*/
  moveChainBar(-127);
  delay(700);
  moveChainBar(0);
  delay(700);
  drive(BACK,25);
  turn(LEFT,100,1000,1.5,3);
  //chainup(UP, 2300, 3000, 1.5, 3);
  moveChainBar(127);
  arm(UP, 50, 1000,1.5,3);
  moveArm(-10);//was 70
  moveChainBar(0);
  drive(FORWARD,295);//275
  //delay(300);
  moveIntake(127);
  delay(700);
  arm(UP, 60, 1000,1.5,3);
  drive(BACK,250);
  stopEverything();
}

void stationarygoalblue(){

  encoderReset(encoderL);
  encoderReset(encoderR);
  moveIntake(-40);
  moveChainBar(127);
  arm(UP, 60, 1000,1.5,3);//100
  moveChainBar(0);
  drive(FORWARD,525);
  //delay(300);
  arm(DOWN,20,1000,1.5,3);
  moveIntake(127);//2
  delay(100);
  arm(UP, 40, 1000,1.5,3);
  drive(BACK,250);
  moveIntake(-127);
  delay(200);
  moveArm(127);
  turn(LEFT,100,1000,1.5,3);
  moveArm(0);
  drive(FORWARD,40);
  /*moveArm(127);
  delay(500);//500
  moveArm(0);*/
  moveChainBar(-127);
  delay(700);
  moveChainBar(0);
  delay(700);
  drive(BACK,25);
  turn(RIGHT,100,1000,1.5,3);
  //chainup(UP, 2300, 3000, 1.5, 3);
  moveChainBar(127);
  arm(UP, 50, 1000,1.5,3);
  moveArm(-10);//was 70
  moveChainBar(0);
  drive(FORWARD,275);//275
  //delay(300);
  moveIntake(127);
  delay(700);
  arm(UP, 60, 1000,1.5,3);
  drive(BACK,250);
  stopEverything();
}

void pointred() {

  encoderReset(encoderL);
  encoderReset(encoderR);
  moveIntake(-40); //Hold PreLoad until Mobile Goal
  chainup(2500, 1500, 1.5, 9); //Arm Up to open way for Mogo and Intake
  moveMogo(-127);
  drive(FORWARD, 1400);
  moveMogo(0);
  delay(300);
  moveMogo(127);
  delay(1300);
  moveMogo(0);
  moveIntake(127);
  delay(500);
  moveIntake(0);
  turn(RIGHT,210,2700,1.5,3);// 210 before
  drive(FORWARD, 1000);
  moveDrive(127,127);
  delay(1000);
  moveDrive(0,0);
  moveMogo(-127);
  delay(1300);
  moveDrive(-127,-127);
  delay(200);
  moveMogo(127);
  delay(400);
  stopEverything();
  chainup(2500, 3000, 1.5, 6);
}

void pointblue() {

}

void noauto() {

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

void autonomous(){

switch(myauto){

    case -1:
    noauto();
    break;

    case 0:
    skills();
    break;

    case 1:
    mobileleftred();
    break;

    case 2:
    mobilerightblue();
    break;

    case 3:
    mobilerightred();
    break;

    case 4:
    mobileleftblue();
    break;

    case 5:
    stationarygoalred();
    break;

    case 6:
    stationarygoalblue();
    break;

    case 7:
    pointred();
    break;

    case 8:
    pointblue();
    break;

 }
}
