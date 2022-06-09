#include <iostream>
#define SDL_MAIN_HANDLED
#include "Engine.h"
const char *WINDOW_TITLE = "SDL2 Game Engine by Satvik Gaikwad https://github.com/SatvikG7/SDL2-Game-Engine";
const int W_WIDTH = 640;
const int W_HEIGHT = 640;
const bool FULLSCREEN = false;
Engine *Game = nullptr;

int main()
{
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    Uint32 frameTime;
    Game = new Engine();
    Game->init(WINDOW_TITLE, W_WIDTH, W_HEIGHT, FULLSCREEN);
    while (Game->running())
    {
        frameStart = SDL_GetTicks();
        Game->handleEvents();
        Game->update();
        Game->render();
        // std::cout << Game->getRefreshRate(Game->getWindow()) << std::endl;
        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    Game->clean();

    return 0;
}
