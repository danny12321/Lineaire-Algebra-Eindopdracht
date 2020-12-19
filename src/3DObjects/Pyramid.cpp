//
// Created by Thierry on 19-12-2020.
//

#include "Pyramid.hpp"


Pyramid::Pyramid() {
// Creates pyramide
// Create points
    Vector3D A {0,0,2};
    Vector3D B {0,0,0};
    Vector3D C {2,0,0};
    Vector3D D {2,0,2};
    Vector3D E {1,2,1};

// Create lines with these points
    lines.emplace_back(A, B);
    lines.emplace_back(B, C);
    lines.emplace_back(C, D);
    lines.emplace_back(D, A);
    lines.emplace_back(A, E);
    lines.emplace_back(B, E);
    lines.emplace_back(C, E);
    lines.emplace_back(D, E);
}
