#include <iostream>
#include "Satellite.h"
#include "ResourceManager.h"
#include "SpriteManager.h"
#include "Bullet.h"
#include "Missile.h"
#include "Fov.h"
#include "Visitor.h"

Satellite::Satellite(int x, int y,Fov* fov):bulletDelayTime(65536){
    pos_x = x;
    pos_y = y;
    image = ResourceManager::INSTANCE()->loadImage("resources/images/satellite.png");
    //image2 = ResourceManager::INSTANCE()->loadImage("resources/images/satellite2.JPG");
    currImage = image;
    active = false;
    shoot_delay=0;
    this->fov = fov;
}
Satellite::~Satellite(){
    
}

void Satellite::update(){
    SDL_PumpEvents();
    SDL_GetMouseState(&mouse_x,&mouse_y);
    
    /*
     *TODO: The stuff after fov->inFov() is a hack to satellite shooting to 
     *      work,it is due to failures with handling the cross product properly
     */
    if(SDL_GetMouseState(NULL, NULL)&SDL_BUTTON(1) && fov->inFov(mouse_x,mouse_y) && pos_x <= 475 && mouse_x < 475){
        active = true;
    } else if(SDL_GetMouseState(NULL, NULL)&SDL_BUTTON(1) && fov->inFov(mouse_x,mouse_y) && pos_x >= 475 && mouse_x > 475){
        active = true;
    } else {
        active = false;
    }
    
    if(active && SDL_GetMouseState(NULL, NULL)&SDL_BUTTON(1)){
        shoot(Satellite::GUN, mouse_x, mouse_y);
    }
}

void Satellite::render(SDL_Surface* screen){
    SDL_Rect offset;
    offset.x = (int)pos_x;
    offset.y = (int)pos_y;
    SDL_BlitSurface(currImage, NULL, screen, &offset);
    SpriteManager::INSTANCE()->render(screen);
}

void Satellite::accept(Visitor* v, Sprite* s){
    
}

void Satellite::explode(){
    
}

void Satellite::shoot(WEAPON weapon, int mouse_x, int mouse_y){
    switch(weapon){
        case GUN:
            if(shoot_delay == 0){
                SpriteManager::INSTANCE()->addProjectile(new Bullet(pos_x,pos_y,mouse_x,mouse_y));
            } else {
                shoot_delay++;
                if(shoot_delay == bulletDelayTime) 
                    shoot_delay = 0;
            }
            
            break;
        case MISSILE:
            SpriteManager::INSTANCE()->addProjectile(new Missile(pos_x,pos_y,mouse_x,mouse_y));
            break;
    }
}

bool Satellite::markedForRemoval(){
    return needsRemoved;
}

void Satellite::markForRemoval(){
    needsRemoved = true;
}

float Satellite::getX(){
    return pos_x;
}

float Satellite::getY(){
    return pos_y;
}