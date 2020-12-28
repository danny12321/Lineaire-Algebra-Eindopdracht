//
// Created by Thierry on 18-12-2020.
//

#include "Camera.hpp"

Vector3D Camera::getDirection() {
    return (eye - lookat).getEenheidsvector();
}

Vector3D Camera::getRight() {
    Vector3D fakeUp{0, 1, 0};
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
                          {right.getX(), right.getY(), right.getZ(), 0},
                          {up.getX(), up.getY(), up.getZ(), 0},
                          {dir.getX(), dir.getY(), dir.getZ(), 0},
                          {0, 0, 0, 1}
                  }};
}

Matrix Camera::getTranslationMatrix() {
    return Matrix{{
                          {1, 0, 0, -eye.getX()},
                          {0, 1, 0, -eye.getY()},
                          {0, 0, 1, -eye.getZ()},
                          {0, 0, 0, 1},
                  }};
}

Matrix Camera::getToOriginMatrix() {
    return this->getRotationMatrix() * this->getTranslationMatrix();
}

Matrix Camera::getProjectionMatrix() {
    float PI = std::atan(1.0f) * 4;
    //    float rad = (fovy / 180) * PI;
    //    float scale = near * tan(fovy * 0.5f);
    float scale = 1 / (tan((fovy / 2) * (PI / 180)));

    return Matrix{{
                          {scale, 0, 0, 0},
                          {0, scale, 0, 0},
                          {0, 0, -far / (far - near), -1},
                          {0, 0, (-far * near) / (far - near), 0}
                  }};
}

void Camera::rotateCameraZ(float deg) {
    Matrix eyeMatrix{eye};
    eyeMatrix.pushOne();

    Matrix m1 = Matrix::getRotationMatrixM1(eyeMatrix);
    Matrix rotation = Matrix::getRotationMatrixZ(deg);
    Matrix m5 = Matrix::getRotationMatrixM5(eyeMatrix);
    Matrix result = (m5 * rotation * m1) * eyeMatrix;

    eye.setX(result.getNumber(0, 0));
    eye.setY(result.getNumber(1, 0));
    eye.setZ(result.getNumber(2, 0));
}

void Camera::rotateCameraY(float deg) {
    Matrix eyeMatrix{eye};
    eyeMatrix.pushOne();

    Matrix m1 = Matrix::getRotationMatrixM1(eyeMatrix);
    Matrix m2 = Matrix::getRotationMatrixM2(eyeMatrix);
    Matrix rotation = Matrix::getRotationMatrixY(deg);
    Matrix m4 = Matrix::getRotationMatrixM4(eyeMatrix);
    Matrix m5 = Matrix::getRotationMatrixM5(eyeMatrix);
    Matrix result = (m5 * m4 * rotation * m2 * m1) * eyeMatrix;

    eye.setX(result.getNumber(0, 0));
    eye.setY(result.getNumber(1, 0));
    eye.setZ(result.getNumber(2, 0));
}

void Camera::translateRelative(float x, float y, float z) {
    Matrix eyeMatrix{eye};
    eyeMatrix.pushOne();

    Matrix lookatMatrix{lookat};
    lookatMatrix.pushOne();

    Matrix m1 = Matrix::getRotationMatrixM1(eyeMatrix);
    Matrix translation = Matrix::getTranslationMatrix(x, y, z);
    Matrix m5 = Matrix::getRotationMatrixM5(eyeMatrix);
    Matrix result = (m5 * translation * m1) * eyeMatrix;

    Matrix l1 = Matrix::getRotationMatrixM1(lookatMatrix);
    Matrix ltranslation = Matrix::getTranslationMatrix(x, y, z);
    Matrix l5 = Matrix::getRotationMatrixM5(lookatMatrix);
    Matrix lresult = (m5 * ltranslation * m1) * lookatMatrix;

    eye.setX(result.getNumber(0, 0));
    eye.setY(result.getNumber(1, 0));
    eye.setZ(result.getNumber(2, 0));

    lookat.setX(lresult.getNumber(0, 0));
    lookat.setY(lresult.getNumber(1, 0));
    lookat.setZ(lresult.getNumber(2, 0));
}

