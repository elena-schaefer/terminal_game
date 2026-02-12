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
        bool on_item = false;

    public:
        Monster();
        Monster(int x, int y);

        void decide_move(const Player& player, const Map& map);
        bool get_on_item() const;
        void set_on_item(bool on_item);
};

#endif // MONSTER_H