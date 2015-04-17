#include <iostream>
#include "MenuState.h"
#include "ResourceManager.h"
#include "Button.h"
#include "foo.h"
#include "SpriteManager.h"

MenuState::MenuState(){
    startGame = NULL;
    quitGame = NULL;
    background = NULL;
}

MenuState::~MenuState(){
    std::cout << "menustate destructor called" << std::endl;
}
void MenuState::update(){
    startGame->update();
    quitGame->update();
    //SpriteManager::INSTANCE()->update();
}

void MenuState::render(SDL_Surface* screen){
    SDL_Rect offset; 
    offset.x = 0; 
    offset.y = 0; 
   
    SDL_BlitSurface( background, NULL, screen, &offset );   
    //SpriteManager::INSTANCE()->render(screen);
    startGame->render(screen);
    quitGame->render(screen);    
}

void MenuState::uninstall(){
    /*
    delete startGame;
    startGame = NULL;
    delete quitGame;
    quitGame = NULL;
    delete background;
    background = NULL;
     */
    
}

void MenuState::install(){
    if(background == NULL) background = ResourceManager::INSTANCE()->loadImage("resources/images/menuBackground.png");
    if(startGame == NULL) startGame = new Button<Game,void,Game::STATE>("Start",425,350,&*Game::INSTANCE(),&Game::setState,Game::RUNNING_STATE);
    if(quitGame == NULL) quitGame= new Button<Game,void,Game::STATE>("Quit",425,390,&*Game::INSTANCE(),&Game::setState,Game::QUIT_STATE);
    //SpriteManager::INSTANCE()->generateAsteroidWave();
}
