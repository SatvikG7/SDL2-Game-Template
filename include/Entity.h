#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Vector2.h"

class Entity : public Vector2
{
private:
    SDL_Texture *m_texture;
    int m_width;
    int m_height;
    SDL_Rect currentFrame;
    SDL_Rect src;
    SDL_Rect dest;

public:
    Entity(Vector2 p_pv,
           int p_width,
           int p_height,
           SDL_Texture *p_texture);
    SDL_Texture *getTexture();

    void render(SDL_Renderer *p_renderer);
    // void move(Entity *p_entity, int code);
    SDL_Rect *getCurrentFrame();
};
