#ifndef ROCKET_H
#define ROCKET_H

class Work_with_rockets {  //a class that describes functions for working with rackets
private:
	int position;  // the variable responsible for the rockets position
	int check_up_rocket(int rocket);    // function declaration check_up_rocket
	int check_down_rocket(int rocket);  // function declaration check_down_rocket

public:
	Work_with_rockets(
		int value_Height);  // declaration class constructor Work_with_rockets
	int get_position() const;  // function declaration get_position
	void move_left_rocket(char key);  // function declaration move_left_rocket
	void move_right_rocket(char key);  // function declaration move_right_rocket
	void start_position();             // function declaration start_position
};
#endif
