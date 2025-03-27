#include "rocket.h"

Work_with_rockets::Work_with_rockets(int position_rocket) :
    position(position_rocket) {

}

int Work_with_rockets::check_up_rocket(int rocket) {
    if (rocket > 2) {
        rocket--;
    }
    return rocket;
}

int Work_with_rockets::check_down_rocket(int rocket) {
    if (rocket < 22) {
        rocket++;
    }
    return rocket;
}

int Work_with_rockets::get_position() const { return position; }

void Work_with_rockets::move_left_rocket(char key) {
    if (key == 'a' || key == 'A') {
        position = check_up_rocket(position);
    }
    else if (key == 'z' || key == 'Z') {
        position = check_down_rocket(position);
    }
}

void Work_with_rockets::move_right_rocket(char key) {
    if (key == 'k' || key == 'K') {
        position = check_up_rocket(position);
    }
    else if (key == 'm' || key == 'M') {
        position = check_down_rocket(position);
    }
}

void Work_with_rockets::start_position() {
    position = 12;
}