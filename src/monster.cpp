#include "monster.h"

Monster::Monster() = default;

Monster::Monster(int x, int y)
{
    this -> x = x;
    this -> y = y;
    set_is_found(true);
}