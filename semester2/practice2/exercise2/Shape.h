//
//  Shape.h
//  exercise2
//
//  Created by Arne Bahlo on 04.04.13.
//  Copyright (c) 2013 Arne Bahlo. All rights reserved.
//

#ifndef __exercise2__Shape__
#define __exercise2__Shape__

#include <iostream>

class Shape {
public:
    virtual void move(int, int) = 0;
    virtual void draw() = 0;
private:
};

#endif /* defined(__exercise2__Shape__) */
