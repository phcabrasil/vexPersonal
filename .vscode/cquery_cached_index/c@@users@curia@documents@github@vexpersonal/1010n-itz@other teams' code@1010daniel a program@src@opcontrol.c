

#include "main.h"

void operatorControl() {
	while (1) {

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
		motorSet(DRIVE_LF, -Y1 + X1);//Left Front
		motorSet(DRIVE_LB, -Y1 + X1);//Left Back

		//Right Drive
		motorSet(DRIVE_RF, Y1 + X1);//Right Front
		motorSet(DRIVE_RB, Y1 + X1);//Right Back

		//***********************
		//        MOGO
		//***********************

		if (joystickGetDigital(1, 6, JOY_UP)){
			motorSet(MOGO,-127);
			motorSet(MOGO_A,127);
		}
		else if (joystickGetDigital(1, 6, JOY_DOWN)){
			motorSet(MOGO,127);
			motorSet(MOGO_A,-127);

		}
		else{
			motorSet(MOGO,0);
			motorSet(MOGO_A,0);
		}



		delay(20);
	}
}
