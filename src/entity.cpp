#include "entity.h"

Entity::Entity() = default;

bool Entity::is_initialized() const
{
    return is_found;
}

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

void Entity::decide_move(int player_x, int player_y)
{

}

void Entity::reset_move()
{
    dx = 0;
    dy = 0;
}

void Entity::initialize(bool is_found)
{
    this -> is_found = is_found;
}

void Entity::move(int newX, int newY)
{
    x = newX;
    y = newY;
}