void Camera::rotateCameraRelativeY(float deg) {
//    Matrix lookatMatrix {lookat};
//    lookatMatrix.pushOne();
//
//    Matrix eyeMatrix {eye};
//    eyeMatrix.pushOne();
//
//    Matrix translationToOrigin = Matrix::getTranslationMatrix(eye.getX(), eye.getY(), eye.getZ());
//    Matrix m1 = Matrix::getRotationMatrixM1(lookatMatrix);
//    Matrix m2 = Matrix::getRotationMatrixM2(lookatMatrix);
//    Matrix rotation = Matrix::getRotationMatrixY(deg);
//    Matrix m4 = Matrix::getRotationMatrixM4(lookatMatrix);
//    Matrix m5 = Matrix::getRotationMatrixM5(lookatMatrix);
//    Matrix translationBack = Matrix::getTranslationMatrix(-eye.getX(), -eye.getY(), -eye.getZ());
//    Matrix result = (translationBack * m5 * m4 * rotation * m2 * m1 * translationToOrigin) * lookatMatrix;
//
//    lookat.setX(result.getNumber(0,0));
//    lookat.setY(result.getNumber(1,0));
//    lookat.setZ(result.getNumber(2,0));
}

void Camera::rotateCameraRelativeZ(float deg) {

}

void Camera::handleEvents(const EventSystem &system) {
    if (system.keyIsPressed(SDLK_HOME)) fovy -= 1;
    if (system.keyIsPressed(SDLK_END)) fovy += 1;


    if (system.keyIsPressed(SDLK_LEFT)) setEyeX(eye.getX() - .1f);
    if (system.keyIsPressed(SDLK_RIGHT)) setEyeX(eye.getX() + .1f);
    if (system.keyIsPressed(SDLK_UP)) setEyeZ(eye.getZ() - .1f);
    if (system.keyIsPressed(SDLK_DOWN)) setEyeZ(eye.getZ() + .1f);
    if (system.keyIsPressed(SDLK_PAGEUP)) setEyeY(eye.getY() + .1f);
    if (system.keyIsPressed(SDLK_PAGEDOWN)) setEyeY(eye.getY() - .1f);
//    if (system.keyIsPressed(SDLK_w)) translateRelative(-1, 0, 0);
//    if (system.keyIsPressed(SDLK_s)) translateRelative(1, 0, 0);
//    if (system.keyIsPressed(SDLK_a)) translateRelative(0, 0, 1);
//    if (system.keyIsPressed(SDLK_d)) translateRelative(0, 0, -1);
    if (system.keyIsPressed(SDLK_LSHIFT)) translateRelative(0, -1, 0);
//    if (system.keyIsPressed(SDLK_SPACE)) translateRelative(0, 1, 0);
//    if (system.keyIsPressed(SDLK_q)) rotateCameraY(-1);
//    if (system.keyIsPressed(SDLK_e)) rotateCameraY(1);
    if (system.keyIsPressed(SDLK_r)) rotateCameraZ(1);
    if (system.keyIsPressed(SDLK_f)) rotateCameraZ(-1);
}

void Camera::followObject(Object3D &object, Vector3D* offset) {
    followingObject = &object;
    followingOffset = offset;
}

void Camera::update() {
    if(followingObject == nullptr) {
        return;
    }

    Vector3D middle = followingObject->getMiddle();

    lookat.setX(middle.getX());
    lookat.setY(middle.getY());
    lookat.setZ(middle.getZ());

    eye.setX(middle.getX() + followingOffset->getX());
    eye.setY(middle.getY() + followingOffset->getY());
    eye.setZ(middle.getZ() + followingOffset->getZ());
}
