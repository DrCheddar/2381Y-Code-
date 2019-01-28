#include "main.h"
#include "autoFunctions.h"
#include "util.h"






void launchCat(){



  if (digitalRead(LIMIT_SWITCH) == LOW){
    setCat(50);
    delay(1000);
    setCat(0);
  }
}

void startIntake(){

  setIntake(127);
  delay(5000);
  setIntake(0);

}


void flipCap(){

  setIntake(-127);
  delay(1000);
  setIntake(0);

}

void driveBackwards(int speed, int microSec){

    setDriveLeft(-speed);
    setDriveRight(speed);

     delay(microSec);

     setDriveLeft(0);
     setDriveRight(0);

 }

 void driveStraight(int speed, int microSec){

     setDriveLeft(speed);
     setDriveRight(-speed);

     delay(microSec);
     setDriveLeft(0);
     setDriveRight(0);

 }

 void driveTurn(int speed1, int speed2, int microSec){

     setDriveLeft(speed1);
     setDriveRight(speed2);

     delay(microSec);
     setDriveLeft(0);
     setDriveRight(0);

 }
