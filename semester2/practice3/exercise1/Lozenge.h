//
//  Lozenge.h
//  exercise1
//
//  Created by Arne Bahlo on 23.04.13.
//  Copyright (c) 2013 Arne Bahlo. All rights reserved.
//

#ifndef __exercise1__Lozenge__
#define __exercise1__Lozenge__

#include <iostream>

#include "Shape.h"

class Lozenge : public Shape {
public:
    Lozenge();
    Lozenge(int _x1, int _y1, int _x2, int _y2);
    void move(int x, int y);
    void draw(Frame* fr);
private:
    bool is_valid(Frame *fr);
    int x1;
    int y1;
    int x2;
    int y2;
    int x3;
    int y3;
    int x4;
    int y4;
};

#endif /* defined(__exercise1__Lozenge__) */
