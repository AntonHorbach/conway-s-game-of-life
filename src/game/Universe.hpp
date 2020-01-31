#ifndef UNIVERSE_HPP
#define UNIVERSE_HPP

#include <vector>
#include <iostream>

class Cell;

class Universe {
    std::vector<std::vector<Cell*>> cells;
    std::string texture_id;

public:
    Universe(size_t h, size_t w, std::string&& texture_id);

    void init();
    void handleEvents();
    void draw();
    void update();

    ~Universe();
};

#endif