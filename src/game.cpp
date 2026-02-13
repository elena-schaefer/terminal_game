#include "game.h"
#include "map.h"
#include "player.h"
#include "mapRenderer.h"
#include "symbol.hpp"
#include "spawnPoint.hpp"

#include <conio.h>
#include <memory>

void Game::init()
{
    // open file
    if (map.load_from_file())
    {
        init_entities();
        item_amount = map.collect_items();
    }
    else
    {
        playing = false;
    }
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
            player = std::make_unique<Player>(spawn.x, spawn.y);
        }
        if (spawn.symbol == symbol::MONSTER) 
        {
            monsters.push_back(std::make_unique<Monster>(spawn.x, spawn.y)); 
        }
    }

    if (!player){
        playing = false;
        std::cerr << "No Player found." << std::endl;
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

void Game::collision_check(Monster& monster)
{
    // calculate new position
    int newX = monster.get_x() + monster.get_dx();
    int newY = monster.get_y() + monster.get_dy();

    bool on_item = monster.get_on_item();
    monster.set_on_item(false);

    if (!map.is_accessible(newX, newY))
    {
        return;
    }

    char field = map.get_field(newX, newY);
        
    switch (field)
    {
        case symbol::ITEM:
            monster.set_on_item(true);
            break;
        case symbol::MONSTER:
            return;
        case symbol::PLAYER:
            game_over(monster, newX, newY);
            return;
    }
    update(monster, newX, newY, on_item);
}

void Game::collision_check(Player& player)
{
    // calculate new position
    int newX = player.get_x() + player.get_dx();
    int newY = player.get_y() + player.get_dy();

    if (!map.is_accessible(newX, newY))
    {
        return;
    }

    char field = map.get_field(newX, newY);
    if (field == symbol::MONSTER)
    {
        game_over(player, newX, newY);
        return;
    }
    else if (field == symbol::ITEM)
    {
        player.collect_item(item_amount);
    }
    
    update(player, newX, newY);
}

void Game::update(Entity& entity, int newX, int newY, bool monster_on_item){
    // Update map and entity coordinates
    char symbol = (monster_on_item == true) ? symbol::ITEM : symbol::FLOOR;
    map.set_field(entity.get_x(), entity.get_y(), symbol);
    map.set_field(newX, newY, entity.get_symbol());

    entity.move(newX, newY);
    entity.reset_move();
}

void Game::game_over(Entity& entity, int newX, int newY){
    map.set_field(entity.get_x(), entity.get_y(), symbol::FLOOR);
    map.set_field(newX, newY, symbol::DEAD);
    map_renderer.draw(map);
    playing = false;
}

void Game::run()
{
    init();

    while (playing){
 
        map_renderer.draw(map);

        handle_input();

        if (player->is_moving()){

            collision_check(*player);
            if (item_amount == 0)
            {
                map_renderer.draw(map);
                return;
            }
            for (auto& monsti : monsters)
            {
                monsti->decide_move(*player, map);
                collision_check(*monsti);
                if (!playing){
                    return;
                }
            }
        }
    }
}
