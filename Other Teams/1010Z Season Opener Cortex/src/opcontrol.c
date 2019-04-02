
#include "main.h"

void operatorControl() {
	while (1) {

		int Y1 = joystickGetAnalog(1, 3);
		int X1 = joystickGetAnalog(1, 1);

		if(Y1 > 90){Y1 = 90;}
		if(Y1 < -90){Y1 = -90;}
		if(X1 > 90){X1 = 90;}
		if(X1 < -90){X1 = -90;}

		//left drive
		motorSet(driveLF, -Y1 - X1);
		motorSet(driveLFP, Y1 + X1);
		motorSet(driveLB, Y1 + X1);
		//right drive
		motorSet(driveRF, -Y1 + X1);
		motorSet(driveRFP, Y1 - X1);
		motorSet(driveRB, Y1 - X1);

		if (joystickGetDigital(1, 6, JOY_UP)){
			motorSet(intake, 127);
		}
		else if (joystickGetDigital(1, 6, JOY_DOWN)){
			motorSet(intake, -127);
		}
		else {
			motorSet(intake, 0);
		}

		if (joystickGetDigital(1, 5, JOY_UP)){
			motorSet(shooterR, 127);
			motorSet(shooterL, -127);
		}
		else if (joystickGetDigital(1, 5, JOY_DOWN)){
			motorSet(shooterR, -127);
			motorSet(shooterL, 127);
		}
		else {
			motorSet(shooterR, 0);
			motorSet(shooterL, 0);
		}

		if (joystickGetDigital(1, 8, JOY_UP)){
			motorSet(descore, 127);
		}
		else if (joystickGetDigital(1, 8, JOY_DOWN)){
			motorSet(descore, -127);
		}
		else {
			motorSet(descore, 0);
		}

		delay(20);
	}
}
