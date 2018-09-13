#include "main.h"
#include "autofunctions.h"
#include "lcdfunctions.h"
#include "drive.h"
#include "intake.h"
#include "arm.h"

void autonomous() {

  TaskHandle arm_position = taskCreate(arm, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
  TaskHandle intake = taskCreate(intakeDistance, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
  TaskHandle fourbar_position = taskCreate(fourBar, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);

}
