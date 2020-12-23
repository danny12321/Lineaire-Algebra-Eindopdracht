#include "Matrix.hpp"
#include "Camera.hpp"
#include "SDLRenderer.hpp"
#include "CoordinateSystem.hpp"
#include "Events.hpp"
#include "3DObjects/Pyramid.hpp"
#include "3DObjects/Cube.hpp"

int main() {
    SDLRenderer sdlRenderer;
    CoordinateSystem coordinateSystem {sdlRenderer, 50, 50, 0, 0, 1280, 720, 0, 1};
    Events events;

    Vector3D eye{5, 5, 5};
    Vector3D lookat{0, 0, 0};
    Camera camera{eye, lookat};

    Cube cube {};
    Pyramid pyramid {};

    if(sdlRenderer.init()) {
        while( !sdlRenderer.isRunning() ) {

            sdlRenderer.clearScreen();

            events.doEvents(coordinateSystem, sdlRenderer, camera);

            Matrix multiplyMatrix =  camera.getProjectionMatrix() *camera.getToOriginMatrix();

            coordinateSystem.setMultiplyMatrix(multiplyMatrix);

            sdlRenderer.setDrawColor(255, 0, 0, 255);

            cube.translate(0, 0,0.01);
            coordinateSystem.renderObject(pyramid);
            sdlRenderer.setDrawColor(0,0,255,255);
            coordinateSystem.renderObject(cube);


            sdlRenderer.setDrawColor(255, 255, 255, 255);

            sdlRenderer.render();

            sdlRenderer.delay();
        }

        sdlRenderer.close();
    }
    return 0;
}
