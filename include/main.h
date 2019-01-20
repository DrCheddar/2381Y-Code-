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

#define MOT_INTAKE 1
#define MOT_LDRIVE_1 2
#define MOT_LDRIVE_2 3
#define MOT_LDRIVE_3 4
#define MOT_LDRIVE_3 5
#define MOT_RDRIVE_1 6
#define MOT_RDRIVE_2 7
#define MOT_RDRIVE_3 8
#define MOT_RDRIVE_3 9
#define MOT_CAT 10

#define LIMIT_SWITCH 1



#endif
