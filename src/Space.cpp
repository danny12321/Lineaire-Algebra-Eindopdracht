#include "Space.hpp"
#include "3DObjects/Cube.hpp"
#include "3DObjects/Pyramid.hpp"
#include "3DObjects/Jezus.hpp"
#include "3DObjects/Spaceship.hpp"
#include "3DObjects/Axis.hpp"

Space::Space() : camera({{5, 5, 5},
                         {0, 0, 0}}), coordinateSystem({sdlRenderer, eventSystem}) {
    sdlRenderer.init();
    coordinateSystem.init(eventSystem);
    eventSystem.addEventHandler(getEventHandler());

    objectManager.addObject<Spaceship>(new Spaceship(objectManager));
    objectManager.addObject<Cube>(new Cube());
//    objectManager.addObject<Jezus>(new Jezus());
    objectManager.addObject<Axis>(new Axis(new Vector3D{4, 0,0}, 255,0,0)); // x
    objectManager.addObject<Axis>(new Axis(new Vector3D{0, 4,0}, 0,255,0)); // y
    objectManager.addObject<Axis>(new Axis(new Vector3D{0, 0,4}, 0,0,255)); // z
    objectManager.doAddObjects();
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

        handleEvents();

        camera.update(eventSystem);

        render();

        sdlRenderer.delay();
    }
}

void Space::handleEvents() {
    if(eventSystem.keyPressedThisUpdate(SDLK_ESCAPE))
        this->sdlRenderer.toggleEndlessCursor();

    if(eventSystem.keyPressedThisUpdate(SDLK_1))
        camera.followObject(objectManager.getObjects().at(0).get(), new Vector3D {1,1,1});

    if(eventSystem.keyPressedThisUpdate(SDLK_2))
        camera.followObject(objectManager.getObjects().at(0).get(), new Vector3D {20,30,50});

    if(eventSystem.keyPressedThisUpdate(SDLK_0))
        camera.followObject(nullptr, new Vector3D {20,30,50});
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