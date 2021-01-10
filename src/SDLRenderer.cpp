//
// Created by Thierry on 11-11-2020.
//

#include "SDLRenderer.hpp"
#include <vector>

bool SDLRenderer::init() {
    //Initialization flag
    bool success = true;


    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    } else {

        //Set texture filtering to linear
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
            printf("Warning: Linear texture filtering not enabled!");
        }

        auto flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED;

        //Create window
        window = SDL_CreateWindow("Linal", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, NULL, NULL, flags);
        SDL_SetRelativeMouseMode(SDL_TRUE);

        if (window == NULL) {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        } else {

            SDL_SetWindowMinimumSize(window, 400, 300);
//            Create renderer for window
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if (renderer == NULL) {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                success = false;
            }
        }
    }

    return success;
}

void SDLRenderer::close() {
    //Destroy window
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    window = NULL;
    renderer = NULL;

    SDL_Quit();
}

bool SDLRenderer::isRunning() const {
    return quit;
}

void SDLRenderer::clearScreen() {
    SDL_RenderClear(renderer);
}

void SDLRenderer::render() {
    SDL_RenderPresent(renderer);
}

void SDLRenderer::drawLine(int x1, int y1, int x2, int y2) {
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}

void SDLRenderer::delay() const {
    SDL_Delay(waitingTimeForFrame);
}

void SDLRenderer::setDrawColor(int r, int g, int b, int a) {
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

void SDLRenderer::toggleEndlessCursor() {
    endlessCursor = !endlessCursor;
    SDL_SetRelativeMouseMode(endlessCursor ? SDL_TRUE : SDL_FALSE);
}