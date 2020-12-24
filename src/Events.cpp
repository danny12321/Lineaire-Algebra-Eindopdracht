//
// Created by Thierry on 12-11-2020.
//

#include "Events.hpp"

void Events::doEvents(CoordinateSystem &coordinateSystem, SDLRenderer &sdlRenderer, Camera &camera) {
    while (SDL_PollEvent(&e) != 0) {

        int x, y;
//        SDL_GetMouseState(&x, &y);


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
            if(e.key.keysym.sym == SDLK_w) camera.translateRelative(-1, 0, 0);
            if(e.key.keysym.sym == SDLK_s) camera.translateRelative(1, 0, 0);
            if(e.key.keysym.sym == SDLK_a) camera.translateRelative(0, 0, 1);
            if(e.key.keysym.sym == SDLK_d) camera.translateRelative(0, 0, -1);
            if(e.key.keysym.sym == SDLK_LSHIFT) camera.translateRelative(0, -1, 0);
            if(e.key.keysym.sym == SDLK_SPACE) camera.translateRelative(0, 1, 0);
            if(e.key.keysym.sym == SDLK_q) camera.rotateCameraY(-1);
            if(e.key.keysym.sym == SDLK_e) camera.rotateCameraY(1);
            if(e.key.keysym.sym == SDLK_r) camera.rotateCameraZ(1);
            if(e.key.keysym.sym == SDLK_f) camera.rotateCameraZ(-1);
        }
    }
}
