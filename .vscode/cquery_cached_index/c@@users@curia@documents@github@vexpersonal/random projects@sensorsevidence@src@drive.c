#include "main.h"

void moveDrive(int left, int right){

    motorSet(frontLeft1,-left);
    motorSet(frontLeft2,left);
    motorSet(frontRight1,right);
    motorSet(frontRight2,right);
    motorSet(backLeft1,-left);
    motorSet(backLeft2,-left);
    motorSet(backRight1,right);
    motorSet(backRight2,right);

}
