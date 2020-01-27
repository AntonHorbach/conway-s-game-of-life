#include <iostream>

#include "Game.hpp"

int main() {
    Game game;

    game.init("game of life", 300, 150, 640, 480);

    return game.exec();
}