//
// Created by Thierry on 28-12-2020.
//

#include "Bullet.hpp"
#include "Cube.hpp"


Bullet::Bullet(Vector3D position, float spaceShipVelocity, Vector3D rotation, ObjectManager& objectManager) : objectManager(objectManager) {
    this->setColor(255,0,0);

    points.push_back(new Vector3D{0,0,.1});
    points.push_back(new Vector3D{0,0,0});
    points.push_back(new Vector3D{.1,0,0});
    points.push_back(new Vector3D{.1,0,.1});
    points.push_back(new Vector3D{0,.1,.1});
    points.push_back(new Vector3D{0,.1,0});
    points.push_back(new Vector3D{.1,.1,0});
    points.push_back(new Vector3D{.1,.1,.1});

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


    Vector3D direction = (rotation - position).getEenheidsvector();
    this->velocity.setX(direction.getX() * (spaceShipVelocity + bulletSpeed));
    this->velocity.setY(direction.getY() * (spaceShipVelocity + bulletSpeed));
    this->velocity.setZ(direction.getZ() * (spaceShipVelocity + bulletSpeed));

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
    resetXyzAxis();
}

void Bullet::update(const EventSystem &system) {
        translate(velocity.getX(), velocity.getY(), velocity.getZ());
}

void Bullet::collide(Object3D &collider) {
    if(typeid(collider).name() == std::string{ "class Cube" }) {
        objectManager.removeObject(&collider);
        objectManager.removeObject(this);
    }
}
