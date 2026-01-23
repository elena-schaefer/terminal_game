#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
#include <vector>
#include <string>

class Monster{

    private:
        int x;
        int y;
        bool monster_found = false;

    public:
        Monster();
        Monster(int x, int y);

        bool is_initialized() const;

        int get_x() const;
        int get_y() const;
        void move(int newX, int newY);
};

#endif // MONSTER_H