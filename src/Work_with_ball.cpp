#include "../include/Work_with_ball.h"

#include "../include/Variables.h"

Work_with_ball::Work_with_ball(int start_x, int start_y)
	: position_ball_x(start_x),
	position_ball_y(start_y) {  // constructor of the class in which we
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
	if (position_ball_x == height - (height - 1) ||
		position_ball_x == height - 2) {
		deviation_ball_x = -deviation_ball_x;
	}
	return deviation_ball_x;
}

int Work_with_ball::touching_the_rocket(
	int position_ball_x, int position_ball_y, int& movement_ball,
	Work_with_rockets
	rocket) {  // the function of bouncing the ball off the racket
	if ((position_ball_y == width - (width - 2) ||
		position_ball_y == width - 3) &&
		(position_ball_x == rocket.get_position() ||
			position_ball_x == rocket.get_position() - 1 ||
			position_ball_x == rocket.get_position() + 1)) {
		movement_ball = -movement_ball;
	}
	return movement_ball;
}
int Work_with_ball::start_position_x() {  // a function that returns the
	// position of the ball by x
	return position_ball_x;
}
int Work_with_ball::start_position_y() {  // a function that returns the
	// position of the ball by y
	return position_ball_y;
}