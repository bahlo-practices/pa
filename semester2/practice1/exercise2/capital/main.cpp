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
        inv.push_back(123456);
        inv.push_back(234567);
        inv.push_back(345678);
        inv.push_back(456789);
        inv.push_back(567890);

        // Create rate
        double rate = 13.37;

        NPV capital(inv, rate);

        capital.randomize();
        capital.calculate();

        capital.print();

        return 0;  
    } catch (exception &e) {
        cerr << e.what();
        return 1;
    } catch (...) {
        cerr << "Unbekannter Fehler!";
        return 2;
    }
}

