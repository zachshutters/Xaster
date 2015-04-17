/* 
 * File:   Vector.h
 * Author: zach
 *
 * Created on March 9, 2009, 3:18 PM
 */

#ifndef _VECTOR_H
#define	_VECTOR_H
#include <cmath>
#include <iostream>
#include <cstdlib>

class Vector {
public:
    Vector(float x, float y){
        this->x = x;
        this->y = y; 
        normalize();
    }
    
    Vector& operator-(Vector& v){
        Vector* v2 = new Vector(v.x-this->x,v.y-this->y);
	return *v2;  
    }
    
    Vector& operator+(Vector& v){
        Vector* v2 = new Vector(v.x+this->x,v.y+this->y);
        return *v2;  
    }

    float cross(Vector& v){
        float t = x*v.y-y*v.x;
        //std::cout << "\ncrossing vector [" << x << "," << y << "]" << std::endl;
        //std::cout << "    into vector [" << v.x << "," << v.y << "]" << std::endl;
        //std::cout << "Result: " << t << std::endl;
        return t;
    }
    //friend ostream& operator<<(ostream& out, Vector2D& v);
    float x;
    float y;
private:
    void normalize(){
        float r = sqrt(x*x+y*y);
        x = x/r;
        y = y/r;
    }
};
#endif	/* _VECTOR_H */

