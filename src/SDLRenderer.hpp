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

    void events();

    bool isRunning();

    void clearScreen();

    void render();

    void drawLine(int x1, int y1, int x2, int y2);

    void delay();

    void setDrawColor(int r, int g, int b, int a);

    [[nodiscard]] int getScreenWidth() const { return SCREEN_WIDTH; }

    [[nodiscard]] int getScreenHeight() const { return SCREEN_HEIGHT; }

//    bool loadFont(const std::string &id, const std::string &filePath);

//    void
//    drawText(std::string &text, int x, int y, int width, int height, int fontSize, int r, int g,
//             int b,
//             int alpha, bool bold, bool italic, bool underline, bool strikethrough, std::string horizontalAlignment,
//             std::string verticalAlignment);
//
    void quitApp() { quit = true; }
//
//    void setViewport(int x, int y, int width, int height);
private:
    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 720;

    const int fps = 100;
    const int waitingTimeForFrame = 1000 / fps;

    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Event e;

    bool quit = false;

    // Text meuk
//    std::map<std::string, std::string> fontPathMap;
//    std::map<std::string, std::map<int, TTF_Font *>> fontMap;
//
//    TTF_Font *getFont(const std::string &id, const int fontSize);
//
//    void setStyle(TTF_Font *font, bool bold, bool italic, bool underline, bool strikethrough);
//
//    std::vector<std::string> GetLines(std::string text, TTF_Font *font, int width);
//
//    int getHeight(std::vector<std::string> lines, TTF_Font *font);
//
//    int getYMargin(int height, int textHeight, std::string alignment);
//
//    int GetHorizontalAlignment(std::string &alignment, int x, int messageWidth, int rectWidth);


};


#endif //LINAL_SDLRENDERER_HPP