/* 
 * File:   main.cpp
 * Author: Johannes Wahl
 *
 * Created on 24. November 2012, 14:55
 */
#include "mp3Tag.h"
#include "mp3TagList.h"
#include <cstdlib>
#include <vector>

using namespace std;

int main() {
    
    mp3TagList liste; //object for mp3Tag objects, contains vector of mp3Tag
    
    mp3Tag test;
    mp3Tag run("Iron Maiden", "Run to the Hills", 5.30, false, mp3Tag::Rock);
//    test.printall();
//    test.setkopierschutz(false);
//    test.printall();
    
    
    liste.populate(test);
    liste.populate(run);
    liste.printall();
    
    return 0;
}

