#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
#include <vector>
#include <string>
#include "entity.h"
#include "player.h"

class Monster : public Entity{

    private:

    public:
        Monster();
        Monster(int x, int y);

        void decide_move(int player_x, int player_y);
};

#endif // MONSTER_H