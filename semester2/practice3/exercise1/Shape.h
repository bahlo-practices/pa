//
//  Shape.h
//  exercise1
//
//  Created by Arne Bahlo on 22.04.13.
//  Copyright (c) 2013 Arne Bahlo. All rights reserved.
//

#ifndef __exercise1__Shape__
#define __exercise1__Shape__

#include <iostream>

#include "Frame.h"

class Shape {
public:
    Shape();
    virtual void move(int, int) = 0; // rein virtuelle Methode
    virtual void draw(Frame*) = 0; // rein virtuelle Methode //...
private:
};

#endif /* defined(__exercise1__Shape__) */
