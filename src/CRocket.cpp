#include "../include/CRocket.h"

#include "../include/Variables.h"

using namespace helperVar;

const int MINIMUM_VERTICAL_POSITION_OF_THE_RACKET = 2; // minimum vertical position of the racket
const int MAXIMUM_VERTICAL_POSITION_OF_THE_RACKET = -3; // the maximum vertical position of the racket. It is calculated by adding the height and this number.

CRocket::CRocket(int position_rocket)
	: m_position(position_rocket) {  // constructor of the class in which we
	// initialize the racket position
}

int CRocket::m_check_up_rocket(
	int rocket) {  // checking that the racket does not go beyond the boundaries
	// of the field from above
	if (rocket > MINIMUM_VERTICAL_POSITION_OF_THE_RACKET) {
		rocket--;
	}
	return rocket;
}

int CRocket::m_check_down_rocket(
	int rocket) {  // checking that the racket does not go beyond the boundaries
	// of the field from below
	if (rocket < HEIGHT + MAXIMUM_VERTICAL_POSITION_OF_THE_RACKET) {
		rocket++;
	}
	return rocket;
}

int CRocket::get_position() const {
	return m_position;
}  // a function that returns the position of the racket

void CRocket::move_left_rocket(
	char key) {  // the function that is responsible for the movement of the
	// left racket
	if (key == 'a' || key == 'A') {
		m_position = m_check_up_rocket(m_position);
	}
	else if (key == 'z' || key == 'Z') {
		m_position = m_check_down_rocket(m_position);
	}
}

void CRocket::move_right_rocket(
	char key) {  // the function that is responsible for the movement of the
	// right racket
	if (key == 'k' || key == 'K') {
		m_position = m_check_up_rocket(m_position);
	}
	else if (key == 'm' || key == 'M') {
		m_position = m_check_down_rocket(m_position);
	}
}

void CRocket::start_position() {  // a function that moves the racket
	// to the starting position
	m_position = HEIGHT / 2;
}