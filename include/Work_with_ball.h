#ifndef BALL_H
#define BALL_H
#include "Work_with_rockets.h"

class Work_with_ball {  //a class that describes functions for working with ball
private:
	int position_ball_x;  // the variable responsible for the ball's x position
	int position_ball_y;  // the variable responsible for the ball's y position
public:
	Work_with_ball(int start_x,
		int start_y);  // declaration class constructor Work_with_ball
	int movement_ball(int position_ball,
		int movement_ball);  // function declaration movement_ball
	int touching_the_walls(
		int position_ball_x,
		int deviation_ball_x);  // function declaration touching_the_walls
	int touching_the_rocket(
		int position_ball_x, int position_ball_y, int& movement_ball,
		Work_with_rockets rocket);  // function declaration touching_the_rocket
	int start_position_x();         // function declaration start_position_x
	int start_position_y();         // function declaration start_position_y
};
#endif
