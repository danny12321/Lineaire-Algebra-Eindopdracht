//
// Created by Thierry on 18-12-2020.
//

#ifndef LINAL_OBJECT3D_HPP
#define LINAL_OBJECT3D_HPP

#include "Line.hpp"
#include <vector>

class Object3D {
    Object3D();
private:
    std::vector<Line> lines;
};


#endif //LINAL_OBJECT3D_HPP
