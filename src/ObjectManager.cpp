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
