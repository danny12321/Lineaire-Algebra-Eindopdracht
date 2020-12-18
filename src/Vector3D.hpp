//
// Created by Thierry on 26-11-2020.
//

#ifndef LINAL_VECTOR3D_HPP
#define LINAL_VECTOR3D_HPP

#include <cmath>
#include <math.h>

class Vector3D {
public:
    Vector3D(float x, float y, float z) : x(x), y(y), z(z)  {};

    friend Vector3D operator+(const Vector3D& a, const Vector3D& b);
    friend Vector3D operator-(const Vector3D& a, const Vector3D& b);
    friend Vector3D operator*(int scalair, const Vector3D& a);
    friend Vector3D operator*(const Vector3D& a, int scalair);

    float dotProduct(const Vector3D& a);
    Vector3D crossProduct(const Vector3D& a);
    bool independentOf(const Vector3D& a);
    float getAngleBetween(const Vector3D& a);
    float getAngleBetweenInRadians(const Vector3D& a);

    [[nodiscard]] float getX() const { return x; }
    [[nodiscard]] float getY() const { return y; }
    [[nodiscard]] float getZ() const { return z; }

    float getLength() const;
    Vector3D getEenheidsvector();

    void setX(float x) { this->x = x; };
    void setY(float y) { this->y = y; };
    void setZ(float z) { this->y = z; };

//    Matrix getMatrix1x2();
//    Matrix getMatrix1x3();
private:
    const float PI = std::atan(1.0f)*4;
    float x, y, z;
};


#endif //LINAL_VECTOR3D_HPP