#include "entity.h"

Entity::Entity() = default;

char Entity::get_symbol() const
{
    return symbol;
}

int Entity::get_x() const
{
    return x;
}

int Entity::get_y() const
{
    return y;
}

int Entity::get_dx() const
{
    return dx;
}

int Entity::get_dy() const
{
    return dy;
}

void Entity::reset_move()
{
    dx = 0;
    dy = 0;
}

void Entity::move(int newX, int newY)
{
    x = newX;
    y = newY;
}
