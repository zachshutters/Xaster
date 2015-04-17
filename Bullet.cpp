#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <cmath>
#include "Bullet.h"
#include "ResourceManager.h"
#include "Vector.h"

Bullet::Bullet(int x, int y, int mouse_x, int mouse_y){
    image = ResourceManager::INSTANCE()->loadImage("resources/images/bullet.png");
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

Bullet::~Bullet(){

}
void Bullet::update(){
    pos_x += 5*v->x;
    pos_y += 5*v->y;
    
    if(pos_x > 1024 || pos_x < 0 || pos_y > 768 || pos_y < 0){
        markForRemoval();
    }
}

void Bullet::render(SDL_Surface* screen){
    SDL_Rect temp;
    temp.x = (int)pos_x;
    temp.y = (int)pos_y;
    SDL_BlitSurface(image, NULL, screen, &temp);
}

void Bullet::accept(Visitor* v, Sprite* s){
    v->visit(this,s);
}

void Bullet::explode(){
    
}

bool Bullet::markedForRemoval(){
    return needsRemoved;
}

void Bullet::markForRemoval(){
    needsRemoved = true;
}

Vector& Bullet::velocity() const {
    return *v;
}

void Bullet::playSoundEffect(){
    Mix_PlayChannel(-1,sound,0);
}

float Bullet::getX(){
    return pos_x;
}

float Bullet::getY(){
    return pos_y;
}