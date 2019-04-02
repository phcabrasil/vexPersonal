#include "main.h"
using namespace okapi;

void opcontrol() {

  pros::Task::delay(100);

  //Controller
  Controller controller; //Set Main Controller
  ControllerButton elbowRight(ControllerId::partner, ControllerDigital::R1); //Partner R1
  ControllerButton elbowLeft(ControllerId::partner, ControllerDigital::R2); //Partner R2
  ControllerButton intakeOpen(ControllerId::partner, ControllerDigital::L1); //Button L1
  ControllerButton intakeClose(ControllerId::partner, ControllerDigital::L2); //Button L2
  ControllerButton runAutoButton(ControllerDigital::X); //Button X
  pros::Controller second(pros::E_CONTROLLER_PARTNER);


  //Drive
  auto drive = ChassisControllerFactory::create (
                 {driveLF, driveLB}, {driveRF, driveRB}, //Left Ports + Right Ports
                 AbstractMotor::gearset::green, //Motor Gear Ration
                 {4_in, 13.5_in} //Wheel Diameter + Base Width
               );
  auto profileController = AsyncControllerFactory::motionProfile (1.0/*Velocity*/, 2.0/*Acceleration*/, 9.0/*Jerk*/, drive);

  //Arm
  int armCurrPos;
  pros::Motor arm(12);
  Motor armMotorL = 12_mtr; //Arm Motor Left
  Motor armMotorR = 3_mtr; //Arm Motor Right

  int currPos = 0;
  auto liftControl = AsyncControllerFactory::posIntegrated(14);
  int inCurrPos;
  auto intakeControl = AsyncControllerFactory::posIntegrated(13);



  //Intake
  pros::Motor intake(13);
  Motor intakeMotor = 13_mtr;
  //Motor elbowMotor = 14_mtr;


	profileController.generatePath({ //Test Path
  	Point{0_ft, 0_ft, 0_deg},
  	Point{1_ft, -2_ft, -90_deg}},
  	"MEMES"
	);

  while (true) {

    drive.arcade(controller.getAnalog(ControllerAnalog::leftY), //Drive Arcade
                 controller.getAnalog(ControllerAnalog::rightX));


    armMotorR.move(-second.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y));
    armMotorL.move(second.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y));

/*
armCurrPos = arm.get_position();
    if (armUp.isPressed()) { //Arm Control
      armMotorR.move(-127);
      armMotorL.move(127);
    }
    else if (armDown.isPressed()){
      armMotorR.move(127);
      armMotorL.move(-127);
    }
    else{
      if(inCurrPos>310){
        armMotorR.move(-13);
        armMotorL.move(13);
      }
        else if(armCurrPos<60){
          armMotorR.move(13);
          armMotorL.move(-13);
        }
      else{
      armMotorR.move(0);
      armMotorL.move(0);
    }
    }
    */


    if (intakeClose.isPressed()) { //Intake Control
      intakeMotor.move(-127);
      inCurrPos = intake.get_position();
    } else if (intakeOpen.isPressed()) {
      intakeMotor.move(127);
      inCurrPos = intake.get_position();
    } else {
      intakeControl.setTarget(inCurrPos);
    }

    if (elbowRight.isPressed()) { //Elbow Control
      currPos = 135;
    } else if (elbowLeft.isPressed()) {
      currPos = 405;
    } else {
      liftControl.setTarget(currPos);
    }

    if (runAutoButton.changedToPressed()) { //Test Auto
      //intakeController.setTarget(200);
    }

    pros::Task::delay(10);

  }
}
