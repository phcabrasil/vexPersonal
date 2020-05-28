#include "main.h"
#include "robot_includes/robot_includes.hpp"

using namespace pros;

//========================================//
//				Project Object Defines					//
//========================================//

//Controllers//
Controller master(E_CONTROLLER_MASTER);
Controller partner(E_CONTROLLER_PARTNER);
//~~~~~~~~//

//Motors//
Motor left_back_mtr(5, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
Motor left_front_mtr(9, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
Motor right_front_mtr(4, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
Motor right_back_mtr(1, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
Motor arm_mtr(15, E_MOTOR_GEARSET_36, true, E_MOTOR_ENCODER_DEGREES);
Motor intake_mtr(17, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
Motor intake_mtr_two(11, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
Motor angler_mtr(6, E_MOTOR_GEARSET_36, true, E_MOTOR_ENCODER_DEGREES);
//~~~~~~~//

//Sensors//
ADIDigitalIn liftLim('h');
ADIDigitalIn rampLim('g');
ADIUltrasonic lUltra('c','d');
ADIUltrasonic rUltra('e', 'f');
//~~~~~~~//

//Classes//
Chassis chassis;
Lift lift;
PID drive_PID;
PID turn_PID;
PID pivot_PID;
PID fenceL_PID;
PID fenceR_PID;
PID outerCurve_PID;
PID innerCurve_PID;
PID ramp_PID;
PID lift_PID;
//~~~~~~~//

//Global Variables//
int intake_state;
int lift_state;
int drive_priority;
int auto_state;
int ramp_state;
//~~~~~~~//

//Tasks//
pros::Task LIFT_task(
		 liftAuto_fn,
		 (void*)"PROS",
		 TASK_PRIORITY_DEFAULT,
		 TASK_STACK_DEPTH_DEFAULT,
		 "Lift Auto Task"
);
//~~~~~~~//

void initialize() {
	//Initialize LCD
  lcd::initialize();
	//Gyro
	imu.reset();
	//Motor Break Modes
	left_back_mtr.set_brake_mode(MOTOR_BRAKE_BRAKE);
	left_front_mtr.set_brake_mode(MOTOR_BRAKE_BRAKE);
	right_back_mtr.set_brake_mode(MOTOR_BRAKE_BRAKE);
	right_front_mtr.set_brake_mode(MOTOR_BRAKE_BRAKE);
	angler_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);
	arm_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);
	intake_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);
	intake_mtr_two.set_brake_mode(MOTOR_BRAKE_HOLD);
}

void disabled() {}

void competition_initialize() {}

void autonomous() {
}

void opcontrol() {
	while (true) {
    chassis.driveControl();
		lift.driveControl();
		pros::delay(10);
	}
}
