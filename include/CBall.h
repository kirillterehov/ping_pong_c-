#ifndef BALL_H
#define BALL_H
#include "CRocket.h"

struct Coordinates {
	int x; //Ñoordinate by x;
	int y; //Ñoordinate by y;
};


class CBall {  //a class that describes functions for working with ball
private:
public:
	Coordinates position_ball;  // the variable responsible for the ball's position
	Coordinates deviation_ball; // the variable responsible for the ball's deviation


	CBall(int start_x,
		int start_y, int start_deviarion_x, int start_deviarion_y);  // declaration class constructor Work_with_ball

	int movement_ball(int position_ball,
		int movement_ball);  // function declaration movement_ball

	void touching_the_walls();  // function declaration touching_the_walls
	void touching_the_rocket(
		CRocket& rocket);  // function declaration touching_the_rocket

	void start_position();         // function declaration start_position_x
	//void start_position_y();         // function declaration start_position_y
	void position();  // function declaration position
	void deviation(
		CRocket& left_rocket,
		CRocket& right_rocket);  // function declaration deviation
};
#endif