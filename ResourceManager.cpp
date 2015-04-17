#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "ResourceManager.h"

ResourceManager* ResourceManager::SINGLETON = 0;

ResourceManager* ResourceManager::INSTANCE(){
    if(SINGLETON == NULL){
        SINGLETON = new ResourceManager();
    }
    return SINGLETON;
}

ResourceManager::ResourceManager(){}

SDL_Surface* ResourceManager::loadImage(std::string filename){
    SDL_Surface* loadedImage = NULL;
    SDL_Surface* optimizedImage = NULL;
    loadedImage = IMG_Load(filename.c_str());
    if( loadedImage != NULL ) { 
        optimizedImage = SDL_DisplayFormatAlpha( loadedImage ); 
        SDL_FreeSurface( loadedImage );
    } else {
        //image not found
    }
    return optimizedImage; 
}

Mix_Chunk* ResourceManager::loadSound(std::string filename){
    return Mix_LoadWAV(filename.c_str()); 
}