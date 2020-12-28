//
// Created by Thierry on 12-11-2020.
//

#ifndef LINAL_EVENTSYSTEM_HPP
#define LINAL_EVENTSYSTEM_HPP


#include <SDL2/SDL_events.h>
#include <map>
#include <vector>
#include <functional>

class EventSystem {
public:
    void handleEvents();

    [[nodiscard]] bool keyIsPressed(const SDL_Keycode &keycode) const {
        if (keyPressed.find(keycode) == keyPressed.end()) return false;
        return keyPressed.at(keycode);
    };

    [[nodiscard]] bool keyIsPressedOnce(const SDL_Keycode &keycode) const {
        if (keyPressed.find(keycode) == keyPressed.end() || keyPressedThisUpdateList.find(keycode) == keyPressedThisUpdateList.end()) return false;
        if(!keyIsPressed(SDLK_SPACE) && keyPressedThisUpdate(SDLK_SPACE)) return true;
        return keyPressed.at(keycode) && (prevKeyPressed.find(keycode) == prevKeyPressed.end() || prevKeyPressed.at(keycode) == false);
    };


    [[nodiscard]] bool keyPressedThisUpdate(const SDL_Keycode &keycode) const {
        if (keyPressedThisUpdateList.find(keycode) == keyPressedThisUpdateList.end()) return false;
        return keyPressedThisUpdateList.at(keycode);
    };

    void addEventHandler(const std::function<void(const SDL_Event &)>& handler) {
        customHandlers.emplace_back(handler);
    };

private:

    SDL_Event e;
    std::map<SDL_Keycode, bool> keyPressed;
    std::map<SDL_Keycode, bool> prevKeyPressed;
    std::map<SDL_Keycode, bool> keyPressedThisUpdateList;

    std::vector<std::function<void(const SDL_Event&)>> customHandlers;
};


#endif //LINAL_EVENTSYSTEM_HPP
