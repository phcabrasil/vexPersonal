#include "main.h"
#include "robot_includes/robot_includes.hpp"

//==================================================
//              Initialize Class
//==================================================

Chassis::Chassis()
{
	driveWidth = 11.25; //Drive Width in Inches multiplied by covertion ratio to encoder units (360 degrees dvided by wheel circumference)
  idle_PID.target = 0; //Target for Stationary Wheel in Pivot
}

//==================================================
//         		    Expo Function
//==================================================

const int cJoyDead = 8; // Joystick range in which movement is considered accidental
const int cMotorMin = 13; // Minimum drive motor power
const float cDriveExp = 1.4; // Exponent for drive power calculations (1 = linear, 2 = squared)

int expDrive (int joyVal, float driveExp, int joyDead, int motorMin) {
    int joySign;
    int joyMax = 127 - joyDead;
    int joyLive = abs(joyVal) - joyDead;
    if (joyVal > 0) {joySign = 1;}
    else if (joyVal < 0) {joySign = -1;}
    else {joySign = 0;}
    int power = joySign * (motorMin + ((127 - motorMin) * pow(joyLive, driveExp) / pow(joyMax, driveExp)));
    return power;
} //END int expDrive

//==================================================
//             Set Power Functions
//==================================================

void Chassis::setLeft(int power) {
  left_front_mtr = -power;
  left_back_mtr = -power;
}

void Chassis::setRight(int power) {
  right_front_mtr = power;
  right_back_mtr = power;
}

void Chassis::stop(bool sensors){
	setLeft(0);
	setRight(0);
	if (sensors == true){
		resetChassisSensors(true);
	}
}

//==================================================
//        			     Sensors
//==================================================

int Chassis::leftPosition() {
 return left_front_mtr.get_position();
}

int Chassis::rightPosition() {
 return right_front_mtr.get_position();
}

int Chassis::gyroValue() {
	return gyro.get_value();
}

void Chassis::resetChassisSensors(bool reset_gyro) {
  left_front_mtr.tare_position();
  left_back_mtr.tare_position();
  right_front_mtr.tare_position();
  right_back_mtr.tare_position();
  if (reset_gyro == true) {
    gyro.reset();
  }
}

//==================================================
//             Driver Control Function
//==================================================

void Chassis::driveControl()
{
  arcadeY = expDrive(master.get_analog(ANALOG_LEFT_Y), cDriveExp, cJoyDead, cMotorMin);
  arcadeX = expDrive(master.get_analog(ANALOG_RIGHT_X), cDriveExp, cJoyDead, cMotorMin);
  left = arcadeY + arcadeX;
  right = arcadeY - arcadeX;
  resetChassisSensors(false);
	setLeft(left);
	setRight(right);
}

//==================================================
//                Auto Functions
//==================================================

// ==== Drive Function ==== //
void Chassis::autoDrive(int direction, int target, int timeout)
{
	drive_PID.set_PID_vars(0.29, 0, 1.1, 0, 0);
	resetChassisSensors(true);
	drive_PID.target = target;
	startTimer(AUTO_DRIVE_TIMEOUT);
	while(getTime(AUTO_DRIVE_TIMEOUT) < timeout)
	{
		drive_PID.current = chassis.leftPosition();
		right = drive_PID.output(127);
		left = drive_PID.output(127);
		setRight(right);
		setLeft(left);
	} //End while(getTime(AUTO_DRIVE_TIMEOUT) < timeout)
	stop(true);
} //End autoDrive(int, int, int)


// ==== Turn Function ==== //
void Chassis::autoTurn(int direction, int target, int timeout)
{
	turn_PID.set_PID_vars(0.23, 0, 1.7, 0, 0);
	resetChassisSensors(true);
	turn_PID.target = target;
	startTimer(AUTO_DRIVE_TIMEOUT);
	while(getTime(AUTO_DRIVE_TIMEOUT) < timeout)
	{
		turn_PID.current = chassis.gyroValue();
		right = turn_PID.output(127);
		left = turn_PID.output(127);
		setRight(right);
		setLeft(-left);
	} //End while(getTime(AUTO_DRIVE_TIMEOUT) < timeout)
	stop(true);
} //End Chassis::autoTurn(int, int, int)

// ==== Pivot Function ==== //
void Chassis::autoPivot(int pivot_side, int direction, int target, int timeout)
{
	pivot_PID.set_PID_vars(0.23, 0, 1.45, 0, 0);
	resetChassisSensors(true);
	pivot_PID.target = target;
	startTimer(AUTO_DRIVE_TIMEOUT);
	while(getTime(AUTO_DRIVE_TIMEOUT) < timeout)
	{
		switch(pivot_side)
		{
			case RIGHT:
			pivot_PID.current = gyroValue();
			idle_PID.current = rightPosition();
			setLeft(pivot_PID.output(127));
			right_front_mtr = idle_PID.output(127);
			break;
			case LEFT:
			pivot_PID.current = gyroValue();
			idle_PID.current = leftPosition();
			setRight(-pivot_PID.output(127));
			left_front_mtr = idle_PID.output(127);
			break;
		}
	} //End while(getTime(AUTO_DRIVE_TIMEOUT) < timeout)
	stop(true);
} //End Chassis::autoPivot(int, int, int, int)

