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

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void skills() { //Skills
  moveIntake(-90);
  moveArm(90);
  delay(200);
  moveArm(7);
  moveMogo(90);
  delay(200);
  drive(FORWARD, 300);
  delay(100);
  moveMogo(-127);
  delay(1800);
  moveMogo(-30);
  moveIntake(90);
  delay(100);
  drive(BACK, 250);
  turn(RIGHT,90,750,1.5,0.9);
  drive(FORWARD, 65);
  turn(RIGHT,90,750,1.5,0.9);
  moveDrive(127,127);
  delay(500);
  moveMogo(127);
  delay(750);
  moveMogo(-90);
  moveDrive(-70,-70);
  delay(1000);//was 500 v.1 750 v.2 both work
  moveDrive(0,0);
  moveMogo(0);
  delay(200);
  turn(LEFT,90,750,1.5,0.9);
  drive(FORWARD,30);
  turn(LEFT,90,750,1.5,0.9);
  moveDrive(-127,-127);
  delay(400);
  moveDrive(0,0);
  moveMogo(90);
  delay(200);
  drive(FORWARD, 350);
  delay(100);
  moveMogo(-90);
  delay(1500);
  moveMogo(-20);
  drive(BACK, 100);
  turn(LEFT,170,1000,1.5,0.9);
  moveMogo(90);
  drive(FORWARD,50);
  delay(200);
  moveMogo(-5);
  drive(BACK,200);
  turn(LEFT,170,1000,1.5,0.9);
  moveMogo(90);
  drive(FORWARD,500);
  moveMogo(-90);
  delay(500);
  drive(FORWARD,500);
  moveMogo(90);
  delay(750);
  moveMogo(0);
  drive(BACK,75);

}

////////////////////////////////////////////////////////////////////////////////

void threetwentyright() { //3 Cone Mobile 20 Right
  int armCounter = -11.8;
  gyroReset(gyro);
  moveIntake(-45);
  moveChainBar(127);
  //arm(UP, 1900, 750, 0.5, 0.8);
  armUp(2150);
  moveChainBar(30);
  moveArm(armCounter);
  moveMogo(90);
  drive(FORWARD, 600);//was 610
  delay(300);
  moveChainBar(30);
  moveIntake(127);
  delay(400);
  moveMogo(-127);
  delay(1200);
  moveIntake(-127);
  drive(FORWARD,30);
  moveMogo(-30);
  moveArm(0);
  //arm(DOWN, 2600, 750, 0.45, 0.8);
  armDown(2500);
  delay(400);
  //arm(UP, 2100, 750, 0.45, 0.8);
  armUp(2300);
  moveArm(armCounter);
  moveChainBar(-127);
  delay(500);
  moveChainBar(0);
  moveIntake(127);
  delay(500);
  drive(FORWARD,25);
  moveChainBar(127);
  delay(500);
  moveChainBar(30);
  moveIntake(-127);
  //arm(DOWN, 2600, 750, 0.45, 0.8);
  armDown(2500);
  delay(400);
  //arm(UP, 2000, 750, 0.45, 0.8);
  armUp(2250);
  moveArm(armCounter);
  moveChainBar(-127);
  delay(600);
  moveChainBar(0);
  moveIntake(127);
  delay(500);
  armUp(2000);
  moveArm(armCounter);
  drive(-1, 800);
  turn(LEFT,135,1000,2.5,5);// was 1.5 and 1
  drive(1, 50);
  turn(LEFT,90,750,2.5,5);
  moveDrive(127,127);
  delay(800);//was 1200
  moveMogo(90);
  delay(800);//1000
  moveMogo(-90);
  moveDrive(-70,-70);
  delay(1000);//was 500 v.1 750 v.2 both work
  stopEverything();
}

////////////////////////////////////////////////////////////////////////////////

