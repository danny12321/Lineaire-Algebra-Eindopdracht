//
// Created by Thierry on 18-12-2020.
//

#include "Object3D.hpp"


Object3D::Object3D() {

}

void Object3D::translate(float x, float y, float z) {
    Matrix translation = Matrix::getTranslationMatrix(x, y, z);
    for (auto* point : points) {
//        point->setX(point->getX() + 0.1f);
        auto a = vectorToMatrix(*point);
        Matrix pointMatrix = translation * vectorToMatrix(*point);

        point->setX(pointMatrix.getNumber(0,0));
        point->setY(pointMatrix.getNumber(1,0));
        point->setZ(pointMatrix.getNumber(2,0));
    }
}

Matrix Object3D::vectorToMatrix(const Vector3D &v) {
    return Matrix{{
                          {v.getX()},
                          {v.getY()},
                          {v.getZ()},
                          {1}
                  }};
}
