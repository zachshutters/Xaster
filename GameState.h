/* 
 * File:   GameState.h
 * Author: zach
 *
 * Created on March 5, 2009, 2:27 PM
 */

#ifndef _GAMESTATE_H
#define	_GAMESTATE_H
#include <SDL/SDL.h>
#include <queue>

class GameState {
public:
    virtual void update()=0;
    virtual void render(SDL_Surface* screen)=0;
    virtual void uninstall()=0;
    virtual void install()=0;
    
};


#endif	/* _STATE_H */

