//
// Created by Thierry on 18-12-2020.
//

#include "Object3D.hpp"


Object3D::Object3D() {

}

void Object3D::translate(float x, float y, float z) {
    Matrix translation = Matrix::getTranslationMatrix(x, y, z);
    for (auto& line : lines) {
        Matrix start = translation * vectorToMatrix(line.start);
        Matrix end = translation * vectorToMatrix(line.end);

        line.start.setX(start.getNumber(0,0));
        line.start.setY(start.getNumber(1,0));
        line.start.setZ(start.getNumber(2,0));

        line.end.setX(end.getNumber(0,0));
        line.end.setY(end.getNumber(1,0));
        line.end.setZ(end.getNumber(2,0));
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
