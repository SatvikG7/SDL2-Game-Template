#include "Sprite.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Sprite::Sprite(Vector2 p_pv,
               int p_width,
               int p_height,
               SDL_Texture *p_texture)
    : Vector2(p_pv.getX(), p_pv.getY()), m_texture(NULL)
{
    m_texture = p_texture;
    m_width = p_width;
    m_height = p_height;
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.h = m_height;
    currentFrame.w = m_width;
};

void Sprite::render(SDL_Renderer *p_renderer)
{
    src.x = currentFrame.x;
    src.y = currentFrame.y;
    src.w = currentFrame.w;
    src.h = currentFrame.h;

    dest.x = getX();
    dest.y = getY();
    dest.w = src.w;
    dest.h = src.h;
    SDL_RenderCopy(p_renderer, m_texture, &src, &dest);
};

SDL_Texture *Sprite::getTexture()
{
    return m_texture;
}
SDL_Rect *Sprite::getCurrentFrame()
{
    return &currentFrame;
}

void Sprite::move(int code)
{
    switch (code)
    {
    case 8:
        setXY(getX(), getY() - 32);
        break;
    case 2:
        setXY(getX(), getY() + 32);
        break;
    case 4:
        setXY(getX() - 32, getY());
        break;
    case 6:
        setXY(getX() + 32, getY());
        break;
    default:
        break;
    }
}