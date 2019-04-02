#include "main.h"

//Angler Variables
int angle = 2;
//Angler P
float kp = 1.2;
int error;
int output;

 //Expo Code
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
 const int cJoyDead = 8; //Joystick range in which movement is considered accidental
 const int cMotorMin = 15; //Minimum drive motor power
 const float cDriveExp = 1.5; //Exponent for drive power calculations  (1 = linear, 2 = squared) //1.4

 void opcontrol() {

 	while (true) {

 		//Expo Controller Inputs Drive
     int Y1 = expDrive(master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y), cDriveExp, cJoyDead, cMotorMin); //Expo Forward-Backwards
     int Z1 = expDrive(master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X), cDriveExp, cJoyDead, cMotorMin); //Expo Yaw

     //Drive Arcade
     driveLF.move( Y1 + Z1 );
     driveLB.move( Y1 + Z1 );
     driveRF.move( Y1 - Z1 );
     driveRB.move( Y1 - Z1 );

		 //Roller Control
     if (master.get_digital(E_CONTROLLER_DIGITAL_R1)){
       roller.move(127);
     }
     else if (master.get_digital(E_CONTROLLER_DIGITAL_R2)){
       roller.move(-127);
     }
     else {
       roller.move(0);
     }

		 //Puncher Control
     if (master.get_digital(E_CONTROLLER_DIGITAL_L1)){
       puncherL.move(127);
			 puncherR.move(127);
     }
     else {
       puncherL.move(0);
			 puncherR.move(0);
     }

		 if (master.get_digital(E_CONTROLLER_DIGITAL_L2)){


   angler.move_absolute(25, 50);
       }

       else if (master.get_digital(E_CONTROLLER_DIGITAL_LEFT)){

  		    angler.move_absolute(90, 50);
		 }


 		pros::delay(20);
 	}
 }
