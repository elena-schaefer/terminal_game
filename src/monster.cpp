#include <cmath>
#include <array>
#include <algorithm>
#include <vector>

#include "monster.h"
#include "map.h"
#include "player.h"
#include "symbol.hpp"

Monster::Monster() = default;

Monster::Monster(int x, int y)
{
    symbol = symbol::MONSTER;
    this -> x = x;
    this -> y = y;
    is_found = true;
}

void Monster::decide_move(const Player& player, const Map& map)
{
    struct Option {
        int dx;
        int dy;
        int score;
    };

    std::vector<Option> options;

    const int px = player.get_x();
    const int py = player.get_y();

    const std::array<std::pair<int, int>, 4> directions {{
        { 1, 0}, { -1, 0}, { 0, 1}, { 0, -1}
    }};

    for (const auto& direction : directions)
    {
        if (map.is_accessable(x + direction.first, y + direction.second))
        {
            int new_x = x + direction.first;
            int new_y = y + direction.second;

            int score = std::abs(px - new_x) + std::abs(py - new_y);
    
            options.push_back({
                                direction.first,
                                direction.second,
                                score
                            });
        }
    }

    auto best = std::min_element(
        options.begin(),
        options.end(),
        [](const Option& a, const Option& b){
            return a.score < b.score;
        }
    );

    dx = best->dx;
    dy = best->dy;
}

bool Monster::get_on_item() const
{
    return on_item;
}

void Monster::set_on_item(bool on_item){
    this->on_item = on_item;
}