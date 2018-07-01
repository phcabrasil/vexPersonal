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

}

////////////////////////////////////////////////////////////////////////////////

void threetwentyright() { //3 Cone Mobile 20 Right

  int armCounter = 10;
  gyroReset(gyro);
  moveIntake(-90);
  armUp(1850);
  moveMogo(90);
  moveArm(armCounter);
  drive(FORWARD, 1500);//was 1500
  delay(0);//500 works
  moveMogo(-127);
  delay(1500);
  moveMogo(-30);
  moveIntake(127);
  delay(300);
  //second cone
  drive(FORWARD,150);//was 160
  moveChainBar(127);
  moveIntake(-127);
  moveArm(0);
  armDown(2350);
  delay(100);
  armP(UP, 1750, 500);
  moveArm(armCounter);
  moveChainBar(-127);
  delay(500);
  moveChainBar(-30);
  moveIntake(127);
  delay(200);
  //thrird cone
  drive(FORWARD,150);//was 160// was 140
  moveChainBar(127);
  moveIntake(-127);
  moveArm(0);
  armDown(2350);
  delay(100);
  armP(UP, 1850, 500); //was 1700
  moveArm(armCounter);
  moveChainBar(-127);
  delay(500);
  moveChainBar(-30);
  moveIntake(127);
  delay(100);
  //SCCOREMOGO
  drive(-1, 1850);//1100 for 1 cone 1500 for 2 cones
  turn(RIGHT,40,450,2.5,5.5);
  drive(-1, 800);
  turn(RIGHT,95,650,2.5,5.5);
  moveDrive(90,90);
  delay(1200);
  moveDrive(50,50);
  moveMogo(90);
  delay(1100);
  moveMogo(-90);
  moveDrive(-70,-70);
  delay(1000);
  stopEverything();
}

////////////////////////////////////////////////////////////////////////////////

void threetwentyleft() { //3 Cone Mobile 20 Left
  int armCounter = 10;
  gyroReset(gyro);
  moveIntake(-90);
  armP(UP, 1850, 500);
  moveMogo(90);
  moveArm(armCounter);
  drive(FORWARD, 1500);
  delay(0);//500 works
  moveMogo(-127);
  delay(1500);
  moveMogo(-30);
  moveIntake(127);
  delay(300);
  //second cone
  drive(FORWARD,150);//was 160 //was 140
  moveChainBar(127);
  moveIntake(-127);
  moveArm(0);
  armDown(2350);
  delay(100);
  armP(UP, 1700, 500);
  moveArm(armCounter);
  moveChainBar(-127);
  delay(500);
  moveChainBar(-30);
  moveIntake(127);
  delay(200);
  //thrird cone
  drive(FORWARD,150);//was 160
  moveChainBar(127);
  moveIntake(-127);
  moveArm(0);
  armDown(2350);
  delay(100);
  armP(UP, 1700, 500);
  moveArm(armCounter);
  moveChainBar(-127);
  delay(500);
  moveChainBar(-30);
  moveIntake(127);
  delay(100);
  //SCCOREMOGO
  drive(-1, 1850);//1100 for 1 cone 1500 for 2 cones
  turn(LEFT,40,450,2.5,5);
  drive(-1, 800);
  turn(LEFT,95,650,2.5,5);
  moveDrive(90,90);
  delay(1200);
  moveDrive(50,50);
  moveMogo(90);
  delay(1100);
  moveMogo(-90);
  moveDrive(-70,-70);
  delay(1000);
  stopEverything();
}

///////////////////////////////////////////////////////////////////////////////

