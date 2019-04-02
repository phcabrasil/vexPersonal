#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_
#include "main.h"
class RoboVision {

public:
void stopSearch();
void Align_to_Object(int sig /*object signature*/, int obj_num /*object to go to if there are multiple*/, int TargetX, float KP, float KD, float KI);
void Go_to_Object(int sig /*object signature*/, int obj_num /*object to go to if there are multiple*/, int TargetY, float KP, float KD);
};
#endif
