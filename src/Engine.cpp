#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Engine.h"
#include "Texture.h"
#include "Entity.h"
#include "Sprite.h"
#include "Vector2.h"

Engine::Engine() : m_window(NULL)
{

    if (SDL_Init(SDL_INIT_VIDEO) > 0)
    {
        std::cout << "SDL_Init failed" << std::endl;
        std::cout << "ERROR: " << SDL_GetError() << std::endl;
    }
    else
    {
        std::cout << "SDL_Init success" << std::endl;
    }
    if (!IMG_Init(IMG_INIT_PNG))
    {
        std::cout << "IMG_Init failed" << std::endl;
        std::cout << "ERROR: " << SDL_GetError() << std::endl;
    }
    else
    {
        std::cout << "IMG_Init success" << std::endl;
    }
}

int Engine::init(const char *p_title, int p_w, int p_h, bool p_fullscreen)
{

    if (p_fullscreen)
    {
        m_window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_FULLSCREEN);
        m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    }
    else
    {
        m_window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);
        m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

        // Set Window Icon
        SDL_Surface *icon = IMG_Load("assets/logo.png");
        SDL_SetWindowIcon(m_window, icon);
    }
    if (m_window == NULL)
    {
        std::cout << "SDL_CreateWindow failed" << std::endl;
        std::cout << "ERROR: " << SDL_GetError() << std::endl;
        return -1;
    }
    if (m_renderer == NULL)
    {
        std::cout << "SDL_CreateRenderer failed" << std::endl;
        std::cout << "ERROR: " << SDL_GetError() << std::endl;
        return -1;
    }
    else
    {
        std::cout << "SDL_CreateRenderer success" << std::endl;
        SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
    }
    isRunning = true;
    Texture tile(m_renderer, "assets/checkerboard.png");

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            manager.addEntity(Entity(Vector2(i * 64, j * 64), 64, 64, tile.getTexture()));
        }
    }

    Texture spriteTex(m_renderer, "assets/hero.png");
    manager.createSprite(Sprite(Vector2(32,32), 32,32, spriteTex.getTexture()));
    return 0;
}

void Engine::update()
{
    // Update
}

void Engine::render()
{
    SDL_RenderClear(m_renderer);
    manager.renderEntities(m_renderer);
    manager.renderSprite(m_renderer);
    SDL_RenderPresent(m_renderer);
}

void Engine::handleEvents()
{
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            isRunning = false;
        }
        // handle arrow key presses
        else if (event.type == SDL_KEYDOWN)
        {
            // std::cout<<"Key Pressed"<<std::endl;
            manager.handleKeyPress(event.key.keysym);
        }
    }
}

void Engine::clean()
{
    SDL_DestroyWindow(m_window);
}
void Engine::end()
{
    isRunning = false;
}
Engine::~Engine()
{
    SDL_Quit();
}

// Utils

bool Engine::running()
{
    return isRunning;
}

SDL_Window *Engine::getWindow()
{
    return m_window;
}

int Engine::getRefreshRate(SDL_Window *window)
{
    int displayIndex = SDL_GetWindowDisplayIndex(window);
    SDL_DisplayMode mode;
    SDL_GetCurrentDisplayMode(displayIndex, &mode);
    return mode.refresh_rate;
}

SDL_Event Engine::getEvent()
{
    return event;
}