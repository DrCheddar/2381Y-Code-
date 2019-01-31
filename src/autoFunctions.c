#include "main.h"
#include "autoFunctions.h"
#include "util.h"


void drive(int speed){
  if  (digitalRead(BUMP_SWITCH) == HIGH)   {
      setAutoDriveLeft(-speed);
      setAutoDriveRight(speed);
  }
  //if catapult is not touching the switch
  else if ( digitalRead(LIMIT_SWITCH) == LOW) {

    setAutoDriveLeft(0);
    setAutoDriveRight(0);
  }

}



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
  delay(5000);
  setIntake(0);

}

void driveBackwards(int speed, int microSec){

    setDriveLeft(-speed);
    setDriveRight(speed);

     delay(microSec);

     setAutoDriveLeft(0);
     setAutoDriveRight(0);

 }

 void driveStraight(int speed, int microSec){

     setDriveLeft(speed* 0.9);
     setDriveRight(-speed);

     delay(microSec);
     setDriveLeft(0);
     setDriveRight(0);

 }



 void driveTrn(int speed1, int speed2, int microSec){

     setAutoDriveLeft(speed1);
     setAutoDriveRight(speed2);

     delay(microSec);
     setAutoDriveLeft(0);
     setAutoDriveRight(0);
 }



void driveBackEncoder(int speed, int distance){

encoderReset(driveRightOSE);

   while ( true ) {

     if ( getRightOSE() > -distance ) {

<<<<<<< HEAD
       setDriveLeft( -speed*0.9);
       setDriveRight( speed);
=======
       setDriveLeft( -speed *0.95 );
       setDriveRight( speed );
>>>>>>> 7239b6524f96d77e75dad550a304222536ee8a25
     }

     else{

       setDriveLeft( 40 );
       setDriveRight( -40 );

       delay( 40 );

       setDriveLeft( 0 );
       setDriveRight( 0 );

       break;

     }

     delay( 20 );

   }
}

void driveTurnEncoder(int speed, int distance){

encoderReset(driveRightOSE);

   while ( true ) {

     if ( getRightOSE() > -distance ) {

<<<<<<< HEAD
     setDriveLeft( speed *0.9);
=======
     setDriveLeft( speed *0.95 );
>>>>>>> 7239b6524f96d77e75dad550a304222536ee8a25
     setDriveRight( speed);

   } else {

       setDriveLeft( -40 );
       setDriveRight( -40 );

       delay( 40 );

       setDriveLeft( 0 );
       setDriveRight( 0 );

       break;

     }

     delay( 20 );

   }
}

void driveTurnLeftEncoder(int speed, int distance){

encoderReset(driveRightOSE);

   while ( true ) {

     if ( getRightOSE() < distance ) {

     setDriveLeft( -speed *0.9);
     setDriveRight( -speed);

   } else {

       setDriveLeft( 40 );
       setDriveRight( 40 );

       delay( 40 );

       setDriveLeft( 0 );
       setDriveRight( 0 );

       break;

     }

     delay( 20 );

   }
}

/*
void driveTurnEncoder(int speed, int distance){

encoderReset(driveRightOSE);

   while ( true ) {

     if ( getRightOSE() > -distance ) {

     setDriveLeft( speed );
     setDriveRight( speed);

   }else {

       setDriveLeft( -40 );
       setDriveRight( -40 );

       delay( 40 );

       setDriveLeft( 0 );
       setDriveRight( 0 );

       break;

     }

     delay( 20 );

   }
}
*/
void driveEncoder(int speed, int distance){

encoderReset(driveRightOSE);

   while ( true ) {

     if ( getRightOSE() < distance ) {

     setDriveLeft( speed *0.95);
     setDriveRight( -speed);

   } else {

       setDriveLeft( -40 );
       setDriveRight( 40 );

       delay( 40 );

       setDriveLeft( 0 );
       setDriveRight( 0 );

       break;

     }

     delay( 20 );

   }
}


/*
void driveBackEncoder(int speed, int distance){

encoderReset(driveRightOSE);

   while ( true ) {

     setDriveLeft( -speed );
     setDriveRight( speed);

     if ( getRightOSE() < -distance ) {

       setDriveLeft( 40 );
       setDriveRight( -40 );

       delay( 40 );

       setDriveLeft( 0 );
       setDriveRight( 0 );

       break;

     }

     delay( 20 );

   }
}


void driveTurnEncoder(int speed, int distance){

encoderReset(driveRightOSE);

   while ( true ) {

     setDriveLeft( speed );
     setDriveRight( speed);

     if ( getRightOSE() < -distance ) {

       setDriveLeft( -40 );
       setDriveRight( -40 );

       delay( 40 );

       setDriveLeft( 0 );
       setDriveRight( 0 );

       break;

     }

     delay( 20 );

   }
}

void driveEncoder(int speed, int distance){

encoderReset(driveRightOSE);

   while ( true ) {

     setDriveLeft( speed );
     setDriveRight( -speed);

     if ( getRightOSE() > distance ) {

       setDriveLeft( -40 );
       setDriveRight( 40 );

       delay( 40 );

       setDriveLeft( 0 );
       setDriveRight( 0 );

       break;

     }

     delay( 20 );

   }
}
*/
