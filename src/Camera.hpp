//
// Created by Thierry on 18-12-2020.
//

#ifndef LINAL_CAMERA_HPP
#define LINAL_CAMERA_HPP

#include "Matrix.hpp"
#include "Vector3D.hpp"
#include "EventSystem.hpp"
#include "3DObjects/Object3D.hpp"

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

    Matrix naberekening(const Matrix &m);

    void increaseFov() { if (fovy < 179) fovy += 1; }

    void decreaseFov() { if (fovy > 1) fovy -= 1; }

    float getFov() { return fovy; }

    void setEyeX(float x) { eye.setX(x); }

    void setEyeY(float y) { eye.setY(y); }

    void setEyeZ(float z) { eye.setZ(z); }

    [[nodiscard]] Vector3D getEye() const { return eye; }

    void rotateCameraY(float deg);
    void rotateCameraZ(float deg);

    void rotateCameraRelativeY(float deg);
    void rotateCameraRelativeZ(float deg);

    void translateRelative(float x, float y, float z);

    void handleEvents(const EventSystem &system);

    void goForward(float distance);
    void goSideways(float distance);

    void lookSideways(float deg);

    void lookUpDown(float deg);

    void followObject(Object3D& object, Vector3D* offset);

    void update(const EventSystem &system);
private:
    Vector3D eye;
    Vector3D lookat;
    Object3D* followingObject = nullptr;
    Vector3D* followingOffset = nullptr;
    float near = 0.1f;
    float far = 100;
    float fovy = 60;
};


#endif //LINAL_CAMERA_HPP
