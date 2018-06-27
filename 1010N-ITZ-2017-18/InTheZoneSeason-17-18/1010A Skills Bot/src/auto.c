#include "main.h"
#include "autofunctions.h"
#include "lcdfunctions.h"
#include "drive.h"
#include "intake.h"
#include "mogo.h"

#define UP -1
#define DOWN 1
#define FORWARD 1
#define BACK -1
#define RIGHT 1
#define LEFT -1

void skills() {

}

void mobileleftred() {

}

void mobilerightblue() {

}

void mobilerightred() {

}

void mobileleftblue() {

}

void stationarygoalred() {
  
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
