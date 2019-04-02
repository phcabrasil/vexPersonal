#include "main.h"

using namespace okapi;

//Drive
auto drive = ChassisControllerFactory::create (
               {11, 12}, {-13, -14}, //Left Ports + Right Ports
               AbstractMotor::gearset::green, //Motor Gear Ration
               {4_in, 12.5_in} //Wheel Diameter + Base Width
);

auto profileController = AsyncControllerFactory::motionProfile(
  0.7,
  2.0,
  10.0,
  drive
);
//Motion Profiling Controller
//auto profileController = AsyncControllerFactory::motionProfile (0.7/*Velocity*/, 1.5/*Acceleration*/, 8.0/*Jerk*/, drive); //9

void autonomous() {
/* Far back Blue
  angler.move_absolute(15, 75);
  drive.setMaxVelocity(100);
  roller.move(75);
  drive.moveDistance(3_ft);
  roller.move(0);
  drive.moveDistance(-1_ft);
  drive.turnAngle(120_deg);
  puncherL.move(127);
  puncherR.move(127);
  delay(700);
  puncherL.move(0);
  puncherR.move(0);
  roller.move(127);
  pros::delay(1000);
  roller.move(0);
  angler.move_absolute(50, 65);
  puncherL.move(127);
  puncherR.move(127);
  delay(700);
  puncherL.move(0);
  puncherR.move(0);
  drive.turnAngle(-147_deg);
  drive.moveDistance(-2.3_ft);

  */

  /* Top Blue
    angler.tare_position();
    angler.move_absolute(25, 75);
    drive.setMaxVelocity(100);
    roller.move(75);
    drive.moveDistance(3_ft);
    roller.move(0);
    drive.moveDistance(-3_ft);
    drive.turnAngle(90_deg);
    puncherL.move(127);
    puncherR.move(127);
    delay(700);
    puncherL.move(0);
    puncherR.move(0);
    roller.move(127);
    pros::delay(1000);
    roller.move(0);
    angler.move_absolute(55, 65);
    puncherL.move(127);
    puncherR.move(127);
    delay(700);
    puncherL.move(0);
    puncherR.move(0);
    drive.turnAngle(147_deg);
    drive.moveDistance(2.3_ft);
    */
    /*Far back RED
     angler.move_absolute(25, 75);
     drive.setMaxVelocity(100);
     roller.move(75);
     drive.moveDistance(3_ft);
     roller.move(0);
     drive.moveDistance(-1_ft);
     drive.turnAngle(-52_deg);
     puncherL.move(127);
     puncherR.move(127);
     delay(700);
     puncherL.move(0);
     puncherR.move(0);
     roller.move(127);
     pros::delay(1000);
     roller.move(0);
     angler.move_absolute(50, 65);
     puncherL.move(127);
     puncherR.move(127);
     delay(700);
     puncherL.move(0);
     puncherR.move(0);
     drive.turnAngle(147_deg);
     drive.moveDistance(-2.3_ft);
     */
     /* Top RED
       angler.tare_position();
       angler.move_absolute(25, 75);
       drive.setMaxVelocity(100);
       roller.move(75);
       drive.moveDistance(3_ft);
       roller.move(0);
       drive.moveDistance(-1_ft);
       drive.turnAngle(90_deg);
       puncherL.move(127);
       puncherR.move(127);
       delay(700);
       puncherL.move(0);
       puncherR.move(0);
       roller.move(127);
       pros::delay(1000);
       roller.move(0);
       angler.move_absolute(55, 65);
       puncherL.move(127);
       puncherR.move(127);
       delay(700);
       puncherL.move(0);
       puncherR.move(0);
       drive.turnAngle(147_deg);
       drive.moveDistance(2.3_ft);
       */
       /* Top RED flag, drive flag, back, fwd, flip and platform
       angler.tare_position();
       angler.move_absolute(25, 75);
       drive.setMaxVelocity(100);
       puncherL.move(127);
       puncherR.move(127);
       delay(700);
       puncherL.move(0);
       puncherR.move(0);
       drive.moveDistance(3.5_ft);
       drive.moveDistance(-3_ft);
       drive.turnAngle(-180_deg);
       drive.moveDistance(-3.5_ft);
       drive.turnAngle(-90_deg);
       roller.move(127);
       pros::delay(1000);
       roller.move(0);
       drive.moveDistance(3_ft);
       drive.turnAngle(90_deg);
       drive.moveDistance(-2.3_ft);
       */
       /* Top BLUE flag, drive flag, back, fwd, flip and platform
       angler.tare_position();
       angler.move_absolute(25, 75);
       drive.setMaxVelocity(100);
       puncherL.move(127);
       puncherR.move(127);
       delay(700);
       puncherL.move(0);
       puncherR.move(0);
       drive.moveDistance(3.5_ft);
       delay(2000);
       drive.moveDistance(-3.5_ft);
       drive.turnAngle(-90_deg);
       drive.moveDistance(3_ft);
       drive.turnAngle(-90_deg);
       roller.move(127);
       pros::delay(1000);
       roller.move(0);
       drive.moveDistance(3_ft);
       drive.turnAngle(90_deg);
       drive.moveDistance(-2.3_ft);
       */

       /*safebet Bottom BLUE
       drive.setMaxVelocity(100);
       drive.moveDistance(3_ft);
       roller.move(75);
       drive.moveDistance(3_ft);
       roller.move(0);
       drive.moveDistance(-1_ft);
       drive.turnAngle(120_deg);
       drive.turnAngle(-147_deg);
       drive.moveDistance(-2.3_ft);
       */

       /*'safebet Bottom RED
       drive.setMaxVelocity(100);
       drive.moveDistance(3_ft);
       roller.move(-75);
       drive.moveDistance(2.5_ft);
       roller.move(0);
       drive.moveDistance(-1_ft);
       drive.turnAngle(-120_deg);
       drive.turnAngle(-90_deg);
       drive.moveDistance(-2.3_ft);
       */

       /*Bottom just staright and intake ball/ a cap
       drive.setMaxVelocity(100);
       drive.moveDistance(3_ft);
       roller.move(75);
       drive.moveDistance(2.5_ft);
       roller.move(0);
       drive.moveDistance(-1.5_ft);

       */
       /*Top just staright and a cap
       drive.setMaxVelocity(100);
       drive.moveDistance(3_ft);
       roller.move(-75);
       drive.moveDistance(2.5_ft);
       roller.move(0);
       drive.moveDistance(-1.5_ft);

       */
}
