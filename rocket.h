#ifndef ROCKET_H
#define ROCKET_H

class Work_with_rockets {
private:
    int position;
    int check_up_rocket(int rocket);
    int check_down_rocket(int rocket);


public:
    Work_with_rockets(int value_Height); // конструктор, в котором можно задать размер матрицы

    int get_position() const;

    void move_left_rocket(char key);


    void move_right_rocket(char key);


    void start_position();

};
#endif

