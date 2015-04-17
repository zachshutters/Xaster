/* 
 * File:   Visitor.h
 * Author: zach
 *
 * Created on March 12, 2009, 3:59 PM
 */

#ifndef _VISITOR_H
#define	_VISITOR_H

class SmallAsteroid;
class Sprite;
class Bullet;
class Missile;

class Visitor {
public:
    virtual ~Visitor(){};
    virtual void visit(SmallAsteroid* a, Sprite* b)=0;
    virtual void visit(Bullet* b, Sprite* s)=0;
    virtual void visit(Missile* m, Sprite* s)=0;
};


#endif	/* _VISITOR_H */

