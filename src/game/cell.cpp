#include "cell.hpp"

Cell::Cell(std::string&& texture_id_): texture_id(texture_id_) {}

size_t Cell::count() {
    size_t res = 0;

    for(size_t neighbor = (size_t)NEIGHBOR::UPPER;
        neighbor <= (size_t)NEIGHBOR::BOT_LEFT;
        ++neighbor)
    {
        if(neighbors[neighbor] != nullptr && neighbors[neighbor]->isAlive())
        {
            ++res;
        }
    }

    return res;
}

void Cell::setNeighbors(const std::initializer_list<Cell*>& neighbors) {
    size_t i = 0;

    for(Cell* n : neighbors) {
        this->neighbors[i++] = n;
        if(i == 8) break;
    }
}

void Cell::draw(int x, int y, int scale) {
    if(alive) {
        Game::textureManager.drawTexture(texture_id,
                                        {0, 0, 1, 1},
                                        {x, y, scale * 3, scale * 3});
    }
}

void Cell::reborn() {
    new_state ^= true;
}

bool Cell::isAlive() {
    return alive;
}

void Cell::update() {
    if(orthogenesis) {
        switch(count()) {
        case 2: break;
        case 3: {
            new_state = true;

            break;
        }
        default: {
            new_state = false;
            break;
        }
        }
    }
}

void Cell::commitState() {
    alive = new_state;
}

void Cell::handleEvents() {
    switch (Game::event.type)
    {
    case SDL_KEYDOWN: {
        if(Game::event.key.keysym.sym == SDLK_RETURN) {
            orthogenesis ^= true;
        }
        break;
    }
    default:
        break;
    }
}