#ifndef BALL_H
#define BALL_H
#include "rocket.h"

class Work_with_ball {
private:
    int position_ball_x;
    int position_ball_y;
public:
    Work_with_ball(int start_x, int start_y);

    int movement_ball(int position_ball, int movement_ball);


    int touching_the_walls(int position_ball_x, int deviation_ball_x);



    int touching_the_rocket(int position_ball_x, int position_ball_y, int& movement_ball, Work_with_rockets rocket);


    int start_position_x();


    int start_position_y();


};
#endif
