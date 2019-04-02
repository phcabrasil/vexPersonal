#include "vision.hpp"
#include "main.h"

void RoboVision::stopSearch(){

}
void RoboVision::Align_to_Object(int sig, int obj_num, int TargetX, float KP, float KD, float KI){
    vSensor.clear_led();
    vSensor.set_zero_point(E_VISION_ZERO_CENTER);
    vision_object_s_t targetObject = (vSensor.get_object_count() > 0) ? vSensor.get_by_sig(obj_num, sig) : vSensor.get_by_sig(0, sig);
  /*  if(vSensor.get_object_count() > 0){targetObject = vSensor.get_by_sig(obj_num, sig);}
    else{targetObject = vSensor.get_by_sig(0, sig);}
    */
    int CurrentX = targetObject.x_middle_coord;
    int motorOutput;
    int outTime = millis();
    int err = 0;
    int derr = 0;
    int err_last = 0;
    int err_sum = 0;
    float p;
    float i;
    float d;
    while((outTime - millis() > 7500)){
      CurrentX = targetObject.x_middle_coord;
      err = TargetX - CurrentX;
      err_last = err;
      derr = (err - err_last);
      err_sum += err;
      motorOutput = ((KP*err)+(KD*derr)+(KI*err_sum));
      motorOutput = (motorOutput > 127 ? 127 : motorOutput < -127 ? -127 : motorOutput);

      BaseFL.move(-(motorOutput));
      BaseBL.move(-(motorOutput));
      BaseBR.move((motorOutput));
      BaseFR.move((motorOutput));
    }
}
