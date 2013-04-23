//
//  Rectangle.cpp
//  exercise1
//
//  Created by Arne Bahlo on 23.04.13.
//  Copyright (c) 2013 Arne Bahlo. All rights reserved.
//

#include "Line.h"

#include "Rectangle.h"

Rectangle::Rectangle() : x1(0), y1(0), x2(0), y2(0) {};

Rectangle::Rectangle(int _x1, int _y1, int _x2, int _y2) : x1(_x1), y1(_y1), x2(_x2), y2(_y2) {};

void Rectangle::move(int x, int y) {
    x1 += x;
    x2 += x;
    y1 += y;
    y2 += y;
}

void Rectangle::draw(Frame* fr) {
    /* 
     * x1y2-------x2y2
     * |             |
     * |             |
     * |             |
     * x1y1-------x2y1
     */
    if(x1 > x2 && y1 > y2) {
        std::swap(x1, x2);
        std::swap(y1, y2);
    }
    if(is_valid(fr)) {
        // Create 4 lines
        Line line1(x1, y1, x1, y2);
        Line line2(x1, y2, x2, y2);
        Line line3(x2, y2, x2, y1);
        Line line4(x2, y1, x1, y1);
        // Draw them
        line1.draw(fr);
        line2.draw(fr);
        line3.draw(fr);
        line4.draw(fr);
    } else {
        throw std::runtime_error("Rechteck nicht korrekt!");
    }
}

bool Rectangle::is_valid(Frame* fr) {
    return (
        fr->on_frame(x1, y1) && fr->on_frame(x2, y2)
    );
}


