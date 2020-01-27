#include "Game.hpp"

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

Game::Game(): running(false) {}

bool Game::init(const char* title, size_t x, size_t y, size_t w, size_t h)
{
    bool res = true;

    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << SDL_GetError() << std::endl;
        res = false;
    }

    window = SDL_CreateWindow(title, x, y, w, h, SDL_WINDOW_SHOWN);
    if(res && !window) {
        std::cout << SDL_GetError() << std::endl;
        res = false;
    }

    renderer = SDL_CreateRenderer(window, -1,
                SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(res && !renderer) {
        std::cout << SDL_GetError() << std::endl;
        res = false;
    }

    if(res) {
        running = true;
        SDL_SetRenderDrawColor(renderer, 123, 123, 123, 255);
    }

    return res;
}

void Game::handleEvents() {
    while(SDL_PollEvent(&event)) {
        switch (event.type)
        {
        case SDL_QUIT:
            running = false;
            break;
        
        default:
            break;
        }
    }
}

void Game::draw() {
    SDL_RenderClear(renderer);


    SDL_RenderPresent(renderer);
}

void Game::update() {
    std::cout << "Updating" << std::endl;
}

int Game::exec() {
    while(running) {
        draw();
        handleEvents();
        update();
    }

    return 0;
}

Game::~Game() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}