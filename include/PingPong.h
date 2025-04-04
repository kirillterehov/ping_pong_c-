#ifndef PINGPONG_H
#define PINGPONG_H

#include "CBall.h"
#include "CRocket.h"

class PingPong {  // a class that describes functions for field rendering, scoring, cleaning, and other auxiliary functions for the work function, which is responsible for executing the main part of the program
public:
	void cleaner();  // function declaration cleaner
	int writting_field(
		CRocket left_rocket, CRocket right_rocket,
		CBall
		ball);  // function declaration writting_field
	void check_win_player(
		int first_player);  // function declaration check_win_player
	void start_position(
		CRocket& left_rocket, CRocket& right_rocket,
		CBall& ball);  // function declaration start_position
	void check_position_ball(
		int& first_player,
		int& second_player, CRocket& left_rocket,
		CRocket& right_rocket,
		CBall& ball);  // function declaration check_position_ball
	void check_key(
		char key, CRocket& left_rocket,
		CRocket& right_rocket);  // function declaration check_key
	void work();                           // function declaration work
};
#endif