#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>
#include "player.h"

class Map {
    private:
        std::vector<std::string> map_vector;
        int width;
        int height;
    
    public:
        Map();
        void load_from_file();
        Player spawn_player();
        bool is_accessable(int x, int y) const;
        char get_field(int x, int y) const;
        void set_field(int x, int y, char symbol);
        int get_width() const;
        int get_height() const;
        std::vector<std::string> get_map() const;
};

#endif // MAP_H