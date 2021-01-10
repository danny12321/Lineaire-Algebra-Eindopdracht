//
// Created by Thierry on 24-12-2020.
//

#include "Jezus.hpp"

Jezus::Jezus() : Object3D("jezus") {
    rotateX(90);
    scale(0.1, 0.1, 0.1);
    toOrigin();
    translate(0,0,-5);
    resetXyzAxis();
}