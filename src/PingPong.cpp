#include "../include/PingPong.h"

#include <iostream>

#include "../include/Variables.h"

using namespace std;
using namespace helperVar;

void PingPong::cleaner() {  // a function that prints 10 line breaks
	for (int i = 0; i < 10; i++) {
		cout << endl;
	}
}

int PingPong::writting_field(Work_with_rockets left_rocket,
	Work_with_rockets right_rocket, int position_ball_x,
	int position_ball_y) {  // field rendering function
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
			else if (i == position_ball_x &&
				j == position_ball_y) {  // drawing the ball
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
	Work_with_ball ball(HEIGHT / 2, WIDTH / 2);
	Work_with_rockets left_rocket(HEIGHT / 2);
	Work_with_rockets right_rocket(HEIGHT / 2);
	int first_player = 0;
	int second_player = 0;
	int position_ball_x = HEIGHT / 2;
	int position_ball_y = WIDTH / 2;
	int deviation_ball_x = 1;
	int deviation_ball_y = -1;
	while (first_player <= SCORE || second_player <= SCORE) {
		if ((first_player == SCORE) || (second_player == SCORE)) {
			check_win_player(first_player);  // checking the winner
			break;
		}
		char key = getchar();  // input sumbol by keyboard
		while (getchar() != '\n');
		check_key(key, left_rocket,
			right_rocket);  // responsible for the movement of the rackets
		position(position_ball_x, position_ball_y, deviation_ball_x,
			deviation_ball_y,
			ball);  // changes the position of the ball on the field
		deviation(position_ball_x, position_ball_y, deviation_ball_x,
			deviation_ball_y, ball, left_rocket,
			right_rocket);  // checking the bounce off walls and rackets
		check_position_ball(
			position_ball_y, deviation_ball_y, first_player, second_player,
			position_ball_x, left_rocket, right_rocket,
			ball);  // checking the exit from the field and scoring points and moves
		// the rackets and the ball to their starting positions
		cleaner();  // clean field
		cout << "first player score: " << first_player << " "
			<< "second player score: " << second_player << endl;  // output score
		writting_field(left_rocket, right_rocket, position_ball_x,
			position_ball_y);  // writting field
	}
}

void PingPong::start_position(
	int& position_ball_x, int& position_ball_y, Work_with_rockets& left_rocket,
	Work_with_rockets& right_rocket,
	Work_with_ball& ball) {  // a function that moves the rackets and the ball
	// to their starting positions
	position_ball_x =
		ball.start_position_x();  // we take the value from the object of the
	// class Work_with_ball ball(12, 40);
	position_ball_y =
		ball.start_position_y();  // we take the value from the object of the
	// class Work_with_ball ball(12, 40);
	left_rocket
		.start_position();  // we take the value from the function start_position
	// in which we change the position
	right_rocket
		.start_position();  // we take the value from the function start_position
	// in which we change the position
}

void PingPong::check_position_ball(
	int& position_ball_y, int& deviation_ball_y, int& first_player,
	int& second_player, int& position_ball_x, Work_with_rockets& left_rocket,
	Work_with_rockets& right_rocket,
	Work_with_ball&
	ball) {  // checking the exit from the field and scoring points
	if (position_ball_y + deviation_ball_y > WIDTH - MINIMUM_BALL_POSITION_OUTSIDE_THE_FIELD ||
		position_ball_y + deviation_ball_y < MINIMUM_BALL_POSITION_OUTSIDE_THE_FIELD) {
		if (position_ball_y + deviation_ball_y > WIDTH - MINIMUM_BALL_POSITION_OUTSIDE_THE_FIELD) {
			first_player++;
		}
		else if (position_ball_y + deviation_ball_y < MINIMUM_BALL_POSITION_OUTSIDE_THE_FIELD) {
			second_player++;
		}
		start_position(
			position_ball_x, position_ball_y, left_rocket, right_rocket,
			ball);  // moving the rackets and the ball to the starting position
	}
}

void PingPong::position(
	int& position_ball_x, int& position_ball_y, int& deviation_ball_x,
	int& deviation_ball_y,
	Work_with_ball& ball) {  // a function that changes the position of the ball
	// on the field
	position_ball_x = ball.movement_ball(position_ball_x, deviation_ball_x);
	position_ball_y = ball.movement_ball(position_ball_y, deviation_ball_y);
}

void PingPong::deviation(
	int& position_ball_x, int& position_ball_y, int& deviation_ball_x,
	int& deviation_ball_y, Work_with_ball& ball, Work_with_rockets& left_rocket,
	Work_with_rockets& right_rocket) {  // the function responsible for checking
	// the bounce off walls and rackets
	deviation_ball_x = ball.touching_the_walls(position_ball_x, deviation_ball_x);
	deviation_ball_y = ball.touching_the_rocket(position_ball_x, position_ball_y,
		deviation_ball_y, left_rocket);
	deviation_ball_y = ball.touching_the_rocket(position_ball_x, position_ball_y,
		deviation_ball_y, right_rocket);
}

void PingPong::check_key(
	char key, Work_with_rockets& left_rocket,
	Work_with_rockets& right_rocket) {  // the function that is responsible for
	// the movement of the rackets
	if (key == 'a' || key == 'z' || key == 'A' || key == 'Z' || key == 'k' ||
		key == 'm' || key == 'K' || key == 'M') {
		left_rocket.move_left_rocket(key);
		right_rocket.move_right_rocket(key);
	}
}
