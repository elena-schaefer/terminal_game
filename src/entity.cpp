#include "entity.h"

Entity::Entity() = default;

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

void Entity::initialize(bool is_found)
{
    this -> is_found = is_found;
}

void Entity::move(int newX, int newY)
{
    x = newX;
    y = newY;
}
