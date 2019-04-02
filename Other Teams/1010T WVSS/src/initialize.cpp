#include "main.h"

//Define Controller
Controller master(E_CONTROLLER_MASTER);

//Define Motors
Motor driveLF(12, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
Motor driveLB(11, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
Motor driveRF(13, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
Motor driveRB(14, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
Motor roller(16, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
Motor puncherL(20, E_MOTOR_GEARSET_36, true, E_MOTOR_ENCODER_DEGREES);
Motor puncherR(19, E_MOTOR_GEARSET_36, false, E_MOTOR_ENCODER_DEGREES);
Motor angler(18, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);

//Define Gyro
ADIGyro gyro('a');

void initialize() {

	//PROS LCD Initialize
	pros::lcd::initialize();

	//Set Brake Modes
	driveLF.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	driveLB.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	driveRF.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	driveRB.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	roller.set_brake_mode(E_MOTOR_BRAKE_COAST);
	puncherR.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	puncherL.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	angler.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	angler.tare_position();

}

void disabled() {}

void competition_initialize() {}
