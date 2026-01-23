#include "player.h"

Player::Player() = default;

Player::Player(int x, int y)
    :   player_found(true)
{
    this -> x = x;
    this -> y = y;
}

bool Player::is_initialized() const
{
    return player_found;
}

int Player::get_x() const
{
    return x;
}

int Player::get_y() const
{
    return y;
}

void Player::move(int newX, int newY)
{
    x = newX;
    y = newY;
}
