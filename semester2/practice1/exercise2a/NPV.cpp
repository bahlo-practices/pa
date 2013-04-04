/* 
 * File:   NPV.cpp
 * 
 * Created on 3. April 2013, 20:00
 */

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cmath>

#include "NPV.h"

NPV::NPV() : capital(0.0) {
    // Randomize data
    // Generate random inv
    for(int i = 0; i < 20; i++) {
        long int number = rand() % 100000;
        if(rand() % 2 == 1) number = number * -1;
        inv.push_back(number);
    }
    // Generate random rate between 0 % and 10.0 %
    double rate = rand() % 100000;
    rate = rate / 1000000;
    irate = rate;
}

NPV::NPV(vector<long int> inv, double irate) : inv(inv), irate(irate), capital(0.0) {
    if(irate < 0) throw Invalid();
    if(irate > 1) throw Invalid();
}

// Calculation
void NPV::calculate() {
    for (int i = 0; i < inv.size(); i++) {
        capital += inv.at(i) * (pow(1 + irate, -i));
    }
    // Round capital
    capital = floorf(capital * 1000 + 0.5) / 1000;
}

// Getter
vector<long int> const NPV::get_inv() {
    return inv;
}
double const NPV::get_irate() {
    return irate;
}

// Setter
void NPV::set_inv(vector<long int> inv) {
    inv = inv;
}
void NPV::set_irate(double irate) {
    irate = irate;
}

// Print
void const NPV::print() {
    cout << "Zahlungsreihe: ";
    for(int i = 0; i < inv.size(); i++) {
        cout << inv.at(i);
        if(i != inv.size() - 1) {
            cout << ", ";
        } else {
            cout << endl;
        }
    }
    cout << "Zinssatz: " << irate * 100 << " %" << endl;
    cout << "Kapital: " << capital << endl;
    cout << "----" << endl;
}