/*
void Chassis::autoTurn(int direction, int target, int timeout)
{
	drive_priority = TURNING;
	turn_PID.set_PID_vars(2.5, 0, 0, 0, 0);
	resetChassisSensors(true);
	turn_PID.target = driveWidth * PI * (target / 12.56);
	startTimer(AUTO_DRIVE_TIMEOUT);
	while(getTime(AUTO_DRIVE_TIMEOUT) < timeout)
	{
		turn_PID.current = leftPosition();
		right = turn_PID.output(127);
		left = turn_PID.output(127);
		setRight(-right);
		setLeft(left);
	} //End while(getTime(AUTO_DRIVE_TIMEOUT) < timeout)
	stop(true);
} //End Chassis::autoTurn(int, int, int)
*/

// ==== Curve/Arc Function ==== //
/*
void Chassis::autoCurve(int direction, int angle, int circleRadius, int timeout)
{
	drive_priority = CURVE;

	float innerArc = (abs(angle) * (PI/180)) * (circleRadius*(360/12.56));
	float outerArc = (abs(angle) * (PI/180)) * ((circleRadius*(360/12.56)) + (driveWidth*(360/12.56)));
	int desiredAngle = (angle * 10);
	float targetRatio = innerArc / outerArc;

	bool rightSide = (angle > 0) ? true : false;

	float turnKP = 0.006;
	int turnError;
	float turnPower;

	float ratioKP = 2.0;
 	float currentRatio;
 	float ratioError;
 	float ratioPower;

 	int outerEnc;
 	int innerEnc;

	outerCurve_PID.set_PID_vars(0.29, 0, 1.1, 0, 0);
	innerCurve_PID.set_PID_vars(0.29, 0, 1.1, 0, 0);

	outerCurve_PID.target = outerArc;
	innerCurve_PID.target = innerArc;

	resetChassisSensors(true);

	startTimer(AUTO_DRIVE_TIMEOUT);

 	while(getTime(AUTO_DRIVE_TIMEOUT) < timeout)
	{

	 	innerEnc = rightSide ? rightPosition() : leftPosition(); //In Brackets
	 	outerEnc = rightSide ? leftPosition() : rightPosition();

	 	if (outerEnc != 0) currentRatio = innerEnc / outerEnc;
		else currentRatio = 0;

	 	ratioError = targetRatio - currentRatio;
	 	ratioPower = ratioError * ratioKP;

		turnError = (angle * 10) - gyroValue();
		turnPower = turnError * turnKP;

		outerCurve_PID.current = outerEnc;
		innerCurve_PID.current = innerEnc;

		left = rightSide ? outerCurve_PID.output(127) - ratioPower : innerCurve_PID.output(127) + ratioPower;
		right = rightSide ? innerCurve_PID.output(127) + ratioPower : outerCurve_PID.output(127) - ratioPower;

		setRight(-right);
		setLeft(left);
	} //End while(getTime(AUTO_DRIVE_TIMEOUT) < timeout)
	stop(true);
} //End Chassis::autoCurve(int, int, int, int)
*/

//==================================================
//          	  Drive Task for Auto
//==================================================

/*
void driveAuto_fn(void*parameter)
{
	//Set PID Variables
	drive_PID.set_PID_vars(0.5, 0, 0, 0, 0);
	turn_PID.set_PID_vars(0, 0, 0, 0, 0);
	drive_PID.current = 0;
	drive_PID.target = 0;
	turn_PID.current = 0;
	turn_PID.target = 0;

	drive_priority = COMPLETE;

	int right_output;
	int left_output;

	chassis.resetChassisSensors(true);

	while(true){
		switch(auto_state)
		{
			case INCOMPLETE:
				//Set PID Target
				drive_PID.target = drive_target;
				turn_PID.target = turn_target;
				//Start Timer for timeout
				startTimer(AUTO_DRIVE_TIMEOUT);
				switch(drive_priority)
				{
					case TURNING:
						turn_PID.current = chassis.gyroValue();

				    right_output = turn_PID.output(127);
				    left_output = turn_PID.output(127);

				    chassis.setRight(-right_output);
				    chassis.setLeft(left_output);

				    if (abs(turn_PID.data[ERROR]) < 3 || getTime(AUTO_DRIVE_TIMEOUT) > 3000)
						{
							drive_target = 0;
							turn_target = 0;
							chassis.setRight(0);
							chassis.setLeft(0);
				      auto_state = COMPLETE;
				    }
					break;
					case DRIVING:
						drive_PID.current = chassis.leftPosition();

				    right_output = drive_PID.output(127);
				    left_output = drive_PID.output(127);

				    chassis.setRight(right_output);
				    chassis.setLeft(left_output);

				    if (abs(drive_PID.data[ERROR]) < 3 || getTime(AUTO_DRIVE_TIMEOUT) > 3000)
						{
							drive_target = 0;
							turn_target = 0;
							chassis.setRight(0);
							chassis.setLeft(0);
				      auto_state = COMPLETE;
				    }
					break;
				} // end switch(drive_priority)
			break;

			case COMPLETE:
				chassis.resetChassisSensors(true);
				drive_priority = IDLE;
				chassis.setRight(0);
				chassis.setLeft(0);
				if(drive_target =! 0 || turn_target == 0)
				{
					drive_priority = DRIVING;
					auto_state = INCOMPLETE;
				}
				else if(turn_target =! 0 || drive_target == 0)
				{
					drive_priority = TURNING;
					auto_state = INCOMPLETE;
				}
				else
				{
					drive_target = 0;
					turn_target = 0;
				}
			break;
		} // end switch(auto_state)
	} // end while(true)
} // end void Chassis::autoChassisPID
*/
