#include "Matrix.hpp"
#include "Camera.hpp"
#include "SDLRenderer.hpp"
#include "CoordinateSystem.hpp"
#include "Events.hpp"
#include "Object3D.hpp"

int main() {
    SDLRenderer sdlRenderer;
    CoordinateSystem coordinateSystem {sdlRenderer, 50, 50, 0, 0, 1280, 720, 0, 1};
    Events events;

    Vector3D eye{5, 5, 8};
    Vector3D lookat{0, 0, 0};
    Camera camera{eye, lookat};
    if(sdlRenderer.init()) {
        while( !sdlRenderer.isRunning() ) {

            Matrix toOrigin = camera.getToOriginMatrix();

            Object3D obj {};

            events.doEvents(coordinateSystem, sdlRenderer, camera);

            sdlRenderer.clearScreen();
            sdlRenderer.setDrawColor(255, 255, 255, 255);
            coordinateSystem.drawCoordinateSystem();
            sdlRenderer.setDrawColor(255, 0, 0, 255);

            for(auto line : obj.lines) {
                Matrix lineStart {line.start};
                lineStart.pushOne();
                Matrix lineEnd {line.end};
                lineEnd.pushOne();

                Matrix c = toOrigin * lineStart;
                Matrix d = toOrigin * lineEnd;

                sdlRenderer.setDrawColor(255, 1, 1, 255);

                Vector3D pointOne {c.getNumber(0, 0), c.getNumber(1, 0), c.getNumber(2, 0)};
                Vector3D pointTwo {d.getNumber(0, 0), d.getNumber(1, 0), d.getNumber(2, 0)};

                coordinateSystem.renderLine(pointOne,pointTwo);
            }

            sdlRenderer.setDrawColor(255, 255, 255, 255);

//            Matrix a{{
//                             {1, 2},
//                             {3, 4}
//                     }};
//
//            Matrix b{{
//                             {4, 3},
//                             {2, 1}
//                     }};
//
//            // Act
//            Matrix result = Matrix::getRotationMatrixX(15);

            sdlRenderer.render();

            sdlRenderer.delay();
        }

        sdlRenderer.close();
    }
    return 0;
}
