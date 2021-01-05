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

class SDLRenderer {
public:
    bool init();

    void close();

    bool isRunning();

    void clearScreen();

    void render();

    void drawLine(int x1, int y1, int x2, int y2);

    void delay();

    void setDrawColor(int r, int g, int b, int a);

    [[nodiscard]] int getScreenWidth() const { return SCREEN_WIDTH; }

    [[nodiscard]] int getScreenHeight() const { return SCREEN_HEIGHT; }

    void quitApp() { quit = true; }
private:
    int SCREEN_WIDTH = 1920;
    int SCREEN_HEIGHT = 1080;

    const int fps = 100;
    const int waitingTimeForFrame = 1000 / fps;

    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Event e;

    bool quit = false;
};


#endif //LINAL_SDLRENDERER_HPP