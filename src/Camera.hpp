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
    Matrix getProjectionMatrix();
    Matrix naberekening(const Matrix& m);

    void increaseEye() {eye.setX(eye.getX() + 0.1f);}
    void decreaseEye() {eye.setX(eye.getX() - 0.1f);}

    void increaseFov() { fovy += 1; }
    void decreaseFov() { fovy -= 1; }

    float getFov() {return fovy;}

    void setEyeX(float x) {eye.setX(x);}
    void setEyeY(float y) {eye.setY(y);}
    void setEyeZ(float z) {eye.setZ(z);}
private:
    Vector3D eye;
    Vector3D lookat;
    float near = 0.1f;
    float far = 100;
    float fovy = 60;
};


#endif //LINAL_CAMERA_HPP
