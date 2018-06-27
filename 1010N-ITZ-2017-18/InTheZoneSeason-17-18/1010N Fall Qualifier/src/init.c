#include "main.h"
#include "lcdfunctions.h"
#include "ports.h"

void initializeIO() {
}

void initialize() {

  //Initialize Encoders (Drive, Arm and Claw)
  encoder1 = (encoderInit(1, 2, false));
  encoder2 = (encoderInit(5, 6, false));
  chainencoder = (encoderInit(7, 8, false));


  //Initialize Gyro
  gyro = (gyroInit(3, 0));

  //Initialize LCD Screen
  lcdInit(uart1);
  lcdClear(uart1);

  //Handle Task Disable LCD
  TaskHandle disablelcd_task = taskCreate(disablelcd, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);

}
