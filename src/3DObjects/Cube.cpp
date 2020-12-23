//
// Created by Thierry on 19-12-2020.
//

#include "Cube.hpp"

Cube::Cube() {
    // Create points
//    points.push_back(std::make_unique<Vector3D>(0,0,1));
//    points.push_back(std::make_unique<Vector3D>(0,0,0));
//    points.push_back(std::make_unique<Vector3D>(1,0,0));
//    points.push_back(std::make_unique<Vector3D>(1,0,1));
//    points.push_back(std::make_unique<Vector3D>(0,1,1));
//    points.push_back(std::make_unique<Vector3D>(0,1,0));
//    points.push_back(std::make_unique<Vector3D>(1,1,0));
//    points.push_back(std::make_unique<Vector3D>(1,1,1));

    points.push_back(new Vector3D{0.5,0,1});
    points.push_back(new Vector3D{0.5,0,0});
    points.push_back(new Vector3D{1.5,0,0});
    points.push_back(new Vector3D{1.5,0,1});
    points.push_back(new Vector3D{0.5,1,1});
    points.push_back(new Vector3D{0.5,1,0});
    points.push_back(new Vector3D{1.5,1,0});
    points.push_back(new Vector3D{1.5,1,1});

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
}
