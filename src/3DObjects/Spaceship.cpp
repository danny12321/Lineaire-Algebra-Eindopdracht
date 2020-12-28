//
// Created by Danny on 24/12/2020.
//

#include "Spaceship.hpp"
#include "../EventSystem.hpp"
#include "Cube.hpp"

Spaceship::Spaceship(ObjectManager& objectManager) : objectManager(objectManager), Object3D() {
    Vector3D* v1 = new Vector3D{0,0,0};
    Vector3D* v2 = new Vector3D{0,100,0};
    Vector3D* v3 = new Vector3D{0,0,100};

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
    if (system.keyIsPressed(SDLK_q)) rotateLocalZ(1);
    if (system.keyIsPressed(SDLK_e)) rotateLocalZ(-1);

//    PITCH
    if (system.keyIsPressed(SDLK_w)) rotateLocalX(-1);
    if (system.keyIsPressed(SDLK_s)) rotateLocalX(1);

//    Yaw
    if (system.keyIsPressed(SDLK_a)) rotateLocalY(1);
    if (system.keyIsPressed(SDLK_d)) rotateLocalY(-1);

    if(system.keyIsPressed(SDLK_SPACE)) shoot();
    if(system.keyIsPressed(SDLK_h)) std::cout << "Helpline activated" << std::endl;
}

void Spaceship::shoot() {
//    float bulletSpeed = 1;
//    Vector3D normalVector = getNormalVector(*canon[0], *canon[1], *canon[2]);
//    Vector3D normalVectorFromOrigin = normalVector - *canon[0];
//    Vector3D bulletVector = normalVector * bulletSpeed;
std::cout << "Shoot" << std::endl;
    objectManager.addObject<Cube>(new Cube());

//    std::cout << "x " << a.getX() << " b " << a.getY() << " z " << a.getZ() << std::endl;
}
