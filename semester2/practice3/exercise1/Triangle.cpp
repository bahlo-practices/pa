//
//  Triangle.cpp
//  exercise1
//
//  Created by Arne Bahlo on 22.04.13.
//  Copyright (c) 2013 Arne Bahlo. All rights reserved.
//

#include <stdexcept>

#include "Line.h"

#include "Triangle.h"

Triangle::Triangle() : x1(0), y1(0), x2(0), y2(0), x3(0), y3(0) {};

Triangle::Triangle(int _x1, int _y1, int _x2, int _y2, int _x3, int _y3) : x1(_x1), y1(_y1), x2(_x2), y2(_y2), x3(_x3), y3(_y3) {};

Triangle::Triangle(int hor, int ver, int len1, int len2, int len3) : x1(ver), y1(hor), x2(0), y2(0), x3(0), y3(0) {
    // Calculate way to top (/)
    x2 = x1 + len1;
    y2 = y1 + len1;
    // Calculate way from top to bottom right (\)
    x3 = x2 + len2;
    y3 = y2 - len2;
    // Check if we have a triangle
    x1 = x3 - len3;
    y1 = y3;
}

void Triangle::move(int x, int y) {
    // Horizontal
    x1 += x;
    x2 += x;
    x3 += x;
    // Vertical
    y1 += y;
    y2 += y;
    y3 += y;
}

void Triangle::draw(Frame* fr) {
    /*
     *     x2y2
     *     /  \
     *    /    \
     *   /      \
     * x1y1----x3y3
     */
    if(is_valid(fr)) {
        // Create 3 Line objects to create triangle
        Line line1(x1, y1, x2, y2);
        Line line2(x2, y2, x3, y3);
        Line line3(x3, y3, x1, y1);
        
        line1.draw(fr);
        line2.draw(fr);
        line3.draw(fr);
    } else {
        throw std::runtime_error("Dreieck nicht korrekt!");
    }
}

bool Triangle::is_valid(Frame* fr) {
    return (
        fr->on_frame(x1, y1) && fr->on_frame(x2, y2) && fr->on_frame(x3, y3) // Auf dem Frame
        && y2 > y1 // Punkt 1 höher als Punkt 2 (und damit auch 3)
        && y1 == y3 // Punkt 2 und 3 auf gleicher höhe
        && x3 > x1 // Punkt 2 weiter rechts als Punkt 3
    );
}