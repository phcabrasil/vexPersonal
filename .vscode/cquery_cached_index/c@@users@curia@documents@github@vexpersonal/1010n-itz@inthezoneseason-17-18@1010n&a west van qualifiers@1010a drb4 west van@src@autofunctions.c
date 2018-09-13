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
#define BACKWARD -1
#define RIGHT 1
#define LEFT -1

void stopEverything(){
  moveChainBar(0);
  moveDrive(0,0);
  moveArm(0);
  moveMogo(0);
  moveIntake(0);
}

//********************************
//       Motor Speed Cap
//********************************

void motorCap(int what, int speed){
  if(what > speed){
    what = speed;//Caps Max Motor Speed
  }
  else if(what < -speed){
    what = -speed;//Caps Min Motor Speed
  }
}

//***********************
//       Drive PID
//***********************

void drive(int direction, int target){

  int leftPower;
  int rightPower;
  int tics;
  int ticsL;
  int ticsR;

  tics = 0;
  encoderReset(encoderL);
  encoderReset(encoderR);

while(tics < target){

  ticsL = encoderGet(encoderL);
  ticsR = encoderGet(encoderR);
  tics = (abs(ticsL) + abs(ticsR))/2;


if(tics < target){
      leftPower = 127;
      rightPower = 127;}
    else{
      leftPower = 0;
      rightPower = 0;}
    // checking R
moveDrive(direction*rightPower,direction*leftPower);
      delay(20);
}
}

//***********************
//       Turn PID
//***********************

void turn(int direction, int targetTurn, int timeout, float kp, float kd)
{
gyroReset(gyro);

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

int startTime = millis();
while((millis()-startTime)<timeout)
{

pos = abs(gyroGet(gyro));
error =  targetTurn - pos;

error_diff = error - error_last;
error_last = error;
error_sum  += error; // same as errorsum  = errorsum + error

p = kp * error;

d  = kd * error_diff;
if(error < 5) //icap
{i = ki * error_sum;}

drivepower = p+i+d;
if(drivepower>127){drivepower = 127;}
if(drivepower<-127){drivepower = -127;}

int leftside = direction*drivepower;
int rightside = direction*drivepower;
moveDrive(leftside, -rightside);
delay(40);
}
delay(20);
}

//***********************
//       Arm Move PID
//***********************

void arm(int direction, int targetValue, int timeout, float kp, float kd){

  int error = 0;
  int error_last = 0;
  int error_diff = 0;
  int error_sum = 0;
  int pos =  0;
  float ki = 0;
  float p;
  float d;
  float i;
  int armpower;

  int startTime = millis();
  while((millis()-startTime)<timeout){

    pos = analogRead(ARMPOT);
    error =  targetValue - pos;

    error_diff = error - error_last;
    error_last = error;
    error_sum  += error;

    p = kp * error;

    d  = kd * error_diff;
    if(error < 5) //icap
    {i = ki * error_sum;}

    armpower = p+i+d;
    if(armpower>90){armpower = 90;}
    if(armpower<-90){armpower = -90;}

    int speed = armpower * direction;

    moveArm(speed);

    delay(40);
  }
}

//***********************
//       Mogo Function
//***********************

void mogo(int direction, int timeout){
  moveMogo(-127*direction);
  delay(timeout);
  moveMogo(0);
}

//***************************
//       FourBar PID
//***************************

void chainup(int targetValue, int timeout, float kp, float kd){
  bool barUp = joystickGetDigital(2,5,JOY_UP);
  bool barDown = joystickGetDigital(2,5,JOY_DOWN);
  float barGain = 0.2;
  int barError;
  int barSpeed;


  barError = targetValue - analogRead(CHAINPOT);
  barSpeed = barError * barGain;
  moveChainBar(barSpeed);
}

void chaindown(int targetValue, int timeout, float kp, float kd){
while(analogRead(CHAINPOT)>targetValue){
  moveChainBar(-127);
}
}
