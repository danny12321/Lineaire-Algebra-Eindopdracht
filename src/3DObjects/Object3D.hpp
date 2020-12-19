//
// Created by Thierry on 18-12-2020.
//

#ifndef LINAL_OBJECT3D_HPP
#define LINAL_OBJECT3D_HPP

#include "../Line.hpp"
#include <vector>

class Object3D {
public:
    Object3D();

    [[nodiscard]] std::vector<Line> getLines() const { return lines; }
    void addLine(const Line& line) { lines.push_back(line); }

protected:
    std::vector<Line> lines;
};


#endif //LINAL_OBJECT3D_HPP
