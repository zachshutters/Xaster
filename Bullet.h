/* 
 * File:   Bullet.h
 * Author: zach
 *
 * Created on March 5, 2009, 1:22 PM
 */

#ifndef _BULLET_H
#define	_BULLET_H
#include <SDL/SDL_mixer.h>
#include "Sprite.h"

class Vector;
class Visitor;

class Bullet:public Sprite {
 public:
    Bullet(int x, int y, int mouse_x, int mouse_y);
    ~Bullet();
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


#endif	/* _BULLET_H */

