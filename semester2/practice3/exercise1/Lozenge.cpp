//
//  Lozenge.cpp
//  exercise1
//
//  Created by Arne Bahlo on 23.04.13.
//  Copyright (c) 2013 Arne Bahlo. All rights reserved.
//

#include "Line.h"

#include "Lozenge.h"

Lozenge::Lozenge() : x1(0), y1(0), x2(0), y2(0), x3(0), y3(0), x4(0), y4(0) {}

Lozenge::Lozenge(int _x1, int _y1, int _x2, int _y2) : x1(_x1), y1(_y1), x2(_x2), y2(_y2), x3(0), y3(0), x4(0), y4(0) {
    x3 = (x2 - x1) * 2 + x1;
    y3 = y1;
    x4 = x2;
    y4 = (y2 - y1) * 2 - y2;
}

void Lozenge::move(int x, int y) {
    x1 += x;
    x2 += x;
    y1 += y;
    y2 += y;
}

void Lozenge::draw(Frame* fr) {
    /*
     *     x2y2
     *    /    \
     * x1y1   x3y3
     *    \    /
     *     x4y4
     */
    if(x1 > x2 && y1 > y2) {
        std::swap(x1, x2);
        std::swap(y1, y2);
    }
    if(is_valid(fr)) {
        Line line1(x1, y1, x2, y2);
        Line line2(x2, y2, x3, y3);
        Line line3(x3, y3, x4, y4);
        Line line4(x4, y4, x1, y1);
        
        line1.draw(fr);
        line2.draw(fr);
        line3.draw(fr);
        line4.draw(fr);
    }
}

bool Lozenge::is_valid(Frame* fr) {
    return (
        fr->on_frame(x1, y1) && fr->on_frame(x2, y2)
        && x1 < x2
        && y1 < y2
        && y1 == y3
        && x2 == x4
    );
}
