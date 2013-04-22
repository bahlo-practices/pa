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

int main(int argc, char** argv) {
    try {
        int x1 = 5;
        int y1 = 11;
        int x2 = 1;
        int y2 = 1;

        Frame frame1;
        Line line1(x1, y1, x2, y2);
        //frame1.reset();
        //frame1.show();
        line1.draw(&frame1);
        

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

