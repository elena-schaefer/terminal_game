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
    : dx(0),
      dy(0),
      playing(true),
      move(false)
{

}

void Game::handle_input()
{
    char user_input = getch();

    move = true;

    switch(user_input) {
        case 'w':
        case 'W':
            dx = 0;
            dy = -1;
            break;
        case 's':
        case 'S':
            dx = 0;
            dy = 1;
            break;
        case 'a':
        case 'A':
            dx = -1;
            dy = 0;
            break;
        case 'd':
        case 'D':
            dx = 1;
            dy = 0;
            break;
        case 'q':
        case 'Q':
            std::cout << "Quitting game" << '\n';
            playing = false;
            move = false;
            break;
        default:        // invalid input
            move = false;
            break;
    }; 
}

void Game::update()
{
    // calculate new position
    int newX = player.get_x() + dx;
    int newY = player.get_y() + dy;

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

        handle_input();

        if (move){
            update();
        }
    }
}
