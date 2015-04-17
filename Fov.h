/* 
 * File:   Fov.h
 * Author: zach
 *
 * Created on March 10, 2009, 1:15 PM
 */

#include "Vector.h"


#ifndef _FOV_H
#define	_FOV_H
#include "Vector.h"
#include <cmath>
#include <cstdlib>

class Fov {
public:
    Fov(Vector v1, Vector v2, float pos_x, float pos_y):v1(v1),v2(v2){
        this->pos_x = pos_x;
        this->pos_y = pos_y;
        this->v1 = v1;
        this->v2 = v2;
    }
    
    bool inFov(int mouse_x, int mouse_y){
        //change coordinate system of p
        float x = (pos_x - mouse_x);//mouse_x - pos_x);
        float y = (pos_y - mouse_y); 
        
        if(mouse_x > 512){
            x = 0-x;
        }
        Vector u(x,y);
        //cross v1 into p and v2 into p, if both position return true
        
        float a = v1.cross(u);
        float b = u.cross(v2);
        
        //std::cout << "v1 crossed into u: " << a << std::endl;
        //std::cout << "u crossed into v2: " << b << std::endl;
        //exit(0);
        if((a < 0 && b < 0)){// || (a > 0 && b > 0)){
            //std::cout << "returning true" << std::endl;
            return true;
        } else {
            return false;
        }
    }
    
private:
    float pos_x;
    float pos_y;
    Vector v1;
    Vector v2;
};

#endif	/* _FOV_H */

