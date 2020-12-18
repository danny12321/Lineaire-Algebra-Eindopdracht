//
// Created by Thierry on 11-11-2020.
//

#ifndef LINAL_COORDINATESYSTEM_HPP
#define LINAL_COORDINATESYSTEM_HPP

#include <vector>
#include "SDLRenderer.hpp"
#include "Vector3D.hpp"

class CoordinateSystem {
public:
    CoordinateSystem(SDLRenderer& sdlRenderer, int xLineSize, int yLineSize, int x, int y, int width, int height, int xAxis, int yAxis) :
            sdlRenderer(sdlRenderer), xLineSize(xLineSize), yLineSize(yLineSize), x(x), y(y), width(width), height(height), xAxis(xAxis), yAxis(yAxis) {};

    void drawCoordinateSystem();

    void renderVector(Vector3D& vector, int xStart, int yStart);

    void plusXYLineSize(int size);
    void minusXYLineSize(int size);

    void setMiddleX(int x) { xMiddle = x; }
    void setMiddleY(int y) { yMiddle = y; }

//    void drawVectorList(Vector2DGroup vlist);

    void renderLine(Vector3D &v1, Vector3D &v2);
private:
    int maxXLineSize = 500;
    int maxYLineSize = 500;
    int minXLineSize = 10;
    int minYLineSize = 10;
    int xLineSize = 50;
    int yLineSize = 50;
    int x = 0;
    int y = 0;
    int width = 0;
    int height = 0;
    int xAxis = 0;
    int yAxis = 1;

    SDLRenderer& sdlRenderer;
    int xMiddle = width / 2;
    int yMiddle = height / 2;

    bool isOffScreen(float x, float y);
};


#endif //LINAL_COORDINATESYSTEM_HPP