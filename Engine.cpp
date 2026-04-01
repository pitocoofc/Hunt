#include "Engine.h"
#include <iostream>

bool Engine::init(const char* title, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "SDL Init Error\n";
        return false;
    }

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, width, height, 0);

    if (!window) return false;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer) return false;

    return true;
}

void Engine::run() {
    while (isRunning) {
        handleEvents();
        update();
        render();
    }
}

void Engine::handleEvents() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            isRunning = false;
        }
    }
}

void Engine::update() {
    // Aqui depois entra DOM + layout
}

void Engine::render() {
    SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);
    SDL_RenderClear(renderer);

    // Aqui depois entra o render do DOM

    SDL_RenderPresent(renderer);
}

void Engine::shutdown() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
