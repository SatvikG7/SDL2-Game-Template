#include "Texture.h"
#include <iostream>
Texture::Texture(SDL_Renderer *renderer, const char *p_filePath)
    : texture(NULL)
{
    texture = IMG_LoadTexture(renderer, p_filePath);
    if (texture == NULL)
    {
        std::cout << "Failed to load texture";
    }
}

SDL_Texture *Texture::getTexture()
{
    return texture;
}

