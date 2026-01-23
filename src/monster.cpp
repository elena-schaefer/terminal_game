#include "monster.h"

Monster::Monster() = default;

Monster::Monster(int x, int y)
    :   monster_found(true)
{
    this -> x = x;
    this -> y = y;
}

bool Monster::is_initialized() const
{
    return monster_found;
}

int Monster::get_x() const
{
    return x;
}

int Monster::get_y() const
{
    return y;
}

void Monster::move(int newX, int newY)
{
    x = newX;
    y = newY;
}
