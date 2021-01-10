//
// Created by Thierry on 26-11-2020.
//

#include <cmath>
#include "Vector3D.hpp"
#include <math.h>

Vector3D operator+(const Vector3D &a, const Vector3D &b) {
    return Vector3D {a.x + b.x, a.y + b.y, a.z + b.z};
}

Vector3D operator-(const Vector3D &a, const Vector3D &b) {
    return Vector3D {a.x - b.x, a.y - b.y, a.z - b.z};
}

Vector3D operator*(int scalair, const Vector3D &a) {
    return Vector3D {a.x * scalair, a.y * scalair, a.z * scalair};
}

Vector3D operator*(const Vector3D &a, int scalair) {
    return Vector3D {a.x * scalair, a.y * scalair, a.z * scalair};
}

float Vector3D::dotProduct(const Vector3D &a) {
    return (this->getX() * a.getX()) + (this->getY() * a.getY()) + (this->getZ() * a.getZ());
}

Vector3D Vector3D::crossProduct(const Vector3D &a) {
    return Vector3D(
            (this->getY() * a.getZ()) - (this->getZ() * a.getY()),
            (this->getZ() * a.getX()) - (this->getX() * a.getZ()),
            (this->getX() * a.getY()) - (this->getY() * a.getX())
    );
}

bool Vector3D::independentOf(const Vector3D &a) {
    float factor = a.getX() / this->getX();
    return !(this->getY() * factor == a.getY() && this->getZ() * factor == a.getZ());
}

float Vector3D::getLength() const {
    return sqrt((this->getX() * this->getX()) + (this->getY() * this->getY()) + (this->getZ() * this->getZ()));
}

float Vector3D::getAngleBetween(const Vector3D &a) {
    float dotproduct = this->dotProduct(a);
    float lengthThis = this->getLength();
    float lengthA = a.getLength();
    return (acos(dotproduct / (lengthThis * lengthA)) * 180) / M_PI;
}

Vector3D Vector3D::getEenheidsvector() {
    float length = this->getLength();
    if(length == 0) {
        return Vector3D(0,0,0);
    }
    return Vector3D(this->getX() / length, this->getY() / length, this->getZ() / length);
}