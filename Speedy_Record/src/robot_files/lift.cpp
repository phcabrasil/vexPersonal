#include "main.h"
#include "robot_includes/robot_includes.hpp"

//==================================================
//              Initialize Class
//==================================================

Lift::Lift()
{
  slowTake = false;
  ramp_PID.set_PID_vars(0.23, 0, 1.7, 0, 0);
  lift_PID.set_PID_vars(0.23, 0, 1.7, 0, 0);
  arm_mtr.tare_position(); //Reset Arm Position
  lift_state = INTAKING; //Set starting position at INTAKING
  ramp_state = RETURN;
}

//==================================================
//             Set Power Functions
//==================================================

void Lift::setIntakePower(int power) {
  intake_mtr = power;
  intake_mtr_two = -power;
}

void Lift::setRampVel(int power) {
  angler_mtr.move_velocity(power);
}

void Lift::setLiftPower(int power) {
  arm_mtr = power;
}

//==================================================
//             Driver Control Function
//==================================================

void Lift::driveControl()
{
  // ==== Buttons ==== //
  if(master.get_digital(DIGITAL_UP)) lift_state = MID_TOWER;
  else if(master.get_digital(DIGITAL_RIGHT)) lift_state = LOW_TOWER;
  else if(master.get_digital(DIGITAL_DOWN)) lift_state = INTAKING;
  else if(master.get_digital(DIGITAL_X)) lift_state = BLOCKER_UP;


  if(master.get_digital(DIGITAL_L1)) ramp_state = SCORING;
  else if(master.get_digital(DIGITAL_L2)) ramp_state = RETURN;
  else ramp_state = STOP;


  if(master.get_digital(DIGITAL_R1)){
    lift.setIntakePower(127);
  }
  else if(master.get_digital(DIGITAL_R2)){
    lift.setIntakePower(-80);
  }
  else if(master.get_digital(DIGITAL_A)){
    lift.setIntakePower(-80);
  }
  else{
    if(lift.slowTake){
       if(arm_mtr.get_position() < 180) {
         lift.setIntakePower(-67);
       }
       else {
         lift.setIntakePower(0);
         lift.slowTake = false;
       }
    }
    else {
      lift.setIntakePower(0);
    }
  }



} //End void Lift::driveControl

//==================================================
//                Auto Function
//==================================================

void liftAuto_fn(void*parameter){

  while(true) {

    // ==== LIFT CONTROL ==== //
    if(lift_state == INTAKING) {
      lift.slowTake = false;
      if(liftLim.get_value() == 0){
        arm_mtr = -127;
      }
      else{
         arm_mtr = -25;
         arm_mtr.tare_position();
      }
    }
    else if(lift_state == BLOCKER_UP) {
      lift.slowTake = true;
      arm_mtr.move_absolute(350, 100);
    }
    else if(lift_state == LOW_TOWER) {
      lift.slowTake = false;
      arm_mtr.move_absolute(350, 100);
    }
    else if(lift_state == MID_TOWER) {
      lift.slowTake = false;
      arm_mtr.move_absolute(450, 100);
    }
    else if(lift_state == DEPLOY){
      lift.slowTake = false;
      arm_mtr.move_absolute(350, 100);
    }

    if(ramp_state == SCORING){
      if(angler_mtr.get_position() > 400){
        lift.setRampVel(20);
        if(angler_mtr.get_position() > 725){
          lift.setRampVel(0);
        }
      }
      else lift.setRampVel(127);
    }
    else if(ramp_state == RETURN){
      if(!rampLim.get_value()) lift.setRampVel(-127);
      else {
        lift.setRampVel(0);
        angler_mtr.tare_position();
      }
    }
    else lift.setRampVel(0);


    pros::delay(10);
  } //End while(true)
} //End void LiftAuto_fn(void*parameter)
