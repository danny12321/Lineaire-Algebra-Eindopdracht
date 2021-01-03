//
// Created by Thierry on 28-12-2020.
//

#ifndef LINAL_OBJECTMANAGER_HPP
#define LINAL_OBJECTMANAGER_HPP

#include "3DObjects/Object3D.hpp"

class ObjectManager {
public:
    std::vector<std::unique_ptr<Object3D>>& getObjects() {return objects;}

    template<typename T>
    void addObject(T* object) {objectsToAdd.push_back(std::make_unique<T>(*object));}
    void update(const EventSystem &system);
    void doAddObjects();
    void collisionCheck();
private:
    bool doObjectsCollide(Object3D& one, Object3D& two);
    std::vector<std::unique_ptr<Object3D>> objects;
    std::vector<std::unique_ptr<Object3D>> objectsToAdd;
};

#endif //LINAL_OBJECTMANAGER_HPP
