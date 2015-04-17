/* 
 * File:   RunningState.h
 * Author: zach
 *
 * Created on March 6, 2009, 5:34 PM
 */

#ifndef _RUNNINGSTATE_H
#include <SDL/SDL.h>
#include <vector>
#include "GameState.h"
#include "Button.h"
#include "Game.h"
#include "Satellite.h"

class RunningState:public GameState {
public:
    RunningState();
    void update();
    void render(SDL_Surface* screen);
    void uninstall();
    void install();
private:
    SDL_Surface* background;
    SDL_Event event;
    SDL_Rect offset;
    std::vector<Satellite*> satellites;
  
};
#define	_RUNNINGSTATE_H



#endif	/* _RUNNINGSTATE_H */

