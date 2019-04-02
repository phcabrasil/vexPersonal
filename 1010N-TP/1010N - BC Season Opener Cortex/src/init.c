#include "C:\Users\Curia\Documents\GitHub\2018-2019-1010N\1010N-TP\1010N - BC Season Opener\include\main.h"
#include "C:\Users\Curia\Documents\GitHub\2018-2019-1010N\1010N-TP\1010N - BC Season Opener\include\lcdfunctions.h"

void initializeIO() {

  //Limit Swicthes
  pinMode(BALLSLIMIT, INPUT);
  pinMode(LIFTLIMIT, INPUT);

}

void initialize() {

  //Initialize Encoders (Drive and Arm)
  encoderR = (encoderInit(ENCR1, ENCR2, 0));
  encoderL = (encoderInit(ENCL1, ENCL2, 0));
  encoderA = (encoderInit(ENCA1, ENCA2, 0));
  encoderF = (encoderInit(ENCF1, ENCF2, 0));

  //Calibrate Potentimeters
  analogCalibrate(CAPPOT);

  //Initialize Gyro
  absoluteGyro = (gyroInit(AGYRO, 0));
  relativeGyro = (gyroInit(RGYRO, 0));

  //Initialize LCD Screen
  lcdInit(uart1);
  lcdClear(uart1);

  //Handle Task Disable LCD
  TaskHandle disablelcd_task = taskCreate(disablelcd, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);

}
