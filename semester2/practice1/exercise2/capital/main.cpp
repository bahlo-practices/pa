/* 
 * File:   main.cpp
 * Author: arne
 *
 * Created on 3. April 2013, 19:58
 */

#include <iostream>
#include <vector>
#include <stdexcept>

#include "NPV.h"

using namespace std;

int main() {
    try {
        // Create investment vector
        vector<long int> inv;
        
        // Create rate
        double rate = 0.0;
        
        for(int i = 0; i < 10; i++) {
            NPV capital(inv, rate);
            capital.randomize();
            capital.calculate();
            capital.print();
        }

        return 0;  
    } catch (exception &e) {
        cerr << e.what();
        return 1;
    } catch (...) {
        cerr << "Unbekannter Fehler!";
        return 2;
    }
}

