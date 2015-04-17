/* 
 * File:   Asteroid.h
 * Author: zach
 *
 * Created on March 5, 2009, 1:18 PM
 */

#ifndef _ASTEROID_H
#define	_ASTEROID_H
#include "Sprite.h"

class Animation;
class Vector;
class Visitor;
class Bullet;

class SmallAsteroid:public Sprite {
public:
    SmallAsteroid(float x, float y);
    ~SmallAsteroid();
    void update();
    void render(SDL_Surface* screen);
    void accept(Visitor* v, Sprite* s);
    void operator+(const Bullet*);
    bool markedForRemoval();
    void markForRemoval();
    float pos_x,pos_y;
    float getX();
    float getY();
private:
    void explode();
    Animation* animation;
    Vector* velocity;
    const float speed;
    int target_x, target_y;
    int mass;
    bool needsRemoved;
    bool damaged;
};

#endif	/* _ASTEROID_H */

