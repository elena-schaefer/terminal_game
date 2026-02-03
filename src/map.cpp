#include "map.h"
#include "monster.h"
#include "player.h"
#include "symbol.hpp"
#include "spawnPoint.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

Map::Map(){
    width = 0;
    height = 0;
}

bool Map::load_from_file(){

    std::string line;
    std::ifstream Map("assets/map.txt");

    if(Map){
        while (getline (Map, line)) {
            // save map
            map_vector.push_back(line);
        }

        Map.close();

        width = map_vector[0].size();
        height = map_vector.size();

        return true;
    }

    std::cerr << "Map can't be loaded." << std::endl;
    return false;
}

std::vector<SpawnPoint> Map::collect_spawn_points() const
{
    std::vector<SpawnPoint> spawn_points;
    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
            char symbol = get_field(x, y);
            if (symbol == symbol::PLAYER || symbol == symbol::MONSTER){ 
                spawn_points.push_back({symbol, x, y});
            }
        }
    }
    return spawn_points;
}

bool Map::is_accessable(int x, int y) const{
    // check for borders & collisions
    if (0 > x || x >= width || 
        0 > y || y >= height){
        return false;
    }
    if (map_vector[y][x] == symbol::WALL){
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

const std::vector<std::string>& Map::get_map() const
{
    return map_vector;
}
