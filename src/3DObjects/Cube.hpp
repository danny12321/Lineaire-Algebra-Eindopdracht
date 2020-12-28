//
// Created by Thierry on 19-12-2020.
//

#ifndef LINAL_CUBE_HPP
#define LINAL_CUBE_HPP

#include "Object3D.hpp"
#include "../ObjectManager.hpp"

class Cube : public Object3D {
public:
    Cube();

    void update(const EventSystem &system) override;
};


#endif //LINAL_CUBE_HPP
