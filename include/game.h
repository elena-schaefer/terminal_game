#ifndef GAME_H
#define GAME_H

#include "map.h"
#include "monster.h"
#include "player.h"
#include "mapRenderer.h"

#include <memory>

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
        void collission_check(Entity& entity);
        void update(Entity& entity, int newX, int newY);
        void game_over(Entity& entity, int newX, int newY);
        void run();
};

#endif