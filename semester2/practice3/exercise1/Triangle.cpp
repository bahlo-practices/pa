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

/*
 *      1:7
 *     +   +
 *    +     +
 *  4:3++++++4:12
 */

Triangle::Triangle() : x1(0), y1(0), x2(0), y2(0), x3(0), y3(0) {};

Triangle::Triangle(int _x1, int _y1, int _x2, int _y2, int _x3, int _y3) : x1(_x1), y1(_y1), x2(_x2), y2(_y2), x3(_x3), y3(_y3) {};

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
    if(
       fr->on_frame(x1, y1) && fr->on_frame(x2, y2) && fr->on_frame(x3, y3) && // Alle Punkte auf dem Frame?
       y1 > y2 && // Erster Punkt über den beiden anderen
       y2 == y3 && // Die beiden anderen Punkte müssen auf einer Höhe sein
       x2 < x3 // Punk 2 muss links von Punkt 3 liegen
    ) {
        // Create 3 Line objects to create triangle
        Line line1(x1, y1, x2, y2);
        Line line2(x2, y2, x3, y3);
        Line line3(x3, y3, x1, y1);
        
        line1.draw(fr);
        line2.draw(fr);
        line3.draw(fr);
    } else throw std::runtime_error("Dreieck nicht korrekt!");
}
