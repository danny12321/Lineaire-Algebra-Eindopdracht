//
// Created by Thierry on 28-12-2020.
//

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
    // Moet eigenlijk in één loop gebeuren. Wordt nu 1 object per cycle verwijderd. Maar is wel priem zo.

    if(!objectsToDelete.empty()) {

        int indexToRemove = -1;
        for(int i = 0; i < objects.size(); ++i) {
            if(objects[i].get() == objectsToDelete[0]) {
                indexToRemove = i;
            }
        }

        if(indexToRemove != -1) {
            objects.erase(objects.begin() + indexToRemove);
            objectsToDelete.erase(objectsToDelete.begin());
        }
    }

}


