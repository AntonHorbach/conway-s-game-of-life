#ifndef CELL_HPP
#define CELL_HPP

#include <iostream>
#include <string>

#include "Game.hpp"
#include "TextureManager.hpp"

enum class NEIGHBOR: size_t {
    UPPER = 0, LOWER, LEFT, RIGHT, TOP_RIGHT, TOP_LEFT, BOT_RIGHT, BOT_LEFT
};

class Cell {
    std::string texture_id;
    Cell* neighbors[8];

public:
    Cell(std::string&& texture_id);
    
    size_t count();
    void draw(int x, int y, int scale);
};

#endif