//
// Created by Danny on 24/12/2020.
//

#include "Space.hpp"
#include "3DObjects/Cube.hpp"
#include "3DObjects/Pyramid.hpp"
#include "3DObjects/Jezus.hpp"

Space::Space() : camera({{5, 5, 5},
                         {0, 0, 0}}), coordinateSystem({sdlRenderer, 50, 50, 0, 0, 1280, 720, 0, 1}) {
    sdlRenderer.init();
    objects.emplace_back(Jezus{});
    objects[0].toOrigin();
    objects[0].scale(0.01, 0.01, 0.01);
    objects[0].translate(1,2,1);
    objects[0].rotateX(-90);
    objects.emplace_back(Cube{});
    objects.emplace_back(Pyramid{});
}

Space::~Space() {
    sdlRenderer.close();
}

void Space::Run() {
    while (!sdlRenderer.isRunning()) {
        sdlRenderer.clearScreen();

        objects[0].rotateX(30);
        objects[0].rotateY(20);
        objects[0].rotateZ(10);

        events.doEvents(coordinateSystem, sdlRenderer, camera);

        Matrix multiplyMatrix = camera.getProjectionMatrix() * camera.getToOriginMatrix();
        coordinateSystem.setMultiplyMatrix(multiplyMatrix);

        render();
//        sdlRenderer.delay();
    }
}

void Space::render() {
    for (const auto &object : objects)
        coordinateSystem.renderObject(object);

    sdlRenderer.setDrawColor(0, 0, 0, 255);
    sdlRenderer.render();
}
