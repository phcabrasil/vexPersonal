#include "main.h"

void moveDrive(int left, int right){

    motorSet(frontLeft,left);
    motorSet(frontRight,-right);
    motorSet(backLeft,left);
    motorSet(backRight,-right);

}
