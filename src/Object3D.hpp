//
// Created by Thierry on 18-12-2020.
//

#ifndef LINAL_OBJECT3D_HPP
#define LINAL_OBJECT3D_HPP

#include "Line.hpp"
#include <vector>

class Object3D {
public:
    Object3D();
    std::vector<Line> lines;
private:
};


#endif //LINAL_OBJECT3D_HPP
