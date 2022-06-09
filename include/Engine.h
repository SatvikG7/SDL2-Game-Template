#pragma once
#include <SDL2/SDL.h>
#include "Entity.h"
// #include "Sprite.h"
#include <vector>
#include "Manager.h"
class Engine
{
private:
    /* data */
    SDL_Window *m_window = nullptr;
    SDL_Event event;
    bool isRunning;
    SDL_Renderer *m_renderer;
    Manager manager;

public:
    Engine();
    int init(const char *p_title, int p_w, int p_h, bool p_fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();
    void end();

    // Utils
    SDL_Window *getWindow();
    int getRefreshRate(SDL_Window *p_window);
    SDL_Event getEvent();
    bool running();
    ~Engine();
};
