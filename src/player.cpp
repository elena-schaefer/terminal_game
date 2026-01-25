#include "player.h"

#include <conio.h>

Player::Player() = default;

Player::Player(int x, int y)
{
    this -> x = x;
    this -> y = y;
    playing = true;
    initialize(true); // still necessary with playing?
}

void Player::handle_input()
{
    char user_input = getch();

    moving = true;

    switch(user_input) {
        case 'w':
        case 'W':
            dx = 0;
            dy = -1;
            break;
        case 's':
        case 'S':
            dx = 0;
            dy = 1;
            break;
        case 'a':
        case 'A':
            dx = -1;
            dy = 0;
            break;
        case 'd':
        case 'D':
            dx = 1;
            dy = 0;
            break;
        case 'q':
        case 'Q':
            std::cout << "Quitting game" << '\n';
            playing = false;
            moving = false;
            break;
        default:        // invalid input
            moving = false;
            break;
    }; 
}

bool Player::is_moving()
{
    return moving;
}

bool Player::is_playing()
{
    return playing;
}
