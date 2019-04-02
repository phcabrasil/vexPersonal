#include "main.h"

Controller master(E_CONTROLLER_MASTER);

Motor driveLF(6, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
Motor driveLB(2, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
Motor driveRF(7, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
Motor driveRB(1, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
Motor punchMtrR(5, E_MOTOR_GEARSET_36, false, E_MOTOR_ENCODER_DEGREES);
Motor punchMtrL(3, E_MOTOR_GEARSET_36, true, E_MOTOR_ENCODER_DEGREES);
Motor intakeMtr(9, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
Motor angleMtr(8, E_MOTOR_GEARSET_36, true, E_MOTOR_ENCODER_DEGREES);

void initialize() {

	driveLF.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
	driveLB.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
	driveRF.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
	driveRB.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
	intakeMtr.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
	angleMtr.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
	punchMtrL.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	punchMtrR.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	angleMtr.tare_position();

}

void disabled() {}

void competition_initialize() {}
