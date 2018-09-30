#include "C:\Users\Curia\Documents\GitHub\vexPersonal\1010N-TP\1010N - BC Season Opener\include\main.h"
#include "C:\Users\Curia\Documents\GitHub\vexPersonal\1010N-TP\1010N - BC Season Opener\include\lcdfunctions.h"
#include "C:\Users\Curia\Documents\GitHub\vexPersonal\1010N-TP\1010N - BC Season Opener\include\flywheel.h"
#include "C:\Users\Curia\Documents\GitHub\vexPersonal\1010N-TP\1010N - BC Season Opener\include\drive.h"
#include "C:\Users\Curia\Documents\GitHub\vexPersonal\1010N-TP\1010N - BC Season Opener\include\lift.h"


int flywheelRamp = -45;
int targetflywheelRamp = -90;
int rest = 0;
int ramp = 1;

void operatorControl() {
	while (1) {

		TaskHandle opcontrollcd_task = taskCreate(opcontrollcd, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);

		//********************************
		//   Flywheel and Ball Intake
		//********************************

		if (ramp == 1){
			rest = 0;
		}

		//Flywheel Move
		if(joystickGetDigital(1,8,JOY_LEFT)){
			ramp = 0;
		}

		if(ramp == 1){
			if(flywheelRamp < targetflywheelRamp){
				for(flywheelRamp; flywheelRamp < 90; flywheelRamp++){
					moveFlywheel(flywheelRamp);
					delay(400);
				}
			}
		}

		if (joystickGetDigital(1,8,JOY_UP)) {
			rest = 0;
		}

		if (joystickGetDigital(1,8,JOY_DOWN)) {
			rest = 1;
		}

		if (rest == 1) {
			moveFlywheel(40);
		}
		else {
			moveFlywheel(90);
		}

		//Ball Intake
		if (joystickGetDigital(1, 6, JOY_UP)) {
			moveIntake(90);
		}
		else if (joystickGetDigital(1, 6, JOY_DOWN)) {
			moveIntake(-90);
		}
		else {
			moveIntake(0);
		}

		//**********************
		//        Drive
		//**********************

		//Variables
		int Y1 = 0; //Y-Axis on Arcade
		int X1 = 0; //X-Axis on Arcade
		int deadZone = 10; //Deadzone Value Was 20
		int leftStickVertical = joystickGetAnalog(1, 3); //Joystick command for vertical movement
		int leftStickHorizontal = joystickGetAnalog(1, 1); //Joystick command for horizontal movement

		//Deadzone Code
		if (abs (leftStickVertical) > deadZone) {
			Y1 = leftStickVertical;
		}
		else {
			Y1 = 0;
		}
		if (abs (leftStickHorizontal) > deadZone) {
			X1 = leftStickHorizontal;
		}
		else {
			X1 = 0;
		}

		//Cap Motors
		if (Y1 > 90) {Y1 = 90;}
		if (Y1 < -90) {Y1 = -90;}
		if (X1 > 90) {X1 = 90;}
		if (X1 < -90) {X1 = -90;}

		//Left Drive
		motorSet(mtrDriveRF, Y1 + X1);
		motorSet(mtrDriveRB, -Y1 - X1);
		//Right Drive
		motorSet(mtrDriveLF, -Y1 + X1);
		motorSet(mtrDriveLB, -Y1 + X1);

		//*****************************
		//   Elevator and Cap Intake
		//*****************************

		//Variables
		int rightStickVertical = joystickGetAnalog(2, 2);

		if (digitalRead(LIFTLIMIT) == LOW) {
			if (rightStickVertical < 0){rightStickVertical = 0;}
		}

		//Elevator
		motorSet(mtrElevatorR, -rightStickVertical);
		motorSet(mtrElevatorL, rightStickVertical);

		//Cap Intake
		if (joystickGetDigital(2, 5, JOY_UP)){
			motorSet(mtrCapIntake, -90);
		}
		else if (joystickGetDigital(2, 5, JOY_DOWN)){
			motorSet(mtrCapIntake, 90);
		}
		else {
			motorSet(mtrCapIntake, 0);
		}

	}

	delay(20);

}
