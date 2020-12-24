//
// Created by Danny on 24/12/2020.
//

#include "Space.hpp"
#include "3DObjects/Cube.hpp"
#include "3DObjects/Pyramid.hpp"

Space::Space() : camera({{200, 100, 200},
                         {0, 0, 0}}), coordinateSystem({sdlRenderer, 50, 50, 0, 0, 1280, 720, 0, 1}) {
    sdlRenderer.init();
//    objects.emplace_back(JsonObject3D{"jezus"});
//    objects.emplace_back(JsonObject3D{"saturn"});
    objects.emplace_back(Cube{});
    objects.emplace_back(Pyramid{});
}

Space::~Space() {
    sdlRenderer.close();
}

void Space::Run() {
    while (!sdlRenderer.isRunning()) {
        sdlRenderer.clearScreen();

        events.doEvents(coordinateSystem, sdlRenderer, camera);

        Matrix multiplyMatrix = camera.getProjectionMatrix() * camera.getToOriginMatrix();
        coordinateSystem.setMultiplyMatrix(multiplyMatrix);

        render();
        sdlRenderer.delay();
    }
}

void Space::render() {
    for (const auto &object : objects)
        coordinateSystem.renderObject(object);

    sdlRenderer.setDrawColor(0, 0, 0, 255);
    sdlRenderer.render();
}
