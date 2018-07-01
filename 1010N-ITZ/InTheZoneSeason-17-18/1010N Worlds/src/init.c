#include "main.h"
#include "lcdfunctions.h"

void initializeIO() {
  //button
  pinMode(BUTTON, INPUT);
  //LEDs
  pinMode(LED_STRP, OUTPUT);
  digitalWrite(LED_STRP, HIGH);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GRN, OUTPUT);
  pinMode(LED_YLW, OUTPUT);

}

void initialize() {

  //calibrate Potentiometers
  analogCalibrate(CHAINPOT);
  analogCalibrate(MOGOPOT);
  analogCalibrate(ARMPOT);

  //LED Program
  pinMode(12, OUTPUT);
  digitalWrite(12, HIGH);

  //ultrasonic sensor
  sonar = ultrasonicInit(ULTRASONIC_L, ULTRASONIC_R);

  //Initialize Encoders (Drive and Arm)
  encoderR = (encoderInit(2, 1, false));
  encoderL = (encoderInit(5, 6, false));

  //Initialize Gyro
  gyro = (gyroInit(3, 0));

  //Initialize LCD Screen
  lcdInit(uart1);
  lcdClear(uart1);

  //Handle Task Disable LCD
  TaskHandle disablelcd_task = taskCreate(disablelcd, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);

}
