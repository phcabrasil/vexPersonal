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
Motor left_back_mtr(8, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
Motor left_front_mtr(5, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
Motor right_front_mtr(6, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
Motor right_back_mtr(7, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
Motor arm_mtr(20, E_MOTOR_GEARSET_36, true, E_MOTOR_ENCODER_DEGREES);
Motor intake_mtr(19, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
Motor intake_mtr_two(11, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
Motor angler_mtr(1, E_MOTOR_GEARSET_36, false, E_MOTOR_ENCODER_DEGREES);
//~~~~~~~//

//Sensors//
ADIAnalogIn anglerPot('b');
ADIDigitalIn rampLim('g');
ADIDigitalIn liftLim('h');
ADIGyro gyro('a');
//~~~~~~~//

//Classes//
Chassis chassis;
Lift lift;
PID drive_PID;
PID turn_PID;
PID pivot_PID;
PID outerCurve_PID;
PID innerCurve_PID;
PID idle_PID;
PID ramp_PID;
//~~~~~~~//

//Global Variables//
int selected_auto;
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
	//Motor Break Modes
	left_back_mtr.set_brake_mode(MOTOR_BRAKE_COAST);
	left_front_mtr.set_brake_mode(MOTOR_BRAKE_COAST);
	right_back_mtr.set_brake_mode(MOTOR_BRAKE_COAST);
	right_front_mtr.set_brake_mode(MOTOR_BRAKE_COAST);
	angler_mtr.set_brake_mode(MOTOR_BRAKE_COAST);
	arm_mtr.set_brake_mode(MOTOR_BRAKE_COAST);
	intake_mtr.set_brake_mode(MOTOR_BRAKE_COAST);
	intake_mtr_two.set_brake_mode(MOTOR_BRAKE_COAST);
}

void disabled() {}

void competition_initialize() {}

void autonomous() {
  //chassis.autoPivot(RIGHT, RIGHT, 900, 5000);
  //chassis.autoTurn(RIGHT, 900, 5000);
  chassis.autoDrive(BACKWARDS, -300, 1000);
}

void opcontrol() {
	while (true) {
    chassis.driveControl();
		lift.driveControl();
		pros::delay(10);
	}
}
