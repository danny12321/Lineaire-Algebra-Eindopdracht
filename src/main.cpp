#include "Matrix.hpp"
#include "Camera.hpp"
#include "SDLRenderer.hpp"
#include "CoordinateSystem.hpp"
#include "Events.hpp"

int main(int argc, char* args[]) {

    SDLRenderer sdlRenderer;
    CoordinateSystem coordinateSystem {sdlRenderer, 50, 50, 0, 0, 1280, 720, 0, 1};
    Events events;

    if(sdlRenderer.init()) {
        while( !sdlRenderer.isRunning() ) {
            Vector3D eye{10, 10, 10};
            Vector3D lookat{0, 0, 0};
            Camera camera{eye, lookat};

            events.doEvents(coordinateSystem, sdlRenderer);

            sdlRenderer.setDrawColor(255, 255, 255, 255);
            sdlRenderer.clearScreen();
            coordinateSystem.drawCoordinateSystem();

            Matrix a{{
                             {1, 2},
                             {3, 4}
                     }};

            Matrix b{{
                             {4, 3},
                             {2, 1}
                     }};

            // Act
            Matrix result = Matrix::getRotationMatrixX(15);

            sdlRenderer.render();

            sdlRenderer.delay();
        }
    }
    sdlRenderer.close();
    return 0;
}
