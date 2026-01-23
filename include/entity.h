#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <vector>
#include <string>

class Entity {

    private:
        int x;
        int y;
        bool is_found = false;

    public:
        Entity();
        Entity(int x, int y);

        bool is_initialized() const;
        bool is_alive() const;

        int get_x() const;
        int get_y() const;
        void move(int newX, int newY);
};

#endif // ENTITY_H