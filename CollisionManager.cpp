#include <iostream>
#include <typeinfo>
#include <cmath>
#include "CollisionManager.h"
#include "SmallAsteroid.h"
#include "BigAsteroid.h"
#include "Sprite.h"
#include "Bullet.h"
#include "Missile.h"
using namespace std;
CollisionManager* CollisionManager::SINGLETON = 0;

CollisionManager* CollisionManager::INSTANCE(){
    if(SINGLETON == NULL){
        SINGLETON = new CollisionManager();
        srand((unsigned)time(0));
    }
    return SINGLETON;
}

CollisionManager::CollisionManager(){}

void CollisionManager::visit(SmallAsteroid* a,Sprite* s){
    if(typeid(*s) == typeid(Bullet)){
        Bullet* b = reinterpret_cast<Bullet*>(s);
        //now we know the two object types
        float x = ((a->pos_x+30) - (b->pos_x));
        float y = ((a->pos_y+30) - (b->pos_y));
               
        if( sqrt(x*x+y*y) < 30 && b->pos_x < 1024 && b->pos_x > 0 && b->pos_y > 0 && b->pos_y < 768){
            //std::cout << "woot" << std::endl;
            if(!b->markedForRemoval()){
                *a+b;
                b->playSoundEffect();
            }
            b->markForRemoval();
        }
    }
}

void CollisionManager::visit(Bullet* b,Sprite* s){
    if(typeid(*s) == typeid(SmallAsteroid)){
        SmallAsteroid* a = reinterpret_cast<SmallAsteroid*>(s);
        //now we know the two object types
        float x = ((a->pos_x+30) - (b->pos_x));
        float y = ((a->pos_y+30) - (b->pos_y));
               
        if( sqrt(x*x+y*y) < 30 && b->pos_x < 1024 && b->pos_x > 0 && b->pos_y > 0 && b->pos_y < 768){
            //std::cout << "woot" << std::endl;
            if(!b->markedForRemoval()){
                *a+b;
                b->playSoundEffect();
            }
            b->markForRemoval();
        }
    }
    else if(typeid(*s) == typeid(BigAsteroid)){
        BigAsteroid* a = reinterpret_cast<BigAsteroid*>(s);
        //now we know the two object types
        float x = ((a->pos_x+30) - (b->pos_x));
        float y = ((a->pos_y+30) - (b->pos_y));
               
        if( sqrt(x*x+y*y) < 30 && b->pos_x < 1024 && b->pos_x > 0 && b->pos_y > 0 && b->pos_y < 768){
            //std::cout << "woot" << std::endl;
            if(!b->markedForRemoval()){
                *a+b;
                b->playSoundEffect();
            }
            b->markForRemoval();
        }
    }
}

void CollisionManager::visit(Missile* m,Sprite* s){
    /*
    if(typeid(*s) == typeid(SmallAsteroid)){
        SmallAsteroid* a = reinterpret_cast<SmallAsteroid*>(s);
        //now we know the two object types
        float x = ((a->pos_x+30) - (b->pos_x));
        float y = ((a->pos_y+30) - (b->pos_y));
               
        if( sqrt(x*x+y*y) < 30 && b->pos_x < 1024 && b->pos_x > 0 && b->pos_y > 0 && b->pos_y < 768){
            //std::cout << "woot" << std::endl;
            if(!b->markedForRemoval()){
                *a+b;
                b->playSoundEffect();
            }
            b->markForRemoval();
        }
    }
    else if(typeid(*s) == typeid(BigAsteroid)){
        BigAsteroid* a = reinterpret_cast<BigAsteroid*>(s);
        //now we know the two object types
        float x = ((a->pos_x+30) - (b->pos_x));
        float y = ((a->pos_y+30) - (b->pos_y));
               
        if( sqrt(x*x+y*y) < 30 && b->pos_x < 1024 && b->pos_x > 0 && b->pos_y > 0 && b->pos_y < 768){
            //std::cout << "woot" << std::endl;
            if(!b->markedForRemoval()){
                *a+b;
                b->playSoundEffect();
            }
            b->markForRemoval();
        }
    }
     */
}

int CollisionManager::partitionx(std::vector<Sprite*>& list, int firstIndex,int lastIndex, float pivot){
    //float pivot = list[firstIndex]->getX();
    int left = firstIndex;
    int right = lastIndex;
    int index;
    if(firstIndex < lastIndex){ 
        while(list[left]->getX() <= pivot){
            if(left == lastIndex){
                left = 0;
                firstIndex++;
                break;
            } else {
                left++;
            }
        }
        
        while(list[right]->getX() > pivot)
            right--;
        
        if(left < right){
            swap(list[left],list[right]);
            index = partitionx(list,firstIndex,right,5);
        }
        else {
            return right; 
        }
    }
    return index;
}

void CollisionManager::swap(Sprite*& x, Sprite*& y){
    Sprite* temp;
    temp = x;
    x = y;
    y = temp;  
}

void CollisionManager::checkCollisions(std::vector<Sprite*> list,int firstIndex,int lastIndex,int pivot){
    int index;
    if(firstIndex < lastIndex){
      index = partitionx(list,firstIndex,lastIndex,pivot);
      std::cout << "\nindex: " << index << std::endl;
      //checkCollisions(list,firstIndex,index);  //y axis
      //checkCollisions(list,index,lastIndex); //x axis
  }

}