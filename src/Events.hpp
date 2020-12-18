//
// Created by Thierry on 12-11-2020.
//

#ifndef LINAL_EVENTS_HPP
#define LINAL_EVENTS_HPP

#include "CoordinateSystem.hpp"

class Events {
public:
    Events() {};

    void doEvents(CoordinateSystem& coordinateSystem, SDLRenderer& sdlRenderer);
private:
    SDL_Event e;
};


#endif //LINAL_EVENTS_HPP
