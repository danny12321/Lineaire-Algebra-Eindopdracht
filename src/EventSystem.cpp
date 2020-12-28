//
// Created by Thierry on 12-11-2020.
//

#include "EventSystem.hpp"


//void EventSystem::doEvents(CoordinateSystem &coordinateSystem, SDLRenderer &sdlRenderer, Camera &camera) {
//    while (SDL_PollEvent(&e) != 0) {
//
//        int x, y;
////        SDL_GetMouseState(&x, &y);
//
//
//        //User requests quit
//        if (e.type == SDL_QUIT) {
//            sdlRenderer.quitApp();
//        }
//
//        if (e.type == SDL_MOUSEWHEEL) {
//            if (e.wheel.y > 0) // scroll up
//                camera.decreaseFov();
//            else if (e.wheel.y < 0) // scroll down
//                camera.increaseFov();
//            std::cout << camera.getFov() << std::endl;
//        }

//    }
//}

void EventSystem::handleEvents() {
    prevKeyPressed = keyPressed;
    keyPressedThisUpdateList.clear();

    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_KEYDOWN) {
            keyPressed[e.key.keysym.sym] = true;
            keyPressedThisUpdateList[e.key.keysym.sym] = true;
        }
        if (e.type == SDL_KEYUP) keyPressed[e.key.keysym.sym] = false;
    }

    for (auto &handler : customHandlers)
        handler(e);
}