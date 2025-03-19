#include <iostream>
using namespace std;

class Work_with_rockets {
private:
    int position = 12;
    int check_up_rocket(int rocket) {
        if (rocket > 2) {
            rocket--;
        }
        return rocket;
    }

    int check_down_rocket(int rocket) {
        if (rocket < 22) {
            rocket++;
        }
        return rocket;
    }

public:
    int get_position() const { return position; }

    void move_left_rocket(char key) {
        if (key == 'a' || key == 'A') {
            position = check_up_rocket(position);
        }
        else if (key == 'z' || key == 'Z') {
            position = check_down_rocket(position);
        }
    }

    void move_right_rocket(char key) {
        if (key == 'k' || key == 'K') {
            position = check_up_rocket(position);
        }
        else if (key == 'm' || key == 'M') {
            position = check_down_rocket(position);
        }
    }

    void start_position() {
        position = 12;
    }
};



class Work_with_ball {
private:
   int position_ball_x = 12;
   int position_ball_y = 40;
public:
    int movement_ball(int position_ball, int movement_ball) {
        position_ball += movement_ball;
        return position_ball;
    }

    int touching_the_walls(int position_ball_x, int deviation_ball_x) {
        if (position_ball_x == 1 || position_ball_x == 23) {
            deviation_ball_x = -deviation_ball_x;
        }
        return deviation_ball_x;
    }

    int touching_the_rocket(int position_ball_x, int position_ball_y, int movement_ball, Work_with_rockets rocket) {
        if ((position_ball_y == 2 || position_ball_y == 77) && (position_ball_x == rocket.get_position() || position_ball_x == rocket.get_position() - 1 || position_ball_x == rocket.get_position() + 1)) {
            movement_ball = -movement_ball;
        }
        return movement_ball;
    }
    int start_position_x() {
        return position_ball_x;
    }
    int start_position_y() {
        return position_ball_y;
    }
};


void cleaner() {
    for (int i = 0; i < 10; i++) {
        cout << endl;
    }
}

int writting_field(Work_with_rockets left_rocket, Work_with_rockets right_rocket, int position_ball_x, int position_ball_y) {
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 80; j++) {
            if (i == 0 || i == 24) {
                cout << "-";
            }
            else if (j == 0 || j == 79 || j == 40) {
                cout << '|';
            }
            else if ((i == left_rocket.get_position() || i == left_rocket.get_position() - 1 || i == left_rocket.get_position() + 1) && j == 1) {
                cout << '|';
            }
            else if ((i == right_rocket.get_position() || i == right_rocket.get_position() - 1 || i == right_rocket.get_position() + 1) && j == 78) {
                cout << '|';
            }
            else if (i == position_ball_x && j == position_ball_y) {
                cout << 'o';
            }
            else {
                cout << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}

void check_win_player(int first_player) {
    if (first_player == 21) {
        cout << "Player 1 win!";
    }
    else {
        cout << "Player 2 Win!";
    }
}


int main() {
    Work_with_ball ball;
    Work_with_rockets left_rocket;
    Work_with_rockets right_rocket;
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
        writting_field( left_rocket,  right_rocket,  position_ball_x,  position_ball_y);
    }
    return 0;
}
