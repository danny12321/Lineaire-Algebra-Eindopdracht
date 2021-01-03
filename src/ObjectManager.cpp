//
// Created by Thierry on 28-12-2020.
//

#include "ObjectManager.hpp"

void ObjectManager::update(const EventSystem &system) {

    for (auto &object : objects) {
        object->update(system);
    }

    doAddObjects();
}

void ObjectManager::doAddObjects() {
    for(auto &object : objectsToAdd) {
        objects.push_back(std::move(object));
    }
    objectsToAdd.clear();
}

void ObjectManager::collisionCheck() {
    for(auto& object : objects) {
        for(auto& otherObject : objects) {
            if(object != otherObject) {
                if(doObjectsCollide(*object, *otherObject)) {
                    object->collide(*otherObject);
                }
            }
        }
    }
}

bool ObjectManager::doObjectsCollide(Object3D &a, Object3D &b) {
    return (a.getNegativeX() <= b.getPositiveX() && a.getPositiveX() >= b.getNegativeX()) &&
           (a.getNegativeY() <= b.getPositiveY() && a.getPositiveY() >= b.getNegativeY()) &&
           (a.getNegativeZ() <= b.getPositiveZ() && a.getPositiveX() >= b.getNegativeZ());
}


