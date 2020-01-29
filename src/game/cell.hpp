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
    bool alive = false;
    bool orthogenesis = false;

public:
    Cell(std::string&& texture_id);
    
    size_t count();
    void reborn();
    bool isAlive();
    void setNeighbors(const std::initializer_list<Cell*>& neighbors);
    void draw(int x, int y, int scale);
    void handleEvents();
    void update();
};

#endif