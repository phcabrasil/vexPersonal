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

ChainBar Max Height is 530
ChainBar Min Height is 2540
ChainBar 90 Degrees is 1405

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void operatorControl() {

	//Reset and Calibrate Sensors
	autostack = 0;
	gyroReset(gyro);
	analogCalibrate(ARMPOT);
	analogCalibrate(CHAINPOT);
	analogCalibrate(MOGOPOT);
	int currentChain = 1250;
	int armTarget = 2600;
	int lock = 0;
	int lockCount = 0;

TaskHandle conePresetTask = taskCreate(conePreset, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
	while (1) {

		//LCD Task
		TaskHandle opcontrollcd_task = taskCreate(opcontrollcd, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);



		//***********************
		//       Drive
		//***********************


		int Y1 = 0; //Y-Axis on Arcade
		int X1 = 0; //X-Axis on Arcade
		int deadZone = 10; //Deadzone Value Was 20
		int leftStickVertical = joystickGetAnalog(1, 3); //Joystick command for vertical movement
		int leftStickHorizontal = joystickGetAnalog(1, 1); //Joystick command for horizontal movement

		if(joystickGetDigital(2,8,JOY_RIGHT)){
			lock = 1;
			lockCount += 1;
			//lock
		}
		if(lockCount > 1){
			lock = 0;
			lockCount = 0;
			//unlock
		}

		if(lock == 1 && leftStickVertical < 10 && leftStickHorizontal < 10 && leftStickVertical > -10 && leftStickHorizontal > -10){
			motorSet(DRIVE_LF, -15);
			motorSet(DRIVE_LB, 10);
			//right drive
			motorSet(DRIVE_RF, 15);
			motorSet(DRIVE_RB, 10);
	}

		else {
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

		if(Y1 > 90){Y1 = 90;}
		if(Y1 < -90){Y1 = -90;}
		if(X1 > 90){X1 = 90;}
		if(X1 < -90){X1 = -90;}

		//left drive
		motorSet(DRIVE_LF, Y1 + X1);
		motorSet(DRIVE_LB, Y1 + X1);
		//right drive
		motorSet(DRIVE_RF, - Y1 + X1);
		motorSet(DRIVE_RB, Y1 - X1);
	}

		//***********************
		//   Mobile Goal Lift
		//***********************
		bool mogoUp = joystickGetDigital(1,5,JOY_UP);
		bool mogoDown = joystickGetDigital(1,5,JOY_DOWN);
		bool mogoscore = joystickGetDigital(1, 7, JOY_UP);

		int stop;
		//Mobile goal intake in
		if(mogoUp ==1 && mogoDown == 0 && mogoscore == 0){
			moveMogo(-90);
			stop = 1;
		}
		//Mobile goal intake out
		else if(mogoUp == 0 && mogoDown == 1 && mogoscore == 0){
			moveMogo(90);
			stop = 0;
		}
		else if(mogoUp == 0 && mogoDown == 0 && mogoscore == 0 && stop == 1){
			moveMogo(-20);
		}
		//Preset for scoring with cones - also moves out
		else if(mogoUp == 0 && mogoDown == 0 && mogoscore == 1){
			stop = 0;
		}
		//Otherwise move mobile goal 0
		else{
			moveMogo(0);
		}



		if(autostack != 1){

		//***********************
		//        Arm
		//***********************

		//Arm Variables
		bool armStick = joystickGetAnalog(2,2);
		float armKp = 0.1;//0.2
		float armKd = 2; //2 Worked
		int armSpeed;
		int armError;
		int armErrorDiff;
		int armErrorLast;
		float armP;
		float armD;

		//Move Arm Up and Down
		if(armStick == 1){
			int armPowerOP = joystickGetAnalog(2,2);
			motorCap(armPowerOP, 90);
			moveArm(armPowerOP);
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
		//       Intake
		//***********************

		//Intake Variables
		int hold;

		//Claw Hold
		if (joystickGetDigital(2, 6, JOY_UP)){
			moveIntake(-90);
			hold = 1;
		}
		//Claw Let Go
		else if (joystickGetDigital(2, 6, JOY_DOWN)){
			moveIntake(90);
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
		bool barStraight = joystickGetDigital(2, 8, JOY_UP);
		float barGain = 0.1;//Was 0.1
		int barError;
		float p;
		barError =  currentChain - analogRead(CHAINPOT);

		p = barGain * barError;

		motorCap(p,90);
		moveChainBar(p);

		//ChainBar Up to Preset
		if(barUp == 1 && barDown == 0 && barStraight == 0){
			currentChain = 1250;
		}

		//ChainBar Down to Preset
		else if(barUp == 0 && barDown == 1 && barStraight == 0){
			currentChain = 3400;
		}


		else if(barUp == 0 && barDown == 0 && barStraight == 1){
			currentChain = 2300;
		}

		else{

		}

	}

	else {
		if(joystickGetDigital(2,7,JOY_DOWN)){
			taskDelete(conePresetTask);
			stopEverything();
			TaskHandle conePresetTask = taskCreate(conePreset, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
			}
	}

		delay(20);
	}
}
