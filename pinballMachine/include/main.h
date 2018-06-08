
#ifndef MAIN_H_

#define MAIN_H_

#include <API.h>

#ifdef __cplusplus
extern "C" {
#endif

#define bumperLeft 1
#define bumperRight 2
#define puncherButton 3

#define puncher 2
#define bumperL 1
#define bumperR 3

void autonomous();
void initializeIO();
void initialize();
void operatorControl();

#ifdef __cplusplus
}
#endif

#endif
