#include "Matrix.hpp"
#include "Camera.hpp"
#include "SDLRenderer.hpp"
#include "CoordinateSystem.hpp"
#include "Events.hpp"
#include "3DObjects/Pyramid.hpp"
#include "3DObjects/Cube.hpp"
#include "3DObjects/JsonObject3D.hpp"

int main() {
    SDLRenderer sdlRenderer;
    CoordinateSystem coordinateSystem {sdlRenderer, 50, 50, 0, 0, 1280, 720, 0, 1};
    Events events;

    Vector3D eye{200, 100, 200};
    Vector3D lookat{0, 0, 0};
    Camera camera{eye, lookat};

    JsonObject3D spaceship {"saturn"};
    JsonObject3D jezus {"jezus"};
    jezus.rotateX(-90);
    spaceship.rotateX(180);


    if(sdlRenderer.init()) {
        while( !sdlRenderer.isRunning() ) {

            sdlRenderer.clearScreen();

            events.doEvents(coordinateSystem, sdlRenderer, camera);

            Matrix multiplyMatrix =  camera.getProjectionMatrix() *camera.getToOriginMatrix();

            coordinateSystem.setMultiplyMatrix(multiplyMatrix);

            coordinateSystem.renderObject(spaceship);
            coordinateSystem.renderObject(jezus);

            sdlRenderer.setDrawColor(255, 255, 255, 255);
            sdlRenderer.render();

            sdlRenderer.delay();
        }

        sdlRenderer.close();
    }
    return 0;
}
