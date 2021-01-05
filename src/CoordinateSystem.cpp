//
// Created by Thierry on 11-11-2020.
//

#include "CoordinateSystem.hpp"

void CoordinateSystem::renderVector(Vector3D& vector, int xStart, int yStart) {
    sdlRenderer.drawLine(xMiddle + (xLineSize * xStart),
                         yMiddle + (yLineSize * (yStart * -1)),
                         xMiddle + (xLineSize * xStart) + (xLineSize * vector.getX()),
                         yMiddle + (yLineSize * (yStart * -1)) + (yLineSize * (vector.getY() * -1)));
}

void CoordinateSystem::renderLine(Vector3D& v1, Vector3D& v2) {
    sdlRenderer.drawLine(xMiddle + (xLineSize * v1.getX()),
                         yMiddle + (yLineSize * (v1.getY() * -1)),
                         xMiddle + (xLineSize * v2.getX()),
                         yMiddle + (yLineSize * (v2.getY() * -1)));
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

void CoordinateSystem::renderObject(const Object3D &object) {

    auto xyzLines = object.getXyzAxisLines();
    if(!xyzLines.empty() && object.getShowLocalXyz()) {
        sdlRenderer.setDrawColor(255, 0, 0, 255);
        renderLineList(xyzLines);
    }

    auto boundingBoxLines = object.getBoundingBox();
    if(!boundingBoxLines.empty() && object.getShowBoundingBox()) {
        sdlRenderer.setDrawColor(0, 255, 0, 255);
        renderLineList(boundingBoxLines);
    }

    sdlRenderer.setDrawColor(object.getRedColor(), object.getGreenColor(), object.getBlueColor(), 255);
    renderLineList(object.getLines());
}

Matrix CoordinateSystem::naberekening(const Matrix& m) {
//    float screenXHalf = (float)sdlRenderer.getScreenWidth() / 2;
//    float screenYHalf = (float)sdlRenderer.getScreenHeight() / 2;

    float x = m.getNumber(0,0);
    // Ultra comment!
    // We doen de y-as keer -1 omdat sdl vanuit de linker bovenhoek rekent
    // en dan is naar benden de plus richting en naar boven de negatieverichting.
    // Dit willen wij anderzom hebben, daarom doen we de y keer -1.
    float y = m.getNumber(1,0);
    float z = m.getNumber(2,0);
    float w = m.getNumber(3,0);

    if(w < 0) {
        return Matrix {{
                               { 0 },
                               { 0 },
                               { 0 },
                               { 0 }
                       }};
    }

    float xw = (x / w);
    float yw = (y / w);
    float zw = (z / w);

    return Matrix {{
           { xw },
           { yw },
           { zw },
           { 1 }
    }};

//    return Matrix {{
//           { screenXHalf + ((xw / 2) * screenXHalf) },
//           { screenYHalf + ((yw / 2) * screenYHalf) },
//           { zw },
//           { w }
//   }};
}

void CoordinateSystem::renderLineList(const std::vector<Line*>& lines) {
    for(auto line : lines) {
        Matrix lineStart { *line->start };
        lineStart.pushOne();
        Matrix lineEnd { *line->end };
        lineEnd.pushOne();

        Matrix multiplyLineStart = *multiplyMatrix * lineStart;
        Matrix multiplyLineEnd =  *multiplyMatrix * lineEnd;

        if(multiplyLineStart.getNumber(3,0) < 0 || multiplyLineEnd.getNumber(3,0) < 0) {
            continue;
        }

        Matrix matrixLineStart = naberekening(multiplyLineStart);
        Matrix matrixLineEnd = naberekening(multiplyLineEnd);

        Vector3D pointOne {matrixLineStart.getNumber(0, 0), matrixLineStart.getNumber(1, 0), matrixLineStart.getNumber(2, 0)};
        Vector3D pointTwo {matrixLineEnd.getNumber(0, 0), matrixLineEnd.getNumber(1, 0), matrixLineEnd.getNumber(2, 0)};

        renderLine(pointOne, pointTwo);
    }
}
