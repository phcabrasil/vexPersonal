#include "main.h"
using namespace okapi;

void opcontrol() {

  pros::Task::delay(100);

  //Drive
  auto drive = ChassisControllerFactory::create (
                 {driveLF, driveLB, driveLM}, {driveRF, driveRB, driveRM}, //Left Ports + Right Ports
                 AbstractMotor::gearset::green, //Motor Gear Ration
                 {3.25_in, 12.5_in} //Wheel Diameter + Base Width
               );
  auto profileController = AsyncControllerFactory::motionProfile (1.0/*Velocity*/, 2.0/*Acceleration*/, 9.0/*Jerk*/, drive);

  Motor descoreMotor = 5_mtr; //Descorer Motor

  Controller controller; //Set Main Controller
  ControllerButton descoreOutButton(ControllerDigital::R1); //Button R1
  ControllerButton descoreInButton(ControllerDigital::R2); //Button R2
  ControllerButton runAutoButton(ControllerDigital::X); //Button X

	profileController.generatePath({ //Test Path
  	Point{0_ft, 0_ft, 0_deg},
  	Point{5_ft, 0_ft, 0_deg}},
  	"MEMES"
	);

  while (true) {

    drive.arcade(controller.getAnalog(ControllerAnalog::leftY), //Drive Arcade
                 controller.getAnalog(ControllerAnalog::rightX));

    if (descoreOutButton.isPressed()) { //Descorer Control
      descoreMotor.move(127);
    } else if (descoreInButton.isPressed()) {
      descoreMotor.move(-127);
    } else {
      descoreMotor.move(0);
    }

    if (runAutoButton.changedToPressed()) { //Test Auto
      profileController.setTarget("MEMES");
      profileController.waitUntilSettled();
    }

    pros::Task::delay(10);

  }
}
