#include "main.h"
#include "drive.hpp"

void driveClass::timeDrive (int speed, int delay) {

  driveLF.move(speed);
  driveLB.move(speed);
  driveRF.move(speed);
  driveRB.move(speed);

  pros::delay(delay);

  driveLF.move(0);
  driveLB.move(0);
  driveRF.move(0);
  driveRB.move(0);

}

void driveClass::drive(int direction, int target, int timeout, float kp, float kd){

  //Drive Variables
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
  driveLB.tare_position();
  driveRB.tare_position();
  int startTime = pros::millis();

  while((pros::millis()-startTime)<timeout){ //Timeout

    pos = abs((driveLB.get_position() + driveRB.get_position()) / 2); //current value is the absolute of gyro value
    errorG =  target - pos; //difference between target value and current value

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

    int leftSide = direction*drivepower;
    int rightSide = direction*drivepower;

    driveLF.move(leftSide);
    driveLB.move(leftSide);
    driveRF.move(rightSide);
    driveRB.move(rightSide);

    delay(40);
  }
  delay(20);

}

void driveClass::strafe(int direction, int target, int timeout, float kp, float kd){

  //Strafe Variables
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
  driveLB.tare_position();
  int startTime = millis();

  while((millis()-startTime)<timeout){ //Timeout

    pos = abs(driveLB.get_position()); //current value is the absolute of gyro value
    errorG =  target - pos; //difference between target value and current value

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

    int leftSide = direction*drivepower;
    int rightSide = direction*drivepower;

    driveLF.move(leftSide);
    driveLB.move(-leftSide);
    driveRF.move(-rightSide);
    driveRB.move(rightSide);

    delay(40);
  }
  delay(20);

}

void driveClass::turn(int direction, int target, int timeout, float kp, float kd){

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
  gyroR.reset();
  gyroL.reset();
  int startTime = millis();

  while((millis()-startTime)<timeout){ //Timeout

    pos = abs((gyroR.get_value()+gyroL.get_value())/2); //current value is the absolute of gyro value
    errorG =  target - pos; //difference between target value and current value

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

    int leftSide = direction*drivepower;
    int rightSide = direction*drivepower;

    driveLF.move(leftSide);
    driveLB.move(leftSide);
    driveRF.move(-rightSide);
    driveRB.move(-rightSide);

    delay(40);
  }
  delay(20);

}
