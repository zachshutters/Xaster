/* 
 * File:   MenuState.h
 * Author: zach
 *
 * Created on March 5, 2009, 2:29 PM
 */

#ifndef _MENUSTATE_H
#define	_MENUSTATE_H
#include <vector>
#include <SDL/SDL.h>
#include "GameState.h"
#include "Button.h"
#include "Game.h"

class MenuState:public GameState {
public:
    MenuState();
    ~MenuState();
    void update();
    void render(SDL_Surface* screen);
    void uninstall();
    void install();
private:
    SDL_Surface* background;
    SDL_Event event;
    Button<Game,void,Game::STATE>* startGame;
    Button<Game,void,Game::STATE>* quitGame;
};

#endif	/* _MENUSTATE_H */

