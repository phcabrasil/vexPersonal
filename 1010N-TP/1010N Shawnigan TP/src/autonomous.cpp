#include "main.h"
#include "drive.hpp"
using namespace okapi;

//Drive
auto drive = ChassisControllerFactory::create (
               {1, 20}, {-7, -10}, //Left Ports + Right Ports
               AbstractMotor::gearset::green, //Motor Gear Ration
               {4_in, 13_in} //Wheel Diameter + Base Width
);

driveClass base;

//Motion Profiling Controller
//auto profileController = AsyncControllerFactory::motionProfile (0.7/*Velocity*/, 1.5/*Acceleration*/, 8.0/*Jerk*/, drive); //9

void autonomous() {

  //profileController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{2.9_ft, 0_ft, 0_deg}}, "A");
  //profileController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{2_ft, 0_ft, 0_deg}}, "B");
  //profileController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{0.6_ft, 0_ft, 0_deg}}, "O");

  //Skills
  fwMtrB.move(127);
  fwMtrF.move(127);
  intakeMtr.move(127);
  drive.moveDistance(2.8_ft);
  pros::delay(300);
  fwIntakeMtr.move(127);
  pros::delay(500);
  fwIntakeMtr.move(0);
  drive.setMaxVelocity(110);
  drive.moveDistance(-0.5_ft);
  intakeMtr.move(-127);
  pros::delay(200);
  drive.moveDistance(0.8_ft);
  pros::delay(500);
  drive.setMaxVelocity(200);
  drive.moveDistance(-3_ft);
  base.turn(RIGHT, 960, 2000, 0.7, 0.8);
  drive.moveDistance(2.1_ft);
  base.turn(LEFT, 960, 1500, 0.7, 0.8);
  pros::delay(700);
  drive.moveDistance(2.9_ft);
  pros::delay(300);

  /*
  fwMtrB.move(127);
  fwMtrF.move(127);
  intakeMtr.move(127);
  profileController.setTarget("A");
  profileController.waitUntilSettled();
  pros::delay(300);
  fwIntakeMtr.move(127);
  pros::delay(500);
  fwIntakeMtr.move(0);
  drive.setMaxVelocity(100);
  drive.moveDistance(-0.5_ft);
  intakeMtr.move(-127);
  pros::delay(200);
  drive.moveDistance(1.2_ft);
  drive.setMaxVelocity(200);
  pros::delay(500);
  drive.moveDistance(-3.8_ft);
  intakeMtr.move(0);
  base.turn(LEFT, 960, 2000, 0.7, 0.8);
  fwIntakeMtr.move(127);
  pros::delay(800);
  fwIntakeMtr.move(0);
  profileController.setTarget("B");
  profileController.waitUntilSettled();
  fwIntakeMtr.move(127);
  pros::delay(800);
  fwIntakeMtr.move(0);
  base.turn(RIGHT, 960, 2000, 0.7, 0.8);
  intakeMtr.move(-127);
  drive.setMaxVelocity(100);
  drive.moveDistance(1.2_ft);
  pros::delay(300);
  drive.setMaxVelocity(120);
  drive.moveDistanceAsync(-3_ft);
  pros::delay(1300);
  drive.stop();
  profileController.setTarget("O");
  profileController.waitUntilSettled();
  base.turn(LEFT, 960, 2000, 0.7, 0.8);
  drive.moveDistanceAsync(3_ft);
  pros::delay(2000);
  drive.stop();
  pros::delay(300);
  drive.setMaxVelocity(200);
  drive.stop();
  drive.moveDistance(-8.6_ft);
  base.turn(RIGHT, 960, 2000, 0.7, 0.8);
  drive.setMaxVelocity(100);
  drive.moveDistanceAsync(-3.5_ft);
  pros::delay(700);
  drive.stop();
  drive.moveDistance(1.4_ft);
  drive.setMaxVelocity(200);
  intakeMtr.move(127);
  profileController.setTarget("A");
  profileController.waitUntilSettled();
  pros::delay(300);
  fwIntakeMtr.move(127);
  pros::delay(500);
  fwIntakeMtr.move(0);
  drive.setMaxVelocity(100);
  drive.moveDistance(-0.5_ft);
  intakeMtr.move(-127);
  pros::delay(350);
  drive.moveDistance(1.2_ft);
  drive.setMaxVelocity(200);
  pros::delay(500);
  drive.moveDistance(-3.8_ft);
  intakeMtr.move(0);
  base.turn(RIGHT, 960, 2000, 0.7, 0.8);
  drive.moveDistance(2.2_ft);
  base.turn(LEFT, 960, 2000, 0.7, 0.8);
  intakeMtr.move(-127);
  profileController.setTarget("A");
  profileController.waitUntilSettled();
  pros::delay(300);
  drive.moveDistance(-4.2_ft);
  intakeMtr.move(0);
  fwMtrB.move(105);
  fwMtrF.move(105);
  base.turn(LEFT, 960, 2000, 0.7, 0.8);
  drive.moveDistance(4.1_ft);//was 4.1
  base.turn(LEFT, 300, 2000, 0.7, 0.8);
  pros::delay(200);
  fwIntakeMtr.move(127);
  pros::delay(1200);
  fwIntakeMtr.move(0);
  base.turn(LEFT, 1260, 2000, 0.7, 0.8);
  drive.setMaxVelocity(100);
  drive.moveDistanceAsync(3.5_ft);//3.5
  pros::delay(1000);
  drive.stop();
  drive.setMaxVelocity(200);
  drive.moveDistanceAsync(-10_ft);
  pros::delay(2875);//2750
  drive.stop();
  drive.moveDistanceAsync(10_ft);
  pros::delay(100);
  drive.stop();
  */


//YEET

  //Red Flag
/*
  fwMtrB.move(127);
  fwMtrF.move(127);
  intakeMtr.move(127);
  profileController.setTarget("A");
  profileController.waitUntilSettled();
  pros::delay(300);
  fwIntakeMtr.move(127);
  pros::delay(500);
  fwIntakeMtr.move(0);
  drive.setMaxVelocity(200);
  pros::delay(500);
  drive.moveDistance(-3.2_ft);
  intakeMtr.move(0);
  drive.turnAngle(-155_deg);
  fwIntakeMtr.move(127);
  pros::delay(800);
  fwIntakeMtr.move(0);
  profileController.setTarget("B");
  profileController.waitUntilSettled();
  fwIntakeMtr.move(127);
  pros::delay(800);
  fwIntakeMtr.move(0);
  drive.turnAngle(150_deg);
  intakeMtr.move(-95);
  drive.setMaxVelocity(100);
  drive.moveDistance(1.2_ft);
  pros::delay(300);
  drive.setMaxVelocity(150);
  drive.moveDistanceAsync(-3_ft);
  pros::delay(1200);
  drive.stop();
  profileController.setTarget("O");
  profileController.waitUntilSettled();
  drive.turnAngle(-175_deg);//was 150
  drive.moveDistanceAsync(3_ft);
  pros::delay(1750);
  drive.stop();
  pros::delay(300);
  drive.setMaxVelocity(200);
  drive.stop();
  drive.moveDistance(-4_ft);
*/

  //Blue Flag
/*
  fwMtrB.move(127);
  fwMtrF.move(127);
  intakeMtr.move(127);
  profileController.setTarget("A");
  profileController.waitUntilSettled();
  pros::delay(300);
  fwIntakeMtr.move(127);
  pros::delay(500);
  fwIntakeMtr.move(0);
  drive.setMaxVelocity(200);
  pros::delay(500);
  drive.moveDistance(-3.2_ft);
  intakeMtr.move(0);
  drive.turnAngle(144_deg);
  fwIntakeMtr.move(127);
  pros::delay(800);
  fwIntakeMtr.move(0);
  profileController.setTarget("B");
  profileController.waitUntilSettled();
  fwIntakeMtr.move(127);
  pros::delay(800);
  fwIntakeMtr.move(0);
  drive.turnAngle(-150_deg);
  intakeMtr.move(-95);
  drive.setMaxVelocity(100);
  drive.moveDistance(1.2_ft);
  pros::delay(300);
  drive.setMaxVelocity(150);
  drive.moveDistanceAsync(-3_ft);
  pros::delay(1200);
  drive.stop();
  profileController.setTarget("O");
  profileController.waitUntilSettled();
  drive.turnAngle(170_deg);//was 150
  drive.moveDistanceAsync(3_ft);
  pros::delay(1750);
  drive.stop();
  pros::delay(300);
  drive.setMaxVelocity(200);
  drive.stop();
  drive.moveDistance(-4_ft);
*/

  //Red cap

  //Blue Cap
  /*
  fwMtrB.move(105);
  fwMtrF.move(105);
  pros::delay(3000);
  fwIntakeMtr.move(127);
  pros::delay(500);
  fwIntakeMtr.move(0);
  drive.turnAngle(-95_deg);
  drive.setMaxVelocity(100);
  drive.moveDistanceAsync(-3.5_ft);
  pros::delay(700);
  drive.stop();
  drive.moveDistance(1.4_ft);
  drive.setMaxVelocity(200);
  intakeMtr.move(127);
  profileController.setTarget("A");
  profileController.waitUntilSettled();
  pros::delay(300);
  fwIntakeMtr.move(127);
  pros::delay(500);
  fwIntakeMtr.move(0);
  drive.moveDistance(-1.8_ft);
  intakeMtr.move(0);
  drive.turnAngle(147_deg); //was 150
  drive.moveDistanceAsync(-10_ft);
  pros::delay(1400);//2750
  drive.stop();
  */


} //END void autonomous
