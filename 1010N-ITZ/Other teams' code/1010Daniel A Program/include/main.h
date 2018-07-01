
#ifndef MAIN_H_

// This prevents multiple inclusion, which isn't bad for this file but is good practice
#define MAIN_H_

#include <API.h>

// Allow usage of this file in C++ programs
#ifdef __cplusplus
extern "C" {
#endif

//Motor Ports
#define DRIVE_RF 3
#define DRIVE_RB 2 //Power Expander D
#define DRIVE_LF 8 //Power Expander C
#define DRIVE_LB 9
#define ARM_R 5
#define ARM_L 4 //Power Expander A
#define ARM_RL 7
#define MOGO 10
#define MOGO_A 1
#define FOURBAR 6 //Power Expander B

void autonomous();
void initializeIO();
void initialize();
void operatorControl();

// End C++ export structure
#ifdef __cplusplus
}
#endif

#endif
