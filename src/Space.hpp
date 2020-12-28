//
// Created by Danny on 24/12/2020.
//

#ifndef LINAL_SPACE_HPP
#define LINAL_SPACE_HPP

#include "ObjectManager.hpp"
#include "SDLRenderer.hpp"
#include "CoordinateSystem.hpp"
#include "EventSystem.hpp"
#include "Camera.hpp"

class Space {
public:
    Space();

    ~Space();

    void run();

    void update();

private:
    void render();

    ObjectManager objectManager;
    SDLRenderer sdlRenderer;
    CoordinateSystem coordinateSystem;
    EventSystem eventSystem;

    Camera camera;

    void handleEvents();

    std::function<void(const SDL_Event &)> getEventHandler();
};


#endif //LINAL_SPACE_HPP
