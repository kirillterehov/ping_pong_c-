#include "../include/PingPong.h"

#include <iostream>

#include "../include/Variables.h"

using namespace std;
using namespace helperVar;

PingPong::PingPong() : m_ball({ HEIGHT / 2, WIDTH / 2 }, { DEVIATION_X, DEVIATION_Y }),
m_left_rocket(HEIGHT / 2), m_right_rocket(HEIGHT / 2), m_first_player(0), m_second_player(0) {

} // initialization list of the class constructor PingPong
void PingPong::cleaner() {  // a function that prints 10 line breaks
	for (int i = 0; i < 10; i++) {
		cout << endl;
	}
}

int PingPong::writting_field(CRocket left_rocket,
	CRocket right_rocket, CBall
	ball) {  // field rendering function
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (i == 0 || i == HEIGHT - UPPER_BOUNDARY_OF_THE_FIELD) {  // drawing the upper and lower borders
				cout << "-";
			}
			else if (j == 0 || j == WIDTH - UPPER_BOUNDARY_OF_THE_FIELD ||
				j == WIDTH / 2) {  // drawing the left and right borders and
				// the center line
				cout << '|';
			}
			else if ((i == left_rocket.get_position() ||
				i == left_rocket.get_position() - PART_OF_THE_RACKET ||
				i == left_rocket.get_position() + PART_OF_THE_RACKET) &&
				j == HORIZONTAL_POSITION_OF_THE_LEFT_RACKET) {  // drawing the left racket
				cout << '|';
			}
			else if ((i == right_rocket.get_position() ||
				i == right_rocket.get_position() - PART_OF_THE_RACKET ||
				i == right_rocket.get_position() + PART_OF_THE_RACKET) &&
				j == WIDTH + HORIZONTAL_POSITION_OF_THE_RIGHT_RACKET) {  // drawing the right racket
				cout << '|';
			}
			else if (i == ball.position_ball.x &&
				j == ball.position_ball.y) {  // drawing the ball
				cout << 'o';
			}
			else {
				cout << ' ';  // drawing the field
			}
		}
		cout << endl;
	}
	return 0;
}

void PingPong::check_win_player(int first_player) {  // checking the winner
	if (first_player == SCORE) {
		cout << "Player 1 win!";
	}
	else {
		cout << "Player 2 Win!";
	}
}

void PingPong::work() {
	while (m_first_player <= SCORE || m_second_player <= SCORE) {
		if ((m_first_player == SCORE) || (m_second_player == SCORE)) {
			check_win_player(m_first_player);  // checking the winner
			break;
		}
		char key = getchar();  // input sumbol by keyboard
		while (getchar() != '\n');
		check_key(key, m_left_rocket,
			m_right_rocket);  // responsible for the movement of the rackets
		m_ball.position(
		);  // changes the position of the ball on the field
		m_ball.deviation(m_left_rocket,
			m_right_rocket);  // checking the bounce off walls and rackets
		check_position_ball(
			m_first_player, m_second_player,
			m_left_rocket, m_right_rocket,
			m_ball);  // checking the exit from the field and scoring points and moves
		// the rackets and the ball to their starting positions
		cleaner();  // clean field
		cout << "first player score: " << m_first_player << " "
			<< "second player score: " << m_second_player << endl;  // output score
		writting_field(m_left_rocket, m_right_rocket, m_ball);  // writting field
	}
}

void PingPong::reset_Position(
	CRocket& left_rocket,
	CRocket& right_rocket,
	CBall& ball) {  // a function that moves the rackets and the ball
	// to their starting positions
	ball.reset_Position();  // we take the value from the object of the
	// class Work_with_ball ball(12, 40);
	left_rocket
		.reset_Position();  // we take the value from the function start_position
	// in which we change the position
	right_rocket
		.reset_Position();  // we take the value from the function start_position
	// in which we change the position
}

void PingPong::check_position_ball(
	int& first_player,
	int& second_player, CRocket& left_rocket,
	CRocket& right_rocket,
	CBall&
	ball) {  // checking the exit from the field and scoring points
	if (ball.position_ball.y + ball.deviation_ball.y > WIDTH - MINIMUM_BALL_POSITION_OUTSIDE_THE_FIELD ||
		ball.position_ball.y + ball.deviation_ball.y < MINIMUM_BALL_POSITION_OUTSIDE_THE_FIELD) {
		if (ball.position_ball.y + ball.deviation_ball.y > WIDTH - MINIMUM_BALL_POSITION_OUTSIDE_THE_FIELD) {
			first_player++;
		}
		else if (ball.position_ball.y + ball.deviation_ball.y < MINIMUM_BALL_POSITION_OUTSIDE_THE_FIELD) {
			second_player++;
		}
		reset_Position(
			left_rocket, right_rocket,
			ball);  // moving the rackets and the ball to the starting position
	}
}



void PingPong::check_key(
	char key, CRocket& left_rocket,
	CRocket& right_rocket) {  // the function that is responsible for
	// the movement of the rackets
	if (key == 'a' || key == 'z' || key == 'A' || key == 'Z' || key == 'k' ||
		key == 'm' || key == 'K' || key == 'M') {
		left_rocket.move_left_rocket(key);
		right_rocket.move_right_rocket(key);
	}
}