//
// Created by Thierry on 11-12-2020.
//

#ifndef LINAL_MATRIX_HPP
#define LINAL_MATRIX_HPP

#include <iostream>
#include <vector>

class Matrix {
public:
    Matrix(std::vector<std::vector<float>> matrix) : matrix(matrix) {};
//    Matrix(Vector2D &vector);
//    Matrix(float deg);

    float getNumber(int row, int col) { return matrix[row][col]; }
    int getRows() { return matrix.size(); }
    void pushOne() { matrix.push_back({1}); }

    friend Matrix operator+(const Matrix& a, const Matrix& b);
    friend Matrix operator-(const Matrix& a, const Matrix& b);
    friend Matrix operator*(int scalair, const Matrix& a);
    friend Matrix operator*(const Matrix& a, int scalair);
    friend Matrix operator*(const Matrix& a, const Matrix& b);
//    friend Matrix operator*(const Matrix& a, const Vector2D& b);

//    static Matrix getTranslationMatrix(float tx, float ty, float tz);
    static Matrix getRotationMatrixX(float deg);
    static Matrix getRotationMatrixY(float deg);
    static Matrix getRotationMatrixZ(float deg);

//    static Matrix getRotationMatrixM1(Matrix m);
//    static Matrix getRotationMatrixM2(Matrix m);
//    static Matrix getRotationMatrixM4(Matrix m);
//    static Matrix getRotationMatrixM5(Matrix m);
private:
    const float PI = std::atan(1.0f)*4;
    std::vector<std::vector<float>> matrix;
};

#endif //LINAL_MATRIX_HPP
