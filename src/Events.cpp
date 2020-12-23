//
// Created by Thierry on 12-11-2020.
//

#include "Events.hpp"

void Events::doEvents(CoordinateSystem &coordinateSystem, SDLRenderer &sdlRenderer, Camera &camera) {
    while (SDL_PollEvent(&e) != 0) {

        //User requests quit
        if (e.type == SDL_QUIT) {
            sdlRenderer.quitApp();
        }

        if (e.type == SDL_MOUSEWHEEL) {
            if (e.wheel.y > 0) // scroll up
                camera.decreaseFov();
            else if (e.wheel.y < 0) // scroll down
                camera.increaseFov();
            std::cout << camera.getFov() << std::endl;
        }

        if(e.type == SDL_KEYDOWN) {
            if(e.key.keysym.sym == SDLK_LEFT) camera.setEyeX(camera.getEye().getX() - .1f);
            if(e.key.keysym.sym == SDLK_RIGHT) camera.setEyeX(camera.getEye().getX() + .1f);
            if(e.key.keysym.sym == SDLK_UP) camera.setEyeZ(camera.getEye().getZ() - .1f);
            if(e.key.keysym.sym == SDLK_DOWN) camera.setEyeZ(camera.getEye().getZ() + .1f);
            if(e.key.keysym.sym == SDLK_PAGEUP) camera.setEyeY(camera.getEye().getY() + .1f);
            if(e.key.keysym.sym == SDLK_PAGEDOWN) camera.setEyeY(camera.getEye().getY() - .1f);
        }
    }
}
