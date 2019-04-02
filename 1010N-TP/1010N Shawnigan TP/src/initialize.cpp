#include "main.h"

Controller master(E_CONTROLLER_MASTER);

Motor driveLF(1, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
Motor driveLB(20, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
Motor driveRF(7, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
Motor driveRB(10, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
Motor fwMtrF(8, E_MOTOR_GEARSET_06, true, E_MOTOR_ENCODER_DEGREES);
Motor fwMtrB(9, E_MOTOR_GEARSET_06, true, E_MOTOR_ENCODER_DEGREES);
Motor intakeMtr(3, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
Motor fwIntakeMtr(6, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);

ADIGyro gyroL('a');
ADIGyro gyroR('b');

void initialize() {

	driveLF.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	driveLB.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	driveRF.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	driveRB.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	intakeMtr.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
	fwIntakeMtr.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
	fwMtrF.set_brake_mode(E_MOTOR_BRAKE_COAST);
	fwMtrB.set_brake_mode(E_MOTOR_BRAKE_COAST);

}

void disabled() {}

void competition_initialize() {}
