//
// Created by Thierry on 11-12-2020.
//

#ifndef LINAL_MATRIX_HPP
#define LINAL_MATRIX_HPP

#include <iostream>
#include <vector>
#include "Vector3D.hpp"

class Matrix {
public:
    Matrix(std::vector<std::vector<float>> matrix) : matrix(matrix) {};
    Matrix(Vector3D &vector);

    float getNumber(int row, int col) const { return matrix[row][col]; }
    void pushOne() { matrix.push_back({1}); }

    friend Matrix operator+(const Matrix& a, const Matrix& b);
    friend Matrix operator-(const Matrix& a, const Matrix& b);
    friend Matrix operator*(int scalair, const Matrix& a);
    friend Matrix operator*(const Matrix& a, int scalair);
    friend Matrix operator*(const Matrix& a, const Matrix& b);

    static Matrix getTranslationMatrix(float tx, float ty, float tz);
    static Matrix getRotationMatrixX(float deg);
    static Matrix getRotationMatrixY(float deg);
    static Matrix getRotationMatrixZ(float deg);

    static Matrix getRotationMatrixM1(Matrix m);
    static Matrix getRotationMatrixM2(Matrix m);
    static Matrix getRotationMatrixM4(Matrix m);
    static Matrix getRotationMatrixM5(Matrix m);

    static Matrix getScaleMatrix(float scaleX, float scaleY, float scaleZ);
private:
    std::vector<std::vector<float>> matrix;
};

#endif //LINAL_MATRIX_HPP
