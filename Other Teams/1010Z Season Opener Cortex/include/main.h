
#ifndef MAIN_H_

#define MAIN_H_

#include <API.h>

#ifdef __cplusplus
extern "C" {
#endif

#define driveRB 1
#define shooterR 2
#define driveLFP 3 //Y Cable
#define shooterL 4 //A PE
#define driveLB 5 //B PE
#define descore 6 //C PE
#define intake 7 //D PE
#define driveRFP 8 //Y Cable
#define driveLF 9
#define driveRF 10

void autonomous();
void initializeIO();
void initialize();
void operatorControl();

// End C++ export structure
#ifdef __cplusplus
}
#endif

#endif
