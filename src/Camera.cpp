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
    auto cross = fakeUp.crossProduct(dir);
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

Matrix Camera::getProjectionMatrix() {
    float PI = std::atan(1.0f) * 4;
    //    float rad = (fovy / 180) * PI;
    //    float scale = near * tan(fovy * 0.5f);
    float scale = 1 / (tan((fovy/ 2) * (PI / 180)));

    return Matrix {{
           { scale, 0, 0, 0 },
           { 0, scale, 0, 0 },
           { 0, 0, -far / (far - near), -1 },
           { 0, 0, (-far * near) / (far - near), 0 }
    }};
}

void Camera::rotateCameraZ(float deg) {
    deg = (180.f / 720) * deg;

    Matrix eyeMatrix {eye};
    eyeMatrix.pushOne();

    float activeDeg = eyeMatrix.getAngleZ();
    deg = deg - activeDeg;

    std::cout << activeDeg << std::endl;

    Matrix m1 = Matrix::getRotationMatrixM1(eyeMatrix);
    Matrix rotation = Matrix::getRotationMatrixZ(deg);
    Matrix m5 = Matrix::getRotationMatrixM5(eyeMatrix);
    Matrix result = (m5 * rotation * m1) * eyeMatrix;

    eye.setX(result.getNumber(0,0));
    eye.setY(result.getNumber(1,0));
    eye.setZ(result.getNumber(2,0));
}

void Camera::rotateCameraY(float deg) {

}

void Camera::translateRelative(float x, float y, float z) {
    Matrix eyeMatrix {eye};
    eyeMatrix.pushOne();

    Matrix lookatMatrix {lookat};
    lookatMatrix.pushOne();

    Matrix m1 = Matrix::getRotationMatrixM1(eyeMatrix);
    Matrix translation = Matrix::getTranslationMatrix(x, y, z);
    Matrix m5 = Matrix::getRotationMatrixM5(eyeMatrix);
    Matrix result = (m5 * translation * m1) * eyeMatrix;

    Matrix l1 = Matrix::getRotationMatrixM1(lookatMatrix);
    Matrix ltranslation = Matrix::getTranslationMatrix(x, y, z);
    Matrix l5 = Matrix::getRotationMatrixM5(lookatMatrix);
    Matrix lresult = (m5 * ltranslation * m1) * lookatMatrix;

    eye.setX(result.getNumber(0,0));
    eye.setY(result.getNumber(1,0));
    eye.setZ(result.getNumber(2,0));

    lookat.setX(lresult.getNumber(0,0));
    lookat.setY(lresult.getNumber(1,0));
    lookat.setZ(lresult.getNumber(2,0));
}


