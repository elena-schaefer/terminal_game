#include "player.h"

Player::Player() = default;

Player::Player(int x, int y)
{
    this -> x = x;
    this -> y = y;
    initialize(true);
}