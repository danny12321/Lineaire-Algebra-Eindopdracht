//
// Created by Thierry on 18-12-2020.
//

#include "Object3D.hpp"


Object3D::Object3D() {

}

void Object3D::translate(float x, float y, float z) {
    Matrix translation = Matrix::getTranslationMatrix(x, y, z);
    updatePoints(translation);
}

void Object3D::rotateAroundOriginX(float deg) {
    Matrix rotation = Matrix::getRotationMatrixX(deg);
    updatePoints(rotation);
}

void Object3D::rotateAroundOriginY(float deg) {
    Matrix rotation = Matrix::getRotationMatrixY(deg);
    updatePoints(rotation);
}

void Object3D::rotateAroundOriginZ(float deg) {
    Matrix rotation = Matrix::getRotationMatrixZ(deg);
    updatePoints(rotation);
}


Matrix Object3D::vectorToMatrix(const Vector3D &v) {
    return Matrix{{
                          {v.getX()},
                          {v.getY()},
                          {v.getZ()},
                          {1}
                  }};
}



void Object3D::updatePoints(const Matrix &m) {
    for (auto* point : points) {
        Matrix pointMatrix = m * vectorToMatrix(*point);

        point->setX(pointMatrix.getNumber(0,0));
        point->setY(pointMatrix.getNumber(1,0));
        point->setZ(pointMatrix.getNumber(2,0));
    }
}

void Object3D::rotateX(float deg) {
    Vector3D middle = getMiddle();

    Matrix translation = Matrix::getTranslationMatrix(middle.getX(), middle.getY(), middle.getZ());
    Matrix translationBack = Matrix::getTranslationMatrix(-middle.getX(), -middle.getY(), -middle.getZ());
    Matrix result = translation * Matrix::getRotationMatrixX(deg) * translationBack;

    updatePoints(result);
}

void Object3D::rotateY(float deg) {
    Vector3D middle = getMiddle();

    Matrix translation = Matrix::getTranslationMatrix(middle.getX(), middle.getY(), middle.getZ());
    Matrix translationBack = Matrix::getTranslationMatrix(-middle.getX(), -middle.getY(), -middle.getZ());
    Matrix result = translation * Matrix::getRotationMatrixY(deg) * translationBack;

    updatePoints(result);
}

void Object3D::rotateZ(float deg) {
    Vector3D middle = getMiddle();

    Matrix translation = Matrix::getTranslationMatrix(middle.getX(), middle.getY(), middle.getZ());
    Matrix translationBack = Matrix::getTranslationMatrix(-middle.getX(), -middle.getY(), -middle.getZ());
    Matrix result = translation * Matrix::getRotationMatrixZ(deg) * translationBack;

    updatePoints(result);
}



Vector3D Object3D::getMiddle() {
    float x = 0;
    float y = 0;
    float z = 0;

    for(auto& point : points) {
        x += point->getX();
        y += point->getY();
        z += point->getZ();
    }

    return Vector3D {x / points.size(), y / points.size(), z / points.size() };
}

void Object3D::rotateAxis(const Vector3D &v, float deg) {
    Matrix axis = vectorToMatrix(v);

    Matrix m1 = Matrix::getRotationMatrixM1(axis);
    Matrix m2 = Matrix::getRotationMatrixM2(axis);
    Matrix m3 = Matrix::getRotationMatrixX(deg);
    Matrix m4 = Matrix::getRotationMatrixM4(axis);
    Matrix m5 = Matrix::getRotationMatrixM5(axis);

    Matrix result = m5 * m4 * m3 * m2 * m1;

    updatePoints(result);
}

void Object3D::scale(float scaleX, float scaleY, float scaleZ) {

    Vector3D middle = getMiddle();

    Matrix translation = Matrix::getTranslationMatrix(middle.getX(), middle.getY(), middle.getZ());
    Matrix translationBack = Matrix::getTranslationMatrix(-middle.getX(), -middle.getY(), -middle.getZ());
    Matrix scale = Matrix::getScaleMatrix(scaleX, scaleY, scaleZ);

    Matrix result = translation * scale * translationBack;

    updatePoints(result);
}
