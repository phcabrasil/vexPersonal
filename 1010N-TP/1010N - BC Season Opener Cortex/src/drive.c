#include "C:\Users\Curia\Documents\GitHub\2018-2019-1010N\1010N-TP\1010N - BC Season Opener\include\main.h"

//****************************
//       Move Drive Basic
//****************************

void moveDrive(int left, int right){

  //Left Drive
  motorSet(mtrDriveRF, (right));
  motorSet(mtrDriveRB, -(right));
  //Right Drive
  motorSet(mtrDriveLF, -(left));
  motorSet(mtrDriveLB, -(left));

}

//***********************
//      Drive Slow
//***********************

void moveDriveAim(int left, int right, int cap){

  //Left Drive
  motorSet(mtrDriveRF, (right)*cap);
  motorSet(mtrDriveRB, -(right)*cap);
  //Right Drive
  motorSet(mtrDriveLF, -(left)*cap);
  motorSet(mtrDriveLB, -(left)*cap);

}

//***********************
//       Drive
//***********************

void drive(int direction, int target){

  //Drive Variables
  int leftPower;
  int rightPower;
  int tics;
  int ticsL;
  int ticsR;
  int error;

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


      moveDrive(direction*rightPower, direction*leftPower);//Move Drive

      delay(20);
    }
}

//***********************
//       Drive PID
//***********************

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
  int error;

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
  gyroReset(relativeGyro);
  int startTime = millis();

  while((millis()-startTime)<timeout){ //Timeout

    pos = abs(gyroGet(relativeGyro)); //current value is the absolute of gyro value
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

//**************************
//       Turn Back PID
//**************************

void turnBack(int direction, int timeout, float kp, float kd){

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
  int startTime = millis();

  while((millis()-startTime)<timeout){ //Timeout

    pos = abs(gyroGet(absoluteGyro)); //current value is the absolute of gyro value
    errorG =  0 - pos; //difference between target value and current value

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
