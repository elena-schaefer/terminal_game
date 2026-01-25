#include "player.h"

Player::Player() = default;

Player::Player(int x, int y)
{
    this -> x = x;
    this -> y = y;
    initialize(true); // still necessary with playing?
}

void Player::set_input(int dx, int dy)
{
    this -> dx = dx;
    this -> dy = dy;
}

void Player::set_moving(bool moving)
{
    this -> moving = moving;
}


bool Player::is_moving()
{
    return moving;
}
