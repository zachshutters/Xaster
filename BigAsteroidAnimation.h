/* 
 * File:   BigAsteroidAnimation.h
 * Author: zach
 *
 * Created on March 11, 2009, 3:37 PM
 */

#ifndef _BIGASTEROIDANIMATION_H
#define	_BIGASTEROIDANIMATION_H
#include <SDL/SDL.h>
#include <vector>
#include "Animation.h"


class BigAsteroidAnimation: public Animation {
public:
    BigAsteroidAnimation(int fps);
    ~BigAsteroidAnimation();
    void start();
    void stop();
    void reset();
    void update();
    void render(SDL_Surface* screen, int x, int y);
    
private:
    SDL_Surface* imageStrip;
    int currentFrame;
    int fps;
    SDL_Rect frame[30];
    Uint32 lastRan;
    Uint32 currTime;
    Uint32 elapsedTime;
    bool play;
};

#endif	/* _BIGASTEROIDANIMATION_H */

