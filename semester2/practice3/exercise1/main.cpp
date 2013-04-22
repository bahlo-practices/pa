/* 
 * File:   main.cpp
 *
 * Created on 9. April 2013, 17:51
 */

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <ctime>

#include "Frame.h"
#include "Line.h"
#include "Triangle.h"

int main(int argc, char** argv) {
    try {
        int x1 = 5;
        int y1 = 11;
        int x2 = 1;
        int y2 = 1;
        
        Frame frame1;
        
        // Line
        Line line1(x1, y1, x2, y2);
        //line1.draw(&frame1);
        
        // Triangle
        x1 = 10;
        y1 = 5;
        x2 = 0;
        y2 = 0;
        int x3 = 20;
        int y3 = 0;
        Triangle triangle1(x1, y1, x2, y2, x3, y3);
        triangle1.draw(&frame1);

        clock_t start = clock_t(-1);
        clock_t end = clock_t(-1);
        start = clock();
        std::cout << &frame1;
        end = clock();
        
        std::cout << "Laufzeit: "<< double (end-start)/CLOCKS_PER_SEC << "s" << std::endl;

        return 0;
        
    } catch (std::exception &e) {
        std::cerr << e.what();
        return -2;
    } catch (...) {
        std::cerr << "Unbekannter Fehler";
        return -1;
    }
}

