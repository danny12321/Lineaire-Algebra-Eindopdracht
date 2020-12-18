//
// Created by Thierry on 18-12-2020.
//

#ifndef LINAL_CAMERA_HPP
#define LINAL_CAMERA_HPP

#include "Matrix.hpp"
#include "Vector3D.hpp"

class Camera {
public:
    Camera(Vector3D eye, Vector3D lookat) : eye(eye), lookat(lookat) {};

    Vector3D getDirection();
    Vector3D getRight();
    Vector3D getUp();
    Matrix getRotationMatrix();
    Matrix getTranslationMatrix();
    Matrix getToOriginMatrix();
private:
    Vector3D eye;
    Vector3D lookat;
};


#endif //LINAL_CAMERA_HPP
