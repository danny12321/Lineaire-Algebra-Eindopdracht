//
// Created by Thierry on 12-11-2020.
//

#ifndef LINAL_EVENTSYSTEM_HPP
#define LINAL_EVENTSYSTEM_HPP


#include <SDL2/SDL_events.h>
#include <map>

class EventSystem {
public:
    EventSystem() {};

    void handleEvents();

    [[nodiscard]] bool keyIsPressed(const SDL_Keycode &keycode) const {
        if ( keyPressed.find(keycode) == keyPressed.end() ) {
            return false;
        } else {
            return keyPressed.at(keycode);
        }
    };

private:
    SDL_Event e;
    std::map<SDL_Keycode, bool> keyPressed;
};


#endif //LINAL_EVENTSYSTEM_HPP
