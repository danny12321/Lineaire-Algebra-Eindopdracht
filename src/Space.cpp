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
    objectManager.addObject<Spaceship>(new Spaceship(objectManager));
    objectManager.doAddObjects();
//    objects.emplace_back(std::make_unique<Jezus>());
//    objectManager.getObjects().at(0)->toOrigin();
//    objectManager.getObjects().at(0)->scale(0.1, 0.1, 0.1);
//    objectManager.getObjects().at(0)->translate(1,2,1);
//    objectManager.getObjects().at(0)->rotateZ(100);
//    objectManager.getObjects().at(0)->rotateY(20);
}

Space::~Space() {
    sdlRenderer.close();
}

void Space::run() {
    while (!sdlRenderer.isRunning()) {
        sdlRenderer.clearScreen();

        eventSystem.handleEvents();

        handleEvents();

        objectManager.update(eventSystem);

        render();

//        sdlRenderer.delay();
    }
}

void Space::update() {

}

void Space::render() {
    Matrix multiplyMatrix = camera.getProjectionMatrix() * camera.getToOriginMatrix();
    coordinateSystem.setMultiplyMatrix(multiplyMatrix);

    for (const auto &object : objectManager.getObjects())
        coordinateSystem.renderObject(*object);

    sdlRenderer.setDrawColor(0, 0, 0, 255);
    sdlRenderer.render();
}

void Space::handleEvents() {
    camera.handleEvents(eventSystem);
}
