#ifndef GAME_H
#define GAME_H

#include "map.h"
#include "monster.h"
#include "player.h"
#include "mapRenderer.h"

class Game {

    private:
        bool playing;

        void init();

    public:
        Map map;
        Monster monster;
        Player player;
        MapRenderer map_renderer;

        Game();
        void handle_input();
        void update(Entity& entity);
        void run();
};

#endif