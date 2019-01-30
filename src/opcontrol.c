/** @file opcontrol.c
 * @brief File for operator control code
 *
 * This file should contain the user operatorControl() function and any functions related to it.
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"
#include "API.h"
#include <math.h>
#include "util.h"
#include "autoFunctions.h"



  int a=1;
  void taskAuto( void * parameter );
  void taskCat( void * parameter );
  void taskLoad( void * parameter );
  void taskDrive( void * parameter );
  void taskIntake( void * parameter);

void operatorControl() {



  //  TaskHandle autoTaskHandle = taskCreate( taskAuto, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT );
  TaskHandle driveTaskHandle = taskCreate( taskDrive, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT );
  TaskHandle loadTaskHandle = taskCreate( taskLoad, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT );
  TaskHandle intakeTaskHandle = taskCreate( taskIntake, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT );

  }

int cataLoad = 0;
void taskLoad( void * parameter ) {
    while ( true ) {


      setCat(40 * joystickGetDigital(1, 6, JOY_DOWN) - 30 * joystickGetDigital(1, 8, JOY_DOWN)) ;

      //if catapult is not touching the switch
        if ( digitalRead(1) == LOW) {
          setCat(20);
        }


      if (joystickGetDigital(1, 6, JOY_UP)  == 1 && digitalRead(1) == LOW){
           setCat(40);
           delay(500);
           setCat(0);
       }
        delay( 20 );
  }
}



void taskDrive( void * parameter ) {
  while ( true ) {

        double factor = abs( joystickGetAnalog( JOY_MASTER, AXIS_LEFT_V ) ) / 127.0 ;

        double left = joystickGetAnalog( JOY_MASTER, AXIS_LEFT_V ) + joystickGetAnalog( JOY_MASTER, AXIS_RIGHT_H ) * ( 0.4 + 0.3 * sqrt( factor ) );

        double right = - joystickGetAnalog( JOY_MASTER, AXIS_LEFT_V ) + joystickGetAnalog( JOY_MASTER, AXIS_RIGHT_H ) * ( 0.4 + 0.3 * sqrt( factor ) );

        setDriveLeft( left );
        setDriveRight( right );
  }
        delay( 20 );
}

void taskIntake( void * parameter){

    while ( true ) {
          int intake = joystickGetDigital( JOY_MASTER, 5, JOY_UP) - joystickGetDigital(JOY_MASTER, 5, JOY_DOWN);
          setIntake(100* intake);
          delay( 20 );
        }
      }




      void taskCat( void * parameter ){

        while(true){

        if  (digitalRead(LIMIT_SWITCH) == HIGH)   {
           setCat(48);
        }
        //if catapult is not touching the switch
        else if ( digitalRead(LIMIT_SWITCH) == LOW) {
          setCat(15);
        }

      }


      }

  void taskAuto( void * parameter){


      while(true){


  //    TaskHandle catTaskHandle = taskCreate( taskCat, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT );
  //    delay(2000);
  //    taskDelete(catTaskHandle);
    //  delay(50);
    //  launchCat();
      delay(500);
    //  driveStraight(127, 1250);
     driveBackwards(127, 1900);
        driveTurn(-127, -127, 320);
      driveStraight(127, 1400);
      delay(1000000);
  }
}

/*    if(joystickGetDigital(1, 5, JOY_UP)){
    setIntake(127);

    }

    else if(joystickGetDigital(1, 5, JOY_DOWN))
    setIntake(-127);

    }
    delay( 20 );
  }*/
