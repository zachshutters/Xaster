#include "RunningState.h"
#include "SpriteManager.h"
#include "Vector.h"
#include "Fov.h"
#include <iostream>

RunningState::RunningState(){
    offset.x = 0; 
    offset.y = 0; 
}

void RunningState::update(){
    
    std::vector<Satellite*>::iterator itr;
    for(itr = satellites.begin(); itr != satellites.end();itr++){
        (*itr)->update();
    }
    SpriteManager::INSTANCE()->update();
    
}

void RunningState::render(SDL_Surface* screen){
    SDL_BlitSurface(background, NULL, screen, &offset);
    std::vector<Satellite*>::iterator itr;
    for(itr = satellites.begin(); itr != satellites.end();itr++){
        (*itr)->render(screen);
    }
    SpriteManager::INSTANCE()->render(screen);
}

void RunningState::uninstall(){
    
}

void RunningState::install(){
    std::cout << "installing running state" << std::endl;
    background = ResourceManager::INSTANCE()->loadImage("resources/images/earth.JPG");
    
    //1
    satellites.push_back(new Satellite(250,350,
                         new Fov(
                         Vector(0.1,1),
                         Vector(0.1,-1),250,350)));
    
    //2
    
    satellites.push_back(new Satellite(325,200,
                         new Fov(
                         Vector(-0.5,1),
                         Vector(0.5,-1),325,200)));     
     
    //3
    satellites.push_back(new Satellite(475,150,
                         new Fov(
                         Vector(-1,0.5),
                         Vector(1,0.5),475,150)));
    
    //4
    satellites.push_back(new Satellite(625,200,
                         new Fov(
                         Vector(-1,1),
                         Vector(1,-1),625,200)));
    
    //5
    satellites.push_back(new Satellite(700,350,
                         new Fov(
                         Vector(0.1,1),
                         Vector(0.1,-1),700,350)));
    
    
    //6
    satellites.push_back(new Satellite(625,500,
                         new Fov(
                         Vector(1,1),
                         Vector(-1,-1),625,500)));
     
    //7
    satellites.push_back(new Satellite(475,575,
                         new Fov(
                         Vector(1,0.1),
                         Vector(-1,0.1),475,575)));
    
    //8
    satellites.push_back(new Satellite(325,500,
                         new Fov(
                         Vector(0.5,1),
                         Vector(-0.5,-1),325,500)));
    
    SpriteManager::INSTANCE()->generateAsteroidWave();
}