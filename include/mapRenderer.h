#ifndef MAP_RENDERER_H
#define MAP_RENDERER_H

#include "map.h"

class MapRenderer{
    public:
        MapRenderer();
        void draw(Map map) const;
};

#endif