//
//  Triangle.cpp
//  exercise1
//
//  Created by Arne Bahlo on 22.04.13.
//  Copyright (c) 2013 Arne Bahlo. All rights reserved.
//

#include <stdexcept>
#include <cmath>

#include "Line.h"

#include "Triangle.h"

Triangle::Triangle() : x1(0), y1(0), x2(0), y2(0), x3(0), y3(0) {};

Triangle::Triangle(int _x1, int _y1, int _x2, int _y2, int _x3, int _y3) : x1(_x1), y1(_y1), x2(_x2), y2(_y2), x3(_x3), y3(_y3) {};

Triangle::Triangle(int hor, int ver, int len1, int len2, int len3) : x1(ver), y1(hor), x2(0), y2(0), x3(0), y3(0) {
/*    // Calculate way to top (/)
    x2 = x1 + len1;
    y2 = y1 + len1;
    // Calculate way from top to bottom right (\)
    x3 = x2 + len2;
    y3 = y2 - len2;
    // Check if we have a triangle
    if( x3 - len3 != x1 || y3 != y1 )
        throw std::runtime_error( "Dreieck nicht korrekt" );
 */
    int c = 0;
    if ( len1 >= len2 && len1 >= len3 ) c = len1;
    if ( len2 >= len1 && len2 >= len3 ) c = len2;
    if ( len3 >= len1 && len3 >= len2 ) c = len3;
    int b = 0;
    if ( len1 <= len2 && len1 <= len3 ) b = len1;
    if ( len2 <= len1 && len2 <= len3 ) b = len2;
    if ( len3 <= len1 && len3 <= len2 ) b = len3;
    int a = 0;
    if ( len1 <= c && len1 >= b ) a = len1;
    if ( len2 <= c && len2 >= b ) a = len2;
    if ( len3 <= c && len3 >= b ) a = len3;
    

    x3 = x1 + c;
    y3 = y1;
    
    double a2 = std::pow(a, 2);
    double b2 = std::pow(b, 2);
    double c2 = std::pow(c, 2);

    /* Wer braucht Winkel??
    double beta = ( ( a2 + c2 - b2 ) / (2 * a * c ) ) * ( 180 / M_PI );
    double alpha = 90;
    double gamma = 180 - alpha - beta;
    */
    
    // Höhe berechnen
    double hc = sqrt( 2 * ( a2 * b2 + b2 * c2 + c2 * a2 ) - ( std::pow(a, 4) + std::pow(b, 4), std::pow(c, 4) ) ) / (2 * c);
    
    // e berechnen
    double e = b2 / c;
    
    x2 = c - e;
    y2 = y1 + hc;
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
    // Seiten berechnen
    int side1 = sqrt( std::pow( (x1 - x2), 2 ) + std::pow( ( y1 - y2 ), 2) );
    int side2 = sqrt( std::pow( (x2 - x3), 2 ) + std::pow( ( y2 - y3 ), 2) );
    int side3 = sqrt( std::pow( (x3 - x1), 2 ) + std::pow( ( y3 - y1 ), 2) );
    
    // Steigungen
    double m1 = 0;
    double m2 = 0;
    if ( x1 == x2 || x2 == x3 || x3 == x1 ) {
        // Hier wird die Steigung nicht überprüft
    } else {
        m1 = (double) ( y2 - y1 ) / ( x2 - x1 );
        m2 = (double) ( y3 - y2 ) / ( x3 - x2 );
        if ( m1 == m2 ) return false;
    }
    
    return (
        fr->on_frame(x1, y1) && fr->on_frame(x2, y2) && fr->on_frame(x3, y3) // Alle Punkte auf dem Frame
        // Keine Seite darf größer sein, als die anderen beiden
        && ( !( x1 == x2 && x2 == x3 ) )
        && ( !( y1 == y2 && y2 == y3 ) )
        && side1 <= side2 + side3
        && side2 <= side1 + side3
        && side3 <= side1 + side2
    );
}