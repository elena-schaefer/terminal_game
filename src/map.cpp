#include "map.h"
#include "monster.h"
#include "player.h"
#include "symbol.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

Map::Map(){
    width = 0;
    height = 0;
}

void Map::load_from_file(){

    std::string line;
    std::ifstream Map("assets/map.txt");

    while (getline (Map, line)) {
        // save map
        map_vector.push_back(line);
    }

    Map.close();

    width = map_vector[0].size();
    height = map_vector.size();
}

Player Map::spawn_player()
{
    for (int x = 0; x < width; x++){
        for (int y = 0; y < height; y++){
            if (get_field(x, y) == config::PLAYER){ 
                return Player(x, y);
            }
        }
    }
    return Player();
}

Monster Map::spawn_monster() // mit player zusammen ?
{
    for (int x = 0; x < width; x++){
        for (int y = 0; y < height; y++){
            if (get_field(x, y) == config::MONSTER){ 
                return Monster(x, y);
            }
        }
    }
    return Monster();
}

bool Map::is_accessable(int x, int y) const{
    // check for borders & collisions
    if (0 > x || x >= width || 
        0 > y || y >= height){
        return false;
    }
    if (map_vector[y][x] == config::WALL){
        return false;
    }
    return true;
}

char Map::get_field(int x, int y) const{
    return map_vector[y][x];
}

void Map::set_field(int x, int y, char symbol){
    map_vector[y][x] = symbol;
}

int Map::get_width() const{
    return width;
}

int Map::get_height() const{
    return height;
}

std::vector<std::string> Map::get_map() const
{
    return map_vector;
}
