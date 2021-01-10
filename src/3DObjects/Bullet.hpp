//
// Created by Thierry on 28-12-2020.
//

#ifndef LINAL_BULLET_HPP
#define LINAL_BULLET_HPP

#include "Object3D.hpp"
#include "../ObjectManager.hpp"

class Bullet : public Object3D {

public:
    Bullet(Vector3D position, float velocity, Vector3D rotation, ObjectManager& objectManager);
    void update(const EventSystem &system) override;

    void collide(Object3D &collider) override;

private:
    Vector3D velocity {0,0,0};
    ObjectManager& objectManager;
    float bulletSpeed = .5f;
};


#endif //LINAL_BULLET_HPP
