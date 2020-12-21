
#include "Matrix.hpp"

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
                           { 0, 0, 0, 1 },
                   }};
}

Matrix Matrix::getRotationMatrixX(float deg) {
    float PI = std::atan(1.0f) * 4;
    float rad = (deg / 180) * PI;

    return Matrix {{
                           { 1, 0, 0, 0 },
                           { 0, std::cos(rad), -std::sin(rad), 0},
                           { 0, std::sin(rad), std::cos(rad), 0 },
                           { 0, 0, 0, 1}
                   }};
}

Matrix Matrix::getRotationMatrixY(float deg) {
    float PI = std::atan(1.0f) * 4;
    float rad = (deg / 180) * PI;

    return Matrix {{
                           { std::cos(rad), 0, std::sin(rad), 0 },
                           { 0, 1, 0, 0},
                           { -std::sin(rad), 0, std::cos(rad), 0 },
                           { 0, 0, 0, 1}
                   }};
}

Matrix Matrix::getRotationMatrixZ(float deg) {
    float PI = std::atan(1.0f) * 4;
    float rad = (deg / 180) * PI;

    return Matrix {{
                           { std::cos(rad), -std::sin(rad), 0, 0 },
                           { std::sin(rad), std::cos(rad), 0, 0},
                           { 0, 0, 1, 0 },
                           { 0, 0, 0, 1}
                   }};
}