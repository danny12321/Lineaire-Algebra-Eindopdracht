//
// Created by Danny on 28/12/2020.
//

#include "Axis.hpp"

Axis::Axis(Vector3D *point, int r, int g, int b) {
    points.push_back(new Vector3D{0, 0, 0});
    points.push_back(point);

    lines.push_back(new Line{points[0], points[1]});

    setColor(r, g, b);
}
