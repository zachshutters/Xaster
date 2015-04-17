/* 
 * File:   main.cpp
 * Author: zach
 *
 * Created on March 5, 2009, 1:26 PM
 */
#include <iostream>
#include <stdlib.h>
//#include "Game.h"
#include <SDL/SDL.h>
//#include <SDL/SDL_mixer.h>
//#include <SDL/SDL_ttf.h>

int main(int argc, char** argv) {
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 ) { 
        return EXIT_FAILURE; 
    }  
    /*
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024 ) == -1 ) {
        return EXIT_FAILURE; 
    } 
    
    if(TTF_Init() == -1) { 
        return false; 
    } 
    Game::INSTANCE()->start();
    Mix_CloseAudio();
    */
    SDL_Quit();
    
    return (EXIT_SUCCESS);
}

