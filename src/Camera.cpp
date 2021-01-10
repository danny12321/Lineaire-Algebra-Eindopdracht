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

void Camera::followObject(Object3D* object, Vector3D* offset) {
    followingObject = object;
    followingOffset = offset;
}

void Camera::update(const EventSystem &system) {

    if(system.keyIsPressed(SDLK_t)) goForward(-.3);
    if(system.keyIsPressed(SDLK_g)) goForward(.3);

    if(system.keyIsPressed(SDLK_f)) goSideways(-.3);
    if(system.keyIsPressed(SDLK_h)) goSideways(.3);

    if(system.keyIsPressed(SDLK_UP)) goForward(-.3);
    if(system.keyIsPressed(SDLK_DOWN)) goForward(.3);

    if(system.keyIsPressed(SDLK_LEFT)) goSideways(-.3);
    if(system.keyIsPressed(SDLK_RIGHT)) goSideways(.3);

    if(system.keyIsPressed(SDLK_PAGEUP)) translateRelative(0, 0.3, 0);
    if(system.keyIsPressed(SDLK_PAGEDOWN)) translateRelative(0, -0.3, 0);

    auto mouseMotion = system.getMouseMotion();
    lookSideways(mouseMotion.getX());
    lookUpDown(mouseMotion.getY());

    auto mouseWheel = system.getMouseWheel();
    if(mouseWheel.getY() > 0) {
        decreaseFov();
    } else if(mouseWheel.getY() < 0) {
        increaseFov();
    }

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

void Camera::goForward(float distance) {
    Vector3D direction = getDirection();

    eye.setX(eye.getX() + (direction.getX() * distance));
    eye.setY(eye.getY() + (direction.getY()* distance));
    eye.setZ(eye.getZ() + (direction.getZ() * distance));

    lookat.setX(lookat.getX() + (direction.getX() * distance));
    lookat.setY(lookat.getY() + (direction.getY() * distance));
    lookat.setZ(lookat.getZ() + (direction.getZ() * distance));
}

void Camera::goSideways(float distance) {
    Vector3D direction = getRight();

    eye.setX(eye.getX() + (direction.getX() * distance));
    eye.setY(eye.getY() + (direction.getY()* distance));
    eye.setZ(eye.getZ() + (direction.getZ() * distance));

    lookat.setX(lookat.getX() + (direction.getX() * distance));
    lookat.setY(lookat.getY() + (direction.getY() * distance));
    lookat.setZ(lookat.getZ() + (direction.getZ() * distance));
}

void Camera::lookSideways(float deg) {
    Vector3D middle = eye;
    Vector3D rotationPoint = Vector3D{0,1,0};
    Matrix localXMatrix {rotationPoint};

    Matrix translation = Matrix::getTranslationMatrix(-middle.getX(), -middle.getY(), -middle.getZ());
    Matrix m5 = Matrix::getRotationMatrixM5(localXMatrix);
    Matrix m4 = Matrix::getRotationMatrixM4(localXMatrix);
    Matrix m3 = Matrix::getRotationMatrixX(deg);
    Matrix m2 = Matrix::getRotationMatrixM2(localXMatrix);
    Matrix m1 = Matrix::getRotationMatrixM1(localXMatrix);
    Matrix translationBack = Matrix::getTranslationMatrix(middle.getX(), middle.getY(), middle.getZ());
    Matrix result = translationBack * m5 * m4 * m3 * m2 * m1 * translation;

    Matrix mlookat = result * Matrix{{{lookat.getX()}, {lookat.getY()}, {lookat.getZ()}, {1}}};

    lookat.setX(mlookat.getNumber(0,0));
    lookat.setY(mlookat.getNumber(1,0));
    lookat.setZ(mlookat.getNumber(2,0));
}

void Camera::lookUpDown(float deg) {
    Vector3D middle = eye;
    Vector3D rotationPoint = getRight();
    Matrix localXMatrix {rotationPoint};

    Matrix translation = Matrix::getTranslationMatrix(-middle.getX(), -middle.getY(), -middle.getZ());
    Matrix m5 = Matrix::getRotationMatrixM5(localXMatrix);
    Matrix m4 = Matrix::getRotationMatrixM4(localXMatrix);
    Matrix m3 = Matrix::getRotationMatrixX(deg);
    Matrix m2 = Matrix::getRotationMatrixM2(localXMatrix);
    Matrix m1 = Matrix::getRotationMatrixM1(localXMatrix);
    Matrix translationBack = Matrix::getTranslationMatrix(middle.getX(), middle.getY(), middle.getZ());
    Matrix result = translationBack * m5 * m4 * m3 * m2 * m1 * translation;

    Matrix mlookat = result * Matrix{{{lookat.getX()}, {lookat.getY()}, {lookat.getZ()}, {1}}};

    lookat.setX(mlookat.getNumber(0,0));
    lookat.setY(mlookat.getNumber(1,0));
    lookat.setZ(mlookat.getNumber(2,0));
}