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
        Player* player = nullptr;
        std::vector<std::unique_ptr<Entity>> entities;
        MapRenderer map_renderer;

        Game();
        void init_entities();
        void handle_input();
        void update(Entity& entity);
        void run();
};

#endif