void twotwentyright(){ //2 Cone Mobile 20 Left
  int armCounter = 10;
  gyroReset(gyro);
  moveIntake(-90);
  armP(UP, 1900, 500);
  moveMogo(90);
  moveArm(armCounter);
  drive(FORWARD, 1500);
  delay(0);//500 works
  moveMogo(-127);
  delay(1500);
  moveMogo(-30);
  moveIntake(127);
  delay(300);
  //second cone
  drive(FORWARD,140);//was 160 //was 140
  moveChainBar(127);
  moveIntake(-127);
  moveArm(0);
  armDown(2350);
  delay(100);
  armP(UP, 1800, 500);
  moveArm(armCounter);
  moveChainBar(-127);
  delay(500);
  moveChainBar(-30);
  //SCCOREMOGO
  drive(-1, 1550);//1100 for 1 cone 1550 for 2 cones
  turn(RIGHT,45,450,2.5,5);
  moveIntake(127);
  drive(-1, 800);
  turn(RIGHT,90,650,2.5,5);
  armP(UP, 1750, 500);
  moveDrive(90,90);
  delay(1100);
  moveDrive(50,50);
  moveMogo(90);
  delay(1500);
  moveMogo(-90);
  moveDrive(-70,-70);
  delay(1000);
  stopEverything();
}

////////////////////////////////////////////////////////////////////////////////

void twotwentyleft(){
  //2 Cone Mobile 20 Left
  int armCounter = 9;//was 10
  gyroReset(gyro);
  moveIntake(-90);
  moveArm(90);
  delay(150);
  //armP(UP, 1900, 500);
  moveMogo(90);
  moveArm(armCounter);
  drive(FORWARD, 1500);
  delay(0);//500 works
  moveMogo(-127);
  delay(1500);
  moveMogo(-30);
  moveIntake(127);
  delay(300);
  //second cone
  drive(FORWARD,160);//was 160 //was 150
  moveChainBar(127);
  moveIntake(-127);
  delay(500);
  moveArm(-90);
  delay(500);
  moveArm(0);
  delay(100);
  armP(UP, 2000, 500); //was 1800 //was 2000
  moveArm(armCounter);
  moveChainBar(-127);
  delay(500);
  moveChainBar(-30);
  //wingus match
  moveIntake(127); //REMOVE AFTER WINGUS-DINGUS MATCH
  delay(1000);
  //third cone
  drive(FORWARD,170);//was 160 //was 150
  moveChainBar(127);
  moveIntake(-127);
  delay(500);
  moveArm(-90);
  delay(500);
  moveArm(0);
  delay(100);
  armP(UP, 2000, 500); //was 1800 //was 2000
  moveArm(armCounter);
  moveChainBar(-127);
  delay(500);
  moveChainBar(-30);
  moveIntake(127); //REMOVE AFTER WINGUS-DINGUS MATCH
  //score mogo
  drive(-1, 1850);//1100 for 1 cone 1500 for 2 cones
  turn(LEFT,40,450,2.5,5);
  drive(-1, 800);
  turn(LEFT,95,650,2.5,5);
  moveDrive(90,90);
  delay(1200);
  moveDrive(50,50);
  moveMogo(90);
  delay(1100);
  moveMogo(-90);
  moveDrive(-70,-70);
  delay(1000);
  stopEverything();
}


////////////////////////////////////////////////////////////////////////////////

void stationarygoalred() {
  resetEverything();
  moveIntake(-90);
  turn(RIGHT,90,650,2.5,5);
  delay(125);
  moveArm(90);
  delay(500);
  moveArm(0);
  delay(100);
  drive(FORWARD, 500);
  chainpid(1900);
  delay(250);
  armDown(2000);
  delay(250);
  moveIntake(90);
  armUp(1500);
  delay(200);
  chainpid(1300);
}

////////////////////////////////////////////////////////////////////////////////

void stationarygoalblue(){

}

////////////////////////////////////////////////////////////////////////////////

void threetenright() {

}

////////////////////////////////////////////////////////////////////////////////

void threetenleft() {

}

/////////////////////////////////////////////////////////////////////////////////

