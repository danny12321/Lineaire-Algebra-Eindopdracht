//
// Created by Danny on 24/12/2020.
//

#include "Space.hpp"
#include "3DObjects/Cube.hpp"
#include "3DObjects/Pyramid.hpp"
#include "3DObjects/Jezus.hpp"
#include "3DObjects/Spaceship.hpp"

Space::Space() : camera({{5, 5, 5},
                         {0, 0, 0}}), coordinateSystem({sdlRenderer, 50, 50, 0, 0, 1280, 720, 0, 1}) {
    sdlRenderer.init();
    objects.emplace_back(std::make_unique<Spaceship>());
//    objects.emplace_back(std::make_unique<Jezus>());
    objects[0]->toOrigin();
    objects[0]->scale(0.01, 0.01, 0.01);
    objects[0]->translate(1,2,1);
    objects[0]->rotateX(-90);
}

Space::~Space() {
    sdlRenderer.close();
}

void Space::run() {
    while (!sdlRenderer.isRunning()) {
        sdlRenderer.clearScreen();

        eventSystem.handleEvents();

        handleEvents();

        update();

        render();

//        sdlRenderer.delay();
    }
}

void Space::update() {
    for (auto &object : objects)
        object->update(eventSystem);
}

void Space::render() {
    Matrix multiplyMatrix = camera.getProjectionMatrix() * camera.getToOriginMatrix();
    coordinateSystem.setMultiplyMatrix(multiplyMatrix);

    for (const auto &object : objects)
        coordinateSystem.renderObject(*object);

    sdlRenderer.setDrawColor(0, 0, 0, 255);
    sdlRenderer.render();
}

void Space::handleEvents() {
    camera.handleEvents(eventSystem);
}
