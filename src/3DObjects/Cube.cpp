//
// Created by Thierry on 19-12-2020.
//

#include "Cube.hpp"

Cube::Cube() {
// Creates pyramide
// Create points
    Vector3D A {0,0,1};
    Vector3D B {0,0,0};
    Vector3D C {3,0,0};
    Vector3D D {1,0,1};
    Vector3D E {0,1,1};
    Vector3D F {0,1,0};
    Vector3D G {1,1,0};
    Vector3D H {1,1,1};

// Create lines with these points
    lines.emplace_back(A, B);
    lines.emplace_back(B, C);
    lines.emplace_back(C, D);
    lines.emplace_back(D, A);
    lines.emplace_back(E, F);
    lines.emplace_back(F, G);
    lines.emplace_back(G, H);
    lines.emplace_back(H, E);

    lines.emplace_back(A, E);
    lines.emplace_back(B, F);
    lines.emplace_back(C, G);
    lines.emplace_back(D, H);
}
