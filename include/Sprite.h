#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Vector2.h"

class Sprite : public Vector2
{
private:
    SDL_Texture *m_texture;
    SDL_Rect currentFrame;
    int m_width;
    int m_height;
    SDL_Rect src;
    SDL_Rect dest;

public:
    Sprite(Vector2 p_pv,
           int p_width,
           int p_height,
           SDL_Texture *p_texture);
    SDL_Texture *getTexture();
    void render(SDL_Renderer *p_renderer);
    void move(int code);
    SDL_Rect *getCurrentFrame();
};
