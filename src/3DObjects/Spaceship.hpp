//
// Created by Danny on 24/12/2020.
//

#ifndef LINAL_SPACESHIP_HPP
#define LINAL_SPACESHIP_HPP


#include "Object3D.hpp"

class Spaceship : public Object3D {
public:
    Spaceship();

    void update(const EventSystem &system) override;

};


#endif //LINAL_SPACESHIP_HPP
