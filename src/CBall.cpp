#include "../include/CBall.h"

#include "../include/Variables.h"

using namespace helperVar;

const int TOUCHING_LEFT_RACKET_POSITION_OF_THE_BALL = 2; // the position of the ball to touch the left racket 
const int TOUCHING_RIGHT_RACKET_POSITION_OF_THE_BALL = -3;// the position of the ball to touch the right racket. It is calculated by adding the width and this number.

CBall::CBall(int start_x,
	int start_y, int start_deviarion_x, int start_deviarion_y)
	: position_ball{ start_x, start_y }, deviation_ball{ start_deviarion_x , start_deviarion_y }
{  // constructor of the class in which we
	// initialize the ball position
}

int CBall::movement_ball(
	int position_ball,
	int movement_ball) {  // a function that recalculates the position of the
	// ball on the field
	position_ball += movement_ball;
	return position_ball;
}

void CBall::touching_the_walls() {  // the function of bouncing the ball from the
	// boundaries of the field
	if (position_ball.x == UPPER_BOUNDARY_OF_THE_FIELD ||
		position_ball.x == HEIGHT + LOWER_BOUNDARY_OF_THE_FIELD) {
		deviation_ball.x = -deviation_ball.x;
	}
}

void CBall::touching_the_rocket(

	CRocket&
	rocket) {  // the function of bouncing the ball off the racket
	if ((position_ball.y == TOUCHING_LEFT_RACKET_POSITION_OF_THE_BALL ||
		position_ball.y == WIDTH + TOUCHING_RIGHT_RACKET_POSITION_OF_THE_BALL) &&
		(position_ball.x == rocket.get_position() ||
			position_ball.x == rocket.get_position() - PART_OF_THE_RACKET ||
			position_ball.x == rocket.get_position() + PART_OF_THE_RACKET)) {
		deviation_ball.y = -deviation_ball.y;
	}
}

void CBall::start_position() {  // a function that returns the
	// position of the ball by x
	position_ball.x = HEIGHT / 2;
	position_ball.y = WIDTH / 2;
}


void CBall::position() {  // a function that changes the position of the ball
	// on the field
	position_ball.x = movement_ball(position_ball.x, deviation_ball.x);
	position_ball.y = movement_ball(position_ball.y, deviation_ball.y);
}

void CBall::deviation(CRocket& left_rocket,
	CRocket& right_rocket) {  // the function responsible for checking
	// the bounce off walls and rackets
	touching_the_walls();
	touching_the_rocket(left_rocket);
	touching_the_rocket(right_rocket);
}