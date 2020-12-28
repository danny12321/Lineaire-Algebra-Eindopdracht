//
// Created by Danny on 24/12/2020.
//

#ifndef LINAL_SPACESHIP_HPP
#define LINAL_SPACESHIP_HPP

#include "Object3D.hpp"
#include "../ObjectManager.hpp"

class Spaceship : public Object3D {
public:
    Spaceship(ObjectManager& objectManager);

    void update(const EventSystem &system) override;

    void shoot();

private:
    void move();
    ObjectManager& objectManager;
    float velocity = 0.0f;
    std::vector<Vector3D*> canon;
};


#endif //LINAL_SPACESHIP_HPP
