//
// Created by Thierry on 19-12-2020.
//

#include "Pyramid.hpp"


Pyramid::Pyramid() {
//// Creates pyramide
    points.push_back(new Vector3D{0,0,2});
    points.push_back(new Vector3D{0,0,0});
    points.push_back(new Vector3D{2,0,0});
    points.push_back(new Vector3D{2,0,2});
    points.push_back(new Vector3D{1,2,1});


    // Create lines with these points
    lines.push_back(new Line {points[0], points[1]});
    lines.push_back(new Line {points[1], points[2]});
    lines.push_back(new Line {points[2], points[3]});
    lines.push_back(new Line {points[3], points[0]});
    lines.push_back(new Line {points[3], points[4]});
    lines.push_back(new Line {points[2], points[4]});
    lines.push_back(new Line {points[1], points[4]});
    lines.push_back(new Line {points[0], points[4]});

}
