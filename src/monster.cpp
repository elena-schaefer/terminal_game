#include <cmath>
#include "monster.h"
#include "map.h"
#include "player.h"
#include "symbol.hpp"

Monster::Monster() = default;

Monster::Monster(int x, int y)
{
    symbol = symbol::MONSTER;
    this -> x = x;
    this -> y = y;
    is_found = true;
}

void Monster::decide_move(const Player& player, const Map& map)
{
    int distance_x = player.get_x() - x;
    int distance_y = player.get_y() - y;

    if (abs(distance_x) > abs(distance_y))
    {
        dy = 0;
        dx = (distance_x > 0) ? 1 : -1;
    }
    else
    {
        dx = 0;
        dy = (distance_y > 0) ? 1 : -1;
    }

    // calculate new position
    int newX = x + dx;
    int newY = y + dy;
    
    if (!map.is_accessable(newX, newY)){
        if (abs(distance_x) < abs(distance_y))
        {
            dy = 0;
            dx = (distance_x > 0) ? 1 : -1;
        }
        else
        {
            dx = 0;
            dy = (distance_y > 0) ? 1 : -1;
        }
    }
}