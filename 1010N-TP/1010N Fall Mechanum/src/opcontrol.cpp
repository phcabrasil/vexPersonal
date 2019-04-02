#include "main.h"
#include "flywheel.h"
using namespace pros;

//MOTORS

//Drive
//Left
Motor driveLTop (1, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES); //Port 1 Not Reversed //10
Motor driveLBack (20, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES); //Port 2 Not Reversed //9
//Right
Motor driveRTop (7, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES); //Port 9 Not Reversed //1
Motor driveRBack (10, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES); //Port 10 Not Reversed //2

//Intake
Motor intakeMtr (6, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES); //Port 10 Not Reversed //2

//Flywheel
Motor fwMtrB (8, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES); //Port 10 Not Reversed //2
Motor fwMtrT (9, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES); //Port 10 Not Reversed //2

//END MOTORS

//Expo Code --USELESS--
int expDrive (int joyVal, float driveExp, int joyDead, int motorMin) {
    int joySign;
    int joyMax = 127 - joyDead;
    int joyLive = abs(joyVal) - joyDead;
    if (joyVal > 0) {joySign = 1;}
    else if (joyVal < 0) {joySign = -1;}
    else {joySign = 0;}
    int power = joySign * (motorMin + ((100 - motorMin) * pow(joyLive, driveExp) / pow(joyMax, driveExp)));
    return power;
} //END int expDrive

//Drive Expo Variables
const int cJoyDead = 8; // joystick range in which movement is considered accidental
const int cMotorMin = 15; // minimum drive motor power
const float cDriveExp = 1.5; // exponent for drive power calculations  (1 = linear, 2 = squared) //1.4

//Controller
Controller master (E_CONTROLLER_MASTER);

void opcontrol() {

  pros::Task::delay(100);

  Task Flywheel_Task(
    fwTask_fn,
    (void*)"PROS",
    TASK_PRIORITY_DEFAULT,
    TASK_STACK_DEPTH_DEFAULT,
    "Flywheel Task"
   );

  while (true)
  {

    /*
    //Normal Inputs Drive
    int Y1 = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y); //Forward-Backwards
    int X1 = master.get_analog(E_CONTROLLER_ANALOG_LEFT_X); //Right-Left
    int Z1 = master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X); //Yaw
    */

    //Expo Controller Inputs Drive
    int Y1 = expDrive(master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y), cDriveExp, cJoyDead, cMotorMin); //Expo Forward-Backwards
    int X1 = expDrive(master.get_analog(E_CONTROLLER_ANALOG_LEFT_X), cDriveExp, cJoyDead, cMotorMin); //Expo Right-Left
    int Z1 = expDrive(master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X), cDriveExp, cJoyDead, cMotorMin); //Expo Yaw

    //Drive Manual
    driveLTop.move( Y1 + X1 + Z1 );
    driveLBack.move( Y1 - X1 + Z1 );
    driveRTop.move( Y1 - X1 - Z1 );
    driveRBack.move( Y1 + X1 - Z1 );

    //Intake Control
    if (master.get_digital(E_CONTROLLER_DIGITAL_R1))
      {
        intakeMtr.move(127);
      }
    else if (master.get_digital(E_CONTROLLER_DIGITAL_R2))
      {
        intakeMtr.move(-127);
      }
    else
      {
        intakeMtr.move(0);
      }

    pros::Task::delay(10);

  }//END while(true)

}//END void opcontrol()
