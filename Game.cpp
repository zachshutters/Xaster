#include <iostream>
#include "Game.h"
#include "ResourceManager.h"
#include "GameState.h"
#include "MenuState.h"
#include "RunningState.h"
#include <SDL/SDL_thread.h>

Game* Game::SINGLETON = 0;

Game::Game():screen_width(1024),screen_height(780),screen_bpp(32),menuState(new MenuState){
    screen = SDL_SetVideoMode( screen_width, 
                               screen_height, 
                               screen_bpp, 
                               SDL_SWSURFACE ); 
    //menuState = new MenuState;
    runningState = new RunningState;
    gameState = NULL;
}
Game::~Game(){
    
}

void Game::setState(STATE state){
    switch(state){
        case MENU_STATE: setState(menuState.get()); break;
        case RUNNING_STATE: setState(runningState); break;
        case QUIT_STATE: running=false; break;
    }
}
void Game::setState(GameState* gameState){
    if(this->gameState != NULL){
        this->gameState->uninstall();
    }
    this->gameState = gameState;
    this->gameState->install();
}
void Game::update(){
    gameState->update();
}

void Game::render(SDL_Surface* screen){
    gameState->render(screen);
}

void Game::start(){
    setState(menuState.get());
    running = true;
    Uint32 currTime;
    Uint32 prevTime;
    Uint32 elapsedTime;
    Uint32 overRunTime=0;
    while(running){
        prevTime = SDL_GetTicks();
        update();
        if(overRunTime <= 16){
            render(screen);
        } else {
            overRunTime = 0;  //drop the frame and reset overRunTime
        }
        SDL_Flip(screen);
        
        if(event.type == SDL_QUIT){
            running = false;
            break;
        }
        
        currTime = SDL_GetTicks();
        elapsedTime = currTime-prevTime;
        if(elapsedTime > 16){
            overRunTime += 16 - elapsedTime;
        }
        else if(elapsedTime < 16 && running != false)
            SDL_Delay(33 -elapsedTime);
        
        SDL_PollEvent(&event);
    }
}

Game* Game::INSTANCE(){
    if(SINGLETON == NULL){
        SINGLETON = new Game();
    }
    return SINGLETON;
}
