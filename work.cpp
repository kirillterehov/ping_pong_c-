#include <iostream>
#include "ball.h"
#include "writting_field_and_another_function.h"
using namespace std;

void work() {
    Work_with_ball ball(12, 40);
    Work_with_rockets left_rocket(12);
    Work_with_rockets right_rocket(12);
    int first_player = 0;
    int second_player = 0;
    int position_ball_x = 12;
    int position_ball_y = 40;
    int deviation_ball_x = 1;
    int deviation_ball_y = -1;
    while (first_player <= 21 || second_player <= 21) {
        if ((first_player == 21) || (second_player == 21)) {
            check_win_player(first_player);
            break;
        }
        char key = getchar();
        while (getchar() != '\n')
            ;
        if (key == 'a' || key == 'z' || key == 'A' || key == 'Z' || key == 'k' || key == 'm' || key == 'K' ||
            key == 'M') {
            left_rocket.move_left_rocket(key);
            right_rocket.move_right_rocket(key);
        }
        position_ball_x = ball.movement_ball(position_ball_x, deviation_ball_x);
        position_ball_y = ball.movement_ball(position_ball_y, deviation_ball_y);
        deviation_ball_x = ball.touching_the_walls(position_ball_x, deviation_ball_x);
        deviation_ball_y = ball.touching_the_rocket(position_ball_x, position_ball_y, deviation_ball_y, left_rocket);
        deviation_ball_y = ball.touching_the_rocket(position_ball_x, position_ball_y, deviation_ball_y, right_rocket);
        if (position_ball_y + deviation_ball_y > 79 || position_ball_y + deviation_ball_y < 1) {
            if (position_ball_y + deviation_ball_y > 79) {
                first_player++;
            }
            else if (position_ball_y + deviation_ball_y < 1) {
                second_player++;
            }
            position_ball_x = ball.start_position_x();
            position_ball_y = ball.start_position_y();
            left_rocket.start_position();
            right_rocket.start_position();
        }
        cleaner();
        cout << "first player score: " << first_player << " " << "second player score: " << second_player << endl;
        writting_field(left_rocket, right_rocket, position_ball_x, position_ball_y);
    }
}