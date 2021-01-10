//
// Created by Thierry on 28-12-2020.
//

#include <algorithm>
#include "ObjectManager.hpp"
#include "EventSystem.hpp"

void ObjectManager::update(const EventSystem &system) {

    if(system.keyIsPressedOnce(SDLK_b)) {
        showBoundingBoxes = !showBoundingBoxes;
        for (auto &object : objects) {
            object->setShowBoundingBox(showBoundingBoxes);
        }
    }

    if(system.keyIsPressedOnce(SDLK_l)) {
        showLocalXyz = !showLocalXyz;
        for (auto &object : objects) {
            object->setShowLocalXyz(showLocalXyz);
        }
    }

    for (auto &object : objects) {
        object->update(system);
    }

    doRemoveObjects();
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
           (a.getNegativeZ() <= b.getPositiveZ() && a.getPositiveZ() >= b.getNegativeZ());
}

void ObjectManager::removeObject(Object3D *object) {
    objectsToDelete.push_back(object);
}

void ObjectManager::doRemoveObjects() {
    auto it = std::remove_if(objects.begin(), objects.end(), [this](const std::unique_ptr<Object3D> &object) {
        return std::any_of(objectsToDelete.begin(), objectsToDelete.end(), [&object](const Object3D* objectToDelete) {
            return object.get() == objectToDelete;
        });
    });

    objects.erase(it, objects.end());
    objectsToDelete.clear();
}


