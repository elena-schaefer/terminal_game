#include "monster.h"

Monster::Monster() = default;

Monster::Monster(int x, int y)
{
    this -> x = x;
    this -> y = y;
    initialize(true);
}

void Monster::decide_move(int player_x, int player_y)
{
    int distance_x = player_x - x;
    int distance_y = player_y - y;

    if (distance_x > distance_y)
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