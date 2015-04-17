#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include "SpriteManager.h"
#include "Sprite.h"
#include "SmallAsteroid.h"
#include "CollisionManager.h"
#include "Game.h"

SpriteManager* SpriteManager::SINGLETON = 0;

SpriteManager* SpriteManager::INSTANCE(){
    if(SINGLETON == NULL){
        SINGLETON = new SpriteManager();
        srand((unsigned)time(0));
    }
    return SINGLETON;
}

SpriteManager::SpriteManager(){}

void SpriteManager::update(){
    std::vector<Sprite*>::iterator itr;
    for(itr = obstacles.begin(); itr != obstacles.end(); itr++){
        (*itr)->update();
    }
    for(itr = projectiles.begin(); itr != projectiles.end(); itr++){
        (*itr)->update();
    }
    checkForCollisions();
}

void SpriteManager::render(SDL_Surface* screen){
    std::vector<Sprite*>::iterator itr;
    for(itr = obstacles.begin(); itr != obstacles.end(); itr++){
        (*itr)->render(screen);
    }
    for(itr = projectiles.begin(); itr != projectiles.end(); itr++){
        (*itr)->render(screen);
    }
    if(obstacles.size() == 0){
        Game::INSTANCE()->setState(Game::MENU_STATE);
    }
}

void SpriteManager::addProjectile(Sprite* s){
    projectiles.push_back(s);
}

void SpriteManager::addObstacle(Sprite* s){
    obstacles.push_back(s);
}
void SpriteManager::generateAsteroidWave(){
    
    float radius;
    float t,x,y;
    
    for(int i=0; i<10; i++){
        
        radius = randomFromRange(500,600);
        t = rand()%360;
        t = t*180/3.14;
        y = 384+radius*sin(t);
        x = 512+radius*cos(t);
         
        addObstacle(new SmallAsteroid(x,y));
    } 
}

int SpriteManager::randomFromRange(int lowest, int highest){
    return lowest + rand()%(highest-lowest);
}

void SpriteManager::checkForCollisions(){
    
    std::vector<Sprite*>::iterator itr1; //bullets
    std::vector<Sprite*>::iterator itr2; //asteroids
    
    for(itr1 = projectiles.begin(); itr1 != projectiles.end(); itr1++){
        for(itr2 = obstacles.begin(); itr2 != obstacles.end(); itr2++){
            //we dont know what the obstacles and projectiles are, so we cannot
            //do collision logic here. I could do a bunch of typeid, but how 
            //readable would that code be?
            (*itr1)->accept(CollisionManager::INSTANCE(),*itr2);
            
        }
    }
    
    for(unsigned int x=0;x<projectiles.size();x++){
        if(projectiles[x]->markedForRemoval()){
            projectiles.erase(projectiles.begin()+x);
        }
    }
    
    for(unsigned int x=0;x<obstacles.size();x++){
        if(obstacles[x]->markedForRemoval()){
            obstacles.erase(obstacles.begin()+x);
        }
    }
}
