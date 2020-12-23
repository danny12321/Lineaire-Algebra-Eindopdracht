//
// Created by Thierry on 18-12-2020.
//

#ifndef LINAL_OBJECT3D_HPP
#define LINAL_OBJECT3D_HPP

#include "../Line.hpp"
#include <vector>
#include "../Matrix.hpp"

class Object3D {
public:
    Object3D();

    [[nodiscard]] std::vector<Line*> getLines() const { return lines; }
    void addLine(Line* line) { lines.push_back(line); }

    void translate(float x, float y, float z);

protected:
    std::vector<Line*> lines;
    std::vector<Vector3D*> points;
private:
    Matrix vectorToMatrix(const Vector3D& v);
};


#endif //LINAL_OBJECT3D_HPP
