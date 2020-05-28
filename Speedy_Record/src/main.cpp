#include "main.h"
#include "robot_includes/robot_includes.hpp"

using namespace pros;

//========================================//
//				Project Object Defines					//
//========================================//

double getVelocity(Motor motor) {
  return motor.get_actual_velocity();
}

void record() {
	int count = 0;
	FILE* file = fopen("/usd/example.txt",  "w");
	while (count < 14500) {
					fprintf(file, "%f\n", getVelocity(left_back_mtr));
					fprintf(file, "%f\n", getVelocity(left_front_mtr));
					fprintf(file, "%f\n", getVelocity(right_back_mtr));
					fprintf(file, "%f\n", getVelocity(right_front_mtr));
					fprintf(file, "%f\n", getVelocity(intake_mtr));
					fprintf(file, "%f\n", getVelocity(intake_mtr_two));
					fprintf(file, "%i\n", ramp_state);
					fprintf(file, "%i\n", lift_state);

					chassis.driveControl();
					lift.driveControl();

					pros::delay(10);
					count += 10;
	}
	fclose(file);
}

void reRun() {

  FILE *fp;
  fp = fopen("/usd/example.txt", "r");
  static float v1, v2, v3, v4, v5, v6;
  static int s1, s2;

  while(true) {

    if(feof(fp)) {
      left_back_mtr.move_velocity(0);
      left_front_mtr.move_velocity(0);
      right_back_mtr.move_velocity(0);
      right_front_mtr.move_velocity(0);
      angler_mtr.move_velocity(0);
      intake_mtr.move_velocity(0);
      intake_mtr_two.move_velocity(0);
      arm_mtr.move_velocity(0);
      fclose(fp);
      pros::delay(100);

    } //End if(feof(fp))

    fscanf(fp, "%f %f %f %f %f %f %i %i", &v1, &v2, &v3, &v4, &v5, &v6, &s1, &s2);

    left_back_mtr.move_velocity(v1);
    left_front_mtr.move_velocity(v2);
    right_back_mtr.move_velocity(v3);
    right_front_mtr.move_velocity(v4);
    intake_mtr.move_velocity(v5);
    intake_mtr_two.move_velocity(v6);
    ramp_state = s1;
    lift_state = s2;

    pros::delay(10);

  } //End while(true)
} //End void reRun()

//Controllers//
Controller master(E_CONTROLLER_MASTER);
Controller partner(E_CONTROLLER_PARTNER);
//~~~~~~~~//

//Motors//
Motor left_back_mtr(14, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
Motor left_front_mtr(19, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
Motor right_front_mtr(13, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
Motor right_back_mtr(12, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
Motor arm_mtr(4, E_MOTOR_GEARSET_36, false, E_MOTOR_ENCODER_DEGREES);
Motor intake_mtr(3, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
Motor intake_mtr_two(2, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
Motor angler_mtr(20, E_MOTOR_GEARSET_36, false, E_MOTOR_ENCODER_DEGREES);
//~~~~~~~//

//Sensors//
ADIDigitalIn liftLim('g');
ADIDigitalIn rampLim('a');
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
PID lift_PID;
//~~~~~~~//

//Global Variables//
int intake_state;
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
	angler_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);
	arm_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);
	intake_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);
	intake_mtr_two.set_brake_mode(MOTOR_BRAKE_HOLD);
}

void disabled() {}

void competition_initialize() {}

void autonomous() {
	reRun();
}


void opcontrol() {
	record();
}
