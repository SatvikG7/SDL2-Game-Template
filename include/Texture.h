#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
class Texture
{
private:
    SDL_Texture *texture;
    
public:
    Texture(SDL_Renderer *renderer, const char *p_filePath);
    SDL_Texture *getTexture();
};