#include "main.h"
#include "autofunctions.h"
#include "lcdfunctions.h"
#include "drive.h"
#include "intake.h"
#include "chainbar.h"
#include "mogo.h"
#include "arm.h"

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
INFORMATION:

Arm MAX Height is 1700
Arm MIN Height is 200
Arm IDEAL Height is 300 to 400
Arm Difference in cones is 200(150) per cone

ChainBar Max Height is 175
ChainBar Min Height is 2850
ChainBar 90 Degrees is 1750

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#define UP 1
#define DOWN -1
#define FORWARD 1
#define BACK -1
#define RIGHT 1
#define LEFT -1

//********************************
//       Stop Everything
//********************************

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
      error = target - tics;

        if(tics < target){ //If average is less than target, run motors
          leftPower = 127;
          rightPower = 127;}
        else{ //Otherwise don't move
          leftPower = 0;
          rightPower = 0;}


      moveDrive(direction*rightPower,direction*leftPower);//Move Drive

      delay(20);
    }
}

void drivePID(int direction, int target, int kp, int ki, int kd, int timeout){

  //Variables
  int error_last = 0;
  int error_diff = 0;
  int error_sum = 0;
  float p;
  float d;
  float i;
  int drivepower;
  int tics = 0;
  int ticsL;
  int ticsR;

  //Reset Values and Sensors
  encoderReset(encoderL);
  encoderReset(encoderR);
  int startTime = millis();

  while((millis()-startTime)<timeout){ //Timeout

    ticsL = encoderGet(encoderL); //Get Left Encoder
    ticsR = encoderGet(encoderR); //Get Right Encoder
    tics = (abs(ticsL) + abs(ticsR))/2; //Make average of encoders

    error =  target - tics; //Difference between target value and current value

    error_diff = error - error_last; //Difference between errors = Current Error - Last Error
    error_last = error; //Stores last error
    error_sum  += error; //Sum of error = Current error + Sum of error

    p = kp * error; //Proportional
    i = ki * error_sum; //Integral
    d  = kd * error_diff; //Derivative

    drivepower = p+i+d; //Sets drivepower to PID

      if(drivepower>90){drivepower = 90;} //Motorcap
      if(drivepower<-90){drivepower = -90;} //Motorcap

    int leftside = direction*drivepower; //multiplies drivepower by direction (-1 or 1)
    int rightside = direction*drivepower;//multiplies drivepower by direction (-1 or 1)

    moveDrive(leftside, rightside); //Turns Drive

    delay(40);
  }
  delay(20);

}

//***********************
//       Turn PID
//***********************

void turn(int direction, int targetTurn, int timeout, float kp, float kd){

  //Turn Variables
  int errorG = 0;
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

    pos = abs(gyroGet(gyro)); //current value is the absolute of gyro value
    errorG =  targetTurn - pos; //difference between target value and current value

    error_diff = errorG - error_last; //Difference between errors = Current Error - Last Error
    error_last = errorG; //store last error
    error_sum  += errorG; //Sum of error = Current error + Sum of error

    p = kp * errorG; //Proportional
    d  = kd * error_diff; //Derivative

      if(errorG < 5) //Integral Cap
      {i = ki * error_sum;}

    drivepower = p+i+d; //PID

      if(drivepower>127){drivepower = 127;} //Motor cap
      if(drivepower<-127){drivepower = -127;} //Motor cap

    int leftside = direction*drivepower;
    int rightside = direction*drivepower;

    moveDrive(leftside, -rightside); //Turn Drive

    delay(40);
  }
  delay(20);
}

//***********************
//       Arm Move PID
//***********************

void armpid(){

  //variables
  float armKp = 0.1;//0.2
  float armKd = 2; //2 Worked
  int armTarget;
  int armSpeed;
  int armError;
  int armErrorDiff;
  int armErrorLast;
  float armP;
  float armD;

  armError = armTarget - analogRead(ARMPOT); //error = target value - current potentiometer value
  armP = armError * armKp; //Proportional is the error times KP variable
  armErrorDiff = armError - armErrorLast; //difference between errors
  armErrorLast = armError;
  armD = armKd * armErrorDiff;
  armSpeed = armP + armD;
  moveArm(armSpeed);
}

void arm(void*parameter){

  //Arm PID Variables
  float kp = 0.12;
  int errorA;
  int pos;
  int p;
  int armpower;

    pos = analogRead(ARMPOT);
    errorA = armtargetValue - pos;

    p = kp * errorA;

    armpower = p;

    moveArm(-armpower);
}

void armUp(int targetValue){
  while (analogRead(ARMPOT) > targetValue){
    moveArm(90);
  }
}

void armDown(int targetValue){
  while (analogRead(ARMPOT) < targetValue){
    moveArm(-90);
  }
}

