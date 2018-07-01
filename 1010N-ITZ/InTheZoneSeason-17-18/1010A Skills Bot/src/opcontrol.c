#include "main.h"
#include "autofunctions.h"
#include "lcdfunctions.h"
#include "drive.h"
#include "intake.h"
#include "mogo.h"

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Arm MAX Height is 1700
Arm MIN Height is 200
Arm IDEAL Height is 300 to 400
Arm Difference in cones is 200(150) per cone

ChainBar Max Height is 50
ChainBar Min Height is 3000
ChainBar 90 Degrees is 725

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


void operatorControl() {

	//Reset and Calibrate Sensors
	gyroReset(gyro);
	analogCalibrate(ARMPOT);
	analogCalibrate(CHAINPOT);
	analogCalibrate(MOGOPOT);

	while (1) {

		//LCD Task
		TaskHandle opcontrollcd_task = taskCreate(opcontrollcd, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);

		//***********************
		//       Drive
		//***********************

		int Y1 = 0; //Y-Axis on Arcade
		int X1 = 0; //X-Axis on Arcade
		int deadZone = 10; //Deadzone Value // Was 20

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
		motorSet(DRIVE_LB,  -Y1 + X1);//Left Back

		//Right Drive
		motorSet(DRIVE_RF, -Y1 + X1);//Right Front
		motorSet(DRIVE_RB, Y1 + X1);//Right Back

		//Middler Drive
		motorSet(DRIVE_RM, -Y1 + X1);//Left Front
		motorSet(DRIVE_LM,  Y1 + X1);//Left Back

		//***********************
		//   Mobile Goal Lift
		//***********************

		//Mobile Goal In
		if (joystickGetDigital(1, 5, JOY_UP)){
			moveMogo(-127);
		}
		//Mobile Goal Out
		else if (joystickGetDigital(1, 5, JOY_DOWN)){
			moveMogo(127);
		}
		else {
			moveMogo(0);
		}

		if (joystickGetDigital(1, 6, JOY_UP)){
			openLock();
		}
		//Mobile Goal Out
		else if (joystickGetDigital(1, 6, JOY_DOWN)){
			lock();
		}
		else {
		}

	}
}
