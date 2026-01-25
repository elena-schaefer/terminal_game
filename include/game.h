#ifndef GAME_H
#define GAME_H

#include "map.h"
#include "player.h"
#include "mapRenderer.h"

class Game {

    private:
        bool playing;

        void init();

    public:
        Map map;
        Player player;
        MapRenderer map_renderer;

        Game();
        void update();
        void run();
};

#endif