#include "main.h"
using namespace okapi;

//Intake Motors
pros::Motor intakeMotor (11, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES); //Port 10 Not Reversed //2
pros::Motor fwIntakeMotor (8, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES); //Port 10 Not Reversed //2
pros::Motor fwMtrBA (3, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES); //Port 10 Not Reversed //2
pros::Motor fwMtrTA (12, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES); //Port 10 Not Reversed //2

//Drive
auto drive = ChassisControllerFactory::create (
               {1, 2}, {-10, 9}, //Left Ports + Right Ports
               AbstractMotor::gearset::green, //Motor Gear Ration
               {4_in, 13_in} //Wheel Diameter + Base Width
);


//Motion Profiling Controller
auto profileController = AsyncControllerFactory::motionProfile (0.8/*Velocity*/, 1.6/*Acceleration*/, 8.0/*Jerk*/, drive); //9

void autonomous() {

  profileController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{3_ft, 0_ft, 0_deg}}, "A");
  profileController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{2_ft, 0_ft, 0_deg}}, "B");
  profileController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{0.6_ft, 0_ft, 0_deg}}, "O");

  //Skills
/*
  fwMtrBA.move(127);
  fwMtrTA.move(127);
  intakeMotor.move(127);
  profileController.setTarget("A");
  profileController.waitUntilSettled();
  pros::delay(300);
  fwIntakeMotor.move(127);
  pros::delay(500);
  fwIntakeMotor.move(0);
  drive.setMaxVelocity(100);
  drive.moveDistance(-0.5_ft);
  intakeMotor.move(-127);
  pros::delay(200);
  drive.moveDistance(1.2_ft);
  drive.setMaxVelocity(200);
  pros::delay(500);
  drive.moveDistance(-3.8_ft);
  intakeMotor.move(0);
  drive.turnAngle(-155_deg);
  fwIntakeMotor.move(127);
  pros::delay(800);
  fwIntakeMotor.move(0);
  profileController.setTarget("B");
  profileController.waitUntilSettled();
  fwIntakeMotor.move(127);
  pros::delay(800);
  fwIntakeMotor.move(0);
  //START HERE TMR
  drive.turnAngle(150_deg);
  intakeMotor.move(-127);
  drive.setMaxVelocity(100);
  drive.moveDistance(1.2_ft);
  pros::delay(300);
  drive.setMaxVelocity(120);
  drive.moveDistanceAsync(-3_ft);
  pros::delay(1300);
  drive.stop();
  profileController.setTarget("O");
  profileController.waitUntilSettled();
  drive.turnAngle(-155_deg);//was 150
  drive.moveDistanceAsync(3_ft);
  pros::delay(2000);
  drive.stop();
  pros::delay(300);
  drive.setMaxVelocity(200);
  drive.stop();
  drive.moveDistance(-8.6_ft);
  drive.turnAngle(135_deg);
  drive.setMaxVelocity(100);
  drive.moveDistanceAsync(-3.5_ft);
  pros::delay(700);
  drive.stop();
  drive.moveDistance(1.4_ft);
  drive.setMaxVelocity(200);
  intakeMotor.move(127);
  profileController.setTarget("A");
  profileController.waitUntilSettled();
  pros::delay(300);
  fwIntakeMotor.move(127);
  pros::delay(500);
  fwIntakeMotor.move(0);
  drive.setMaxVelocity(100);
  drive.moveDistance(-0.5_ft);
  intakeMotor.move(-127);
  pros::delay(350);
  drive.moveDistance(1.2_ft);
  drive.setMaxVelocity(200);
  pros::delay(500);
  drive.moveDistance(-3.8_ft);
  intakeMotor.move(0);
  drive.turnAngle(143_deg); //was 150
  drive.moveDistance(2.2_ft);
  drive.turnAngle(-143_deg);
  intakeMotor.move(-127);
  profileController.setTarget("A");
  profileController.waitUntilSettled();
  pros::delay(300);
  drive.moveDistance(-4.2_ft);
  intakeMotor.move(0);
  fwMtrBA.move(105);
  fwMtrTA.move(105);
  drive.turnAngle(-145_deg); //was 150
  drive.moveDistance(4.1_ft);//was 4.1

  drive.turnAngle(56_deg);
  pros::delay(200);
  fwIntakeMotor.move(127);
  pros::delay(1200);
  fwIntakeMotor.move(0);
  drive.turnAngle(-200_deg);
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
  fwMtrBA.move(127);
  fwMtrTA.move(127);
  intakeMotor.move(127);
  profileController.setTarget("A");
  profileController.waitUntilSettled();
  pros::delay(300);
  fwIntakeMotor.move(127);
  pros::delay(500);
  fwIntakeMotor.move(0);
  drive.setMaxVelocity(200);
  pros::delay(500);
  drive.moveDistance(-3.2_ft);
  intakeMotor.move(0);
  drive.turnAngle(-155_deg);
  fwIntakeMotor.move(127);
  pros::delay(800);
  fwIntakeMotor.move(0);
  profileController.setTarget("B");
  profileController.waitUntilSettled();
  fwIntakeMotor.move(127);
  pros::delay(800);
  fwIntakeMotor.move(0);
  drive.turnAngle(150_deg);
  intakeMotor.move(-95);
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
  fwMtrBA.move(127);
  fwMtrTA.move(127);
  intakeMotor.move(127);
  profileController.setTarget("A");
  profileController.waitUntilSettled();
  pros::delay(300);
  fwIntakeMotor.move(127);
  pros::delay(500);
  fwIntakeMotor.move(0);
  drive.setMaxVelocity(200);
  pros::delay(500);
  drive.moveDistance(-3.2_ft);
  intakeMotor.move(0);
  drive.turnAngle(144_deg);
  fwIntakeMotor.move(127);
  pros::delay(800);
  fwIntakeMotor.move(0);
  profileController.setTarget("B");
  profileController.waitUntilSettled();
  fwIntakeMotor.move(127);
  pros::delay(800);
  fwIntakeMotor.move(0);
  drive.turnAngle(-150_deg);
  intakeMotor.move(-95);
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

  fwMtrBA.move(105);
  fwMtrTA.move(105);
  pros::delay(3000);
  fwIntakeMotor.move(127);
  pros::delay(500);
  fwIntakeMotor.move(0);
  drive.turnAngle(-95_deg);
  drive.setMaxVelocity(100);
  drive.moveDistanceAsync(-3.5_ft);
  pros::delay(700);
  drive.stop();
  drive.moveDistance(1.4_ft);
  drive.setMaxVelocity(200);
  intakeMotor.move(127);
  profileController.setTarget("A");
  profileController.waitUntilSettled();
  pros::delay(300);
  fwIntakeMotor.move(127);
  pros::delay(500);
  fwIntakeMotor.move(0);
  drive.moveDistance(-1.8_ft);
  intakeMotor.move(0);
  drive.turnAngle(147_deg); //was 150
  drive.moveDistanceAsync(-10_ft);
  pros::delay(1400);//2750
  drive.stop();


} //END void autonomous
