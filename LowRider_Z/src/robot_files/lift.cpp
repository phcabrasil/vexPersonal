#include "main.h"
#include "robot_includes/robot_includes.hpp"

//==================================================
//              Initialize Class
//==================================================

Lift::Lift()
{
  arm_mtr.tare_position(); //Reset Arm Position
  lift_state = INTAKING; //Set starting position at INTAKING
}

//==================================================
//             Set Power Functions
//==================================================

void Lift::setIntakePower(int power) {
  intake_mtr = -power;
  intake_mtr_two = power;
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
  if(master.get_digital(DIGITAL_UP)) lift_state = HIGH_TOWER;
  else if(master.get_digital(DIGITAL_Y)) lift_state = DEPLOY;
  else if(master.get_digital(DIGITAL_RIGHT)) lift_state = MID_TOWER;
  else if(master.get_digital(DIGITAL_DOWN)) lift_state = LOW_TOWER;
  else if(master.get_digital(DIGITAL_LEFT)) lift_state = INTAKING;
  else if(master.get_digital(DIGITAL_L1)) ramp_state = FREE;
  else if(master.get_digital(DIGITAL_L2)) ramp_state = FREE;
  else if(partner.get_analog(ANALOG_LEFT_X) != 0) ramp_state = MANUAL;
  else if(partner.get_analog(ANALOG_RIGHT_Y) != 0) lift_state = MANUAL;

  // ==== Intake Control ==== //
  if(master.get_digital(DIGITAL_R1) || partner.get_digital(DIGITAL_R1)) Lift::setIntakePower(127);
  else if(master.get_digital(DIGITAL_R2) || partner.get_digital(DIGITAL_L1)) Lift::setIntakePower(-127);
  else if(master.get_digital(DIGITAL_A) || partner.get_digital(DIGITAL_A)) Lift::setIntakePower(-50);
  else Lift::setIntakePower(0);

  pros::lcd::print(0, "%d", anglerPot.get_value());
} //End void Lift::driveControl

//==================================================
//                Auto Function
//==================================================

void liftAuto_fn(void*parameter){

  float kp = 0.27;
  int error;
  int target = 1350;

  while(true){
    // ==== LIFT CONTROL ==== //
    if(lift_state == INTAKING) {
      ramp_state = FREE;
      if(liftLim.get_value() == 1) {
        ramp_state = FREE;
        lift.setLiftPower(-10);
        arm_mtr.tare_position();
      }
      else lift.setLiftPower(-127);
    }
    else if(lift_state == LOW_TOWER) {
      ramp_state = LOCKED;
      arm_mtr.move_absolute(270, 80);
    }
    else if(lift_state == MID_TOWER) {
      ramp_state = LOCKED;
      arm_mtr.move_absolute(360, 80);
    }
    else if(lift_state == HIGH_TOWER) {
      ramp_state = LOCKED;
      arm_mtr.move_absolute(500, 80);
    }
    else if(lift_state == MANUAL){
      arm_mtr.move(partner.get_analog(ANALOG_RIGHT_Y));
    }
    else if(lift_state == DEPLOY){
      arm_mtr.move_absolute(100, 100);
    }
    // ==== RAMP CONTROL ==== //
    if(ramp_state == FREE){
      if(master.get_digital(DIGITAL_L1)){
        if(anglerPot.get_value() > 1150){
          lift.setRampVel(20);
          if (anglerPot.get_value() > 1700) angler_mtr = 0;
        }
        else lift.setRampVel(127);
      }
      else if(master.get_digital(DIGITAL_L2)){
        if(rampLim.get_value() == 1) lift.setRampVel(0);
        else lift.setRampVel(-127);
      }
      else angler_mtr = 0;
    }
    else if(ramp_state == LOCKED){
        error = target - anglerPot.get_value();
        lift.setRampVel(kp * error);
    }
    else if(ramp_state == MANUAL){
      angler_mtr.move(partner.get_analog(ANALOG_LEFT_X));
    }

    if(ramp_state == AUTO && lift_state == AUTO){
      if(anglerPot.get_value() > 1150){
        lift.setRampVel(20);
        if (anglerPot.get_value() > 1700) angler_mtr = 0;
      }
      else lift.setRampVel(127);
    }

    pros::delay(20);
  } //End while(true)
} //End void LiftAuto_fn(void*parameter)
