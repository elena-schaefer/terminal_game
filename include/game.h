#ifndef GAME_H
#define GAME_H

#include "map.h"
#include "player.h"
#include "mapRenderer.h"

class Game {

    private:
        int dx;
        int dy;
        bool playing;
        bool move;

        void init();

    public:
        Map map;
        Player player;
        MapRenderer map_renderer;

        Game();
        void handle_input();
        void update();
        void run();
};

#endif