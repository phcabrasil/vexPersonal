<<<<<<< HEAD
#include "main.h"
#include "lcdfunctions.h"
#include "ports.h"
#include "arm.h"
#include "drive.h"
#include "intake.h"
#include "fourbar.h"
#include "mblift.h"

void operatorControl() {
	while (1) {
			TaskHandle opcontrollcd_task = taskCreate(opcontrollcd, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);

int error;
float gain;
int encoderCurrent;

		//***********************
		//       Drive
		//***********************

		int Y1 = 0;
		int X1 = 0;
		int deadZone = 5;

		int leftStickVertical = joystickGetAnalog(1, 3); //joystick command for vertical movement
		int leftStickHorizontal = joystickGetAnalog(1, 1); //joystick command for horizontal movement


		if (abs (leftStickVertical) > deadZone) {
			Y1 = leftStickVertical; }
			else {
			Y1 = 0;
		}
		if (abs (leftStickHorizontal) > deadZone) {
			X1 = leftStickHorizontal; }
			else {
			X1 = 0;
		}

		motorSet(DRIVE_LF, -Y1 + X1);
		motorSet(DRIVE_LB, -Y1 + X1);

		motorSet(DRIVE_RF, Y1 + X1);
		motorSet(DRIVE_RB, Y1 + X1);

		//***********************
		//        Arm
		//***********************

		if (joystickGetDigital(2, 5, JOY_UP)){
			moveArm(127);
		}
		else if (joystickGetDigital(2, 5, JOY_DOWN)){
			moveArm(-127);
		}
		else {
			moveArm(0);
		}

		//***********************
    //   Mobile Goal Lift
    //***********************

		if (joystickGetDigital(1, 5, JOY_UP)){
			moveLift(127);
		}
		else if (joystickGetDigital(1, 5, JOY_DOWN)){
			moveLift(-127);
		}
		else {
			moveLift(0);
		}

		//***********************
		//       Intake
		//***********************
		//if (analogRead(1) > 800){
		if (joystickGetDigita(1, 6, JOY_UP)){
			moveIntake(-127);
		}
		else if (joystickGetDigital(1, 6, JOY_DOWN)){
			moveIntake(127);
		}
		else {
			moveIntake(0);
		}
//}

/*else{
	while(analogRead(1)<801){
		moveIntake(30);
	}
moveIntake(0);
	}*/
		//***********************
		//     Chain Bar
		//***********************

		if (joystickGetDigital(2, 6, JOY_DOWN)){
			move4bar(-127);
			}

		else if ((joystickGetDigital(2, 6, JOY_UP))) {
			move4bar(127);
		}

		else{
			move4bar(0);
		}

		delay(20);

	}
}
=======
#include "main.h"
#include "lcdfunctions.h"
#include "ports.h"
#include "arm.h"
#include "drive.h"
#include "intake.h"
#include "fourbar.h"
#include "mblift.h"

void operatorControl() {
	while (1) {
			TaskHandle opcontrollcd_task = taskCreate(opcontrollcd, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);

int error;
float gain;
int encoderCurrent;

		//***********************
		//       Drive
		//***********************

		int Y1 = 0;
		int X1 = 0;
		int deadZone = 5;

		int leftStickVertical = joystickGetAnalog(1, 3); //joystick command for vertical movement
		int leftStickHorizontal = joystickGetAnalog(1, 1); //joystick command for horizontal movement


		if (abs (leftStickVertical) > deadZone) {
			Y1 = leftStickVertical; }
			else {
			Y1 = 0;
		}
		if (abs (leftStickHorizontal) > deadZone) {
			X1 = leftStickHorizontal; }
			else {
			X1 = 0;
		}

		motorSet(DRIVE_LF, -Y1 + X1);
		motorSet(DRIVE_LB, -Y1 + X1);

		motorSet(DRIVE_RF, Y1 + X1);
		motorSet(DRIVE_RB, Y1 + X1);

		//***********************
		//        Arm
		//***********************

		if (joystickGetDigital(2, 5, JOY_UP)){
			moveArm(127);
		}
		else if (joystickGetDigital(2, 5, JOY_DOWN)){
			moveArm(-127);
		}
		else {
			moveArm(0);
		}

		//***********************
    //   Mobile Goal Lift
    //***********************

		if (joystickGetDigital(1, 5, JOY_UP)){
			moveLift(127);
		}
		else if (joystickGetDigital(1, 5, JOY_DOWN)){
			moveLift(-127);
		}
		else {
			moveLift(0);
		}

		//***********************
		//       Intake
		//***********************
		//if (analogRead(1) > 800){
		if (joystickGetDigita(1, 6, JOY_UP)){
			moveIntake(-127);
		}
		else if (joystickGetDigital(1, 6, JOY_DOWN)){
			moveIntake(127);
		}
		else {
			moveIntake(0);
		}
//}

/*else{
	while(analogRead(1)<801){
		moveIntake(30);
	}
moveIntake(0);
	}*/
		//***********************
		//     Chain Bar
		//***********************

		if (joystickGetDigital(2, 6, JOY_DOWN)){
			move4bar(-127);
			}

		else if ((joystickGetDigital(2, 6, JOY_UP))) {
			move4bar(127);
		}

		else{
			move4bar(0);
		}

		delay(20);

	}
}
>>>>>>> 3637b237cd0a7285710378320fffdecb427b5c2a
