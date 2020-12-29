//
// Created by Danny on 24/12/2020.
//

#include "Spaceship.hpp"
#include "../EventSystem.hpp"
#include "Cube.hpp"
#include "Bullet.hpp"

Spaceship::Spaceship(ObjectManager& objectManager) : objectManager(objectManager), Object3D("starfighter") {
    Vector3D* v1 = new Vector3D{11,40,0};
    Vector3D* v2 = new Vector3D{10,40,0};
    Vector3D* v3 = new Vector3D{11,40,1};

    points.push_back(v1);
    points.push_back(v2);
    points.push_back(v3);

    lines.push_back(new Line{v1, v2});
    lines.push_back(new Line{v2, v3});
    lines.push_back(new Line{v3, v1});

    canon.push_back(v1);
    canon.push_back(v2);
    canon.push_back(v3);

    rotateX(90);

    resetXyzAxis();
}

void Spaceship::update(const EventSystem &system) {
//    ROLL
    if (system.keyIsPressed(SDLK_q)) rotateLocalZ(3);
    if (system.keyIsPressed(SDLK_e)) rotateLocalZ(-3);

//    PITCH
    if (system.keyIsPressed(SDLK_w)) rotateLocalX(3);
    if (system.keyIsPressed(SDLK_s)) rotateLocalX(-3);

//    Yaw
    if (system.keyIsPressed(SDLK_a)) rotateLocalY(3);
    if (system.keyIsPressed(SDLK_d)) rotateLocalY(-3);

    if (system.keyIsPressed(SDLK_z)) velocity += 0.1;
    if (system.keyIsPressed(SDLK_x)) velocity += -0.1;

    if(system.keyIsPressedOnce(SDLK_SPACE)) shoot();
    if(system.keyPressedThisUpdate(SDLK_h)) rotateToOrigin();

move();
}

void Spaceship::shoot() {
    Vector3D normalVector = getNormalVector(*canon[0], *canon[1], *canon[2]);

    objectManager.addObject<Bullet>(new Bullet(*canon[0], velocity, normalVector));
}

void Spaceship::move() {
    // Zelfde kant op als de kogel, als we een andere kant op willen moeten nog een driehoek maken.
    Vector3D normalVector = getNormalVector(*canon[0], *canon[1], *canon[2]);
    Vector3D a = (normalVector - *canon[0]).getEenheidsvector();
    translate(a.getX() * velocity, a.getY() * velocity, a.getZ() * velocity);
}
