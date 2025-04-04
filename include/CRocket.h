#ifndef ROCKET_H
#define ROCKET_H

class CRocket {  //a class that describes functions for working with rackets
private:
	int m_position;  // the variable responsible for the rockets position
	int m_check_up_rocket(int rocket);    // function declaration check_up_rocket
	int m_check_down_rocket(int rocket);  // function declaration check_down_rocket

public:
	CRocket(
		int value_Height);  // declaration class constructor Work_with_rockets
	int get_position() const;  // function declaration get_position
	void move_left_rocket(char key);  // function declaration move_left_rocket
	void move_right_rocket(char key);  // function declaration move_right_rocket
	void reset_Position();             // function declaration start_position
};
#endif