//
// Created by Thierry on 12-11-2020.
//

#include "Events.hpp"

void Events::doEvents(CoordinateSystem& coordinateSystem, SDLRenderer& sdlRenderer) {
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
                coordinateSystem.plusXYLineSize(5);
            } else if (e.wheel.y < 0) // scroll down
            {
                coordinateSystem.minusXYLineSize(5);
            }
        }
        if(e.type == SDL_MOUSEMOTION)
        {
            int xMouse;
            int yMouse;
            SDL_GetGlobalMouseState(&xMouse,&yMouse);
            coordinateSystem.setMiddleX(xMouse);
            coordinateSystem.setMiddleY(yMouse);
        }

    }
}
