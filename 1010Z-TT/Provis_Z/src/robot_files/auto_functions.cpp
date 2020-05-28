#include "main.h"
#include "robot_includes/robot_includes.hpp"

using namespace okapi;

std::shared_ptr<ChassisController> autoChassis =
  ChassisControllerBuilder()
    .withMotors({-9, -5}, {4, 1})
    // Green gearset, 4 in wheel diam, 11.5 in wheel track
    .withDimensions(AbstractMotor::gearset::green, {{4_in, 11.5_in}, imev5GreenTPR})
    .build();

std::shared_ptr<AsyncMotionProfileController> profileController =
  AsyncMotionProfileControllerBuilder()
    .withLimits({0.9, 1.6, 8.5}) //2.0 | 10.0
    .withOutput(autoChassis)
    .buildMotionProfileController();

double getVelocity(pros::Motor motor) {
  return motor.get_actual_velocity();
}

void reRun() {

  FILE *fp;
  fp = fopen("/usd/example.txt", "r");
  static float v1, v2, v3, v4;
  static int s1, s2, s3;

  while(true) {

    if(feof(fp)) {
      left_back_mtr.move_velocity(0);
      left_front_mtr.move_velocity(0);
      right_back_mtr.move_velocity(0);
      right_front_mtr.move_velocity(0);
      angler_mtr.move_velocity(0);
      intake_mtr.move_velocity(0);
      intake_mtr_two.move_velocity(0);
      arm_mtr.move_velocity(0);
      fclose(fp);
      pros::delay(100);

    } //End if(feof(fp))

    fscanf(fp, "%f %f %f %f %i %i %i", &v1, &v2, &v3, &v4, &s1, &s2, &s3);

    left_back_mtr.move_velocity(v1);
    left_front_mtr.move_velocity(v2);
    right_back_mtr.move_velocity(v3);
    right_front_mtr.move_velocity(v4);
    ramp_state = s1;
    lift_state = s2;
    intake_state = s3;

    pros::delay(10);

  } //End while(true)
} //End void reRun()

void recordRun() {
  int count = 0;
  FILE* file = fopen("/usd/example.txt",  "w");
  while (count < 14500) {
          fprintf(file, "%f\n", getVelocity(left_back_mtr));
          fprintf(file, "%f\n", getVelocity(left_front_mtr));
          fprintf(file, "%f\n", getVelocity(right_back_mtr));
          fprintf(file, "%f\n", getVelocity(right_front_mtr));
          fprintf(file, "%i\n", ramp_state);
          fprintf(file, "%i\n", lift_state);
          fprintf(file, "%i\n", intake_state);

          chassis.driveControl();
          lift.driveControl();

          pros::delay(10);
          count += 10;
  }
  fclose(file);
}

void initPaths() {
  //Red Unprotected
  profileController->generatePath (
    {
      {0_ft, 0_ft, 0_deg},
      {1.5_ft, 2.5_ft, 0_deg}
    },
    "RedUn"
  );
  //Blue Unprotected
  profileController->generatePath (
    {
      {0_ft, 0_ft, 0_deg},
      {1_ft, 0_ft, 0_deg}
    },
    "BlueUn"
  );
}

void redUnprotected(bool safe) {

  if(safe) {

  }

  else {

  }
}

void blueUnprotected(bool safe) {

  if(safe) {

  }

  else {
    intake_state = INTAKE;
    chassis.autoDrive(FORWARD, 1800, 3000, 80);
    intake_state = STOP;
    profileController->tarePosition();
    profileController->setTarget("RedUn",true);
    profileController->waitUntilSettled();
    chassis.autoFence(250, 0.4, 0, 1000);
    chassis.autoDrive(FORWARD, 1700, 3000, 80);
    chassis.autoTurn(RIGHT, 45, 2000);
  }
}

void redProtected() {
  intake_state = EXPEL;
  pros::delay(200);
  intake_state = INTAKE;
  pros::delay(500);
  chassis.autoDrive(FORWARD, 1000, 2000, 90);
  lift_state = LOW_TOWER;
  ramp_state = LOCKED;
  chassis.autoDrive(FORWARD, 900, 2000, 45);
  chassis.autoDrive(FORWARD, 325, 2000, 45);
  lift_state = SLOW_INTAKING;
  ramp_state = SLOW_RETURN;
  pros::delay(2000);
  chassis.autoDrive(FORWARD, 900, 2000, 90);
}

void blueProtected() {

}

void autonSkills() {

}

void rerunAuto() {
  reRun();
}
