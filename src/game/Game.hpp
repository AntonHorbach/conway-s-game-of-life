#include <iostream>

#include <SDL2/SDL.h>

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

    bool init(const char* title, size_t x, size_t y, size_t w, size_t h);
    int exec();

    ~Game();
};