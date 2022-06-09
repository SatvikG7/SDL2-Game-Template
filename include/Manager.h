#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "vector"
#include "Entity.h"
#include "Sprite.h"
class Manager{
    private:
        std::vector<Entity> tiles;
        // std::vector<Sprite> sprites;
        Sprite *sprite = nullptr;


    public:
        Manager();
        // void update();
        // void render();
        // void clean();
        // void end();
    
        void addEntity(Entity p_entity);
        void createSprite(Sprite p_sprite);
        void renderEntities(SDL_Renderer *p_renderer);
        void renderSprite(SDL_Renderer *p_renderer);
        void handleKeyPress(SDL_Keysym p_key);
};