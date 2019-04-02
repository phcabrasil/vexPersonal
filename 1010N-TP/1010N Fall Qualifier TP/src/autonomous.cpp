#include "main.h"
#include "flywheel.h"
using namespace okapi;

Motor fwMotor = 6_mtr;
Motor intakeMotor = 5_mtr; // Intake 5

//Drive
auto driveF = ChassisControllerFactory::create (
               {driveLF, driveLB, driveLM}, {driveRF, driveRB, driveRM}, //Left Ports + Right Ports
               AbstractMotor::gearset::green, //Motor Gear Ration
               {3.25_in, 12.5_in} //Wheel Diameter + Base Width
             );

auto profileControllerF = AsyncControllerFactory::motionProfile (1.0/*Velocity*/, 2.0/*Acceleration*/, 10.0/*Jerk*/, driveF); //9

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */

void autonomous() {

  profileControllerF.generatePath({ //Test Path
    Point{0_ft, 0_ft, 0_deg},
    Point{4.3_ft, 0_ft, 0_deg}}, //Was 4
    "TOFIRSTCAP"
  );
  profileControllerF.generatePath({ //Test Path
    Point{0_ft, 0_ft, 0_deg},
    Point{1.8_ft, 0_ft, 0_deg}},
    "TOSECONDFLAG"
  );
  profileControllerF.generatePath({ //Test Path
    Point{0_ft, 0_ft, 0_deg},
    Point{1.9_ft, 0_ft, 0_deg}},
    "TOSECONDCAP"
  );
  profileControllerF.generatePath({ //Test Path
    Point{0_ft, 0_ft, 0_deg},
    Point{0.5_ft, 0_ft, 0_deg}},
    "CLIMB"
  );


/*
    //Red Flags Auto
    fwMotor.move(127);
    intakeMotor.move(-70);
    profileControllerF.setTarget("TOFIRSTCAP");
    profileControllerF.waitUntilSettled();
    pros::delay(300);
    intakeMotor.move(0);
    driveF.moveDistance(-3.65_ft);//3.65
    pros::delay(100);
    driveF.turnAngle(-84_deg);
    pros::delay(300);
    driveF.moveDistance(0.6_ft);//0.55
    intakeMotor.move(-127);
    pros::delay(1750);
    intakeMotor.move(0);
    profileControllerF.setTarget("TOSECONDFLAG");
    profileControllerF.waitUntilSettled();
    intakeMotor.move(-127);
    pros::delay(1000);
    driveF.moveDistance(1.1_ft);
    intakeMotor.move(0);
    pros::delay(100);
    driveF.moveDistance(-1.4_ft);
    intakeMotor.move(127);
    pros::delay(100);
    driveF.turnAngle(84_deg);
    pros::delay(100);
    profileControllerF.setTarget("TOSECONDCAP");
    profileControllerF.waitUntilSettled();
    pros::delay(100);
    intakeMotor.move(0);
    driveF.arcade(-127,0);
    pros::delay(1000);
    driveF.stop();
  */

  
  //Blue Flags Auto
  fwMotor.move(127);
  intakeMotor.move(-70);
  profileControllerF.setTarget("TOFIRSTCAP");
  profileControllerF.waitUntilSettled();
  pros::delay(300);
  intakeMotor.move(0);
  driveF.moveDistance(-3.65_ft);//3.65
  pros::delay(100);
  driveF.turnAngle(84_deg);
  pros::delay(300);
  driveF.moveDistance(0.6_ft);//0.55
  intakeMotor.move(-127);
  pros::delay(1750);
  intakeMotor.move(0);
  profileControllerF.setTarget("TOSECONDFLAG");
  profileControllerF.waitUntilSettled();
  intakeMotor.move(-127);
  pros::delay(1000);
  driveF.moveDistance(1.1_ft);
  intakeMotor.move(0);
  pros::delay(100);
  driveF.moveDistance(-1.4_ft);
  intakeMotor.move(127);
  pros::delay(100);
  driveF.turnAngle(-84_deg);
  pros::delay(100);
  profileControllerF.setTarget("TOSECONDCAP");
  profileControllerF.waitUntilSettled();
  pros::delay(100);
  intakeMotor.move(0);
  driveF.arcade(-127,0);
  pros::delay(1000);
  driveF.stop();



/*
  //Red Caps Auto
  intakeMotor.move(127);
  pros::delay(100);
  profileControllerF.setTarget("TOFIRSTCAP");
  profileControllerF.waitUntilSettled();
  pros::delay(100);
  intakeMotor.move(0);
  driveF.moveDistance(-4.3_ft);
  pros::delay(100);
  driveF.turnAngle(-23_deg);
  pros::delay(100);
  intakeMotor.move(-70);
  profileControllerF.setTarget("TOFIRSTCAP");
  profileControllerF.waitUntilSettled();
  pros::delay(100);
  intakeMotor.move(0);
  driveF.moveDistance(-0.9_ft);
  driveF.turnAngle(-87_deg);
  driveF.arcade(127,0);
  pros::delay(1000);
  driveF.stop();
*/


/*
  //Blue Caps Auto
  intakeMotor.move(127);
  pros::delay(100);
  profileControllerF.setTarget("TOFIRSTCAP");
  profileControllerF.waitUntilSettled();
  pros::delay(100);
  intakeMotor.move(0);
  driveF.moveDistance(-4_ft);
  pros::delay(100);
  driveF.turnAngle(23_deg);
  pros::delay(100);
  intakeMotor.move(-70);
  profileControllerF.setTarget("TOFIRSTCAP");
  profileControllerF.waitUntilSettled();
  pros::delay(100);
  intakeMotor.move(0);
  driveF.moveDistance(-1.5_ft);
  driveF.turnAngle(88_deg);
  driveF.arcade(127,0);
  pros::delay(1000);
  driveF.stop();
  */


  //Skills Auto
/*
  fwMotor.move(127);
  pros::delay(4000);
  intakeMotor.move(-127);
  pros::delay(2000);
  driveF.turnAngle(88_deg);
  pros::delay(200);
  profileControllerF.setTarget("TOFIRSTCAP");
  profileControllerF.waitUntilSettled();
  pros::delay(500);
  intakeMotor.move(0);
  driveF.moveDistance(-3.7_ft); //-3.9
  pros::delay(100);
  driveF.turnAngle(-88_deg);
  pros::delay(200);
  profileControllerF.setTarget("TOSECONDFLAG");
  profileControllerF.waitUntilSettled();
  intakeMotor.move(-127);
  pros::delay(2000);
  driveF.moveDistance(1.1_ft);
  intakeMotor.move(0);
  pros::delay(100);
  driveF.moveDistance(-1.4_ft);
  intakeMotor.move(127);
  pros::delay(100);
  driveF.turnAngle(84_deg);
  pros::delay(100);
  profileControllerF.setTarget("TOSECONDCAP");
  profileControllerF.waitUntilSettled();
  pros::delay(100);
  intakeMotor.move(0);
  driveF.arcade(-127,0);
  pros::delay(1000);
  driveF.stop();
  pros::delay(100);
  profileControllerF.setTarget("CLIMB");
  profileControllerF.waitUntilSettled();
  pros::delay(300);
  driveF.turnAngle(78_deg);
  pros::delay(1000);
  profileControllerF.setTarget("TOFIRSTCAP");
  profileControllerF.waitUntilSettled();
  pros::delay(300);
  driveF.turnAngle(-83_deg);
  driveF.arcade(-127,0);
  pros::delay(1000);
  driveF.stop();
  driveF.arcade(127,0);
  pros::delay(2600);
  driveF.stop();
*/
}
