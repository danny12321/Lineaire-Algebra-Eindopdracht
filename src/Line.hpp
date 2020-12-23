//
// Created by Thierry on 18-12-2020.
//

#ifndef LINAL_LINE_HPP
#define LINAL_LINE_HPP

#include "Vector3D.hpp"

class Line {
public:
    Line(Vector3D* start, Vector3D* end) : start(start), end(end) {};
    Vector3D* start;
    Vector3D* end;
private:
};


#endif //LINAL_LINE_HPP
