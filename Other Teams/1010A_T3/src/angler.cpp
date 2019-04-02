 #include "main.h"
 #include "angler.h"

 void ANGLE_Task_fn(void*parameter){
   int anglePos;
   float kp = 0.7;
   float kd = 1.5;
   int currentVal;
   int error;
   int error_last = 0;
   int error_diff;
   int power;
   while(true){
     if(partner.get_digital(E_CONTROLLER_DIGITAL_B)){
       if(LimitSwitch.get_value()==HIGH){
         angler.move(-95);

       }
       else if(LimitSwitch.get_value() == LOW){
         angler.move(0);
         angler.tare_position();
       }
     }
     else{
     anglePos = angler.get_position();
     error = angleTarget - anglePos;
     error_diff = error - error_last;
     error_last = error;
     power = (error*kp)+(error_diff*kd);
     if(power>127){power = 127;}
     if(power<-127){power = -127;}
     if(error<3){angler.move(0);}
     else{angler.move(power);};
   }
   delay(20);
   }
 }
