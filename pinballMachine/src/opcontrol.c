
#include "main.h"

void operatorControl() {
	while (1) {
		if (digitalRead(puncherButton)==LOW){
			motorSet(puncher, 127);
			delay(1000);
			motorSet(puncher, 0);
		}
		if (digitalRead(bumperLeft)==LOW){
			motorSet(bumperL, 127);
		}
		else {
			motorSet(bumperL, -127);
			delay(1000);
			motorSet(bumperL, -10);
		}
		if (digitalRead(bumperRight)==LOW){
			motorSet(bumperR, 127);
		}
		else {
			motorSet(bumperR, -127);
			delay(1000);
			motorSet(bumperR, -10);
		}
		delay(20);
	}
}