void threetwentyleft() { //3 Cone Mobile 20 Left
  int armCounter = -11.7;
  gyroReset(gyro);
  moveIntake(-45);
  moveChainBar(127);
  //arm(UP, 1900, 750, 0.5, 0.8);
  armUp(2150);
  moveChainBar(30);
  moveArm(armCounter);
  moveMogo(90);
  drive(FORWARD, 600);//was 610
  delay(200);
  moveChainBar(30);
  delay(100);
  moveIntake(127);
  delay(500);
  moveMogo(-90);
  delay(1200);
  moveIntake(-127);
  drive(FORWARD,30);
  moveMogo(-30);
  moveArm(0);
  //arm(DOWN, 2600, 750, 0.45, 0.8);
  armDown(2500);
  delay(400);
  //arm(UP, 2100, 750, 0.45, 0.8);
  armUp(2300);
  moveArm(armCounter);
  moveChainBar(-127);
  delay(600);
  moveChainBar(0);
  moveIntake(127);
  delay(500);
  drive(FORWARD,25);
  moveChainBar(127);
  delay(500);
  moveChainBar(30);
  moveIntake(-127);
  //arm(DOWN, 2600, 750, 0.45, 0.8);
  armDown(2500);
  delay(400);
  //arm(UP, 2000, 750, 0.45, 0.8);
  armUp(2250);
  moveArm(armCounter);
  moveChainBar(-127);
  delay(600);
  moveChainBar(0);
  moveIntake(127);
  delay(500);
  //arm(UP, 1750, 750, 0.45, 0.8);
  armUp(2000);
  moveArm(armCounter);
  drive(-1, 920);
  turn(RIGHT,135,1000,2.5,5);// was 1.5 and 1
  drive(1, 30);
  turn(RIGHT,90,750,2.5,6);
  moveDrive(127,127);
  delay(1200);
  moveDrive(0,0);
  delay(200);
  moveMogo(90);
  delay(1000);
  moveMogo(-90);
  moveDrive(-70,-70);
  delay(1000);//was 500 v.1 750 v.2 both work
  stopEverything();
}

///////////////////////////////////////////////////////////////////////////////

void twotwentyright(){//2 Cone Mobile 20 Left
  int armCounter = -11.8;
  gyroReset(gyro);
  moveIntake(-45);
  moveChainBar(127);
  //arm(UP, 1900, 750, 0.5, 0.8);
  armUp(2150);
  moveChainBar(30);
  moveArm(armCounter);
  moveMogo(90);
  drive(FORWARD, 600);//was 610
  delay(300);
  moveChainBar(30);
  moveIntake(127);
  delay(400);
  moveMogo(-127);
  delay(1200);
  moveIntake(-127);
  drive(FORWARD,30);
  moveMogo(-30);
  moveArm(0);
  //arm(DOWN, 2600, 750, 0.45, 0.8);
  armDown(2500);
  delay(400);
  //arm(UP, 2100, 750, 0.45, 0.8);
  armUp(2300);
  moveArm(armCounter);
  moveChainBar(-127);
  delay(500);
  moveChainBar(0);
  moveIntake(127);
  delay(500);
  armUp(2000);
  moveArm(armCounter);
  drive(-1, 800);
  turn(LEFT,135,1000,2.5,5);// was 1.5 and 1
  drive(1, 50);
  turn(LEFT,90,750,2.5,5);
  moveDrive(127,127);
  delay(1100);//was 1200
  moveDrive(45,45);
  delay(500);
  moveMogo(90);
  delay(1500);//1000
  moveDrive(-70,-70);
  delay(200);
  moveMogo(-90);
  delay(1000);//was 500 v.1 750 v.2 both work
  stopEverything();
}

////////////////////////////////////////////////////////////////////////////////

void twotwentyleft(){//2 Cone Mobile 20 Left
  int armCounter = -11.8;
  gyroReset(gyro);
  moveIntake(-45);
  moveChainBar(127);
  //arm(UP, 1900, 750, 0.5, 0.8);
  armUp(2150);
  moveChainBar(30);
  moveArm(armCounter);
  moveMogo(90);
  drive(FORWARD, 600);//was 610
  delay(300);
  moveChainBar(30);
  moveIntake(127);
  delay(400);
  moveMogo(-127);
  delay(1200);
  moveIntake(-127);
  drive(FORWARD,30);
  moveMogo(-30);
  moveArm(0);
  //arm(DOWN, 2600, 750, 0.45, 0.8);
  armDown(2500);
  delay(400);
  //arm(UP, 2100, 750, 0.45, 0.8);
  armUp(2300);
  moveArm(armCounter);
  moveChainBar(-127);
  delay(500);
  moveChainBar(0);
  moveIntake(127);
  delay(500);
  armUp(2000);
  moveArm(armCounter);
  drive(-1, 800);
  turn(RIGHT,135,1000,2.5,5);// was 1.5 and 1
  drive(1, 50);
  turn(RIGHT,90,750,2.5,5);
  moveDrive(127,127);
  delay(1100);//was 1200
  moveDrive(45,45);
  delay(500);
  moveMogo(90);
  delay(1500);//1000
  moveDrive(-70,-70);
  delay(200);
  moveMogo(-90);
  delay(1000);//was 500 v.1 750 v.2 both work
  stopEverything();
}

