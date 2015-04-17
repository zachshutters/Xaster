/* 
 * File:   foo.h
 * Author: zach
 *
 * Created on March 6, 2009, 11:32 AM
 */

#ifndef _FOO_H
#define	_FOO_H

class foo {
public:
  int callme(int x){
    std::cout << "method invoked " << x << std::endl;
    return 0;
  }
};


#endif	/* _FOO_H */

