#include "C:\Users\Curia\Documents\GitHub\2018-2019-1010N\1010N-TP\1010N - BC Season Opener\include\main.h"
#include "C:\Users\Curia\Documents\GitHub\2018-2019-1010N\1010N-TP\1010N - BC Season Opener\include\autofunctions.h"
#include "C:\Users\Curia\Documents\GitHub\2018-2019-1010N\1010N-TP\1010N - BC Season Opener\include\lcdfunctions.h"
#include "C:\Users\Curia\Documents\GitHub\2018-2019-1010N\1010N-TP\1010N - BC Season Opener\include\drive.h"
#include "C:\Users\Curia\Documents\GitHub\2018-2019-1010N\1010N-TP\1010N - BC Season Opener\include\flywheel.h"
#include "C:\Users\Curia\Documents\GitHub\2018-2019-1010N\1010N-TP\1010N - BC Season Opener\include\lift.h"

int flywheelRamp = 0;
int targetflywheelRamp = -90;
int rest = 0;
int currentPos = 10;
int speedf;

void operatorControl() {
	while (1) {

		TaskHandle opcontrollcd_task = taskCreate(opcontrollcd, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);

		//********************************
		//   Flywheel and Ball Intake
		//********************************

		if (joystickGetDigital(1,8,JOY_UP)) {
			rest = 0;
		}
		if (joystickGetDigital(1,8,JOY_DOWN)) {
			rest = 1;
		}
		if (joystickGetDigital(1,8,JOY_RIGHT)) {
			rest = 2;
		}

		if (rest == 1) {
			for(int motorValue = 0 ; motorValue <= 40; motorValue +=5){
 			moveFlywheel(motorValue);
 			delay(30);
			}
			for(int motorValue = 0 ; motorValue >= 40; motorValue -=5){
 			moveFlywheel(motorValue);
 			delay(30);
			}
			moveFlywheel(40);
		}
		else if (rest == 2) {
			for(int motorValue = 0 ; motorValue >= 0; motorValue -=5){
 			moveFlywheel(motorValue);
 			delay(30);
		  }
			moveFlywheel(0);
		}
		else {
			for(int motorValue = 0 ; motorValue <= 90; motorValue +=5){
 			moveFlywheel(motorValue);
 			delay(30);
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

		/*//Cap Intake Variables
		float intakeGain = 0.2;//Was 0.1
		int intakeError;
		float p;
		intakeError =  currentPos - analogRead(CAPPOT);

		p = intakeGain * intakeError;

		motorCap(p,90);
		motorSet(mtrCapIntake, p);

		//Cap Up
		if(joystickGetDigital(2,5,JOY_UP) == 1 && joystickGetDigital(2,5,JOY_DOWN) == 0 && joystickGetDigital(2, 8, JOY_UP) == 0){
			currentPos += 1;
		}

		//Cap Down
		else if(joystickGetDigital(2,5,JOY_UP) == 0 && joystickGetDigital(2,5,JOY_DOWN) == 1 && joystickGetDigital(2, 8, JOY_UP) == 0){
			currentPos -= 1;
		}

		//Cap Back
		else if(joystickGetDigital(2,5,JOY_UP) == 0 && joystickGetDigital(2,5,JOY_DOWN) == 0 && joystickGetDigital(2, 8, JOY_UP) == 1){
			currentPos = 2400;
		}

		else if(joystickGetDigital(2,5,JOY_UP) == 0 && joystickGetDigital(2,5,JOY_DOWN) == 0 && joystickGetDigital(2, 8, JOY_DOWN) == 1){
			currentPos = 10;
		}

		else{

		}
		*/

	}

	delay(20);

}
