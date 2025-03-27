#include "writting_field_and_another_function.h"
#include <iostream>

using namespace std;

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