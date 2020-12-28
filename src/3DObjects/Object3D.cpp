//
// Created by Thierry on 18-12-2020.
//

#include "Object3D.hpp"
#include <nlohmann/json.hpp>
#include <string>
#include <fstream>


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
    for (auto *point : points) {
        Matrix pointMatrix = m * vectorToMatrix(*point);

        point->setX(pointMatrix.getNumber(0, 0));
        point->setY(pointMatrix.getNumber(1, 0));
        point->setZ(pointMatrix.getNumber(2, 0));
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

    for (auto &point : points) {
        x += point->getX();
        y += point->getY();
        z += point->getZ();
    }

    return Vector3D{x / points.size(), y / points.size(), z / points.size()};
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

Object3D::Object3D(const std::string &filename) {
    try {
        std::ifstream ifs("resources/objects/" + filename + ".json");
        nlohmann::json data = nlohmann::json::parse(ifs);

        int points_used = 0;

        for (auto &row : data) {
            for (auto &vert : row["verts"]) {
                points.push_back(new Vector3D{vert[0], vert[1], vert[2]});
                points_used++;
            }

            for (int i = 1; i < row["verts"].size(); ++i) {
                lines.push_back(new Line{points[points_used - i], points[points_used - i - 1]});
            }

            if (row["verts"].size() != 0) {
                lines.push_back(new Line{points[points_used - 1], points[points_used - row["verts"].size()]});
            }
        }
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

void Object3D::toOrigin() {
    Vector3D middle = getMiddle();
    Matrix result = Matrix::getTranslationMatrix(-middle.getX(), -middle.getY(), -middle.getZ());
    updatePoints(result);
}

void Object3D::rotateLocalX(float deg) {
    rotationX += deg;

    std::cout << rotationX << std::endl;

    Vector3D middle = getMiddle();

    Matrix translation = Matrix::getTranslationMatrix(middle.getX(), middle.getY(), middle.getZ());
    Matrix translationBack = Matrix::getTranslationMatrix(-middle.getX(), -middle.getY(), -middle.getZ());
    Matrix result = translation * Matrix::getRotationMatrixX(deg) * translationBack;

    updatePoints(result);
}

void Object3D::rotateLocalY(float deg) {
    rotationY += deg;

    Vector3D middle = getMiddle();

    Matrix translation = Matrix::getTranslationMatrix(middle.getX(), middle.getY(), middle.getZ());
    Matrix translationBack = Matrix::getTranslationMatrix(-middle.getX(), -middle.getY(), -middle.getZ());
    Matrix result = translation * Matrix::getRotationMatrixY(deg) * translationBack;

    updatePoints(result);
}

void Object3D::rotateLocalZ(float deg) {
    rotationZ += deg;

    Vector3D middle = getMiddle();

    Matrix translation = Matrix::getTranslationMatrix(middle.getX(), middle.getY(), middle.getZ());
    Matrix translationBack = Matrix::getTranslationMatrix(-middle.getX(), -middle.getY(), -middle.getZ());
    Matrix result = translation * Matrix::getRotationMatrixZ(deg) * translationBack;

    updatePoints(result);
}

Vector3D Object3D::getNormalVector(const Vector3D &origin, const Vector3D &v1, const Vector3D &v2) {
    Vector3D newV1 = Vector3D{v1.getX() - origin.getX(), v1.getY() - origin.getY(), v1.getZ() - origin.getZ(), };
    Vector3D newV2 = Vector3D{v2.getX() - origin.getX(), v2.getY() - origin.getY(), v2.getZ() - origin.getZ(), };
    Vector3D normalVector = newV1.crossProduct(newV2);
    normalVector.setX(normalVector.getX() + origin.getX());
    normalVector.setY(normalVector.getY() + origin.getY());
    normalVector.setZ(normalVector.getZ() + origin.getZ());

    return normalVector;
}
