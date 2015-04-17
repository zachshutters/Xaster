/* 
 * File:   Sprite.h
 * Author: zach
 *
 * Created on March 5, 2009, 1:15 PM
 */

#ifndef _SPRITE_H
#define	_SPRITE_H
#include <SDL/SDL.h>
#include "Visitor.h"
#include "Sprite.h"

class Sprite {
public:
    virtual void update()=0;
    virtual void render(SDL_Surface* screen)=0;
    virtual void accept(Visitor* v, Sprite* s)=0;
    virtual void explode()=0;
    virtual bool markedForRemoval()=0;
    virtual void markForRemoval()=0;
    virtual float getX()=0; //returns true if sprite x is >= parameter x
    virtual float getY()=0; //returns true if sprite y is >= parameter y
    virtual ~Sprite(){}
};


#endif	/* _SPRITE_H */

