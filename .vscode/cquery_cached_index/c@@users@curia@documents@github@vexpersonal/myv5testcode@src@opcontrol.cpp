#include "main.h"


//Variables
int a; //Integer
bool b; //Boolean
float c; //Float
long d; //Long
auto e = 1; //Auto (Pointer)
static int f; //Static Variable (Can't change)
extern int g; //Global Variable
void function ( /*Parameters*/ ) { /*Action*/ }; //Function
/*
--EXAMPLE--
int sumOfNumbers
void function (int number1, int number2) {
	sumOfNumbers = number1 + number2;
	return sumOfNumbers
}
*/

void opcontrol() {

	auto drive = okapi::ChassisControllerFactory::create(driveL, driveR); //Declaring Drive
	pros::Controller master(pros::E_CONTROLLER_MASTER); //Declaring Controller

	while(true){

		drive.arcade(master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y), //Drive Arcade | Get Analog Left Y
								 master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X)); //Get Analog Right X

		pros::Task::delay(20);
	}
}
