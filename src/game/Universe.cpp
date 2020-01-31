#include "Universe.hpp"

#include "cell.hpp"

Universe::Universe(size_t h, size_t w, std::string&& texture_id_)
                    :texture_id(texture_id_)
{
    cells.reserve(h);

    for(size_t i = 0; i < h; ++i) {
        cells.push_back(std::vector<Cell*>());
        cells[i].reserve(w);

        for(size_t j = 0; j < w; ++j) {
            cells[i].push_back(new Cell("cell"));
        }
    }

    init();
}

void Universe::init() {
    for(size_t i = 0; i < cells.size(); ++i) {
        for(size_t j = 0; j < cells[i].size(); ++j) {
            if(i == 0 && j == 0) {
                cells[i][j]->setNeighbors(
                    {nullptr, cells[i + 1][j], nullptr, cells[i][j + 1],
                    nullptr, nullptr, cells[i + 1][j + 1], nullptr}
                );
            }
            else if(i == 0 && j == cells[i].size() - 1) {
                cells[i][j]->setNeighbors(
                    {nullptr, cells[i + 1][j], cells[i][j - 1],
                    nullptr, nullptr, nullptr,
                    nullptr, cells[i + 1][j - 1]}
                );
            }
            else if(i == 0 && j != 0 && j != cells[i].size() - 1) {
                cells[i][j]->setNeighbors(
                    {nullptr, cells[i + 1][j], cells[i][j - 1],
                    cells[i][j + 1], nullptr, nullptr,
                    cells[i + 1][j + 1], cells[i + 1][j - 1]}
                );
            }
            else if(i == cells.size() - 1 && j == 0) {
                cells[i][j]->setNeighbors(
                    {cells[i - 1][j], nullptr, nullptr,
                    cells[i][j + 1], cells[i - 1][j + 1],
                    nullptr, nullptr, nullptr}
                );
            }
            else if(i == cells.size() - 1 && j == cells[i].size() - 1) {
                cells[i][j]->setNeighbors(
                    {cells[i - 1][j], nullptr, cells[i][j - 1],
                    nullptr, nullptr, cells[i - 1][j - 1],
                    nullptr, nullptr}
                );
            }
            else if(i == cells.size() - 1 && j != 0
                    && j != cells[i].size() - 1)
            {
                cells[i][j]->setNeighbors(
                    {cells[i - 1][j], nullptr, cells[i][j - 1],
                    cells[i][j + 1], cells[i - 1][j + 1],
                    cells[i - 1][j - 1], nullptr, nullptr}
                );
            }
            else if(i != 0 && i != cells.size() - 1 && j == 0) {
                cells[i][j]->setNeighbors(
                    {cells[i - 1][j], cells[i + 1][j], nullptr,
                    cells[i][j + 1], cells[i - 1][j + 1],
                    nullptr, cells[i + 1][j + 1], nullptr}
                );
            }
            else if(i != 0 && i != cells.size() - 1
                    && j == cells[i].size() - 1)
            {
                cells[i][j]->setNeighbors(
                    {cells[i - 1][j], cells[i + 1][j], cells[i][j - 1],
                    nullptr, nullptr, cells[i - 1][j - 1], nullptr,
                    cells[i + 1][j - 1]}
                );
            }
            else {
                cells[i][j]->setNeighbors(
                    {cells[i - 1][j], cells[i + 1][j], cells[i][j - 1],
                    cells[i][j + 1], cells[i - 1][j + 1],
                    cells[i - 1][j - 1], cells[i + 1][j + 1],
                    cells[i + 1][j - 1]}
                );
            }
        }
    }
}

void Universe::handleEvents() {
    switch (Game::event.type)
    {
    case SDL_MOUSEBUTTONDOWN: {
        size_t x = Game::event.button.x / 10;
        size_t y = Game::event.button.y / 10;

        if(x >= 0 && x < cells[0].size() && y >= 0 && y < cells.size()) {
            cells[y][x]->reborn();
        }

        break;
    }
    default:
        for(auto& row : cells) {
            for(Cell* cell : row) {
                cell->handleEvents();
            }
        }

        break;
    }
}

void Universe::update() {
    for(auto& row : cells) {
        for(Cell* cell : row) {
            cell->update();
        }
    }

    for(auto& row : cells) {
        for(Cell* cell : row) {
            cell->commitState();
        }
    }
}

void Universe::draw() {
    for(size_t i = 0; i < cells.size(); ++i) {
        for(size_t j = 0; j < cells[i].size(); ++j) {

            Game::textureManager.drawTexture(texture_id, {0, 0, 27, 27},
                                        {(int)(j * 10), (int)(i * 10), 10, 10});
            
            cells[i][j]->draw(j * 10, i * 10, (10 - 1) / 3);
        }
    }
}

Universe::~Universe() {
    for(auto& row : cells) {
        for(Cell* cell : row) {
            delete cell;
        }
    }
}