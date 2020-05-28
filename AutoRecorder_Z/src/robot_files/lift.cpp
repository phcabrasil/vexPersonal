#include "main.h"
#include "robot_includes/robot_includes.hpp"

//==================================================
//              Initialize Class
//==================================================

Lift::Lift()
{
  ramp_PID.set_PID_vars(0.23, 0, 1.7, 0, 0);
  lift_PID.set_PID_vars(0.23, 0, 1.7, 0, 0);
  arm_mtr.tare_position(); //Reset Arm Position
  lift_state = INTAKING; //Set starting position at INTAKING
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
//                  Sensors
//==================================================

int Lift::getRampPos() {
  return angler_mtr.get_position();
}

void Lift::resetRampPos() {
  angler_mtr.tare_position();
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

  if(lift_state == INTAKING){
    if(master.get_digital(DIGITAL_L1)) ramp_state = SCORING;
    else if(master.get_digital(DIGITAL_DOWN)) ramp_state = RETURN;
    else if(master.get_digital(DIGITAL_L2)) ramp_state = RETURN;
  }

  // ==== Intake Control ==== //
  intake_state = MANUAL;

} //End void Lift::driveControl

//==================================================
//                Auto Function
//==================================================

void liftAuto_fn(void*parameter){

  bool memeDOWN = false;

  while(true) {

    // ==== LIFT CONTROL ==== //
    if(lift_state == INTAKING) {
      if(!liftLim.get_value()){
      arm_mtr = -127;
      memeDOWN = true;
    }
      else{
         arm_mtr = -5;
         memeDOWN = false;
         arm_mtr.tare_position();
      }
    }
    if(lift_state == LOW_TOWER) {
      ramp_state = LOCKED;
      arm_mtr.move_absolute(425, 75);
    }
    else if(lift_state == MID_TOWER) {
      ramp_state = LOCKED;
      arm_mtr.move_absolute(550, 75);
    }

    // ==== RAMP CONTROL ==== //
    if(ramp_state == LOCKED){
      angler_mtr.move_absolute(425, 100);
    }
    else if(memeDOWN){
      if(!rampLim.get_value()) lift.setRampVel(-50);
      else {
        lift.setRampVel(0);
        lift.resetRampPos();
        ramp_state = STOP;
      }
    }
    else if(ramp_state == SCORING){
      if(lift.getRampPos() > 375){
        lift.setRampVel(30);
        if(lift.getRampPos() > 675){
          lift.setRampVel(0);
        }
      }
      else lift.setRampVel(127);
    }
    else if(ramp_state == RETURN){
      if(!rampLim.get_value()) lift.setRampVel(-127);
      else {
        lift.setRampVel(0);
        lift.resetRampPos();
        ramp_state = STOP;
      }
    }
    else if(ramp_state == STOP){
      lift.setRampVel(0);
    }

    // ==== INTAKE CONTROL ==== //
    if(pros::competition::is_autonomous()){
      if(intake_state == INTAKE){
        lift.setIntakePower(127);
      }
      else if(intake_state == EXPEL){
        lift.setIntakePower(-127);
      }
      else if(intake_state == SLOW){
        lift.setIntakePower(-80);
      }
      else if(intake_state == STOP){
         lift.setIntakePower(0);
      }
    }

    else{
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
        lift.setIntakePower(0);
      }
    }

    pros::delay(10);
  } //End while(true)
} //End void LiftAuto_fn(void*parameter)
