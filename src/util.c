#include "main.h"
#include "util.h"

void setDriveLeft( int speed ) {

	motorSet( 2, speed );
	motorSet( 3, speed );
	motorSet( 4, speed );

}

void setDriveRight( int speed ) {



	motorSet( 7, speed );
	motorSet( 8, speed );
	motorSet( 9, speed );
}


void setCat( int speed) {

	motorSet( 6, speed );

}

void setIntake ( int speed ) {

	motorSet( MOT_INTAKE, speed );

}

void setAutoDriveLeft ( int speed ) {

	motorSet( 3, speed );
	motorSet( 4, speed );

}

void setAutoDriveRight ( int speed ) {

	motorSet( 7, speed );
	motorSet( 9, speed );

}

int getRightOSE() {
	return encoderGet( driveRightOSE );
}
