#include "main.h"
#include "flywheel.h"
using namespace okapi;

//Expo Code --USELESS-
int expDrive (int joyVal, float driveExp, int joyDead, int motorMin) {
    int joyMax = 127 - joyDead;
    int joyLive = abs(joyVal) - joyDead;
    int power = motorMin + ((100 - motorMin) * pow(joyLive, driveExp) / pow(joyMax, driveExp));
    return power;
}

//Controller
okapi::Controller controller; //Set Main Controller
ControllerButton fullSpeed(ControllerDigital::X); //Button X
ControllerButton noSpeed(ControllerDigital::B); //Button B
ControllerButton halfSpeed(ControllerDigital::A); //Button A
ControllerButton intakeButton(ControllerDigital::R1); //Button R1
ControllerButton outakeButton(ControllerDigital::R2); //Button R2

void opcontrol() {

  pros::Task::delay(100);

  //Drive
  auto drive = ChassisControllerFactory::create (
                 {driveLF, driveLB, driveLM}, {driveRF, driveRB, driveRM}, //Left Ports + Right Ports
                 AbstractMotor::gearset::green, //Motor Gear Ration
                 {3.25_in, 12.5_in} //Wheel Diameter + Base Width
               );

  //Drive Expo Variables
  const int cJoyDead = 8;         // joystick range in which movement is considered accidental
  const int cMotorMin = 15;       // minimum drive motor power
  const float cDriveExp = 1.4;    // exponent for drive power calculations  (1 = linear, 2 = squared)

  int fwSpeed = 0; //Flywheel Speed Variable

  Motor fwMotor = 6_mtr; // Flywheel 6
  Motor intakeMotor = 5_mtr; // Intake 5

  while (true)
  {

    drive.arcade(controller.getAnalog(ControllerAnalog::leftY), //Drive Arcade
                 controller.getAnalog(ControllerAnalog::rightX));

    if (intakeButton.isPressed())
      {
        intakeMotor.move(-127);
      }
    else if (outakeButton.isPressed())
      {
        intakeMotor.move(127);
      }
    else
      {
        intakeMotor.move(0);
      }


    if(fullSpeed.isPressed())
      {
        fwSpeed = 100;
      }
    else if(halfSpeed.isPressed())
      {
        fwSpeed = 50;
      }
    else if(noSpeed.isPressed())
      {
        fwSpeed = -5;
      }
    else
      {
        fwMotor.moveVelocity(fwSpeed);
      }

    pros::Task::delay(10);

  }//END while(true)

}//END void opcontrol()
