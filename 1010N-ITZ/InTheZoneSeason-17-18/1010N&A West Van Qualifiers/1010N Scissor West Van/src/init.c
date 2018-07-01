#include "main.h"
#include "lcdfunctions.h"

void initializeIO() {
}

void initialize() {

pinMode(12, OUTPUT);
digitalWrite(12, HIGH);
  //Initialize Encoders (Drive and Arm)
  encoderR = (encoderInit(1, 2, false));
  encoderL = (encoderInit(5, 6, false));
  encoderA = (encoderInit(7, 8, false));

  //Initialize Gyro
  gyro = (gyroInit(3, 0));

  //Initialize LCD Screen
  lcdInit(uart1);
  lcdClear(uart1);

  //Handle Task Disable LCD
  TaskHandle disablelcd_task = taskCreate(disablelcd, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);

}
