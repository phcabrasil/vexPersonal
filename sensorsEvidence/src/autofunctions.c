#include "main.h"
#include "autofunctions.h"
#include "lcdfunctions.h"
#include "drive.h"
#include "intake.h"
#include "arm.h"

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

SENSOR INFORMATION:

Arm MAX Height is 1700
Arm MIN Height is 200
Arm IDEAL Height is 300 to 400
Arm Difference in cones is 200(150) per cone

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
  moveDrive(0,0);
}

//********************************
//       Motor Speed Cap
//********************************

void motorCap(int cap, int speed){
  if(cap > speed){
    cap = speed;//Caps Max Given Motor Speed
  }
  else if(cap < -speed){
    cap = -speed;//Caps Min Given Motor Speed
  }
}

//*****************************
//       Drive / Encoder
//*****************************

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

        if(tics < target){ //If average is less than target, run motors
          leftPower = 127;
          rightPower = 127;
        }
        else{ //Otherwise don't move
          leftPower = 0;
          rightPower = 0;
        }

      moveDrive(direction*rightPower,direction*leftPower);//Move Drive

      delay(20);
    }
}

void drivePID(int direction, int target, int kp, int ki, int kd, int timeout){

  // Variables
  int error = 0;
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
  double startTime = millis();

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

//******************************
//       Turn PID / Gyro
//******************************

void turn(int direction, int targetTurn, int timeout, float kp, float kd){

  // Variables
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
  double startTime = millis();

  while((millis()-startTime)<timeout){ //Timeout

    pos = abs(gyroGet(gyro)); //current value is the absolute of gyro value
    error =  targetTurn - pos; //difference between target value and current value

    error_diff = error - error_last; //Difference between errors = Current Error - Last Error
    error_last = error; //store last error
    error_sum  += error; //Sum of error = Current error + Sum of error

    p = kp * error; //Proportional
    d  = kd * error_diff; //Derivative

    if(error < 5) //Integral Cap
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

//**************************************
//       ArmPosition / Potentiometer
//**************************************

void arm(void*parameter){

  // Variables
  int error = 0;
  int error_last = 0;
  int error_diff = 0;
  int error_sum = 0;
  int pos =  0;
  float kp = 0;
  float ki = 0;
  float kd = 0;
  float p;
  float d;
  float i;
  int power;

  pos = getPosition; //current value is the absolute of gyro value
  error =  armposition - pos; //difference between target value and current value

  error_diff = error - error_last; //Difference between errors = Current Error - Last Error
  error_last = error; //store last error
  error_sum  += error; //Sum of error = Current error + Sum of error

  p = kp * error; //Proportional
  d  = kd * error_diff; //Derivative

  if(error < 5){ //Integral Cap
    i = ki * error_sum; //Integral Cap{i = ki * error_sum;}
  }

  power = p+i+d; //PID

  moveArm(power);

  delay(40);
}

//****************************
//     Intake / Ultrasound
//****************************

void intakeDistance(void*parameter){

  if (intakeposition == true) {
    if(getDistance < 100){ //If game piece is in reaching range, grab
      moveIntake(127);
    }
    else{ //Otherwise retract
      moveIntake(-10);
    }
  }
  else if (intakeposition == false){ //Retract fast
    moveIntake(-127);
  }
  else{
    moveIntake(0);
  }
}

//******************************************
//       Pneumatic 4-Bar / Solenoid
//******************************************

void fourBar(void*parameter){
  if (barposition == true){
    digitalWrite(solenoid, HIGH); //Move up
  }
  else {
    digitalWrite(solenoid, LOW); //Move down
  }
}

//***************************
//       Reset Everything
//***************************

void resetEverything(){
  gyroReset(gyro); //Resets gyro
  encoderReset(encoderL); //Resets encoderL
  encoderReset(encoderR); //Resets encoderR
}
