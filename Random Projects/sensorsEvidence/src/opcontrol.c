#include "main.h"
#include "autofunctions.h"
#include "lcdfunctions.h"
#include "drive.h"
#include "intake.h"
#include "arm.h"

void operatorControl() {
	while (1) {

		int Y1 = joystickGetAnalog(1, 3); //joystick command for vertical movement
		int X1 = joystickGetAnalog(1, 1); //joystick command for horizontal movement

		moveDrive(Y1 + X1, Y1 - X1);

		delay(20);
	}
}
