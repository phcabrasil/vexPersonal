
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
			motorSet(bumperL, -20);
		}
		if (digitalRead(bumperRight)==LOW){
			motorSet(bumperR, -127);
		}
		else {
			motorSet(bumperR, 20);
		}
		delay(10);
	}
}
