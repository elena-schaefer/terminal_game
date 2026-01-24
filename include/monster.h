#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
#include <vector>
#include <string>
#include "entity.h"

class Monster : public Entity{

    private:

    public:
        Monster();
        Monster(int x, int y);
};

#endif // MONSTER_H