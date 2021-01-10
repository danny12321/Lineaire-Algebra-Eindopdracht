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
#include "EventSystem.hpp"

class CoordinateSystem {
public:
    CoordinateSystem(SDLRenderer& sdlRenderer, EventSystem &system) :
            sdlRenderer(sdlRenderer) {};

    void renderObject(const Object3D& object);

    Matrix naberekening(const Matrix& m);

    void renderLine(Vector3D &v1, Vector3D &v2);

    void setMultiplyMatrix(Matrix m) { multiplyMatrix = std::make_unique<Matrix>(m); };

    void renderLineList(const std::vector<Line*>& lines);

    void init(EventSystem& system);

private:
    std::unique_ptr<Matrix> multiplyMatrix;
    int xLineSize = 50;
    int yLineSize = 50;

    SDLRenderer& sdlRenderer;

    int xMiddle = 1920 / 2;
    int yMiddle = 1080 / 2;

    std::function<void(const SDL_Event &)> getEventHandler();

    void setMiddle();
};


#endif //LINAL_COORDINATESYSTEM_HPP