#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <vector>
#include <string>

class Entity {

    protected:
        char symbol;
        int x = 0;
        int y = 0;
        int dx = 0;
        int dy = 0;
        bool is_found = false;

    public:
        Entity();

        bool is_initialized() const;

        char get_symbol() const;
        int get_x() const;
        int get_y() const;
        int get_dx() const;
        int get_dy() const;

        void reset_move();
        void move(int newX, int newY);
};

#endif // ENTITY_H