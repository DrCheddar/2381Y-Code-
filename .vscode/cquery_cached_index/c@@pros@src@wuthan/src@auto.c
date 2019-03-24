
/** @file auto.c
 * @brief File for autonomous code
 *
 * This file should contain the user autonomous() function and any functions related to it.
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"
#include "autoFunctions.h"
#include "util.h"

#include <math.h>
#include "autoFunctions.h"


//void taskAutonSwitch(void * parameter);
void taskAuto( void * parameter);
void taskAutoB( void * parameter);
void taskCat( void * parameter);
void taskStraight( void * parameter);




void autonomous() {

  int posPotDiv[4] = { 0, 1023, 2047, 4095};
  int posPot2Div[4] = { 0, 1023, 2047, 4095};



//if ( analogRead( POT_AUTON_1 ) > posPotDiv[0] && analogRead( POT_AUTON_1 ) < posPotDiv[1] ) {
//TaskHandle autoTaskHandle = taskCreate( taskAuto, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT );
//}




}

/*


void taskCat( void * parameter ){

  while(true){

  if  (digitalRead(LIMIT_SWITCH) == HIGH)   {
           setCat(48);
  }
        //if catapult is not touching the switch
  else if ( digitalRead(LIMIT_SWITCH) == LOW) {
          setCat(15);
  }
  delay(20);
}
}

void taskStraight( void * parameter){
while(true){
if  (digitalRead(BUMP_SWITCH) == HIGH)   {
    setDriveLeft(127);
    setDriveRight(-127);
}
//if catapult is not touching the switch
else if ( digitalRead(LIMIT_SWITCH) == LOW) {
  setDriveLeft(0);
  setDriveRight(0);
}
delay(20);
}
}


void taskAuto( void * parameter){

      while(true){
      /*
      TaskHandle catTaskHandle = taskCreate( taskCat, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT );
      delay(2000);
      taskDelete(catTaskHandle);
      delay(50);
      launchCat();
      delay(500); */
    //  driveEncoder(50, 1000);
      /*delay(1500);
      driveBackwards(127, 1900);
      driveTurn(-127, -127, 320);
      driveStraight(127, 1400);

      delay(1000000);


}
}

void taskAutoB( void * parameter){

      while(true){
      TaskHandle catTaskHandle = taskCreate( taskCat, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT );
      delay(2000);
      taskDelete(catTaskHandle);
      delay(50);
      launchCat();
      delay(2000);
      setCat(0);
      delay(1000000);
/*      TaskHandle straightTaskHandle = taskCreate( taskStraight, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT );
      delay(1500);
      driveBackwards(127, 1900);
      driveTurn(-127, -127, 320);
      driveStraight(127, 1400);
      delay(1000000); */

//}
//}

/*void autonomous() {


    if ( analogRead( POT_AUTON_1 ) > posPotDiv[1] && analogRead( POT_AUTON_1 ) < posPotDiv[2] )



  if ( analogRead( POT_AUTON_1 ) > posPotDiv[2] && analogRead( POT_AUTON_1 ) < posPotDiv[3] )
    TaskHandle autonSwitchTaskHandle = taskCreate( taskAutonSwitch, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT );
    TaskHandle autonTaskHandle = taskCreate( taskAuton, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT );




  int posPotDiv[4] = { 0, 1023, 2047, 4095}; //pot 2 divisions, front left, front right, back left, back right, none



  // front right
  //if ( analogRead( POT_AUTON_1 ) > posPotDiv[0] && analogRead( POT_AUTON_1 ) < posPotDiv[1] ) {
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

  void taskStraight( void * parameter){
    if  (digitalRead(BUMP_SWITCH) == HIGH)   {
        setDriveLeft(127);
        setDriveRight(-127);
    }
    //if catapult is not touching the switch
    else if ( digitalRead(LIMIT_SWITCH) == LOW) {
      setDriveLeft(0);
      setDriveRight(0);
    }

  }


if ( analogRead( POT_AUTON_1 ) > posPotDiv[0] && analogRead( POT_AUTON_1 ) < posPotDiv[1] ) {
    if ( analogRead( POT_AUTON_1 ) > posPot2Div[0] && analogRead( POT_AUTON_1 ) < posPotDiv[1] ){


          TaskHandle catTaskHandle = taskCreate( taskCat, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT );
          delay(2000);
          taskDelete(catTaskHandle);
          delay(50);
          launchCat();
          delay(500);
          TaskHandle straightTaskHandle = taskCreate( taskStraight, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT );
          driveBackwards(127, 1900);
          driveTurn(-127, -127, 320);
          driveStraight(127, 1400);
          delay(1000000);


    }
  }

}

*/

  //  if ( analogRead( POT_AUTON_1 ) > posPotDiv[3] && analogRead( POT_AUTON_1 ) < posPotDiv[4] )
