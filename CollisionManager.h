/* 
 * File:   CollisionManager.h
 * Author: zach
 *
 * Created on March 12, 2009, 3:57 PM
 */

#ifndef _COLLISIONMANAGER_H
#define	_COLLISIONMANAGER_H
#include <vector>
#include "Visitor.h"
#include "SmallAsteroid.h"

class Sprite;
class Bullet;
class Missile;

class CollisionManager: public Visitor {
public:
    static CollisionManager* INSTANCE();
    void visit(SmallAsteroid* a, Sprite* s);
    void visit(Bullet* b, Sprite* s);
    void visit(Missile* m, Sprite* s);
    
    //this is not being used yet, still experimental
    void checkCollisions(std::vector<Sprite*> list, int firstIndex, int lastIndex, int pivot);
private:

    //this is not being used yet, still experimental
    int partitionx(std::vector<Sprite*>& list, int firstIndex,int lastIndex, float pivot);
    static CollisionManager* SINGLETON;
    CollisionManager();
    CollisionManager(const CollisionManager&);
    CollisionManager& operator=(const CollisionManager&);
    void swap(Sprite*& x, Sprite*& y);
};
#endif	/* _COLLISIONMANAGER_H */

