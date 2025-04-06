#ifndef BALL_H
#define BALL_H
#include "CRocket.h"

struct Coordinates {
	int x; //Coordinate by x;
	int y; //Coordinate by y;
};


class CBall {  //a class that describes functions for working with ball
private:
public:
	Coordinates position_ball;  // the variable responsible for the ball's position
	Coordinates deviation_ball; // the variable responsible for the ball's deviation


	CBall(Coordinates position_ball,
		Coordinates deviation_ball);  // declaration class constructor Work_with_ball


	void touching_the_walls();  // function declaration touching_the_walls
	void touching_the_rocket(
		CRocket& rocket);  // function declaration touching_the_rocket

	void reset_Position();         // function declaration resetPosition

	void position();  // function declaration position
	void deviation(
		CRocket& left_rocket,
		CRocket& right_rocket);  // function declaration deviation
};
#endif