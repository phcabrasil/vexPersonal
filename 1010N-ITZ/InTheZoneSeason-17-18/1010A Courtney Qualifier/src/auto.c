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
  moveIntake(-45);
  moveChainBar(127);
  arm(UP, 1900, 750, 0.45, 0.8);
  moveChainBar(0);
  moveArm(9);
  moveMogo(127);
  drive(FORWARD, 300);//was 610
  delay(100);
  moveIntake(127);
  delay(500);
  moveMogo(-127);
  delay(750);
  moveMogo(0);
  arm(UP, 1950, 750, 0.45, 0.8);
  moveArm(10);
  moveChainBar(-127);
  delay(600);
  moveChainBar(0);
  drive(BACK,250);
  turn(RIGHT, 90, 1000, 1.5, 1);
  drive(FORWARD, 150);
  turn(RIGHT, 90, 1000, 1.5, 1);
  drive(127,127);
  delay(600);
  moveMogo(127);
  delay(750);
  moveMogo(0);
  moveDrive(-127,-127);
  delay(100);
  moveMogo(-127);
  delay(800);
  stopEverything();
  turn(LEFT, 90, 1000, 1.5, 1);
  drive(FORWARD, 150);
  turn(LEFT, 90, 1000, 1.5, 1);
  moveMogo(127);
  drive(FORWARD, 300);
  delay(100);
  moveMogo(-127);
  delay(750);
  moveMogo(0);
  drive(BACK, 300);
  turn(LEFT, 180, 1000, 1.5, 1);
  drive(FORWARD, 50);
  moveMogo(127);
  delay(750);
  moveMogo(0);
  moveDrive(-127,-127);
  delay(100);
  moveMogo(-127);
  delay(500);
  stopEverything();
  turn(LEFT, 180, 1000, 1.5, 1);
  moveMogo(-127);
  drive(FORWARD, 1000);
  delay(100);
  moveMogo(127);
  delay(750);
  drive(FORWARD, 350);
  moveMogo(127);
  delay(750);
  moveMogo(0);
  moveDrive(-127,-127);
  delay(100);
  moveMogo(-127);
  delay(500);
  stopEverything();

}

void mobileleftred() {
  moveIntake(-45);
  moveChainBar(127);
  arm(UP, 1900, 750, 0.45, 0.8);
  moveChainBar(0);
  moveArm(9);
  moveMogo(127);//aws 45
  drive(FORWARD, 600);//was 610
  moveMogo(0);
  moveIntake(127);
  delay(500);
  moveMogo(-127);
  delay(850);
  moveMogo(0);
  moveIntake(-127);
  drive(FORWARD,35);
  moveArm(0);
  arm(DOWN, 2650, 500, 0.45, 0.8);
  delay(400);
  arm(UP, 1950, 750, 0.45, 0.8);
  moveArm(10);
  moveChainBar(-127);
  delay(600);
  moveChainBar(0);
  moveIntake(127);
  delay(500);
  drive(FORWARD,40);
  moveChainBar(127);
  delay(500);
  moveChainBar(0);
  moveIntake(-127);
  arm(DOWN, 2650, 500, 0.45, 0.8);
  delay(400);
  arm(UP, 1900, 900, 0.45, 0.8);
  moveArm(10);
  moveChainBar(-127);
  delay(600);
  moveChainBar(0);
  moveIntake(127);
  delay(500);
  arm(UP, 1600, 500, 0.45, 0.8);
  moveArm(10);
  drive(-1, 900);
  turn(LEFT,135,1000,1.5,1);
  moveDrive(127, 127);
  delay(100);
  moveDrive(0,0);
  moveMogo(127);
  delay(1000);
  moveMogo(0);
  moveDrive(-127,-127);
  delay(100);
  moveMogo(-127);
  delay(500);
  stopEverything();
}

void mobilerightblue() {
  moveIntake(-45);
  moveChainBar(127);
  arm(UP, 1900, 750, 0.45, 0.8);
  moveChainBar(0);
  moveArm(9);
  moveMogo(46);
  drive(FORWARD, 600);//was 610
  delay(100);
  moveIntake(127);
  delay(500);
  moveMogo(-127);
  delay(750);
  moveMogo(0);
  moveIntake(-127);
  drive(FORWARD,35);
  moveArm(0);
  arm(DOWN, 2600, 500, 0.45, 0.8);
  delay(400);
  arm(UP, 1950, 750, 0.45, 0.8);
  moveArm(10);
  moveChainBar(-127);
  delay(600);
  moveChainBar(0);
  moveIntake(127);
  delay(500);
  drive(FORWARD,35);
  moveChainBar(127);
  delay(500);
  moveChainBar(0);
  moveIntake(-127);
  arm(DOWN, 2600, 500, 0.45, 0.8);
  delay(400);
  arm(UP, 1900, 900, 0.45, 0.8);
  moveArm(10);
  moveChainBar(-127);
  delay(600);
  moveChainBar(0);
  moveIntake(127);
  delay(500);
  arm(UP, 1600, 500, 0.45, 0.8);
  moveArm(10);
  drive(-1, 975);
  turn(RIGHT,135,1000,1.5,1);
  moveDrive(127, 127);
  delay(100);
  moveDrive(0,0);
  moveMogo(127);
  delay(750);
  moveMogo(0);
  moveDrive(-127,-127);
  delay(100);
  moveMogo(-127);
  delay(500);
  stopEverything();
}

