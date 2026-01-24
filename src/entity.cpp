#include "entity.h"

Entity::Entity() = default;

Entity::Entity(int x, int y)
    :   is_found(true)
{
    this -> x = x;
    this -> y = y;
}

bool Entity::is_initialized() const
{
    return is_found;
}

int Entity::get_x() const
{
    return x;
}

int Entity::get_y() const
{
    return y;
}

void Entity::set_is_found(bool is_found)
{
    this -> is_found = is_found;
}

void Entity::move(int newX, int newY)
{
    x = newX;
    y = newY;
}
