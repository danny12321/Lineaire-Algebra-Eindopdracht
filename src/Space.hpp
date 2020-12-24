//
// Created by Danny on 24/12/2020.
//

#ifndef LINAL_SPACE_HPP
#define LINAL_SPACE_HPP


#include "3DObjects/Object3D.hpp"
#include "SDLRenderer.hpp"
#include "CoordinateSystem.hpp"
#include "Events.hpp"

class Space {
public:
    Space();
    void Run();
    ~Space();

private:
    void render();

    std::vector<Object3D> objects;
    SDLRenderer sdlRenderer;
    CoordinateSystem coordinateSystem;
    Events events;

    Camera camera;
};


#endif //LINAL_SPACE_HPP
