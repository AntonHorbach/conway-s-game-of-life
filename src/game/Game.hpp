#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>

#include <SDL2/SDL.h>

#include "TextureManager.hpp"

class TextureManager;

class Game {
    SDL_Window* window;
    bool running;

    void handleEvents();
    void draw();
    void update();

public:
    Game();

    static SDL_Renderer* renderer;
    static SDL_Event event;
    static TextureManager textureManager;

    bool init(const char* title, size_t x, size_t y, size_t w, size_t h);
    int exec();

    ~Game();
};

#endif