#ifndef HELPER_H
#define HELPER_H

#include "Work_with_ball.h"
#include "Work_with_rockets.h"

class Helper {  // a class that describes functions for field rendering, scoring, cleaning, and other auxiliary functions for the work function, which is responsible for executing the main part of the program
public:
	void cleaner();  // function declaration cleaner
	int writting_field(
		Work_with_rockets left_rocket, Work_with_rockets right_rocket,
		int position_ball_x,
		int position_ball_y);  // function declaration writting_field
	void check_win_player(
		int first_player);  // function declaration check_win_player
	void start_position(
		int& position_ball_x, int& position_ball_y,
		Work_with_rockets& left_rocket, Work_with_rockets& right_rocket,
		Work_with_ball& ball);  // function declaration start_position
	void check_position_ball(
		int& position_ball_y, int& deviation_ball_y, int& first_player,
		int& second_player, int& position_ball_x, Work_with_rockets& left_rocket,
		Work_with_rockets& right_rocket,
		Work_with_ball& ball);  // function declaration check_position_ball
	void position(int& position_ball_x, int& position_ball_y,
		int& deviation_ball_x, int& deviation_ball_y,
		Work_with_ball& ball);  // function declaration position
	void deviation(
		int& position_ball_x, int& position_ball_y, int& deviation_ball_x,
		int& deviation_ball_y, Work_with_ball& ball,
		Work_with_rockets& left_rocket,
		Work_with_rockets& right_rocket);  // function declaration deviation
	void check_key(
		char key, Work_with_rockets& left_rocket,
		Work_with_rockets& right_rocket);  // function declaration check_key
	void work();                           // function declaration work
};
#endif