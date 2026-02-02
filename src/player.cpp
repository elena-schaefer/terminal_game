#include "player.h"
#include "symbol.hpp"

Player::Player() = default;

Player::Player(int x, int y)
{
    symbol = symbol::PLAYER;
    this -> x = x;
    this -> y = y;
    is_found = true;
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
