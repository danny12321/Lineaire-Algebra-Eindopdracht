//
// Created by Thierry on 11-11-2020.
//

#include "CoordinateSystem.hpp"

void CoordinateSystem::drawCoordinateSystem() {
    xMiddle = (width / 2) + x;
    yMiddle = (height / 2) + y;

    sdlRenderer.setDrawColor(220,220, 220,255);


    // create x positive lines
    int xPos = xMiddle;
    while(xPos + xLineSize < width + x) {
        xPos += xLineSize;
        sdlRenderer.drawLine(xPos, y, xPos, height + y);
    }

    // create x negative lines
    xPos = xMiddle;
    while(xPos - xLineSize > x) {
        xPos -= xLineSize;
        sdlRenderer.drawLine(xPos, y, xPos, height + y);
    }

    // create y positive lines
    int yPos = yMiddle;
    while(yPos - yLineSize > y) {
        yPos -= yLineSize;
        sdlRenderer.drawLine(x, yPos, width + x, yPos);
    }

    // create y positive lines
    yPos = yMiddle;
    while(yPos + yLineSize < height + y) {
        yPos += yLineSize;
        sdlRenderer.drawLine(x, yPos, width + x, yPos);
    }

    // Create X and Y axis
    sdlRenderer.setDrawColor(0,0,255,255);
    sdlRenderer.drawLine(xMiddle, y, xMiddle, height + y);
    sdlRenderer.drawLine(x, yMiddle, width + x, yMiddle);
}

void CoordinateSystem::renderVector(Vector3D& vector, int xStart, int yStart) {
    sdlRenderer.drawLine(xMiddle + (xLineSize * xStart),
                         yMiddle + (yLineSize * (yStart * -1)),
                         xMiddle + (xLineSize * xStart) + (xLineSize * vector.getX()),
                         yMiddle + (yLineSize * (yStart * -1)) + (yLineSize * (vector.getY() * -1)));
}

void CoordinateSystem::renderLine(Vector3D& v1, Vector3D& v2) {
//    if(!isOffScreen(v1.getX(), v1.getY())) {
    sdlRenderer.drawLine(xMiddle + (xLineSize * v1.getX()),
                         yMiddle + (yLineSize * (v1.getY() * -1)),
                         xMiddle + (xLineSize * v2.getX()),
                         yMiddle + (yLineSize * (v2.getY() * -1)));
//    }
}

bool CoordinateSystem::isOffScreen(float x, float y) {
    if(xMiddle + (xLineSize * x) > width + this->x || xMiddle + (xLineSize * x) < this->x) {
        return true;
    }
    if(yMiddle + (yLineSize * (y * -1)) > height + this->y || yMiddle + (yLineSize * (y * -1)) < this->y) {
        return true;
    }
    return false;
}

void CoordinateSystem::plusXYLineSize(int size) {
    if(xLineSize < maxXLineSize && yLineSize < maxYLineSize) {
        xLineSize += size;
        yLineSize += size;
    }
}

void CoordinateSystem::minusXYLineSize(int size) {
    if(xLineSize > minXLineSize && yLineSize > minYLineSize) {
        xLineSize -= size;
        yLineSize -= size;
    }
}

//void CoordinateSystem::drawVectorList(Vector2DGroup vgroup) {
//    sdlRenderer.setDrawColor(255,0,0,0);
//    for (int i = 0; i < vgroup.getList().size(); ++i) {
//        if(i == vgroup.getList().size() - 1){
//            renderLine(vgroup.getList()[i], vgroup.getList()[0]);
//        } else {
//            renderLine(vgroup.getList()[i], vgroup.getList()[i+1]);
//        }
//    }
//
//}
