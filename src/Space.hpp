//
// Created by Danny on 24/12/2020.
//

#ifndef LINAL_SPACE_HPP
#define LINAL_SPACE_HPP


#include "3DObjects/Object3D.hpp"
#include "SDLRenderer.hpp"
#include "CoordinateSystem.hpp"
#include "EventSystem.hpp"
#include "Camera.hpp";

class Space {
public:
    Space();

    ~Space();

    void run();

    void update();

private:
    void render();

    std::vector<std::unique_ptr<Object3D>> objects;
    SDLRenderer sdlRenderer;
    CoordinateSystem coordinateSystem;
    EventSystem eventSystem;

    Camera camera;

    void handleEvents();
};


#endif //LINAL_SPACE_HPP
