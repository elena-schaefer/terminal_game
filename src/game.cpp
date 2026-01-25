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
}

Game::Game()
    : playing(true)
{

}

void Game::update()
{
    // calculate new position
    int newX = player.get_x() + player.get_dx();
    int newY = player.get_y() + player.get_dy();

    if (map.is_accessable(newX, newY)){
        // Update map and player coordinates
        map.set_field(player.get_x(), player.get_y(), config::FLOOR);
        map.set_field(newX, newY, config::PLAYER);

        player.move(newX, newY);
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

        player.handle_input();

        playing = player.is_playing();

        if (player.is_moving()){
            update();
        }
    }
}