////////////////////////////////////////////////////////////////////////////////

void stationarygoalred() {

}

////////////////////////////////////////////////////////////////////////////////

void stationarygoalblue(){
  moveIntake(-45); //Hold cone
  arm(UP,1600,1000,0.3,0.8); //Arm up to score on stationary cone 1
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
  turn(RIGHT,90,1500,3,6);
  drive(FORWARD, 100);
  /*moveIntake(-127);
  moveChainBar(127);
  arm(DOWN, 2650, 500, 0.45, 0.8);
  delay(500);
  moveChainBar(-127);
  drive(BACK,40);
  turn(RIGHT,90,1000,3,6);
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
  turn(LEFT,90,1000,3,6);
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
  turn(RIGHT,90,1000,3,6);
  drive(FORWARD, 30);
  moveChainBar(127);
  delay(500);
  moveIntake(127);
  delay(100);
  moveChainBar(-127);
  delay(500);
  moveChainBar(0);
  drive(BACK,25);*/
  stopEverything();
}

////////////////////////////////////////////////////////////////////////////////

void threetenright() {
  int armCounter = -11.75;
  gyroReset(gyro);
  moveIntake(-45);
  moveChainBar(127);
  //arm(UP, 1900, 750, 0.5, 0.8);
  armUp(2100);
  moveChainBar(30);
  moveArm(armCounter);
  moveMogo(90);
  drive(FORWARD, 600);//was 610
  delay(200);
  moveChainBar(30);
  delay(100);
  moveIntake(127);
  delay(500);
  moveMogo(-90);
  delay(1000);
  moveIntake(-127);
  drive(FORWARD,30);
  moveMogo(-30);
  moveArm(0);
  //arm(DOWN, 2600, 750, 0.45, 0.8);
  armDown(2500);
  delay(400);
  //arm(UP, 2100, 750, 0.45, 0.8);
  armUp(2300);
  moveArm(armCounter);
  moveChainBar(-127);
  delay(600);
  moveChainBar(0);
  moveIntake(127);
  delay(500);
  drive(FORWARD, 30);
  moveChainBar(127);
  delay(500);
  moveChainBar(30);
  moveIntake(-127);
  //arm(DOWN, 2600, 750, 0.45, 0.8);
  armDown(2500);
  delay(400);
  //arm(UP, 2000, 750, 0.45, 0.8);
  armUp(2200);
  moveArm(armCounter);
  moveChainBar(-127);
  delay(600);
  moveChainBar(0);
  moveIntake(127);
  delay(500);
  //arm(UP, 1750, 750, 0.45, 0.8);
  armUp(1900);
  moveArm(armCounter);
  drive(-1, 525);
  turn(LEFT,200,2000,2.5,5);// was 1.5 and 1
  moveMogo(90);
  delay(1200);
  moveMogo(-90);
  moveDrive(-70,-70);
  delay(750);//was 500 v.1 750 v.2 both work
  stopEverything();
}

////////////////////////////////////////////////////////////////////////////////

void threetenleft() {
  int armCounter = -11.75;
  gyroReset(gyro);
  moveIntake(-45);
  moveChainBar(127);
  //arm(UP, 1900, 750, 0.5, 0.8);
  armUp(2100);
  moveChainBar(30);
  moveArm(armCounter);
  moveMogo(90);
  drive(FORWARD, 600);//was 610
  delay(200);
  moveChainBar(30);
  delay(100);
  moveIntake(127);
  delay(500);
  moveMogo(-90);
  delay(1000);
  moveIntake(-127);
  drive(FORWARD,30);
  moveMogo(-30);
  moveArm(0);
  //arm(DOWN, 2600, 750, 0.45, 0.8);
  armDown(2500);
  delay(400);
  //arm(UP, 2100, 750, 0.45, 0.8);
  armUp(2300);
  moveArm(armCounter);
  moveChainBar(-127);
  delay(600);
  moveChainBar(0);
  moveIntake(127);
  delay(500);
  drive(FORWARD, 30);
  moveChainBar(127);
  delay(500);
  moveChainBar(30);
  moveIntake(-127);
  //arm(DOWN, 2600, 750, 0.45, 0.8);
  armDown(2500);
  delay(400);
  //arm(UP, 2000, 750, 0.45, 0.8);
  armUp(2200);
  moveArm(armCounter);
  moveChainBar(-127);
  delay(600);
  moveChainBar(0);
  moveIntake(127);
  delay(500);
  //arm(UP, 1750, 750, 0.45, 0.8);
  armUp(1900);
  moveArm(armCounter);
  drive(-1, 525);
  turn(RIGHT,200,2000,2.5,5);// was 1.5 and 1
  moveMogo(90);
  delay(1200);
  moveMogo(-90);
  moveDrive(-70,-70);
  delay(750);//was 500 v.1 750 v.2 both work
  stopEverything();
}

