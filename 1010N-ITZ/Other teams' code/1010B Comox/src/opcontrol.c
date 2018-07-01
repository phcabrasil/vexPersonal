#include "main.h"
#include "autofunctions.h"
#include "lcdfunctions.h"
#include "drive.h"
#include "intake.h"
#include "chainbar.h"
#include "mogo.h"
#include "arm.h"

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
		motorSet(DRIVE_LB, - Y1 - X1);//Left Back

		//Right Drive
		motorSet(DRIVE_RF, -Y1 + X1);//Right Front
		motorSet(DRIVE_RB, -Y1 + X1);//Right Back

		//***********************
		//        Arm
		//***********************

		//Arm Variables
		bool armStick = joystickGetAnalog(2,2);
		float armKp = 0.1;//0.2
		float armKd = 2; //2 Worked
		int armTarget;
		int armSpeed;
		int armError;
		int armErrorDiff;
		int armErrorLast;
		float armP;
		float armD;

		//Move Arm Up and Down
		if(joystickGetAnalog(2,2)){
			moveArm(joystickGetAnalog(2,2));
			armTarget = analogRead(ARMPOT);
		}
		//Arm PID for when static
		/*else if(armStick == 0){
			armError = armTarget - analogRead(ARMPOT);
			armP = armError * armKp;
			armErrorDiff = armError - armErrorLast;
			armErrorLast = armError;
			armD = armKd * armErrorDiff;
			armSpeed = armP + armD;
			moveArm(armSpeed);
		}*/
		else{
			moveArm(0);
		}

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
		//Preset for scoring with cones (Out)
		else if(joystickGetDigital(1, 7, JOY_UP)){
			while(analogRead(MOGOPOT) < 1000){
				moveMogo(100);
			}
		}
		else {
			moveMogo(0);
		}

		//***********************
		//       Intake
		//***********************

		//Intake Variables
		int hold;

		//Claw Hold
		if (joystickGetDigital(2, 6, JOY_UP)){
			moveIntake(-127);
			hold = 1;
		}
		//Claw Let Go
		else if (joystickGetDigital(2, 6, JOY_DOWN)){
			moveIntake(127);
			hold = 0;
		}
		//Claw Hold On
		else if (hold == 1)
		{
			moveIntake(-45);
		}
		else {
			moveIntake(0);

		}

		//***********************
		//     Chain Bar
		//***********************

		//ChainBar Variables
		bool barUp = joystickGetDigital(2,5,JOY_UP);
		bool barDown = joystickGetDigital(2,5,JOY_DOWN);
		float barGain = 0.2;
		int barError;
		int barSpeed;
		int currentChain;
		int timeout_bar = 2000;

		//ChainBar Up to Preset
		if(barUp == 1 && barDown == 0){
			moveChainBar(127);
		}

		//ChainBar Down to Preset
		else if(barUp == 0 && barDown == 1){
			moveChainBar(-127);
		}


		/*if(joystickGetAnalog(2, 3)){
			moveChainBar(-joystickGetAnalog(2,3));
			currentChain = analogRead(CHAINPOT);
		}*/

		else{
			moveChainBar(0);
		}



		if(joystickGetDigital(2,7,JOY_UP)){
			conePreset();
		}

		delay(20);
	}
}
