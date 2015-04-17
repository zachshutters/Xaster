/* 
 * File:   ResourceManager.h
 * Author: zach
 *
 * Created on March 5, 2009, 1:56 PM
 */

#ifndef _RESOURCEMANAGER_H
#define	_RESOURCEMANAGER_H
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

class ResourceManager {
public:
    static ResourceManager* INSTANCE();
    SDL_Surface* loadImage(std::string filename);
    Mix_Chunk* loadSound(std::string filename);
private:
    static ResourceManager* SINGLETON;
    ResourceManager();
    ResourceManager(const ResourceManager&);
    ResourceManager& operator=(const ResourceManager&);
};


#endif	/* _RESOURCEMANAGER_H */

