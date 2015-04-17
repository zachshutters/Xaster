/* 
 * File:   Satellite.h
 * Author: zach
 *
 * Created on March 5, 2009, 1:17 PM
 */

#ifndef _SATELLITE_H
#define	_SATELLITE_H
#include <SDL/SDL.h>
#include "Sprite.h"

class Visitor;
class Fov;

class Satellite:public Sprite {
public:
    enum WEAPON {GUN,MISSILE};
    Satellite(int x, int y,Fov* fov);
    ~Satellite();
    void update();
    void render(SDL_Surface* screen);
    void shoot(WEAPON weapon,int mouse_x, int mouse_y);
    void accept(Visitor* v, Sprite* s);
    bool markedForRemoval();
    void markForRemoval();
    float getX();
    float getY();
private:
    void explode();
    float pos_x,pos_y;
    SDL_Surface* image;
    SDL_Surface* image2;
    SDL_Surface* currImage;
    int mouse_x,mouse_y;
    int radius;
    bool active;
    int shoot_delay;
    const int bulletDelayTime;
    Fov* fov;
    bool needsRemoved;
};

#endif	/* _SATELLITE_H */

