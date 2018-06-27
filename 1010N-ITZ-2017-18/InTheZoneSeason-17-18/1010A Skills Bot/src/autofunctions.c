#include "main.h"
#include "autofunctions.h"
#include "lcdfunctions.h"
#include "drive.h"
#include "intake.h"
#include "mogo.h"

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Arm MAX Height is 1700
Arm MIN Height is 200
Arm IDEAL Height is 300 to 400
Arm Difference in cones is 200(150) per cone

ChainBar Max Height is 175
ChainBar Min Height is 2850
ChainBar 90 Degrees is 1750

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#define UP -1
#define DOWN 1
#define FORWARD 1
#define BACKWARD -1
#define RIGHT 1
#define LEFT -1

//********************************
//       Stop Everything
//********************************

void stopEverything(){
  moveDrive(0,0);
  moveMogo(0);
}

//********************************
//       Motor Speed Cap
//********************************

void motorCap(int what, int speed){
  if(what > speed){
    what = speed;//Caps Max Given Motor Speed
  }
  else if(what < -speed){
    what = -speed;//Caps Min Given Motor Speed
  }
}

//***********************
//       Drive PID
//***********************

void drive(int direction, int target){

  //Drive Variables
  int leftPower;
  int rightPower;
  int tics;
  int ticsL;
  int ticsR;

  //Reset Values and Sensors
  tics = 0;
  encoderReset(encoderL);
  encoderReset(encoderR);

    while(tics < target){
      ticsL = encoderGet(encoderL); //Get Left Encoder
      ticsR = encoderGet(encoderR); //Get Right Encoder
      tics = (abs(ticsL) + abs(ticsR))/2; //Make average of encoders

        if(tics < target){//If average is less than target
          leftPower = 127;
          rightPower = 127;}
        else{//Otherwise
          leftPower = 0;
          rightPower = 0;}

      moveDrive(direction*rightPower,direction*leftPower);//Move Drive

      delay(20);
    }
}

//***********************
//       Turn PID
//***********************

void turn(int direction, int targetTurn, int timeout, float kp, float kd){

  //Turn Variables
  int error = 0;
  int error_last = 0;
  int error_diff = 0;
  int error_sum = 0;
  int pos =  0;
  float ki = 0;
  float p;
  float d;
  float i;
  int drivepower;

  //Reset Values and Sensors
  gyroReset(gyro);
  int startTime = millis();

  while((millis()-startTime)<timeout){ //Timeout

    pos = abs(gyroGet(gyro));
    error =  targetTurn - pos;

    error_diff = error - error_last; //Difference between errors = Current Error - Last Error
    error_last = error;
    error_sum  += error; //Sum of error = Current error + Sum of error

    p = kp * error; //P
    d  = kd * error_diff; //D

      if(error < 5) //I Cap
      {i = ki * error_sum;}

    drivepower = p+i+d; //PID

      if(drivepower>127){drivepower = 127;} //Motorcap
      if(drivepower<-127){drivepower = -127;} //Motorcap

    int leftside = direction*drivepower;
    int rightside = direction*drivepower;

    moveDrive(leftside, -rightside); //Turn Drive

    delay(40);
  }
  delay(20);
}
