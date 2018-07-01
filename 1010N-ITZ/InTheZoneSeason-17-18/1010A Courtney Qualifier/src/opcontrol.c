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

		if(Y1 > 90){Y1 = 90;}
		if(Y1 < -90){Y1 = -90;}
		if(X1 > 90){X1 = 90;}
		if(X1 < -90){X1 = -90;}

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

		bool mogoUp = joystickGetDigital(1,5,JOY_UP);
		bool mogoDown = joystickGetDigital(1,5,JOY_DOWN);
		bool mogoscore = joystickGetDigital(1,7, JOY_UP);
		int stop;
		//Mobile Goal In
		if (mogoUp == 1 && mogoDown == 0 && mogoscore == 0){
			moveMogo(-90);
			stop = 1;
		}
		//Mobile Goal Out
		else if (mogoUp == 0 && mogoDown == 1 && mogoscore == 0){
			moveMogo(90);
			stop = 0;
		}
		else if(mogoUp == 0 && mogoDown == 0 && mogoscore == 0 && stop==1){
			moveMogo(-25);
		}
		//Preset for scoring with cones (Out)
		else if(mogoUp == 0 && mogoDown == 0 && mogoscore == 1){
			//TaskHandle mogoScore = taskCreate(mogoScore, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
			stop=0;
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
		bool barStraight = joystickGetDigital(2, 8, JOY_UP);
		float barGain = 0.1;
		int barError;
		int barSpeed;
		int currentChain;

		//ChainBar Up to Preset
		if(barUp == 1 && barDown == 0 && barStraight == 0){
			//moveChainBar(-127);
			//TaskHandle matchchainup = taskCreate(matchbarup, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
			currentChain = 600;//was 360
		}

		//ChainBar Down to Preset
		else if(barUp == 0 && barDown == 1 && barStraight == 0){
			//moveChainBar(127);
			//TaskHandle matchbardown = taskCreate(matchbardown, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
			currentChain = 2500;
		}

		//ChainBAr PID for when static
		else if(barUp == 0 && barDown == 0 && barStraight == 0){
			barError = currentChain - analogRead(CHAINPOT);
			barSpeed = barError * barGain;
			moveChainBar(barSpeed);
		}

		else if(barUp == 0 && barDown == 0 && barStraight == 1){
			//TaskHandle matchbarstraight = taskCreate(matchbarstraight, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
			currentChain = 1250;
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
