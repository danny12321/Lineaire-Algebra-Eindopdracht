//
// Created by Thierry on 11-11-2020.
//

#ifndef LINAL_COORDINATESYSTEM_HPP
#define LINAL_COORDINATESYSTEM_HPP

#include <vector>
#include "SDLRenderer.hpp"
#include "Vector3D.hpp"
#include "3DObjects/Object3D.hpp"
#include "Matrix.hpp"

class CoordinateSystem {
public:
    CoordinateSystem(SDLRenderer& sdlRenderer, int width, int height) :
            sdlRenderer(sdlRenderer), width(width), height(height) {};


    void renderVector(Vector3D& vector, int xStart, int yStart);

    void plusXYLineSize(int size);
    void minusXYLineSize(int size);

    void setMiddleX(int x) { xMiddle = x; }
    void setMiddleY(int y) { yMiddle = y; }

    void renderObject(const Object3D& object);

    Matrix naberekening(const Matrix& m);

    void renderLine(Vector3D &v1, Vector3D &v2);

    void setMultiplyMatrix(Matrix m) { multiplyMatrix = std::make_unique<Matrix>(m); };

    void renderLineList(const std::vector<Line*>& lines);
private:
    std::unique_ptr<Matrix> multiplyMatrix;
    int maxXLineSize = 500;
    int maxYLineSize = 500;
    int minXLineSize = 10;
    int minYLineSize = 10;
    int xLineSize = 50;
    int yLineSize = 50;
    int width = 0;
    int height = 0;

    SDLRenderer& sdlRenderer;
    int xMiddle = width / 2;
    int yMiddle = height / 2;
};


#endif //LINAL_COORDINATESYSTEM_HPP