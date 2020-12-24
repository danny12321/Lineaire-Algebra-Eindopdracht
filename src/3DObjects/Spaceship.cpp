//
// Created by Danny on 24/12/2020.
//

#include "Spaceship.hpp"
#include "../EventSystem.hpp"

Spaceship::Spaceship() : Object3D("starfighter") {

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

    if(system.keyIsPressed(SDLK_SPACE)) std::cout << "Bullet goes pieewww" << std::endl;
    if(system.keyIsPressed(SDLK_h)) std::cout << "Helpline activated" << std::endl;
}
