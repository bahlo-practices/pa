//
//  Line.h
//  exercise1
//
//  Created by Arne Bahlo on 22.04.13.
//  Copyright (c) 2013 Arne Bahlo. All rights reserved.
//

#ifndef __exercise1__Line__
#define __exercise1__Line__

#include <iostream>

#include "Shape.h"

class Line : public Shape {
public:
    Line();
    Line(int x1, int y1, int x2, int y2);
    void move(int, int);
    void draw(Frame* fr);
private:
    int x1;
    int y1;
    int x2;
    int y2;
};


#endif /* defined(__exercise1__Line__) */
