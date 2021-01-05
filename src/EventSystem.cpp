//
// Created by Thierry on 12-11-2020.
//

#include "EventSystem.hpp"

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