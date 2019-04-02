#include "main.h"
using namespace okapi;

void opcontrol() {

  pros::Task::delay(100);

  //Drive
  auto drive = ChassisControllerFactory::create (
                 {driveLF, driveLB}, {driveRF, driveRB}, //Left Ports + Right Ports
                 AbstractMotor::gearset::green, //Motor Gear Ration
                 {3.25_in, 12.5_in} //Wheel Diameter + Base Width
               );
  auto profileController = AsyncControllerFactory::motionProfile (1.0/*Velocity*/, 2.0/*Acceleration*/, 9.0/*Jerk*/, drive);

  int fwSpeed = 1;

  Motor intakeMotor = 5_rmtr;
  Motor loadMotor = 6_mtr;
  Motor fwMotor = 4_rmtr;

  Controller controller; //Set Main Controller
  ControllerButton intakeButton(ControllerDigital::R1); //Button R1
  ControllerButton outakeButton(ControllerDigital::R2); //Button R2
  ControllerButton runAutoButton(ControllerDigital::A); //Button X
  ControllerButton descoreInButton(ControllerDigital::Y); //Button X
  ControllerButton descoreOutButton(ControllerDigital::X); //Button X
  ControllerButton loadButton(ControllerDigital::L1); //Button L1
  ControllerButton unloadButton(ControllerDigital::L2); //Button L2
  ControllerButton fullSpeed(ControllerDigital::up); //Button Up
  ControllerButton noSpeed(ControllerDigital::down); //Button Down
  ControllerButton halfSpeed(ControllerDigital::right); //Button Down


	profileController.generatePath({
  	Point{0_ft, 0_ft, 0_deg},
  	Point{5_ft, 0_ft, 0_deg}},
  	"MEMES"
	);

  while (true) {

    drive.arcade(controller.getAnalog(ControllerAnalog::leftY),
                 controller.getAnalog(ControllerAnalog::rightX));

    if (intakeButton.isPressed()) {
      intakeMotor.move(127);
    } else if (outakeButton.isPressed()) {
      intakeMotor.move(-127);
    } else {
      intakeMotor.move(0);
    }

    if (loadButton.isPressed()) {
      loadMotor.move(127);
    } else if (unloadButton.isPressed()) {
      loadMotor.move(-127);
    } else {
      loadMotor.move(0);
    }

    if (noSpeed.isPressed()) {
      fwSpeed = 0;
    } else if (fullSpeed.isPressed()) {
      fwSpeed = 2;
    } else if (halfSpeed.isPressed()) {
      fwSpeed = 1;
    } else { }

    if (fwSpeed == 2) {
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

    if (descoreOutButton.isPressed()) {
      descoreMotor.move(127);
    } else if (descoreInButton.isPressed()) {
      descoreMotor.move(-127);
    } else {
      descoreMotor.move(0);
    }

    if (runAutoButton.changedToPressed()) {
      profileController.setTarget("MEMES");
      profileController.waitUntilSettled();
    }

    pros::Task::delay(10);

  }
}
