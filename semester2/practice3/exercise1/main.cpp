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
        //triangle1.draw(&frame1);
        
        // Triangle c)
        Triangle triangle2(0, 0, 10, 10, 20);
        //triangle2.draw(&frame1);
        
        // Testfälle
        // 1
        Line line3;
        line3.draw(&frame1);
        // 2
        Line line4(0, -10, 0, 0);
        // line4.draw(&frame1);
        // 3
        Line line5(3, 0, 10, 10);
        Line line6(3, 10, 10, 0);
        line5.draw(&frame1);
        line6.draw(&frame1);
        // 4
        // Line line7(100, 20);
        // 5
        Line line8(0, 99, 99, 0);
        line8.draw(&frame1);
        // 6
        Triangle triangle3;
        // triangle3.draw(&frame1);
        // 7
        Triangle triangle4(50, 99, 99, 0, 0, 0);
        triangle4.draw(&frame1);
        // 8
        Triangle triangle5(20, 20, 40, 20, 30);
        triangle5.draw(&frame1);
        // 9
        Triangle triangle6(10, 10, 20, 0, 0, 0);
        triangle6.move(10, 20);
        triangle6.draw(&frame1);
        // 10
        Triangle triangle7(40, 50, 60, 30, 30, 30);
        triangle7.move(-20, -10);
        triangle7.draw(&frame1);
        // */

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

