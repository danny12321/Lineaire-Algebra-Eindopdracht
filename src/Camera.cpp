//
// Created by Thierry on 18-12-2020.
//

#include "Camera.hpp"

Vector3D Camera::getDirection() {
    return (eye - lookat).getEenheidsvector();
}

Vector3D Camera::getRight() {
    Vector3D fakeUp {0,1,0};
    Vector3D dir = this->getDirection();

    return (fakeUp.crossProduct(dir)).getEenheidsvector();
}

Vector3D Camera::getUp() {
    return (this->getDirection().crossProduct(this->getRight())).getEenheidsvector();
}

Matrix Camera::getRotationMatrix() {
    Vector3D dir = this->getDirection();
    Vector3D right = this->getRight();
    Vector3D up = this->getUp();

    return Matrix{{
          { right.getX(), right.getY(), right.getZ(), 0 },
          { up.getX(), up.getY(), up.getZ(), 0 },
          { dir.getX(), dir.getY(), dir.getZ(), 0 },
          { 0, 0, 0, 1 }
    }};
}

Matrix Camera::getTranslationMatrix() {
    return Matrix{{
          { 1, 0, 0, -eye.getX() },
          { 0, 1, 0, -eye.getY() },
          { 0, 0, 1, -eye.getZ() },
          { 0, 0, 0, 1 },
    }};
}

Matrix Camera::getToOriginMatrix() {
    return this->getRotationMatrix() * this->getTranslationMatrix();
}
