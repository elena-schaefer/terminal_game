#include "game.h"
#include "map.h"
#include "player.h"
#include "mapRenderer.h"
#include "symbol.hpp"
#include "spawnPoint.hpp"

#include <conio.h>

void Game::init()
{
    // open file
    map.load_from_file(); // without error handling
}

Game::Game()
    : playing(true)
{
}

void Game::init_entities()
{
    std::vector<SpawnPoint> spawn_point_vector = map.collect_spawn_points();

    for (const SpawnPoint& spawn : spawn_point_vector)
    {
        if (spawn.symbol == symbol::PLAYER) 
        {
            std::unique_ptr<Player> p = std::make_unique<Player>(spawn.x, spawn.y);
            player = p.get();
            entities.push_back(std::move(p));
        }
        if (spawn.symbol == symbol::MONSTER) 
        {
            entities.push_back(std::make_unique<Monster>(spawn.x, spawn.y));
            break;
        }
    }
}

void Game::handle_input()
{
    char user_input = getch();

    player->set_moving(true);

    switch(user_input) {
        case 'w':
        case 'W':
            player->set_input(0, -1);
            break;
        case 's':
        case 'S':
            player->set_input(0, 1);
            break;
        case 'a':
        case 'A':
            player->set_input(-1, 0);
            break;
        case 'd':
        case 'D':
            player->set_input(1, 0);
            break;
        case 'q':
        case 'Q':
            std::cout << "Quitting game" << '\n';
            playing = false;
            player->set_moving(false);
            break;
        default:        // invalid input
            player->set_moving(false);
            break;
    }; 
}

void Game::update(Entity& entity) // Objekt wird genutzt statt kopie
{
    // calculate new position
    int newX = entity.get_x() + entity.get_dx();
    int newY = entity.get_y() + entity.get_dy();

    if (map.is_accessable(newX, newY)){
        // Update map and entity coordinates
        map.set_field(entity.get_x(), entity.get_y(), symbol::FLOOR);
        map.set_field(newX, newY, entity.get_symbol());

        entity.move(newX, newY);
        entity.reset_move();
    }
}

void Game::run()
{
    init();
    init_entities();


    if (!player->is_initialized()){
        playing = false;
        std::cerr << "No Player found.";
    }

    while (playing){
 
        map_renderer.draw(map);

        handle_input();

        if (player->is_moving()){

            for (std::unique_ptr<Entity>& entity : entities)
            {
                entity->decide_move(*player, map);
                update(*entity);
            }
        }
    }
}
