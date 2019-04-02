#include "main.h"
using namespace okapi;

Controller master; //Set Main Controller
ControllerButton intakeButton(ControllerDigital::L1); //Button L1
ControllerButton outakeButton(ControllerDigital::L2); //Button L2
ControllerButton shootButton(ControllerDigital::R1); //Button R1

void opcontrol() {

	auto drive = ChassisControllerFactory::create (
                 {driveLF, driveLB, driveLM}, {driveRF, driveRB, driveRM}, //Left Ports + Right Ports
                 AbstractMotor::gearset::green, //Motor Gear Ration
                 {4_in, 13_in} //Wheel Diameter + Base Width
               );

	Motor shooterMtr = 15_mtr;
	Motor intakeMtr = 16_mtr;

	while (true) {

		drive.arcade(master.getAnalog(ControllerAnalog::leftY), master.getAnalog(ControllerAnalog::rightX));

		if(intakeButton.isPressed()){
			intakeMtr.move(127);
		}
		else if(outakeButton.isPressed()){
			intakeMtr.move(-127);
		}
		else{
			intakeMtr.move(0);
		}

		if(shootButton.isPressed()){
			shooterMtr.move(127);
		}
		else{
			shooterMtr.move(0);
		}

		pros::delay(20);
	}
}
