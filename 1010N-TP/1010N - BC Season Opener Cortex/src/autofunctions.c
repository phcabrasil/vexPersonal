#include "C:\Users\Curia\Documents\GitHub\2018-2019-1010N\1010N-TP\1010N - BC Season Opener\include\main.h"
#include "C:\Users\Curia\Documents\GitHub\2018-2019-1010N\1010N-TP\1010N - BC Season Opener\include\drive.h"
#include "C:\Users\Curia\Documents\GitHub\2018-2019-1010N\1010N-TP\1010N - BC Season Opener\include\flywheel.h"
#include "C:\Users\Curia\Documents\GitHub\2018-2019-1010N\1010N-TP\1010N - BC Season Opener\include\lift.h"

#define UP 1
#define DOWN -1
#define FORWARD 1
#define BACK -1
#define RIGHT 1
#define LEFT -1

//********************************
//       Motor Speed Cap
//********************************

void motorCap(int what, int speed){
  if(what > speed){
    what = speed;//Caps Max Given Motor Speed
  }
  else if(what < -speed){
    what = -speed;//Caps Min Given Motor Speed
  }
}
