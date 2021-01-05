//
// Created by Danny on 24/12/2020.
//

#include "Space.hpp"
#include "3DObjects/Cube.hpp"
#include "3DObjects/Pyramid.hpp"
#include "3DObjects/Jezus.hpp"
#include "3DObjects/Spaceship.hpp"
#include "3DObjects/Axis.hpp"

Space::Space() : camera({{5, 5, 5},
                         {0, 0, 0}}), coordinateSystem({sdlRenderer, 50, 50, 0, 0, 1280, 720, 0, 1}) {
    sdlRenderer.init();
    eventSystem.addEventHandler(getEventHandler());

    objectManager.addObject<Spaceship>(new Spaceship(objectManager));
    objectManager.addObject<Cube>(new Cube());
    objectManager.addObject<Axis>(new Axis(new Vector3D{4, 0,0}, 255,0,0)); // x
    objectManager.addObject<Axis>(new Axis(new Vector3D{0, 4,0}, 0,255,0)); // y
    objectManager.addObject<Axis>(new Axis(new Vector3D{0, 0,4}, 0,0,255)); // z
    objectManager.doAddObjects();
//    objectManager.getObjects().at(1)->translate(-2, 0, 0);
//    objects.emplace_back(std::make_unique<Jezus>());
//    objectManager.getObjects().at(0)->rotateLocalAxis(45,45,45);
//    objectManager.getObjects().at(0)->rotateLocalAxis(0,0,30);
//    objectManager.getObjects().at(0)->rotateToOrigin();
//    objectManager.getObjects().at(0)->rotateLocalAxis(45,10,45);

//    camera.followObject(*objectManager.getObjects().at(0), new Vector3D {20,30,50});
}

Space::~Space() {
    sdlRenderer.close();
}

void Space::run() {
    while (!sdlRenderer.isRunning()) {
        sdlRenderer.clearScreen();

        eventSystem.handleEvents();

        objectManager.update(eventSystem);

        objectManager.collisionCheck();

        camera.update(eventSystem);

        render();

        sdlRenderer.delay();
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

std::function<void(const SDL_Event &)> Space::getEventHandler() {
    return [this](const SDL_Event& e) {
        // process data
        if(e.type == SDL_QUIT) this->sdlRenderer.quitApp();
    };
}