//
// Created by Thierry on 11-11-2020.
//

#ifndef LINAL_SDLRENDERER_HPP
#define LINAL_SDLRENDERER_HPP

#include <SDL.h>
#undef main
#include <iostream>
#include <map>
#include <vector>
#include "Vector3D.hpp"

class SDLRenderer {
public:
    bool init();

    void close();

    bool isRunning() const;

    void clearScreen();

    void render();

    void drawLine(int x1, int y1, int x2, int y2);

    void delay() const;

    void setDrawColor(int r, int g, int b, int a);

    [[nodiscard]] Vector3D getScreenSize() const {
        int w, h;
        SDL_GetWindowSize(window,&w,&h);
        return {(float)w, (float)h, 0};
    }

    void quitApp() { quit = true; }

    void toggleEndlessCursor();

private:
    const int fps = 100;
    const int waitingTimeForFrame = 1000 / fps;

    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Event e;

    bool quit = false;

    bool endlessCursor = true;
};


#endif //LINAL_SDLRENDERER_HPP