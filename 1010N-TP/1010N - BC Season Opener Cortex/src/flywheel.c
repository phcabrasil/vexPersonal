#include "C:\Users\Curia\Documents\GitHub\2018-2019-1010N\1010N-TP\1010N - BC Season Opener\include\main.h"


int calculateSpeed(){ //Calculate Current Flywheel Speed

  //Variables
  int delta_ms;
	int delta_enc;
  int lastTics;
  int lastTime;
  int currTime = millis();
	int tics = encoderGet(encoderF);

  //Calculations
	delta_ms = currTime - lastTime;
	lastTime = currTime;
	delta_enc = (tics - lastTics);
	lastTics = tics;
	float newSpeed = (1000.0 / delta_ms) * delta_enc;
	fwSpeed = (fwSpeed * 0.6) + newSpeed * 0.4;
	return fwSpeed;

}


void moveFlywheel(int speed){

  motorSet(mtrFlywheelT, -speed);
  motorSet(mtrFlywheelB, -speed);

}

/*
void fwControl(){
	pidReset(_fly.flyPID);
	pidInit(_fly.flyPID, 0.6, 0.05, 0, 0, 999999);

	int integralLimit;
	if(_fly.flyPID.kI == 0){
		integralLimit = 0;
	} else{
		integralLimit = 13.0 / _fly.flyPID.kI;
	}

	float output = 0;
	float initTime = nPgmTime;
	while(true){
		fw_ButtonControl();
		//
		//we do not want to zero our error sum when we cross
		if(abs(_fly.flyPID.errorSum) > integralLimit){
			_fly.flyPID.errorSum = integralLimit * _fly.flyPID.errorSum/(abs(_fly.flyPID.errorSum));
		}

		_fly.currSpeed =  FwCalculateSpeed();
		float outVal = pidExecute(_fly.flyPID, _fly.setPoint - _fly.currSpeed);
		float dTime = nPgmTime - initTime;
		initTime = nPgmTime;



		playTone(_fly.currSpeed/2,2);

		output = _fly.pred + outVal;
		if(output < 0){
			output = 0;
		}
		if(output > 127){
			output = 127;
		}
		if((_fly.currSpeed <= 50 && _fly.setPoint == 0) && vexRT[Btn7L] == 1){
			output = -90;
			_updateFlyWheel(output);
			wait1Msec(4000);
			_updateFlyWheel(0);
			wait1Msec(10000);
		}
		_updateFlyWheel(output);
		delay(FW_LOOP_SPEED);
	}
}
TaskHandle fwControl_task;


void stopFwControl(){
	taskDelete(flw_tsk_FeedForwardCntrl);
}

void startFwControl(){
	taskHandle fwControl_task = taskCreate(flw_tsk_FeedForwardCntrl, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
}
*/

void moveIntake(int speed){

  motorSet(mtrBallIntake, speed);

}
