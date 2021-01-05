//
// Created by Thierry on 12-11-2020.
//

#include <iostream>
#include "EventSystem.hpp"

void EventSystem::handleEvents() {
    prevKeyPressed = keyPressed;
    keyPressedThisUpdateList.clear();

    mouseMotion.setX(0);
    mouseMotion.setY(0);

    mouseWheel.setX(0);
    mouseWheel.setY(0);

    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_KEYDOWN) {
            keyPressed[e.key.keysym.sym] = true;
            keyPressedThisUpdateList[e.key.keysym.sym] = true;
        }
        if (e.type == SDL_KEYUP) keyPressed[e.key.keysym.sym] = false;

        if(e.type == SDL_MOUSEMOTION) {
            mouseMotion.setX(e.motion.xrel);
            mouseMotion.setY(e.motion.yrel);
        }

        if(e.type == SDL_MOUSEWHEEL) {
            mouseWheel.setX(e.wheel.x);
            mouseWheel.setY(e.wheel.y);
        }
    }

    for (auto &handler : customHandlers)
        handler(e);
}