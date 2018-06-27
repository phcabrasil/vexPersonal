
#include "main.h"
#include "drive.h"

void operatorControl() {
	while (1) {

		int Y1 = joystickGetAnalog(1, 3); //joystick command for vertical movement
		int Z1 = joystickGetAnalog(1, 4); //joystick command for vertical movement
		int X1 = joystickGetAnalog(1, 1); //joystick command for horizontal movement

		motorSet(frontLeft,Y1 + X1 + Z1);
    motorSet(frontRight,-(Y1 - X1) + Z1);
    motorSet(backLeft,Y1 + X1 - Z1);
    motorSet(backRight,-(Y1 - X1) - Z1);

		delay(20);
	}
}
