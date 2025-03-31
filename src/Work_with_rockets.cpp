#include "../include/Work_with_rockets.h"

#include "../include/Variables.h"

Work_with_rockets::Work_with_rockets(int position_rocket)
	: position(position_rocket) {  // constructor of the class in which we
	// initialize the racket position
}

int Work_with_rockets::check_up_rocket(
	int rocket) {  // checking that the racket does not go beyond the boundaries
	// of the field from above
	if (rocket > height - (height - 2)) {
		rocket--;
	}
	return rocket;
}

int Work_with_rockets::check_down_rocket(
	int rocket) {  // checking that the racket does not go beyond the boundaries
	// of the field from below
	if (rocket < height - 3) {
		rocket++;
	}
	return rocket;
}

int Work_with_rockets::get_position() const {
	return position;
}  // a function that returns the position of the racket

void Work_with_rockets::move_left_rocket(
	char key) {  // the function that is responsible for the movement of the
	// left racket
	if (key == 'a' || key == 'A') {
		position = check_up_rocket(position);
	}
	else if (key == 'z' || key == 'Z') {
		position = check_down_rocket(position);
	}
}

void Work_with_rockets::move_right_rocket(
	char key) {  // the function that is responsible for the movement of the
	// right racket
	if (key == 'k' || key == 'K') {
		position = check_up_rocket(position);
	}
	else if (key == 'm' || key == 'M') {
		position = check_down_rocket(position);
	}
}

void Work_with_rockets::start_position() {  // a function that moves the racket
	// to the starting position
	position = height / 2;
}