#include "cell.hpp"

Cell::Cell(std::string&& texture_id_): texture_id(texture_id_) {}

size_t Cell::count() {
    size_t res = 0;

    for(size_t neighbor = (size_t)NEIGHBOR::UPPER;
        neighbor <= (size_t)NEIGHBOR::BOT_LEFT;
        ++neighbor)
    {
        if(neighbors[neighbor] != nullptr) {
            ++res;
        }
    }

    return res;
}

void Cell::draw(int x, int y, int scale) {
    Game::textureManager.drawTexture(texture_id,
                                    {0, 0, 1, 1},
                                    {x, y, scale * 3, scale * 3});
}