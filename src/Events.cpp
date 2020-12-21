//
// Created by Thierry on 12-11-2020.
//

#include "Events.hpp"

void Events::doEvents(CoordinateSystem& coordinateSystem, SDLRenderer& sdlRenderer, Camera& camera) {
    while( SDL_PollEvent( &e ) != 0 )
    {
        //User requests quit
        if( e.type == SDL_QUIT )
        {
            sdlRenderer.quitApp();
        }
        if(e.type == SDL_MOUSEWHEEL) {
            if (e.wheel.y > 0) // scroll up
            {
//                coordinateSystem.plusXYLineSize(5);
                camera.increaseFov();
//                camera.increaseEye();
            } else if (e.wheel.y < 0) // scroll down
            {
//                coordinateSystem.minusXYLineSize(5);
                camera.decreaseFov();
//                camera.decreaseEye();
            }
            std::cout << camera.getFov() << std::endl;
        }
        if(e.type == SDL_MOUSEMOTION)
        {
            int xMouse;
            int yMouse;
            SDL_GetGlobalMouseState(&xMouse, &yMouse);
//            std::cout << ((float)xMouse / 1500) << std::endl;
            camera.setEyeX((((float)xMouse / 1500) * 40));
            camera.setEyeY((((float)yMouse / 1000) * 40) - 10);
//            coordinateSystem.setMiddleX(xMouse);
//            coordinateSystem.setMiddleY(yMouse);
        }

    }
}
