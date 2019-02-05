/** @file opcontrol.c
 * @brief File for operator control code
 *
 * This file should contain the user operatorControl() function and any functions related to it.
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */


 #include "main.h"


 /*
  * Runs the user operator control code. This function will be started in its own task with the
  * default priority and stack size whenever the robot is enabled via the Field Management System
  * or the VEX Competition Switch in the operator control mode. If the robot is disabled or
  * communications is lost, the operator control task will be stopped by the kernel. Re-enabling
  * the robot will restart the task, not resume it from where it left off.
  *
  * If no VEX Competition Switch or Field Management system is plugged in, the VEX Cortex will
  * run the operator control task. Be warned that this will also occur if the VEX Cortex is
  * tethered directly to a computer via the USB A to A cable without any VEX Joystick attached.
  *
  * Code running in this task can take almost any action, as the VEX Joystick is available and
  * the scheduler is operational. However, proper use of delay() or taskDelayUntil() is highly
  * recommended to give other tasks (including system tasks such as updating LCDs) time to run.
  *
  * This task should never exit; it should end with some kind of infinite loop, even if empty.
  */

  #include "util.h"
  #include <math.h>
  #include "autoFunctions.h"

int autonSwitch = 0;

//void taskAutonSwitch(void * parameter);

void taskAuto( void * parameter);
void taskAutoB( void * parameter);
void taskLoad( void * parameter );
void taskDrive( void * parameter );
void taskIntake( void * parameter);
void taskReset( void * parameter);
void taskCat( void * parameter);
void taskStraight( void * parameter);
void taskCata( void * parameter);





void operatorControl() {


//  if ( analogRead( POT_AUTON_1 ) > posPot2Div[0] && analogRead( POT_AUTON_1 ) < posPotDiv[1] ){
//  TaskHandle autoTaskHandle = taskCreate( taskAuto, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT );
  //}



  TaskHandle driveTaskHandle = taskCreate( taskDrive, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT );
  TaskHandle loadTaskHandle = taskCreate( taskLoad, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT );
  TaskHandle intakeTaskHandle = taskCreate( taskIntake, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT );
  //TaskHandle resetTaskHandle = taskCreate( taskReset, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT );

//  TaskHandle autoTaskHandle = taskCreate( taskAuto, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT );

  //TaskHandle autoBTaskHandle = taskCreate( taskAutoB, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT );

  }




/*void taskLoad( void * parameter ) {
      while ( true ) {

        if  (getCataOSE()< 0 )   {
          setCat(45);
        }
        //if catapult is not touching the switch
    	 else  if ( getCataOSE() == 100) {
    		setCat(15);
    	  }

        if (joystickGetDigital(1, 6,JOY_UP) && getCataOSE() == 100){

    	     setCat(100);//shoot
    	  }
       	  delay( 20 );
    }
  }
*/


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
        TaskHandle catTaskHandle = taskCreate( taskCat, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT );

        delay(3500);

        taskDelete(catTaskHandle);
        delay(50);
        launchCat();
        delay(500);
        driveEncoder(80, 1200);
        delay(500);
        driveBackEncoder(80, 1800);
        driveTurnEncoder(85, 230);
        driveEncoder(127,1800);


        delay(1000000);


  }
}

void taskAutoB( void * parameter){

        while(true){
    /*   TaskHandle catTaskHandle = taskCreate( taskCat, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT );
        delay(2000);
        taskDelete(catTaskHandle);
        delay(50);
        launchCat();*/
        delay(500);
        driveBackEncoder(100, 500);
        startIntake();
        delay(200);
        driveTurnEncoder(100, 200);
        flipCap();
        driveBackEncoder(100, 500);
        driveTurnEncoder(100, 200);
      }
    }


//int posPotDiv[4] = { 0, 1023, 2047, 4095};
//int posPotDiv[4] = { 0, 1023, 2047, 4095};




void taskLoad( void * parameter ) {
    while ( true ) {

      if  (digitalRead(LIMIT_SWITCH) == HIGH)   {
        setCat(50* joystickGetDigital(1, 6, JOY_DOWN));


      }
      //if catapult is not touching the switch
  	  if ( digitalRead(LIMIT_SWITCH) == LOW) {
  		setCat(15);

  	  }

      if (joystickGetDigital(1, 6,JOY_UP) && digitalRead(LIMIT_SWITCH) == LOW){

  	     setCat(100);//shoot
  	     delay(200);
  	     setCat(0);


  	                   }
     	  delay( 20 );
  }
}


void taskDrive( void * parameter ) {

//  issueMotors(127,5000);

  while ( true) {



		double factor = abs( joystickGetAnalog( JOY_MASTER, AXIS_LEFT_V ) ) / 127.0 ;

		double left = joystickGetAnalog( JOY_MASTER, AXIS_LEFT_V ) + joystickGetAnalog( JOY_MASTER, AXIS_RIGHT_H ) * ( 0.4 + 0.4 * sqrt( factor ) );

		double right = - joystickGetAnalog( JOY_MASTER, AXIS_LEFT_V ) + joystickGetAnalog( JOY_MASTER, AXIS_RIGHT_H ) * ( 0.4 + 0.4 * sqrt( factor ) );

		setDriveLeft( left );
		setDriveRight( right );
  }
		delay( 20 );
}

void taskIntake( void * parameter){

    while ( true ) {
          int intake = joystickGetDigital( JOY_MASTER, 5, JOY_UP) - joystickGetDigital(JOY_MASTER, 5, JOY_DOWN);
          setIntake(127* intake);
          delay(20);
        }

}


void taskReset( void * parameter){

    while ( true ) {

          int reset = joystickGetDigital( JOY_MASTER, 8, JOY_UP) - joystickGetDigital(JOY_MASTER, 8, JOY_DOWN);
          setCat(48* reset);
          delay( 200 );

          int shoot = - joystickGetDigital(JOY_MASTER, 8, JOY_RIGHT);
          setCat(100* shoot);
          delay( 200 );
        }

}
