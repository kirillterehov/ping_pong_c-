#include "ball.h"

Work_with_ball::Work_with_ball(int start_x, int start_y) :
    position_ball_x(start_x),
    position_ball_y(start_y) {
}

int Work_with_ball::movement_ball(int position_ball, int movement_ball) {
    position_ball += movement_ball;
    return position_ball;
}

int Work_with_ball::touching_the_walls(int position_ball_x, int deviation_ball_x) {
    if (position_ball_x == 1 || position_ball_x == 23) {
        deviation_ball_x = -deviation_ball_x;
    }
    return deviation_ball_x;
}

int Work_with_ball::touching_the_rocket(int position_ball_x, int position_ball_y, int& movement_ball, Work_with_rockets rocket) {
    if ((position_ball_y == 2 || position_ball_y == 77) && (position_ball_x == rocket.get_position() || position_ball_x == rocket.get_position() - 1 || position_ball_x == rocket.get_position() + 1)) {
        movement_ball = -movement_ball;
    }
    return movement_ball;
}
int Work_with_ball::start_position_x() {
    return position_ball_x;
}
int Work_with_ball::start_position_y() {
    return position_ball_y;
}