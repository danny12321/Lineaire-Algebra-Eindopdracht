
#include "Matrix.hpp"
#define _USE_MATH_DEFINES
#include <math.h>

Matrix::Matrix(Vector3D &vector) {
    this->matrix = {
            {vector.getX()},
            {vector.getY()},
            {vector.getZ()}
    };
}

Matrix operator+(const Matrix &a, const Matrix &b) {
    // Checks
    if(a.matrix.size() != b.matrix.size()) throw "Matrices not same size";
    if(a.matrix[0].size() != b.matrix[0].size()) throw "Matrices not same size";

    std::vector<std::vector<float>> newMatrix(a.matrix.size(), std::vector<float>(a.matrix[0].size()));

    for(int row = 0; row < a.matrix.size(); ++row) {
        for (int col = 0; col < a.matrix[row].size(); ++col) {
            newMatrix[row][col] = a.matrix[row][col] + b.matrix[row][col];
        }
    }

    return Matrix {newMatrix};
}

Matrix operator-(const Matrix &a, const Matrix &b) {
    // Checks
    if(a.matrix.size() != b.matrix.size()) throw "Matrices not same size";
    if(a.matrix[0].size() != b.matrix[0].size()) throw "Matrices not same size";

    std::vector<std::vector<float>> newMatrix(a.matrix.size(), std::vector<float>(a.matrix[0].size()));

    for(int row = 0; row < a.matrix.size(); ++row) {
        for (int col = 0; col < a.matrix[row].size(); ++col) {
            newMatrix[row][col] = a.matrix[row][col] - b.matrix[row][col];
        }
    }

    return Matrix {newMatrix};
}

Matrix operator*(int scalair, const Matrix &a) {
    std::vector<std::vector<float>> newMatrix(a.matrix.size(), std::vector<float>(a.matrix[0].size()));

    for(int row = 0; row < a.matrix.size(); ++row) {
        for (int col = 0; col < a.matrix[row].size(); ++col) {
            newMatrix[row][col] = a.matrix[row][col] * scalair;
        }
    }

    return Matrix {newMatrix};
}

Matrix operator*(const Matrix &a, int scalair) {
    return scalair * a;
}

Matrix operator*(const Matrix &a, const Matrix &b) {
    // Checks
    if(a.matrix[0].size() != b.matrix.size()) {
        throw std::string("Matrix size is not correct for multiplying");
    }

    std::vector<std::vector<float>> newMatrix(a.matrix.size(), std::vector<float>(b.matrix[0].size()));

    for (int row = 0; row < a.matrix.size(); ++row) {
        for (int col = 0; col < b.matrix[0].size(); ++col) {

            for (int currentCalculating = 0; currentCalculating < a.matrix[0].size(); ++currentCalculating) {
                newMatrix[row][col] += a.matrix[row][currentCalculating] * b.matrix[currentCalculating][col];
            }

        }
    }

    return Matrix {newMatrix};
}

Matrix Matrix::getTranslationMatrix(float tx, float ty, float tz) {
    return Matrix {{
                           { 1, 0, 0, tx },
                           { 0, 1, 0, ty },
                           { 0, 0, 1, tz },
                           { 0, 0, 0, 1 }
                   }};
}

Matrix Matrix::getRotationMatrixX(float deg) {
    float rad = (deg / 180) * M_PI;

    return Matrix {{
                           { 1, 0, 0, 0 },
                           { 0, std::cos(rad), std::sin(rad), 0},
                           { 0, -std::sin(rad), std::cos(rad), 0 },
                           { 0, 0, 0, 1}
                   }};
}



Matrix Matrix::getRotationMatrixY(float deg) {
    float rad = (deg / 180) * M_PI;

    return Matrix {{
                           { std::cos(rad), 0, std::sin(rad), 0 },
                           { 0, 1, 0, 0},
                           { -std::sin(rad), 0, std::cos(rad), 0 },
                           { 0, 0, 0, 1}
                   }};
}

Matrix Matrix::getRotationMatrixZ(float deg) {
    float rad = (deg / 180) * M_PI;

    return Matrix {{
                           { std::cos(rad), -std::sin(rad), 0, 0 },
                           { std::sin(rad), std::cos(rad), 0, 0},
                           { 0, 0, 1, 0 },
                           { 0, 0, 0, 1}
                   }};
}

Matrix Matrix::getRotationMatrixM1(Matrix m) {
    float matrixX = m.getNumber(0,0);
    float matrixZ = m.getNumber(2,0);

    float xz = std::sqrt((matrixX * matrixX) + (matrixZ * matrixZ));

    if(xz == 0){
        return Matrix {{
               { 1, 0, 0, 0 },
               { 0, 1, 0, 0 },
               { 0, 0, 1, 0 },
               { 0, 0, 0, 1 }
       }};
    } else {
        return Matrix {{
               { matrixX / xz, 0, matrixZ / xz, 0 },
               { 0, 1, 0, 0 },
               { -matrixZ / xz, 0, matrixX / xz, 0 },
               { 0, 0, 0, 1 }
       }};
    }

}

Matrix Matrix::getRotationMatrixM2(Matrix m) {
    float matrixX = m.getNumber(0,0);
    float matrixY = m.getNumber(1,0);
    float matrixZ = m.getNumber(2,0);

    float xz = std::sqrt((matrixX * matrixX) + (matrixZ * matrixZ));
    float xyz = std::sqrt((matrixX * matrixX) + (matrixY * matrixY) + (matrixZ * matrixZ));

    return Matrix {{
                           { xz / xyz, matrixY / xyz, 0, 0 },
                           { -matrixY / xyz, xz / xyz, 0, 0 },
                           { 0, 0, 1, 0 },
                           { 0, 0, 0, 1 }
                   }};
}

Matrix Matrix::getRotationMatrixM4(Matrix m) {
    float matrixX = m.getNumber(0,0);
    float matrixY = m.getNumber(1,0);
    float matrixZ = m.getNumber(2,0);

    float xz = std::sqrt((matrixX * matrixX) + (matrixZ * matrixZ));
    float xyz = std::sqrt((matrixX * matrixX) + (matrixY * matrixY) + (matrixZ * matrixZ));

    return Matrix {{
                           { xz / xyz, -matrixY / xyz, 0, 0 },
                           { matrixY / xyz, xz / xyz, 0, 0 },
                           { 0, 0, 1, 0 },
                           { 0, 0, 0, 1 }
                   }};
}

Matrix Matrix::getRotationMatrixM5(Matrix m) {
    float matrixX = m.getNumber(0,0);
    float matrixZ = m.getNumber(2,0);

    float xz = std::sqrt((matrixX * matrixX) + (matrixZ * matrixZ));

    if(xz == 0){
        return Matrix {{
                               { 1, 0, 0, 0 },
                               { 0, 1, 0, 0 },
                               { 0, 0, 1, 0 },
                               { 0, 0, 0, 1 }
                       }};
    } else {
        return Matrix {{
                               { matrixX / xz, 0, -matrixZ / xz, 0 },
                               { 0, 1, 0, 0 },
                               { matrixZ / xz, 0, matrixX / xz, 0 },
                               { 0, 0, 0, 1 }
                       }};
    }
}

Matrix Matrix::getScaleMatrix(float scaleX, float scaleY, float scaleZ) {
    return Matrix {{
           { scaleX, 0, 0, 0 },
           { 0, scaleY, 0, 0 },
           { 0, 0, scaleZ, 0 },
           { 0, 0, 0, 1 }
   }};
}