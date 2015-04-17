/* 
 * File:   Animation.h
 * Author: zach
 *
 * Created on March 11, 2009, 3:35 PM
 */

#ifndef _ANIMATION_H
#define	_ANIMATION_H

class Animation {
public:
    /*
     * Starts the animation
     */
    virtual void start()=0;
    
    /*
     * Stops the animation
     */
    virtual void stop()=0;
    
    /*
     * Resets the animation to the first frame
     */
    virtual void reset()=0;
    
    /*
     * Update animation frame based on elapsed time
     */
    virtual void update()=0;
    
    /*
     * Renders current frame to screen
     */
    virtual void render(SDL_Surface* screen, int x, int y)=0;
    
    virtual ~Animation(){};
};

#endif	/* _ANIMATION_H */

