
#include "Vector.h"

#include "BigAsteroid.h"
#include "BigAsteroidAnimation.h"
#include "Vector.h"
#include "Visitor.h"
#include "Bullet.h"

BigAsteroid::BigAsteroid(float x, float y):speed(0.3){
    animation = new BigAsteroidAnimation(60);
    this->pos_x = x;
    this->pos_y = y;
    velocity = new Vector(512-x,384-y);
    mass = 10;
    damaged = false;
    needsRemoved = false;
}

BigAsteroid::~BigAsteroid(){
    
}
void BigAsteroid::update(){
    animation->update();
    pos_x += speed*velocity->x;
    pos_y += speed*velocity->y;
    
    if((pos_x > 1024 || pos_x < 0 || pos_y > 768 || pos_y < 0) && damaged){
        markForRemoval();
    }
}

void BigAsteroid::render(SDL_Surface* screen){
    animation->render(screen,pos_x,pos_y);
}

void BigAsteroid::accept(Visitor* v, Sprite* s){
    //v->visit(this,s);
}

void BigAsteroid::explode(){
    
}

void BigAsteroid::operator+(const Bullet* bullet){
    velocity->x += bullet->velocity().x/mass;
    velocity->y += bullet->velocity().y/mass;
    damaged = true;
}

bool BigAsteroid::markedForRemoval(){
    return needsRemoved;
}

void BigAsteroid::markForRemoval(){
    needsRemoved = true;
}

float BigAsteroid::getX(){
    return pos_x;
}

float BigAsteroid::getY(){
    return pos_y;
}