void armP(int direction, int targetValue, int timeout){
  int errorA;
  float kp = 0.12;//0.12
  int armPower;
  int startTime = millis();
  while((millis()-startTime)<timeout){

    errorA = targetValue - analogRead(ARMPOT);
    armPower = kp*errorA;

    moveArm(-armPower);
  }
}

//***********************
// Mobile Goal Intake Function
//***********************

void mogoIn(int timeout){
  moveMogo(127);
  delay(timeout);
  moveMogo(0);
}

void mogoOut(int timeout){
  moveMogo(-127);
  delay(timeout);
  moveMogo(0);
}

void mogoScore(){
  while(analogRead(MOGOPOT) < 1000){
    moveMogo(-100);
  }
  delay(500);
}

//***************************
//       Four Bar PID
//***************************

void chainpid(int targetValue){
  float chainKp = 0.1;//0.2
  float chainKd = 2; //2 Worked
  int currentChain;
  int chainSpeed;
  int chainError;
  int chainErrorDiff;
  int chainErrorLast;
  float chainP;
  float chainD;

  chainError = targetValue - analogRead(CHAINPOT);
  chainP = chainError * chainKp;
  chainErrorDiff = chainError - chainErrorLast;
  chainErrorLast = chainError;
  chainD = chainKd * chainErrorDiff;
  chainSpeed = chainP + chainD;
  moveChainBar(chainSpeed);
}

void chainup(int targetValue, int timeout, float kp, float kd){

  bool barUp = joystickGetDigital(2,5,JOY_UP);//removable
  bool barDown = joystickGetDigital(2,5,JOY_DOWN);//removable
  float barGain = 0.2;
  int barError;
  int barSpeed;

  barError = targetValue - analogRead(CHAINPOT);
  barSpeed = barError * barGain;
  moveChainBar(-barSpeed);
}

void chaindown(int targetValue, int timeout, float kp, float kd){

  bool barUp = joystickGetDigital(2,5,JOY_UP);
  bool barDown = joystickGetDigital(2,5,JOY_DOWN);
  float barGain = 0.2;
  int barError;
  int barSpeed;

  barError = targetValue - analogRead(CHAINPOT);
  barSpeed = barError * barGain;
  moveChainBar(-barSpeed);
}

 void matchbarup(){
  float barGain = 1.5;
  int barError;
  int barSpeed;
  int currentChain;
  int timeout_bar = 1000;
  int startTime = millis();
  while(analogRead(CHAINPOT) > 360 || (millis()-startTime)<timeout_bar){
  barError = 360 - analogRead(CHAINPOT);
  barSpeed = barError * barGain;
  moveChainBar(barSpeed);
  delay(20);
  }
}

void matchbardown(){
  float barGain = 0.2;
  int barError;
  int barSpeed;
  int currentChain;
  int timeout_bar = 2000;
  int startTime = millis();
  while(analogRead(CHAINPOT) < 2500 || (millis()-startTime)<timeout_bar){
  barError = 2500 - analogRead(CHAINPOT);
  barSpeed = barError * barGain;
  moveChainBar(barSpeed);
  delay(20);
  }
}

void matchbarstraight(){
  float barGain = 1.5;
  int barError;
  int barSpeed;
  int currentChain;
  int timeout_bar = 1000;
  int startTime = millis();
  while(analogRead(CHAINPOT) < 1250 || (millis()-startTime)<timeout_bar){
  barError = 1250 - analogRead(CHAINPOT);
  barSpeed = barError * barGain;
  moveChainBar(barSpeed);
  delay(20);
  }
}

//***************************
//       Intake
//***************************

void intakeOpen(){
  moveIntake(-127);
  delay(100);
  moveIntake(0);
}

void intakeClose(){
  moveIntake(127);
  delay(100);
  moveIntake(0);
}

void intakeStay(){
  moveIntake(0);
}

void intakeHold(){
  moveIntake(30);
}

//***************************
//       PreLoad
//***************************

void preLoads(){}

//***************************
//       Reset Everything
//***************************
void resetEverything(){
  gyroReset(gyro);//Resets gyro
  encoderReset(encoderL);//Resets encoderL
  encoderReset(encoderR); //Resets encoderR
}

//***************************
//       Cone Preset
//***************************

void conePreset(void* parameter){
  if (joystickGetDigital(2, 7, JOY_UP)){
  autostack = 1;
  moveIntake(-90);
  moveArm(90);
  delay(150);
  moveArm(-10);
  moveChainBar(-90);
  delay(600);
  moveChainBar(0);
  moveIntake(90);
  delay(500);
  moveChainBar(90);
  delay(500);
  moveChainBar(0);
  moveIntake(-90);
  armDown(2500);
  autostack = 0;
  delay(20);
}
delay(20);
}
