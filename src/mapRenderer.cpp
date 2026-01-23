#include "mapRenderer.h"

MapRenderer::MapRenderer()
{
}

void MapRenderer::draw(Map map) const
{
    // clear console
    std::cout << "\033[2J\033[H";

    // print map
    for (int entry = 0; entry < map.get_map().size(); entry++){
        std::cout << map.get_map()[entry] << '\n';
    }
}