//
// Created by Thierry on 28-12-2020.
//

#include "Bullet.hpp"

void Bullet::update(const EventSystem &system) {
    translate(velocity.getX(), velocity.getY(), velocity.getZ());
}

Bullet::Bullet(Vector3D position, Vector3D velocity, Vector3D rotation) : velocity(velocity) {

    points.push_back(new Vector3D{0,0,.1});
    points.push_back(new Vector3D{0,0,0});
    points.push_back(new Vector3D{.1,0,0});
    points.push_back(new Vector3D{.1,0,.1});
    points.push_back(new Vector3D{0,.1,.1});
    points.push_back(new Vector3D{0,.1,0});
    points.push_back(new Vector3D{.1,.1,0});
    points.push_back(new Vector3D{.1,.1,.1});

    this->setColor(255,0,0);

    // Create lines with these points
    lines.push_back(new Line {points[0], points[1]});
    lines.push_back(new Line {points[1], points[2]});
    lines.push_back(new Line {points[2], points[3]});
    lines.push_back(new Line {points[3], points[0]});
    lines.push_back(new Line {points[4], points[5]});
    lines.push_back(new Line {points[5], points[6]});
    lines.push_back(new Line {points[6], points[7]});
    lines.push_back(new Line {points[7], points[4]});

    lines.push_back(new Line {points[0], points[4]});
    lines.push_back(new Line {points[1], points[5]});
    lines.push_back(new Line {points[2], points[6]});
    lines.push_back(new Line {points[3], points[7]});

//    scale(0.1, 0.1, 0.1);

//    std::cout << "position " << "x:" <<position.getX() << " y:" << position.getY()<< " z:" << position.getZ() << std::endl;
//    std::cout << "rotation " << "x:" <<rotation.getX() << " y:" << rotation.getY()<< " z:" << rotation.getZ() << std::endl;
//    std::cout << "Angle: " << position.getAngleBetween(rotation) << std::endl;

    Vector3D vel = (rotation - position).getEenheidsvector();
    this->velocity.setX(vel.getX() * 0.5f);
    this->velocity.setY(vel.getY() * 0.5f);
    this->velocity.setZ(vel.getZ() * 0.5f);
//    float schuinezijde = rotationFromOrigin.getLength();
//    float aanliggende = rotationFromOrigin.getX();
//    const float PI = std::atan(1.0f) * 4;
//
//    float a = sqrt(rotationFromOrigin.getX() * rotationFromOrigin.getX() + rotationFromOrigin.getZ() * rotationFromOrigin.getZ());
//
//    float c = rotationFromOrigin.getLength();
//
//    float hoekxy = (acos( a / c ) * 180) / PI;
//
//    float b = sqrt((a * a) - (rotationFromOrigin.getZ() * rotationFromOrigin.getZ()));
//    float hoekxz = (acos( b / a ) * 180) / PI;
//    rotateZ(hoekxy);
//    rotateY(hoekxz);
    translate(position.getX(), position.getY(), position.getZ());
}
