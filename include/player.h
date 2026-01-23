#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include <string>

class Player {

    private:
        int x;
        int y;
        bool player_found = false;

    public:
        Player();
        Player(int x, int y);

        bool is_initialized() const;

        int get_x() const;
        int get_y() const;
        void move(int newX, int newY);
};

#endif // PLAYER_H