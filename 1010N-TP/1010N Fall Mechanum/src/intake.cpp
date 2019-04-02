#include "main.h"
#include "intake.h"
using namespace pros;

void intakeTask_fn(void*ignore)
{

/*

  //Sensors
  okapi::ADIButton highBall ('A');
  okapi::ADIButton lowBall ('B');

  //Motors
  Motor fwIntakeMtr (8, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES); //Port 10 Not Reversed //2

  //Controller
  okapi::ControllerButton fwIntake(okapi::ControllerDigital::L1);
  okapi::ControllerButton fwOutake(okapi::ControllerDigital::L2);
  okapi::ControllerButton fwCancel(okapi::ControllerDigital::Y);

  bool lowB = lowBall.isPressed();
  bool highB =  highBall.isPressed();
  bool cancel = fwCancel.isPressed();

  while(true){

    if(fwIntake.isPressed())
    {
        fwIntakeMtr.move(127);
    }
    else if(fwOutake.isPressed())
    {
      fwIntakeMtr.move(-127);
    }
    else
    {
      fwIntakeMtr.move(0);
    }

    pros::delay(10);

  }

  pros::delay(5);

*/

} //END fwIntake_fn
