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

}

void mobileleftred() {

moveDrive(-127,-127);
delay(2200);
moveDrive(0,0);
delay(5000);
moveDrive(127,127);
delay(1000);
moveDrive(0,0);
}

void mobilerightblue() {

}

void mobilerightred() {

}

void mobileleftblue() {

}

void stationarygoalred() {
  moveIntake(-45);
  matchbarstraight();
  arm(UP,2200,1000,0.2,3);
  drive(FORWARD,400);
  moveIntake(127);


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
