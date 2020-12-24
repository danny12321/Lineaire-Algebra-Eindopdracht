//
// Created by Danny on 23/12/2020.
//

#ifndef LINAL_JSONOBJECT3D_HPP
#define LINAL_JSONOBJECT3D_HPP

#include "Object3D.hpp"

class JsonObject3D : public Object3D {
public:
    JsonObject3D(const std::string &filename);
};

#endif //LINAL_JSONOBJECT3D_HPP
