#include "player.h"
#include "symbol.hpp"

Player::Player() = default;

Player::Player(int x, int y)
{
    symbol = symbol::PLAYER;
    this -> x = x;
    this -> y = y;
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


bool Player::is_moving() const
{
    return moving;
}

void Player::collect_item(int& item_amount)
{
    item_amount --;
}

