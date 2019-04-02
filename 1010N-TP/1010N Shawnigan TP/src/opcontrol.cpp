#include "main.h"
#include "drive.hpp"

using namespace okapi;

driveClass meme;

//Expo Code --USELESS--
int expDrive (int joyVal, float driveExp, int joyDead, int motorMin) {
    int joySign;
    int joyMax = 127 - joyDead;
    int joyLive = abs(joyVal) - joyDead;
    if (joyVal > 0) {joySign = 1;}
    else if (joyVal < 0) {joySign = -1;}
    else {joySign = 0;}
    int power = joySign * (motorMin + ((100 - motorMin) * pow(joyLive, driveExp) / pow(joyMax, driveExp)));
    return power;
} //END int expDrive

//Drive Expo Variables
const int cJoyDead = 8; // joystick range in which movement is considered accidental
const int cMotorMin = 15; // minimum drive motor power
const float cDriveExp = 1.5; // exponent for drive power calculations  (1 = linear, 2 = squared) //1.4

int fwVel = 600;

void opcontrol() {

	while (true) {



		//Expo Controller Inputs Drive
    int Y1 = expDrive(master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y), cDriveExp, cJoyDead, cMotorMin); //Expo Forward-Backwards
    int X1 = expDrive(master.get_analog(E_CONTROLLER_ANALOG_LEFT_X), cDriveExp, cJoyDead, cMotorMin); //Expo Right-Left
    int Z1 = expDrive(master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X), cDriveExp, cJoyDead, cMotorMin); //Expo Yaw

    //Drive Manual
    driveLF.move( Y1 + X1 + Z1 );
    driveLB.move( Y1 - X1 + Z1 );
    driveRF.move( Y1 - X1 - Z1 );
    driveRB.move( Y1 + X1 - Z1 );

    if (master.get_digital(E_CONTROLLER_DIGITAL_X)){
      fwVel = 600;
    }
    else if (master.get_digital(E_CONTROLLER_DIGITAL_A)){
      fwVel = 300;
    }
    else if (master.get_digital(E_CONTROLLER_DIGITAL_B)){
      fwVel = 0;
    }
    else { }

    fwMtrF.move_velocity(fwVel);
    //fwMtrB.move_velocity(fwVel);

    if (master.get_digital(E_CONTROLLER_DIGITAL_R1)){
      intakeMtr.move(127);
    }
    else if (master.get_digital(E_CONTROLLER_DIGITAL_R2)){
      intakeMtr.move(-127);
    }
    else {
      intakeMtr.move(0);
    }

    if (master.get_digital(E_CONTROLLER_DIGITAL_L1)){
      fwIntakeMtr.move(127);
    }
    else if (master.get_digital(E_CONTROLLER_DIGITAL_L2)){
      fwIntakeMtr.move(-127);
    }
    else {
      fwIntakeMtr.move(0);
    }

    if (master.get_digital(E_CONTROLLER_DIGITAL_DOWN)){
      //drive.turn(RIGHT, 960, 5000, 0.7, 0.8);
    }

		pros::delay(20);
	}
}
