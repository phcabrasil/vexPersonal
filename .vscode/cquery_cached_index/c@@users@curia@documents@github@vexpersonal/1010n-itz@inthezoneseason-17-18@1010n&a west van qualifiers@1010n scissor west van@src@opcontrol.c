#include "main.h"
#include "autofunctions.h"
#include "lcdfunctions.h"
#include "drive.h"
#include "intake.h"
#include "fourbar.h"
#include "mogo.h"
#include "arm.h"

void operatorControl() {

	encoderReset(encoderA);
	gyroReset(gyro);
	analogCalibrate(1);

	while (1) {

		TaskHandle opcontrollcd_task = taskCreate(opcontrollcd, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);

		//***********************
		//       Drive
		//***********************

		int Y1 = 0; //Y-Axis on Arcade
		int X1 = 0; //X-Axis on Arcade
		int deadZone = 20; //Deadzone Value

		int leftStickVertical = joystickGetAnalog(1, 3); //Joystick command for vertical movement
		int leftStickHorizontal = joystickGetAnalog(1, 1); //Joystick command for horizontal movement

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

		//Left Drive
		motorSet(DRIVE_LF, Y1 + X1);//Left Front
		motorSet(DRIVE_LB, Y1 + X1);//Left Back

		//Right Drive
		motorSet(DRIVE_RF, -Y1 + X1);//Right Front
		motorSet(DRIVE_RB, -Y1 + X1);//Right Back

		//***********************
		//        Arm
		//***********************
		moveArm(-joystickGetAnalog(2,2));


		//***********************
		//   Mobile Goal Lift
		//***********************

		if (joystickGetDigital(1, 5, JOY_UP)){
			moveMogo(127);
		}
		else if (joystickGetDigital(1, 5, JOY_DOWN)){
			moveMogo(-127);
		}
		else {
			moveMogo(0);
		}

		//***********************
		//       Intake
		//***********************

		if (joystickGetDigital(2, 6, JOY_UP)){
			moveIntake(127);
		}
		else if (joystickGetDigital(2, 6, JOY_DOWN)){
			moveIntake(-127);
		}
		else {
			moveIntake(-30);
			//moveIntake(0);
		}

		//***********************
		//     Four BAR
		//***********************

		if (joystickGetDigital(2, 5, JOY_DOWN)){
			moveFourBar(-127);
		}
		else if (joystickGetDigital(2, 5, JOY_UP)) {
			moveFourBar(127);
		}
		else if (joystickGetDigital(2,7,JOY_LEFT)){
			float bar_gain = 0.2;
			int bar_error = 1250 - analogRead(1);
			int bar_speed = bar_error * bar_gain;
			motorCap(bar_speed, 5);
			moveFourBar(bar_speed);
			}
		else{
			moveFourBar(0);
		}

		delay(20);
	}
}