/////////////////////////////////////////////////////////////////////////////////

void threefiveright() {

}

////////////////////////////////////////////////////////////////////////////////

void threefiveleft() {

}

/////////////////////////////////////////////////////////////////////////////////

void trickright() {

}

////////////////////////////////////////////////////////////////////////////////

void trickleft() {
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
  drive(BACK,110);
  turn(LEFT,500,95,3,4);
  delay(200);
  int armCounter = -12;
  gyroReset(gyro);
  moveIntake(-45);
  moveChainBar(127);
  //arm(UP, 1900, 750, 0.5, 0.8);
  armUp(2100);
  moveChainBar(30);
  moveArm(armCounter);
  moveMogo(90);
  drive(FORWARD, 600);//was 610
  delay(200);
  moveChainBar(30);
  delay(100);
  moveIntake(127);
  delay(500);
  moveMogo(-90);
  delay(1000);
  moveIntake(-127);
  drive(FORWARD,35);
  moveMogo(-30);
  moveArm(0);
  //arm(DOWN, 2600, 750, 0.45, 0.8);
  armDown(2500);
  delay(400);
  //arm(UP, 2100, 750, 0.45, 0.8);
  armUp(2150);
  moveArm(armCounter);
  moveChainBar(-127);
  delay(600);
  moveChainBar(0);
  moveIntake(127);
  delay(500);
  //arm(UP, 1750, 750, 0.45, 0.8);
  armUp(1900);
  moveArm(-armCounter);
  drive(-1, 900);
  turn(RIGHT,135,750,2,4);// was 1.5 and 1
  drive(1, 110);
  turn(RIGHT,90,750,2,4);
  moveDrive(127,127);
  delay(500);
  moveMogo(90);
  delay(1000);
  moveMogo(-90);
  moveDrive(-70,-70);
  delay(1000);//was 500 v.1 750 v.2 both work
  stopEverything();
}

/////////////////////////////////////////////////////////////////////////////////

void farmogoright() {

}

////////////////////////////////////////////////////////////////////////////////

void farmogoleft() {
  int armCounter = -12;
  gyroReset(gyro);
  moveIntake(-45);
  moveChainBar(127);
  //arm(UP, 1900, 750, 0.5, 0.8);
  armUp(2100);
  moveChainBar(30);
  moveArm(armCounter);
  moveMogo(90);
  drive(BACK,2000);
  turn(LEFT, 500, 35, 3,4);
  drive(FORWARD, 100);
  delay(200);
  moveMogo(-90);
  delay(2000);
  stopEverything();

}

/////////////////////////////////////////////////////////////////////////////////

void defence() {
  drive(BACK, 3000);
  delay(7000);
  moveMogo(90);
  drive(FORWARD, 900);
  stopEverything();
}

/////////////////////////////////////////////////////////////////////////////////

void test(){

  turn(LEFT, 90, 1500, 2.5 ,5);

}

////////////////////////////////////////////////////////////////////////////////

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
    threetwentyright();
    break;

    case 2:
    threetwentyleft();
    break;

    case 3:
    twotwentyright();
    break;

    case 4:
    twotwentyleft();
    break;

    case 5:
    stationarygoalred();
    break;

    case 6:
    stationarygoalblue();
    break;

    case 7:
    threetenright();
    break;

    case 8:
    threetenleft();
    break;

    case 9:
    threefiveright();
    break;

    case 10:
    threefiveleft();
    break;

    case 11:
    trickright();
    break;

    case 12:
    trickleft();
    break;

    case 13:
    farmogoright();
    break;

    case 14:
    farmogoleft();
    break;

    case 15:
    defence();
    break;

    case 16:
    test();
    break;

 }
}
