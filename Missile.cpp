#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <cmath>
#include "Missile.h"
#include "ResourceManager.h"
#include "Vector.h"

Missile::Missile(int x, int y, int mouse_x, int mouse_y){
    image = ResourceManager::INSTANCE()->loadImage("resources/images/Missile.png");
    sound = ResourceManager::INSTANCE()->loadSound("resources/sound/Chip015.wav");
    target_x = mouse_x;
    target_y = mouse_y;
    float t1 = mouse_x-x;
    float t2 = mouse_y-y;
    v = new Vector(t1, t2);
    pos_x = x;
    pos_y = y;
    needsRemoved = false;
    //playSoundEffect();
}

Missile::~Missile(){

}
void Missile::update(){
    pos_x += 5*v->x;
    pos_y += 5*v->y;
    
    if(pos_x > 1024 || pos_x < 0 || pos_y > 768 || pos_y < 0){
        markForRemoval();
    }
}

void Missile::render(SDL_Surface* screen){
    SDL_Rect temp;
    temp.x = (int)pos_x;
    temp.y = (int)pos_y;
    SDL_BlitSurface(image, NULL, screen, &temp);
}

void Missile::accept(Visitor* v, Sprite* s){
    v->visit(this,s);
}

void Missile::explode(){
    
}

bool Missile::markedForRemoval(){
    return needsRemoved;
}

void Missile::markForRemoval(){
    needsRemoved = true;
}

Vector& Missile::velocity() const {
    return *v;
}

void Missile::playSoundEffect(){
    Mix_PlayChannel(-1,sound,0);
}

float Missile::getX(){
    return pos_x;
}

float Missile::getY(){
    return pos_y;
}