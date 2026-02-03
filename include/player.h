#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include <string>
#include "entity.h"

class Player : public Entity {

    private:
        bool moving;

    public:
        Player();
        Player(int x, int y);

        void set_input(int dx, int dy);
        void set_moving(bool moving);
        bool is_moving();

        void decide_move(const Player& player, const Map& map) override;
};

#endif // PLAYER_H