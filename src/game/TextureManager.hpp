#ifndef TEXTURE_MANAGER_HPP
#define TEXTURE_MANAGER_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <string>
#include <memory>
#include <map>

#include "Game.hpp"

using sharedTexture = std::shared_ptr<SDL_Texture>;

sharedTexture makeSharedTexture(SDL_Texture* texture);

class TextureManager {
    std::map<std::string, sharedTexture> textures;

public:
    bool loadTexture(const std::string& path, const std::string& key);
    sharedTexture getTexture(const std::string& key);
    void drawTexture(const std::string& key, SDL_Rect srcrect,
                        SDL_Rect dstrect);
    void drawTexture(const sharedTexture& texture, SDL_Rect srcrect,
                        SDL_Rect dstrect);
};

#endif