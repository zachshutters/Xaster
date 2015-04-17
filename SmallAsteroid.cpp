
#include "Vector.h"

#include "SmallAsteroid.h"
#include "BigAsteroidAnimation.h"
#include "Vector.h"
#include "Visitor.h"
#include "Bullet.h"

SmallAsteroid::SmallAsteroid(float x, float y):speed(0.3){
    animation = new BigAsteroidAnimation(rand()%500);
    this->pos_x = x;
    this->pos_y = y;
    velocity = new Vector(512-x,384-y);
    mass = 60;
    damaged = false;
    needsRemoved = false;
    animation->start();
}

SmallAsteroid::~SmallAsteroid(){
    
}
void SmallAsteroid::update(){
    animation->update();
    pos_x += speed*velocity->x;
    pos_y += speed*velocity->y;
    
    if((pos_x > 1024 || pos_x < 0 || pos_y > 768 || pos_y < 0) && damaged){
        markForRemoval();
    }
}

void SmallAsteroid::render(SDL_Surface* screen){
    animation->render(screen,pos_x,pos_y);
}

void SmallAsteroid::accept(Visitor* v, Sprite* s){
    v->visit(this,s);
}

void SmallAsteroid::explode(){
    
}

void SmallAsteroid::operator+(const Bullet* bullet){
    velocity->x += bullet->velocity().x/mass;
    velocity->y += bullet->velocity().y/mass;
    damaged = true;
}

bool SmallAsteroid::markedForRemoval(){
    return needsRemoved;
}

void SmallAsteroid::markForRemoval(){
    needsRemoved = true;
}

float SmallAsteroid::getX(){
    return pos_x;
}

float SmallAsteroid::getY(){
    return pos_y;
}