#include "main.h"
using namespace okapi;

//Controller
Controller controller; //Set Main Controller
ControllerButton intakeButton(ControllerDigital::R1); //Button R1
ControllerButton outakeButton(ControllerDigital::R2); //Button R2
ControllerButton fullSpeed(ControllerDigital::X); //Button X
ControllerButton noSpeed(ControllerDigital::B); //Button B
ControllerButton halfSpeed(ControllerDigital::A); //Button A

void opcontrol() {

  pros::Task::delay(100);

  //Drive
  auto drive = ChassisControllerFactory::create (
                 {driveLF, driveLB}, {-driveRF, driveRB}, //Left Ports + Right Ports
                 AbstractMotor::gearset::green, //Motor Gear Ration
                 {3.25_in, 12.5_in} //Wheel Diameter + Base Width
               );

  int fwSpeed = 1; //Flywheel Speed Variable

  Motor intakeMotor = 3_mtr;
  Motor fwMotor = 8_mtr;

  while (true) {

    drive.arcade(controller.getAnalog(ControllerAnalog::leftY), //Drive Arcade
                 controller.getAnalog(ControllerAnalog::rightX));

    if (intakeButton.isPressed()) { //Intake Control
      intakeMotor.move(127);
    } else if (outakeButton.isPressed()) {
      intakeMotor.move(-127);
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
      fwMotor.move(-127);
      pros::delay(10);
    } else if (fwSpeed == 1) {
      fwMotor.move(-50);
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
