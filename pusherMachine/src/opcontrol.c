
#include "main.h"

void operatorControl() {
	while (1) {

		while(1==1){
			motorSet(pusher, 127);
			delay(300);
			motorSet(pusher, -127);
			delay(300);
			motorSet(pusher, 0);
			delay(60000);
		}

		delay(20);
	}
}
