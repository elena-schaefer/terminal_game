#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include <string>
#include "entity.h"

class Player : public Entity {

    private:
        bool moving;
        bool playing;

    public:
        Player();
        Player(int x, int y);

        void handle_input();
        bool is_moving();
        bool is_playing();
};

#endif // PLAYER_H