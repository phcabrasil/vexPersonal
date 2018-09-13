#include "main.h"
#include "ports.h"
#include "drive.h"
#include "intake.h"
#include "arm.h"
#include "fourbar.h"
#include "mblift.h"

//Cone Heights for Arm
#define ground 0
#define cone1 10
#define cone2 20
#define cone3 30
#define cone4 40
#define cone5 50
#define cone6 60
#define cone7 70
#define cone8 80
#define cone9 90
#define cone10 100
#define cone11 110
#define cone12 120

int motorcap(int value){
  if (value > 127){
    return 127;}
  else if(value < -127){
    return -127;}
  else {
    return value;}
  }

void stopEverything () {
  moveArm(0);
  moveIntake(0);
  moveDrive(0,0);
  moveChainbar(0);
  moveLift(0);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*void drive_encoder(int direction, int target, int timeout, int maxpower, int minpower, float kdrift_encoder, float kaccel, float kdeaccel){

  int netpower = maxpower - minpower;
  float boost;
  int breakpower = 13;

  encoderReset(encoder2);
  encoderReset(encoder1);

  int encoderaverage = 0;
  int start_time = millis();
  int net_time = 0;

  while( (encoderaverage < target) && (net_time < timeout)){

    int net_time = millis() - start_time;

    encoderaverage = abs(encoderGet(encoder2))+abs(encoderGet(encoder1)/2);
    int encoder_error = encoderGet(encoder2) - encoderGet(encoder1); //subtract from L side

    //accel/deaccel constants
    if(encoderaverage < target*kaccel){
      boost = (encoderaverage)/(target*kaccel);}
    else if (encoderaverage > (target - target*kdeaccel)){
      boost = (encoderaverage)/(target - target*kdeaccel);}
    else{
      boost = 1;}

    int power_L = motorcap(minpower + boost*netpower) - direction*encoder_error*kdrift_encoder;
    int power_R = motorcap(minpower + boost*netpower) + direction*encoder_error*kdrift_encoder;
    moveDrive(direction*power_L, direction*power_R);

    delay(20);
    }
  //brake
  moveDrive(-direction*breakpower, -direction*breakpower);
  }
*/

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void driveForward(int direction,int encTarget, int timeout) {

  float kp = 9.5;
  float ki = 0;
  float kd = 19;

  int diff;
  int totalError = 0;
  int lastError = encoderGet(encoder1);
  long runTime = 0;
  long startTime = millis();
  int power;

  encoderReset(encoder1);
  encoderReset(encoder2);

  while(abs(((encoderGet(encoder1))+(encoderGet(encoder2))/2) < (encTarget/3)) && (runTime < timeout)){
     runTime = millis() - startTime;
	   int currValue = abs(encoderGet(encoder1));
     int currError = currValue - encTarget;
     totalError =+ currError;
     int diffError = currError - lastError;
     int currSpeed = currError / kp + totalError / ki + diffError / kd;

     motorSet(DRIVE_LF, -(127)*direction);
     motorSet(DRIVE_LB, -(127)*direction);

     motorSet(DRIVE_RF, (127)*direction);
     motorSet(DRIVE_RB, (127)*direction);

          lastError = currError;
        }
        delay(20);
        moveDrive(0,0);
      }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*void turn_pid(int direction, int target, int maxpower, float kp, float ki, float kd, int ki_range, long timeout){

  gyroReset(gyro);
  long start_time = millis();
  long net_time = 0;

  float kpv;
  float kiv;
  float kdv;

  int error_last = 0;
  int error_diff = 0;
  int error_sum = 0;

  int brake_power = 10;

  while( net_time < timeout){

    net_time = millis() - start_time;

    int pos = abs(gyro_read(gyro, 300));
    int error = target - pos;

    error_diff = error - error_last;
    error_last = error;

    if(abs(error)<ki_range){
      error_sum =+ error; }
    else{ error_sum = 0; }

    kpv = kp*error;
    kiv = ki*error_sum;
    kdv = kd*error_diff;

    int motor_power = (kpv+kiv+kdv);

    moveDrive(motor_power*direction, -motor_power*direction);// L, R

    delay(20);

  }*/

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void driveBack(int encTarget, int timeout) {

  float kp = 9.5;
  float ki = 0;
  float kd = 19;

  int totalError = 0;
  int lastError = encoderGet(encoder1);
  long runTime = 0;
  long startTime = millis();

  encoderReset(encoder1);
  encoderReset(encoder2);

  while(abs(((encoderGet(encoder1))+(encoderGet(encoder2))/2) < encTarget) && (runTime < timeout)){
     runTime = millis() - startTime;
	   int currValue = encoderGet(encoder1);
     int currError = currValue - encTarget;
     totalError =+ currError;
     int diffError = currError - lastError;

     int currSpeed = currError / kp + totalError / ki + diffError / kd;

     moveDrive(-(currSpeed), -(currSpeed));

     lastError = currError;
     delay(20);
  }
  moveDrive(0,0);
}

///////////////////////////////////////////

void turnRight(int degree){
gyroReset(gyro);
gyroGet(gyro);
  while((abs(gyroGet(gyro))) < degree){
    gyroGet(gyro);
    moveDrive(-127,127);
    delay(20);
  }
  gyroGet(gyro);
 if(abs(gyroGet(gyro)) >= degree) {
   moveDrive(0,0);
 }
}

void turnLeft(int degree){
gyroReset(gyro);
gyroGet(gyro);
  while((abs(gyroGet(gyro))) < degree){
    gyroGet(gyro);
    moveDrive(127,-127);
    delay(20);
  }
  gyroGet(gyro);
 if(abs(gyroGet(gyro)) >= degree) {
   moveDrive(0,0);
 }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void turn(int direction, int gyroTarget, int timeout) {

  float kp = 9.5;
  float ki = 0;
  float kd = 19;

  int totalError = 0;
  int lastError = gyroGet(gyro);
  long runTime = 0;
  long startTime = millis();

  gyroReset(gyro);

  while(abs(gyroGet(gyro) < gyroTarget)){
     runTime = millis() - startTime;
	   int currValue = (abs(gyroGet(gyro)));
     int currError = currValue - gyroTarget;
     totalError =+ currError;
     int diffError = currError - lastError;

     int currSpeed = currError / kp + totalError / ki + diffError / kd;

     moveDrive((currSpeed)*direction, -(currSpeed)*direction);

     lastError = currError;
     delay(20);
  }
  moveDrive(0,0);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void liftArm(int heightTarget, int timeout){

  float kp = 9.5;
  float ki = 0;
  float kd = 19;

  int totalError = 0;
  int lastError = encoderGet(chainencoder);
  long runTime = 0;
  long startTime = millis();

  encoderReset(chainencoder);

  while((abs(encoderGet(chainencoder)) < heightTarget) && (runTime < timeout)){

    runTime = millis() - startTime;
    int currValue = encoderGet(chainencoder);
    int currError = currValue - heightTarget;
    totalError =+ currError;
    int diffError = currError - lastError;

    int currSpeed = currError / kp + totalError / ki + diffError / kd;

    moveArm(currSpeed);

    lastError = currError;
    delay(20);
  }
  moveArm(0);
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void lowerArm(int heightTarget, int timeout){

  float kp = 9.5;
  float ki = 0;
  float kd = 19;

  int totalError = 0;
  int lastError = encoderGet(chainencoder);
  long runTime = 0;
  long startTime = millis();

  encoderReset(chainencoder);

  while((abs(encoderGet(chainencoder)) < heightTarget) && (runTime < timeout)){

    runTime = millis() - startTime;
    int currValue = encoderGet(chainencoder);
    int currError = currValue - heightTarget;
    totalError =+ currError;
    int diffError = currError - lastError;

    int currSpeed = currError / kp + totalError / ki + diffError / kd;

    moveArm(-(currSpeed));

    lastError = currError;
    delay(20);
  }
  moveArm(0);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void liftPylon(int timeout){
  moveLift(127);
  delay(timeout);
  moveLift(0);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void lowerPylon(int timeout){
  moveLift(-127);
  delay(timeout);
  moveLift(0);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void getCone(int timeout){

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void dropCone(int timeout){

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void chainIn(int timeout){

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void chainOut(int timeout){

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
