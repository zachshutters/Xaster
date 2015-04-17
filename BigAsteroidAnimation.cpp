#include "BigAsteroidAnimation.h"
#include "ResourceManager.h"
#include <iostream>

BigAsteroidAnimation::BigAsteroidAnimation(int fps){
  
    imageStrip = ResourceManager::INSTANCE()->loadImage("resources/images/asteroid_strip_big.png");
    
    //now need to initialize clipping region
    currentFrame = 0;
    
    for(int h=0; h<180; h+=60){
        for(int w=0; w<600; w+=60){
            frame[currentFrame].x=w;
            frame[currentFrame].y=h;
            frame[currentFrame].w=64;
            frame[currentFrame].h=64;
            currentFrame++;
        }
    }

    currentFrame = 0;
    play = false;
}

BigAsteroidAnimation::~BigAsteroidAnimation(){
    
}

void BigAsteroidAnimation::start(){
    play = true;
}

void BigAsteroidAnimation::stop(){
    play = false;
}

void BigAsteroidAnimation::reset(){
    currentFrame = 0;
    play = false;
}

void BigAsteroidAnimation::update(){
    if(play){
        currTime = SDL_GetTicks();
        elapsedTime += currTime - lastRan;
        int x = elapsedTime/50;
        currentFrame = x%30;
        lastRan = currTime;
    }
}

void BigAsteroidAnimation::render(SDL_Surface* screen,int x, int y){
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
   
    //SDL_BlitSurface(imageStrip,&rect2,screen,&rect);
    SDL_BlitSurface(imageStrip,&frame[currentFrame],screen,&rect);
}