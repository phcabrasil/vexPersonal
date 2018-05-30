#ifndef AUTOFUNCTIONS_H_
#define AUTOFUNCTIONS_H_

#include "main.h"

extern int armTarget;

extern int currentChain;

TaskHandle conePresetTask;

//********************************
//       Functions
//********************************

void arm(void*parameter); //ArmPID for Autonomous
TaskHandle armHandle;

void armDown(int targetValue);

void armPID(int targetValue, float kp, float kd); //ArmPID for OpControl

void armUp(int targetValue); //Arm Up preset

void armP(int direction, int targetValue, int timeout);

void chaindown(int targetValue, int timeout, float kp, float kd); //FourBarPID DOWN for Autonomous

void chainpid(int targetValue);  //PID for Chain Bar
TaskHandle chainpidHandle;

void chainup(int targetValue, int timeout, float kp, float kd); //FourBarPID UP for Autonomous

void conePreset(void* ignore); //Scoring cone preset

void drive(int direction, int target); //Autonomous Drive Function

void drivePID(int direction, int target, int kp, int ki, int kd, int timeout); //Autonomous Drive PID Function

void stopEverything(); //Fucntion to Stop Everything

void intakeOpen(); //Open Claw

void intakeClose(); //Close Claw

void intakeStay(); //Stay Open

void intakeHold(); //Hold Cone

void matchbarup(); //Bar up for match

void matchbardown(); //Bar down for match

void matchbarstraight(); //Bar Straight

void mogoIn(int timeout); //Mobile Goal In

void mogoOut(int timeout); //Mobile Goal Out

void mogoScore(); //mobile goal score preset

void motorCap(int what, int speed); //Motor Cap

void preLoads(); //Preloads

void resetEverything();//Resetting Everything

void turn(int direction, int targetTurn, int timeout, float kp, float kd); //Autonomous Turn Function


#endif
