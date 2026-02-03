#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
#include <vector>
#include <string>
#include "entity.h"

class Map;
class Player;

class Monster : public Entity{

    private:

    public:
        Monster();
        Monster(int x, int y);

        void decide_move(const Player& player, const Map& map) override;
};

#endif // MONSTER_H