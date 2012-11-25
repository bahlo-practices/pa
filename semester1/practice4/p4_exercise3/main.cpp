/* 
 * File:   main.cpp
 * Author: Johannes Wahl
 *
 * Created on 24. November 2012, 14:55
 */
#include "mp3Tag.h"
#include <cstdlib>
#include <vector>

using namespace std;

int main() {
      
    mp3Tag test;
    test.printall();
    test.setkopierschutz(false);
    test.printall();
    
    return 0;
}

