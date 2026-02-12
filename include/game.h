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
        std::vector<std::unique_ptr<Monster>> monsters;
        std::unique_ptr<Player> player;
        MapRenderer map_renderer;

        int item_amount = 0;


        Game();
        void init_entities();
        void handle_input();
        void collission_check(Monster& monster);
        void collission_check(Player& player);
        void update(Entity& entity, int newX, int newY, bool monster_on_item = false);
        void game_over(Entity& entity, int newX, int newY);
        void run();
};

#endif