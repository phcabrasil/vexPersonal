#include "main.h"
#include "lcdfunctions.h"

void initializeIO() {
  pinMode(4, OUTPUT); // configure digital port 1 as an output
  digitalWrite(4, LOW); // write LOW to port 1 (solenoid may be extended or not, depending on wiring)
}

void initialize() {

  //LED Program
  pinMode(12, OUTPUT);
  digitalWrite(12, HIGH);

  //Initialize Encoders (Drive and Arm)
  encoderR = (encoderInit(1, 2, false));
  encoderL = (encoderInit(5, 6, false));

  //Initialize Gyro
  gyro = (gyroInit(3, 0));

  //Initialize LCD Screen
  lcdInit(uart1);
  lcdClear(uart1);

  //Handle Task Disable LCD
  TaskHandle disablelcd_task = taskCreate(disablelcd, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);

}
