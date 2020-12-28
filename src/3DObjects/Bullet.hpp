//
// Created by Thierry on 28-12-2020.
//

#ifndef LINAL_BULLET_HPP
#define LINAL_BULLET_HPP

#include "Object3D.hpp"

class Bullet : public Object3D {

public:
    Bullet(Vector3D position, Vector3D velocity, Vector3D rotation);
    void update(const EventSystem &system) override;

private:
    Vector3D velocity;
};


#endif //LINAL_BULLET_HPP