void mobilerightred() {
  moveIntake(-45);
  moveChainBar(127);
  arm(UP, 1900, 750, 0.45, 0.8);
  moveChainBar(0);
  moveArm(9);
  moveMogo(46);
  drive(FORWARD, 600);//was 610
  delay(100);
  moveIntake(127);
  delay(500);
  moveMogo(-127);
  delay(750);
  moveMogo(0);
  moveIntake(-127);
  drive(FORWARD,35);
  moveArm(0);
  arm(DOWN, 2600, 500, 0.45, 0.8);
  delay(400);
  arm(UP, 1950, 750, 0.45, 0.8);
  moveArm(10);
  moveChainBar(-127);
  delay(600);
  moveChainBar(0);
  moveIntake(127);
  delay(500);
  drive(FORWARD,35);
  moveChainBar(127);
  delay(500);
  moveChainBar(0);
  moveIntake(-127);
  arm(DOWN, 2600, 500, 0.45, 0.8);
  delay(400);
  arm(UP, 1900, 900, 0.45, 0.8);
  moveArm(10);
  moveChainBar(-127);
  delay(600);
  moveChainBar(0);
  moveIntake(127);
  delay(500);
  arm(UP, 1600, 500, 0.45, 0.8);
  moveArm(10);
  drive(-1, 850);
  turn(RIGHT,180,1000,1.5,1);
  moveMogo(127);
  delay(750);
  moveMogo(0);
  moveDrive(-127,-127);
  delay(100);
  moveMogo(-127);
  delay(500);
  stopEverything();
}

void mobileleftblue() {
  moveIntake(-45);
  moveChainBar(127);
  arm(UP, 1850, 750, 0.5, 0.8);
  moveChainBar(0);
  moveArm(9);
  moveMogo(46);
  drive(FORWARD, 600);//was 610
  delay(100);
  moveIntake(127);
  delay(500);
  moveMogo(-127);
  delay(750);
  moveMogo(0);
  moveIntake(-127);
  drive(FORWARD,35);
  moveArm(0);
  arm(DOWN, 2600, 500, 0.45, 0.8);
  delay(400);
  arm(UP, 1950, 750, 0.45, 0.8);
  moveArm(10);
  moveChainBar(-127);
  delay(600);
  moveChainBar(0);
  moveIntake(127);
  delay(500);
  drive(FORWARD,35);
  moveChainBar(127);
  delay(500);
  moveChainBar(0);
  moveIntake(-127);
  arm(DOWN, 2600, 500, 0.45, 0.8);
  delay(400);
  arm(UP, 1900, 900, 0.45, 0.8);
  moveArm(10);
  moveChainBar(-127);
  delay(600);
  moveChainBar(0);
  moveIntake(127);
  delay(500);
  arm(UP, 1600, 500, 0.45, 0.8);
  moveArm(10);
  drive(-1, 700);
  turn(LEFT,170,1000,1.5,1);
  moveMogo(127);
  delay(750);
  moveMogo(0);
  moveDrive(-127,-127);
  delay(100);
  moveMogo(-127);
  delay(500);
  stopEverything();
}

void stationarygoalred() {
  moveIntake(-45); //Hold cone
  arm(UP,1500,1000,0.3,0.8); //Arm up to score on stationary cone 1
  moveArm(-8); //PID Lol
  delay(100);
  drive(FORWARD,100); //Drive towards stationary goal for cone 1
  delay(100);
  moveChainBar(127); //Chainbar down for cone 1
  delay(500);
  moveIntake(127);
  delay(100);
  moveChainBar(-127);
  delay(500);
  moveChainBar(0);
  drive(BACK,20);
  turn(LEFT,90,1000,1.4,1);
  drive(FORWARD, 5);
  moveIntake(-127);
  moveChainBar(127);
  arm(DOWN, 2650, 500, 0.45, 0.8);
  delay(500);
  moveChainBar(-127);
  drive(BACK,50);
  turn(RIGHT,90,1000,1.4,1);
  moveChainBar(0);
  arm(UP,1400,1000,0.3,0.8);
  moveArm(-8);
  drive(FORWARD, 30);
  moveChainBar(127);
  delay(500);
  moveIntake(127);
  delay(300);
  moveChainBar(-127);
  delay(500);
  moveChainBar(0);
  drive(BACK,20);
  turn(LEFT,90,1000,1.5,1);
  drive(FORWARD, 80);
  moveIntake(-127);
  moveChainBar(127);
  arm(DOWN, 2650, 500, 0.45, 0.8);
  delay(500);
  arm(UP,1300,1000,0.3,0.8);
  moveArm(-8);
  moveChainBar(-127);
  drive(BACK, 80);
  moveChainBar(0);
  turn(RIGHT,90,1000,1.5,1);
  drive(FORWARD, 30);
  moveChainBar(127);
  delay(500);
  moveIntake(127);
  delay(100);
  moveChainBar(-127);
  delay(500);
  moveChainBar(0);
  drive(BACK,25);
  stopEverything();





}

void stationarygoalblue(){

}

void pointred() {

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
