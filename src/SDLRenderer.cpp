//
// Created by Thierry on 11-11-2020.
//

#include "SDLRenderer.hpp"
#include <vector>

bool SDLRenderer::init() {
    //Initialization flag
    bool success = true;


    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
//        TTF_Init();

        //Set texture filtering to linear
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            printf( "Warning: Linear texture filtering not enabled!" );
        }

        //Create window
        window = SDL_CreateWindow( "Linal", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( window == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {

//            Create renderer for window
            renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
            if( renderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
        }
    }

//    loadFont("roboto", "../assets/fonts/roboto.ttf");

    return success;
}

void SDLRenderer::close() {
    //Destroy window
    SDL_DestroyRenderer( renderer );
    SDL_DestroyWindow( window );
    window = NULL;
    renderer = NULL;

    //Quit SDL subsystems
//    IMG_Quit();
    SDL_Quit();
//    TTF_Quit();
}

void SDLRenderer::events() {
    //Handle events on queue

}

bool SDLRenderer::isRunning() {
    return quit;
}

void SDLRenderer::clearScreen() {

    SDL_RenderClear( renderer );
}

void SDLRenderer::render() {
    SDL_RenderPresent( renderer );
}

void SDLRenderer::drawLine(int x1, int y1, int x2, int y2) {
    SDL_RenderDrawLine( renderer, x1, y1, x2, y2 );
}

void SDLRenderer::delay() {
    SDL_Delay( waitingTimeForFrame );
}

void SDLRenderer::setDrawColor(int r, int g, int b, int a) {
    SDL_SetRenderDrawColor( renderer, r, g, b, a );
}

//bool SDLRenderer::loadFont(const std::string &id, const std::string &filePath) {
//    std::ifstream f(filePath.c_str());
//    if (f.good()) {
//        this->fontPathMap[id] = filePath;
//        std::map<int, TTF_Font *> map;
//        this->fontMap.insert({id, map});
//        return true;
//    } else {
//        SDL_Log("Failed to load font resource: %s, with id: %s", filePath.c_str(), id.c_str());
//        return false;
//    }
//}

// Text meuk
//void
//SDLRenderer::drawText(std::string &text, int x, int y, int width, int height, int fontSize, int r,
//                      int g, int b,
//                      int alpha,
//                      bool bold, bool italic, bool underline, bool strikethrough, std::string horizontalAlignment,
//                      std::string verticalAlignment) {
//    std::string id = "roboto";
//    auto font = this->getFont(id, fontSize);
//    if (font == nullptr) return;
//
//    setStyle(font, bold, italic, underline, strikethrough);
//
//    SDL_Color color = {static_cast<Uint8>(r), static_cast<Uint8>(g), static_cast<Uint8>(b), static_cast<Uint8>(alpha)};
//
//    std::vector<std::string> lines = GetLines(text, font, width);
//    int textHeight = getHeight(lines, font);
//    int yMargin = getYMargin(height, textHeight, verticalAlignment);
//
//    for (int i = 0; i < lines.size(); ++i) {
//        int w = 0;
//        int h = 0;
//        TTF_SizeText(font, lines[i].c_str(), &w, &h);
//
//        SDL_Surface *surfaceMessage = TTF_RenderText_Blended_Wrapped(font, lines[i].c_str(), color, w);
//        SDL_Rect messageRect{GetHorizontalAlignment(horizontalAlignment, x, w, width), y + (h * i) + yMargin, surfaceMessage->w,
//                             surfaceMessage->h};
//
//        auto message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
//        SDL_RenderCopy(renderer, message, nullptr, &messageRect);
//
//        SDL_FreeSurface(surfaceMessage);
//        SDL_DestroyTexture(message);
//    }
//}
//
//int SDLRenderer::GetHorizontalAlignment(std::string &alignment, int x, int messageWidth, int rectWidth) {
//    if (alignment == "LEFT") return x;
//    if (alignment == "CENTER") return x + (rectWidth / 2) - (messageWidth / 2);
//    if (alignment == "RIGHT") return x + rectWidth - messageWidth;
//
//    return x;
//}
//
//
//TTF_Font *SDLRenderer::getFont(const std::string &id, const int fontSize) {
//
//    if (fontMap.count(id) > 0) { // if the font exists
//        if (fontMap[id].count(fontSize) > 0) { // if the fontsize exists
//            return fontMap[id][fontSize];
//        } else { // if the fontsize doesn't exists
//            auto font = TTF_OpenFont(fontPathMap[id].c_str(), fontSize);
//
//            if (font == nullptr) {
//                SDL_Log("Failed to load font resource: %s, with error: %s", id.c_str(), TTF_GetError());
//                return nullptr;
//            }
//
//            fontMap[id].insert({fontSize, font});
//            return font;
//        }
//    } else
//    { // if the font doesn't exists
//        SDL_Log("Failed to load font resource: %s, with error: font not found in memory", id.c_str());
//        return nullptr;
//    }
//}
//
//void SDLRenderer::setStyle(TTF_Font *font, bool bold, bool italic, bool underline, bool strikethrough) {
//    auto style = TTF_STYLE_NORMAL;
//
//    if (bold) style += TTF_STYLE_BOLD;
//    if (italic) style += TTF_STYLE_ITALIC;
//    if (underline) style += TTF_STYLE_UNDERLINE;
//    if (strikethrough) style += TTF_STYLE_STRIKETHROUGH;
//
//    TTF_SetFontStyle(font, style);
//}
//
//std::vector<std::string> SDLRenderer::GetLines(std::string text, TTF_Font *font, int width)
//{
//    std::vector<std::string> words;
//    std::string tempWord;
//
//    for (auto x : text)
//    {
//        if (x == ' ')
//        {
//            words.push_back(tempWord);
//            tempWord = "";
//        } else if (x == '\n')
//        {
//            words.push_back(tempWord);
//            words.push_back("\n");
//            tempWord = "";
//        } else tempWord = tempWord + x;
//    }
//
//    words.push_back(tempWord);
//
//    std::vector<std::string> lines;
//    std::string line;
//
//    int w = 0;
//    int h = 0;
//
//    for (auto word : words) {
//        if (word == "\n") {
//            lines.push_back(line);
//            line = "";
//            continue;
//        }
//
//        TTF_SizeText(font, (line + word).c_str(), &w, &h);
//
//        if (w > width) {
//            lines.push_back(line);
//            line = word;
//        } else {
//            line = line + word + " ";
//        }
//    }
//
//    lines.push_back(line);
//
//    return lines;
//}
//
//int SDLRenderer::getHeight(std::vector <std::string> lines, TTF_Font *font)
//{
//    int height = 0;
//
//    for (auto line : lines)
//    {
//        int w, h;
//        TTF_SizeText(font, line.c_str(), &w, &h);
//        height += h;
//    }
//
//    return height;
//}
//
//int SDLRenderer::getYMargin(int height, int textHeight, std::string alignment) {
//    if (alignment == "TOP") return 0;
//    if (alignment == "MIDDLE") return (height - textHeight) / 2;
//    if (alignment == "BOTTOM") return height - textHeight;
//
//    return 0;
//}
//
//void SDLRenderer::setViewport(int x, int y, int width, int height) {
//    SDL_Rect viewport;
//    viewport.x = x;
//    viewport.y = y;
//    viewport.w = width;
//    viewport.h = height;
//
//    SDL_RenderSetViewport( renderer, &viewport );
//}