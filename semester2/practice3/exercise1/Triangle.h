//
//  Triangle.h
//  exercise1
//
//  Created by Arne Bahlo on 22.04.13.
//  Copyright (c) 2013 Arne Bahlo. All rights reserved.
//

#ifndef __exercise1__Triangle__
#define __exercise1__Triangle__

#include <iostream>

#include "Shape.h"

class Triangle : public Shape {
public:
    Triangle();
    Triangle(int _x1, int _y1, int _x2, int _y2, int _x3, int _y3);
    Triangle(int hor, int ver, int len1, int len2, int len3);
    void move(int x, int y);
    void draw(Frame*);
private:
    bool is_valid(Frame*);
    int x1;
    int y1;
    int y2;
    int x2;
    int x3;
    int y3;
};

#endif /* defined(__exercise1__Triangle__) */
