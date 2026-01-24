#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include <string>
#include "entity.h"

class Player : public Entity {

    private:

    public:
        Player();
        Player(int x, int y);
};

#endif // PLAYER_H