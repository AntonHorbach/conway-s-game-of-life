#include "TextureManager.hpp"

sharedTexture makeSharedTexture(SDL_Texture* texture) {
    return {texture, SDL_DestroyTexture};
}

bool TextureManager::loadTexture(const std::string& path,
                                const std::string& key)
{
    bool res = true;
    SDL_Surface* surface  = IMG_Load(path.c_str());

    if(!surface) {
        std::cout << SDL_GetError() << std::endl;
        res = false;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer,
                                                        surface);

    if(res && !texture) {
        std::cout << SDL_GetError() << std::endl;
        res = false;
    }

    if(res) {
        textures.insert({key, makeSharedTexture(texture)});
    }

    return res;
}

sharedTexture TextureManager::getTexture(const std::string& key) {
    return textures[key];
}

void TextureManager::drawTexture(const sharedTexture& texture,
                                SDL_Rect srcrect,
                                SDL_Rect dstrect)
{
    if(texture.get() != nullptr) {
        SDL_RenderCopy(Game::renderer, texture.get(), &srcrect, &dstrect);
    }
    else {
        std::cout << "Texture is not loaded" << std::endl;
    }
}

void TextureManager::drawTexture(const std::string& key, SDL_Rect srcrect,
                        SDL_Rect dstrect)
{
    drawTexture(textures[key], srcrect, dstrect);
}