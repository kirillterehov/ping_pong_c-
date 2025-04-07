#ifndef PINGPONG_H
#define PINGPONG_H

#include "CBall.h"
#include "CRocket.h"

class PingPong {  // a class that describes functions for field rendering, scoring, cleaning, and other auxiliary functions for the work function, which is responsible for executing the main part of the program
private:
	CBall m_ball; // A CBall class object is a ball
	CRocket m_left_rocket; // A CRocket class object is a left racket
	CRocket m_right_rocket; // A CRocket class object is a right racket
	int m_first_player; // The score counter of the first player
	int m_second_player; // The score counter of the second player
public:
	PingPong(); //declaration PingPong class constructor
	void cleaner();  // function declaration cleaner
	int writting_field();  // function declaration writting_field
	void check_win_player();  // function declaration check_win_player
	void reset_Position(
		);  // function declaration start_position
	void check_position_ball();  // function declaration check_position_ball
	void check_key(char key);  // function declaration check_key
	void work();                           // function declaration work
};
#endif