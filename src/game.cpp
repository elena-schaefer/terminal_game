#include "game.h"
#include "map.h"
#include "player.h"
#include "mapRenderer.h"
#include "symbol.hpp"

#include <conio.h>

void Game::init()
{
    // open file
    map.load_from_file(); // without error handling

    player = map.spawn_player();
    monster = map.spawn_monster();
}

Game::Game()
    : playing(true)
{
}

void Game::handle_input()
{
    char user_input = getch();

    player.set_moving(true);

    switch(user_input) {
        case 'w':
        case 'W':
            player.set_input(0, -1);
            break;
        case 's':
        case 'S':
            player.set_input(0, 1);
            break;
        case 'a':
        case 'A':
            player.set_input(-1, 0);
            break;
        case 'd':
        case 'D':
            player.set_input(1, 0);
            break;
        case 'q':
        case 'Q':
            std::cout << "Quitting game" << '\n';
            playing = false;
            player.set_moving(false);
            break;
        default:        // invalid input
            player.set_moving(false);
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
        map.set_field(entity.get_x(), entity.get_y(), config::FLOOR);
        map.set_field(newX, newY, entity.get_symbol());

        entity.move(newX, newY);
        entity.reset_move();
    }
}

void Game::run()
{
    init();

    if (!player.is_initialized()){
        playing = false;
        std::cerr << "No Player found.";
    }

    while (playing){
 
        map_renderer.draw(map);

        handle_input();

        if (player.is_moving()){
            update(player);
            monster.decide_move(player.get_x(), player.get_y());
            update(monster);
        }
    }
}
