#include "main.h"
using namespace okapi;

//Expo Code --USELESS-
int expDrive (int joyVal, float driveExp, int joyDead, int motorMin) {
    int joyMax = 128 - joyDead;
    int joyLive = abs(joyVal) - joyDead;
    return /*joySign * */ (motorMin + ((100 - motorMin) * pow(joyLive, driveExp) / pow(joyMax, driveExp)));
}

//Controller
Controller controller; //Set Main Controller
ControllerButton intakeButton(ControllerDigital::R1); //Button R1
ControllerButton outakeButton(ControllerDigital::R2); //Button R2
ControllerButton fullSpeed(ControllerDigital::X); //Button X
ControllerButton noSpeed(ControllerDigital::B); //Button Down
ControllerButton halfSpeed(ControllerDigital::right); //Button Right

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

  int fwSpeed = 1; //Flywheel Speed Variable

  Motor intakeMotor = 5_mtr; // Intake 5
  Motor fwMotor = 6_mtr; // Flywheel 6

  while (true) {

    drive.arcade(controller.getAnalog(ControllerAnalog::leftY), //Drive Arcade
                 controller.getAnalog(ControllerAnalog::rightX));

    if (intakeButton.isPressed()) { //Intake Control
      intakeMotor.move(-127);
    } else if (outakeButton.isPressed()) {
      intakeMotor.move(127);
    } else {
      intakeMotor.move(0);
    }

    if (noSpeed.isPressed()) { //Flywheel Speed Control
      fwSpeed = 0;
    } else if (fullSpeed.isPressed()) {
      fwSpeed = 2;
    } else if (halfSpeed.isPressed()) {
      fwSpeed = 1;
    } else { }

    if (fwSpeed == 2) { //Flywheel Control
      fwMotor.move(127);
      pros::delay(10);
    } else if (fwSpeed == 1) {
      fwMotor.move(50);
      pros::delay(10);
    } else if (fwSpeed == 0) {
      fwMotor.move(0);
      pros::delay(10);
    } else {
      fwMotor.move(0);
    }

    pros::Task::delay(10);

  }

}
