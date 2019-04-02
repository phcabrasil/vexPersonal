#include "main.h"
#include "flywheel.h"
using namespace okapi;

void fwTask_fn(void*ignore)
{


  //Motors
  //Flywheel
  
  pros::Motor fwMtrB (8, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_DEGREES); //Port 10 Not Reversed //2
  pros::Motor fwMtrT (9, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_DEGREES); //Port 10 Not Reversed //2

  //Controller
  ControllerButton fwFullSpeed(ControllerDigital::X);
  ControllerButton fwHalfSpeed(ControllerDigital::A);
  ControllerButton fwNoSpeed(ControllerDigital::B);

  if(pros::competition::is_autonomous())
  {



  }

else{
  //Variables
  int i = 0;
  int speed;
  int cap;

    while(true)
    {

      for(speed = i; true; speed++)
      {
        if(fwFullSpeed.isPressed())
        {
          cap = 600;
        }
        else if(fwHalfSpeed.isPressed())
        {
          cap = 300;
        }
        else if(fwNoSpeed.isPressed())
        {
          cap = 0;
        }
        if(speed > cap){speed = cap;}

        fwMtrB.move_velocity(speed);
        fwMtrT.move_velocity(speed);

        pros::delay(20);

      } //END for loop

      pros::delay(5);

    } //END while(true)

  }

    pros::delay(5);

} //END fwTask_fn
