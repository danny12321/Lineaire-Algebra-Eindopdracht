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
}

void Spaceship::update(const EventSystem &system) {
//    ROLL
    if (system.keyIsPressed(SDLK_q)) rotateZ(1);
    if (system.keyIsPressed(SDLK_e)) rotateZ(-1);

//    PITCH
    if (system.keyIsPressed(SDLK_w)) rotateX(-1);
    if (system.keyIsPressed(SDLK_s)) rotateX(1);

//    Yaw
    if (system.keyIsPressed(SDLK_a)) rotateY(1);
    if (system.keyIsPressed(SDLK_d)) rotateY(-1);

    if(system.keyIsPressedOnce(SDLK_SPACE)) shoot();
    if(system.keyPressedThisUpdate(SDLK_h)) rotateToOrigin();
}

void Spaceship::shoot() {
    float bulletSpeed = 1;
    Vector3D normalVector = getNormalVector(*canon[0], *canon[1], *canon[2]);
    Vector3D normalVectorOne = normalVector.getEenheidsvector();
    Vector3D normalVectorFromOrigin = normalVector - *canon[0];
    Vector3D bulletVector = normalVector * bulletSpeed;
    std::cout << "Shoot" << std::endl;
    Vector3D position {0,0,0};
    Vector3D velocity {0,0,0};
    Vector3D rotation {0,0,0};

    objectManager.addObject<Bullet>(new Bullet(*canon[0], velocity, normalVector));
//    std::cout << "x " << a.getX() << " b " << a.getY() << " z " << a.getZ() << std::endl;
}
