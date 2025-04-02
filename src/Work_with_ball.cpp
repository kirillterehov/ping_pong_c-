#include "../include/Work_with_ball.h"

#include "../include/Variables.h"

using namespace helperVar;

const int TOUCHING_LEFT_RACKET_POSITION_OF_THE_BALL = 2; // the position of the ball to touch the left racket 
const int TOUCHING_RIGHT_RACKET_POSITION_OF_THE_BALL = -3;// the position of the ball to touch the right racket. It is calculated by adding the width and this number.

Work_with_ball::Work_with_ball(int start_x, int start_y)
	: m_position_ball_x(start_x),
	m_position_ball_y(start_y) {  // constructor of the class in which we
	// initialize the ball position
}

int Work_with_ball::movement_ball(
	int position_ball,
	int movement_ball) {  // a function that recalculates the position of the
	// ball on the field
	position_ball += movement_ball;
	return position_ball;
}

int Work_with_ball::touching_the_walls(
	int position_ball_x,
	int deviation_ball_x) {  // the function of bouncing the ball from the
	// boundaries of the field
	if (position_ball_x == UPPER_BOUNDARY_OF_THE_FIELD ||
		position_ball_x == HEIGHT+LOWER_BOUNDARY_OF_THE_FIELD) {
		deviation_ball_x = -deviation_ball_x;
	}
	return deviation_ball_x;
}

int Work_with_ball::touching_the_rocket(
	int position_ball_x, int position_ball_y, int& movement_ball,
	Work_with_rockets
	rocket) {  // the function of bouncing the ball off the racket
	if ((position_ball_y == TOUCHING_LEFT_RACKET_POSITION_OF_THE_BALL ||
		position_ball_y == WIDTH - TOUCHING_RIGHT_RACKET_POSITION_OF_THE_BALL) &&
		(position_ball_x == rocket.get_position() ||
			position_ball_x == rocket.get_position() - PART_OF_THE_RACKET ||
			position_ball_x == rocket.get_position() + PART_OF_THE_RACKET)) {
		movement_ball = -movement_ball;
	}
	return movement_ball;
}
int Work_with_ball::start_position_x() {  // a function that returns the
	// position of the ball by x
	return m_position_ball_x;
}
int Work_with_ball::start_position_y() {  // a function that returns the
	// position of the ball by y
	return m_position_ball_y;
}