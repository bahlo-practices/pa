//
//  Line.cpp
//  exercise1
//
//  Created by Arne Bahlo on 22.04.13.
//  Copyright (c) 2013 Arne Bahlo. All rights reserved.
//

#include "Line.h"

#include "Frame.h"
#include "Shape.h"

Line::Line() : x1(0), y1(0), x2(0), y2(0) {};

Line::Line(int _x1, int _y1, int _x2, int _y2) : x1(_x1), y1(_y1), x2(_x2), y2(_y2) {}

void Line::move(int x, int y) {
    // Punkt 1
    x1 += x;
    y1 += y;
    // Punkt 2
    x2 += x;
    y2 += y;
}

void Line::draw(Frame* fr) {
    if (fr->on_frame(x1, y1) && fr->on_frame(x2, y2)) {
        bool checkY(false); // Merker für "steigend/fallend"
        bool checkXY(false); // Merker für "steil/fach"
        
        if (x1 > x2) { // Überprüfen der Voraussetzungen und setzen der "Merker"
            std::swap(x1, x2);
            std::swap(y1, y2);
        }
        if (y2 < y1) {
            y2 *= -1;
            y1 *= -1;
            checkY = true;
        }
        if ((x2 - x1)<(y2 - y1)) {
            std::swap(x1, y1);
            std::swap(x2, y2);
            checkXY = true;
        }
        
        int dX = x2 - x1; // Berrechnung der für den Algorithmus notwendigen Werte
        int dY = y2 - y1;
        int dXY = 2 * dY - dX;
        
        for (int i = 0; i <= dX; ++i) {
            
            if (checkY) {
                if (checkXY) fr->put_point(y1, -x1); //fallend steil
                if (!checkXY) fr->put_point(x1, -y1); //fallend flach
            }
            if (!checkY) {
                if (checkXY) fr->put_point(y1, x1); //steigend steil
                if (!checkXY) fr->put_point(x1, y1); //steigend flach
            }
            
            if (dXY < 0) {
                x1++; // gehe nach rechts
                dXY += 2 * dY;
            } else {
                x1++; // gehe nach rechts-oben
                y1++;
                dXY += 2 * (dY - dX);
            }
        }
    } else throw std::runtime_error ( "Ermitteln der Punkte nicht möglich, da Punkte nicht auf Frame" );
}