void threefiveright() {
  //2 Cone Mobile 20 Left
  int armCounter = 10;
  gyroReset(gyro);
  moveIntake(-90);
  moveArm(90);
  delay(150);
  //armP(UP, 1900, 500);
  moveMogo(90);
  moveArm(armCounter);
  drive(FORWARD, 1500);
  delay(0);//500 works
  moveMogo(-127);
  delay(1500);
  moveMogo(-30);
  moveIntake(127);
  delay(300);
  //second cone
  drive(FORWARD,170);//was 160 //was 150
  moveChainBar(127);
  moveIntake(-127);
  moveArm(-90);
  delay(500);
  moveArm(0);
  delay(100);
  armP(UP, 2000, 500); //was 1800 //was 2000
  moveArm(armCounter);
  moveChainBar(-127);
  delay(500);
  moveChainBar(-30);
  //score mogo
  drive(-1, 1100);//was 1100 for 1 cone 1500 for 2 cones
  turn(RIGHT,185,500,2.73,5);
  moveMogo(90);
  delay(1200);
  /*moveMogo(30);
  drive(-1, 500);
  turn(RIGHT,90,750,2.5,5);
  drive(1,600);
  turn(RIGHT,80,750,2.5,5);
  drive(-1,300);
  turn(LEFT,40,750,2.5,5);
  drive(1,700);
  moveMogo(-90);
  delay(1200);*/
  stopEverything();
}

////////////////////////////////////////////////////////////////////////////////

void threefiveleft() {
  //2 Cone Mobile 20 Left
  int armCounter = 9;//was 10
  gyroReset(gyro);
  moveIntake(-90);
  moveArm(90);
  delay(150);
  //armP(UP, 1900, 500);
  moveMogo(90);
  moveArm(armCounter);
  drive(FORWARD, 1500);
  delay(0);//500 works
  moveMogo(-127);
  delay(1500);
  moveMogo(-30);
  moveIntake(127);
  delay(300);
  //second cone
  drive(FORWARD,160);//was 160 //was 150
  moveChainBar(127);
  moveIntake(-127);
  delay(500);
  moveArm(-90);
  delay(500);
  moveArm(0);
  delay(100);
  armP(UP, 2000, 500); //was 1800 //was 2000
  moveArm(armCounter);
  moveChainBar(-127);
  delay(500);
  moveChainBar(-30);
  //wingus match
  moveIntake(127); //REMOVE AFTER WINGUS-DINGUS MATCH
  delay(500);
  //third cone
  drive(FORWARD,180);//was 160 //was 150
  moveIntake(-127);
  moveChainBar(127);
  moveArm(-90);
  delay(500);
  moveArm(0);
  delay(100);
  armP(UP, 1900, 500); //was 1800 //was 2000
  moveArm(armCounter);
  moveChainBar(-127);
  delay(500);
  moveChainBar(-30);
  moveIntake(127); //REMOVE AFTER WINGUS-DINGUS MATCH
  //SCCOREMOGO
  drive(-1, 1400);//was 1100 for 1 cone 1500 for 2 cones
  turn(RIGHT,190,2000,2.73,5);
  moveMogo(90);
  delay(1400);
  drive(-1,1000);
  /*moveMogo(30);
  drive(-1, 500);
  turn(LEFT,90,750,2.5,5);
  drive(1,600);
  turn(LEFT,80,750,2.5,5);
  drive(-1,300);
  turn(RIGHT,40,750,2.5,5);
  drive(1,700);
  moveMogo(-90);
  delay(1200);*/
  stopEverything();

}

/////////////////////////////////////////////////////////////////////////////////

void trickright() {

}

////////////////////////////////////////////////////////////////////////////////

void trickleft() {

}

/////////////////////////////////////////////////////////////////////////////////

void farmogoright() {

}

////////////////////////////////////////////////////////////////////////////////

void farmogoleft() {

}

/////////////////////////////////////////////////////////////////////////////////

void defence() {
  gyroReset(gyro);
  moveDrive(-127, -127);
  delay(4000);
  moveDrive(0, 0);
  delay(8000);
  moveDrive(127, 127);
  delay(1000);
  stopEverything();
}

/////////////////////////////////////////////////////////////////////////////////

void test(){

  drivePID(FORWARD, 500, 1, 0, 0, 5000); //NO PID
  //drivePID(FORWARD, 500, 2.5, 0, 0, 5000); //Only P
  //drivePID(FORWARD, 500, 2.5, 0, 5, 5000); //Both P and D
  //drivePID(FORWARD, 500, 2.5, 0.001, 5, 5000); //Full PID
}

////////////////////////////////////////////////////////////////////////////////

void noauto() {

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

void autonomous(){

//TaskHandle armHandle = taskCreate(arm, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);

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
