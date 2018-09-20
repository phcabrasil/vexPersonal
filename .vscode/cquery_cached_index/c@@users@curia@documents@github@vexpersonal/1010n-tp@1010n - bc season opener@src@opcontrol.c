#include "main.h"

void operatorControl() {
	while (1) {

		//********************************
		//   Flywheel and Ball Intake
		//********************************

		//Flywheel Move
		motorSet(mtrFlywheelT, 90);
		motorSet(mtrFlywheelB, -90);

		//Ball Intake
		if (joystickGetDigital(1, 6, JOY_UP)){
			motorSet(mtrBallIntake, 90);
		}
		else if (joystickGetDigital(1, 6, JOY_DOWN)){
			motorSet(mtrBallIntake, -90);
		}
		else {
			motorSet(mtrBallIntake, 0);
		}

		//**********************
		//        Drive
		//**********************

		//Variables
		int Y1 = 0; //Y-Axis on Arcade
		int X1 = 0; //X-Axis on Arcade
		int deadZone = 10; //Deadzone Value Was 20
		int leftStickVertical = joystickGetAnalog(1, 3); //Joystick command for vertical movement
		int leftStickHorizontal = joystickGetAnalog(1, 4); //Joystick command for horizontal movement

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
		motorSet(mtrDriveRB, Y1 + X1);
		//Right Drive
		motorSet(mtrDriveLF, Y1 - X1);
		motorSet(mtrDriveLB, Y1 - X1);

		//*****************************
		//   Elevator and Cap Intake
		//*****************************

		//Variables
		int rightStickVertical = joystickGetAnalog(1, 2);

		//Elevator
		motorSet(mtrElevatorR, rightStickVertical);
		motorSet(mtrElevatorL, -rightStickVertical);

		//Cap Intake
		if (joystickGetDigital(1, 5, JOY_UP)){
			motorSet(mtrCapIntake, 90);
		}
		else if (joystickGetDigital(1, 5, JOY_DOWN)){
			motorSet(mtrCapIntake, -90);
		}
		else {
			motorSet(mtrCapIntake, 0);
		}

	}

	delay(20);

}
