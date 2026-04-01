#pragma once
#include <SDL2/SDL.h>

class Engine {
public:
    bool init(const char* title, int width, int height);
    void run();
    void shutdown();

private:
    void handleEvents();
    void update();
    void render();

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    bool isRunning = true;
};
