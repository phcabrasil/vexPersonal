#include "main.h"

void moveMogo(int speed){

  motorSet(MOGO_R, speed);
  motorSet(MOGO_L, -speed);

}
