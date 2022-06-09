#include "Manager.h"
#include "Entity.h"
#include "Sprite.h"
Manager::Manager()
{
    //
}

void Manager::addEntity(Entity p_entity)
{
    tiles.push_back(p_entity);
}
void Manager::createSprite(Sprite p_sprite)
{
    sprite = new Sprite(p_sprite);
}

void Manager::renderEntities(SDL_Renderer *p_renderer)
{
    for (Entity &tile : tiles)
    {
        tile.render(p_renderer);
    }
}

void Manager::renderSprite(SDL_Renderer *p_renderer)
{
    sprite->render(p_renderer);
}

void Manager::handleKeyPress(SDL_Keysym p_key)
{
    if (p_key.sym == SDLK_UP)
    {
        sprite->move(8);
    }
    else if (p_key.sym == SDLK_DOWN)
    {
        sprite->move(2);
    }
    else if (p_key.sym == SDLK_LEFT)
    {
        sprite->move(4);
    }
    else if (p_key.sym == SDLK_RIGHT)
    {
        sprite->move(6);
    }
}