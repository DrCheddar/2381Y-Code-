
#ifndef MAIN_H_

#define MAIN_H_

#include <API.h>

#ifdef __cplusplus
extern "C" {
#endif



void autonomous();

void initializeIO();

void initialize();

void operatorControl();

#ifdef __cplusplus
}
#endif

#define JOY_MASTER 1
#define JOY_SLAVE 2

#define AXIS_LEFT_H 4
#define AXIS_LEFT_V 3
#define AXIS_RIGHT_H 1
#define AXIS_RIGHT_V 2



#define MOT_LDRIVE_1 2
#define MOT_LDRIVE_2 3
#define MOT_LDRIVE_3 4

#define MOT_CAT 6
#define MOT_RDRIVE_1 7
#define MOT_RDRIVE_2 8
#define MOT_RDRIVE_3 9
#define MOT_INTAKE 10

#define LIMIT_SWITCH 1
#define BUMP_SWITCH 2
#define POT_AUTON_1 3
#define POT_AUTON_2 4

#define OSE_DRIVE_LEFT_TOP 1
#define OSE_DRIVE_LEFT_BOTTOM 2
#define OSE_DRIVE_RIGHT_TOP 7
#define OSE_DRIVE_RIGHT_BOTTOM 8


Encoder driveLeftOSE;
Encoder driveRightOSE;





#endif
