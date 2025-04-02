namespace helperVar
{
	const int HEIGHT = 25; // field height
	const int WIDTH = 80; // field width
	const int SCORE = 21; // the number of points needed to win
	const int UPPER_BOUNDARY_OF_THE_FIELD = 1; // the upper boundary of the field
	const int LOWER_BOUNDARY_OF_THE_FIELD = -2; // the number to calculate is the lower boundary of the field. It is calculated by adding the height and this number.
	const int HORIZONTAL_POSITION_OF_THE_LEFT_RACKET = 1; // left racket's width position
	const int HORIZONTAL_POSITION_OF_THE_RIGHT_RACKET = -2; // right racket's width position. It is calculated by adding the width and this number.
	const int MINIMUM_BALL_POSITION_OUTSIDE_THE_FIELD = 1; // the minimum position of the ball to go beyond the boundaries of the field.
	const int PART_OF_THE_RACKET = 1; // the number responsible for the top and bottom of the racket
}