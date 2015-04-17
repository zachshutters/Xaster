/* 
 * File:   Missile.h
 * Author: zach
 *
 * Created on March 5, 2009, 1:23 PM
 */

#ifndef _MISSILE_H
#define	_MISSILE_H
#include <SDL/SDL.h>
#include "Sprite.h"

class Vector;
class Visitor;

class Missile:public Sprite {
 public:
    Missile(int x, int y, int mouse_x, int mouse_y);
    ~Missile();
    void update();
    void render(SDL_Surface* screen);
    void accept(Visitor* v, Sprite* s);
    bool destroy(); //returns true if this object should be destroyed
    float pos_x,pos_y;
    Vector& velocity() const;
    bool markedForRemoval();
    void markForRemoval();
    void playSoundEffect();
    float getX();
    float getY();
private:
    void explode();
    SDL_Surface* image;
    Vector* v;
    int target_x, target_y;
    bool needsRemoved;
    Mix_Chunk* sound;
};


#endif	/* _MISSILE_H */

