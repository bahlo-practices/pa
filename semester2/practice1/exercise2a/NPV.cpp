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

NPV::NPV(vector<long int> _inv, double _irate) : inv(_inv), irate(_irate), capital(0.0) {
    if(_irate < 0 || _irate > 1) throw Invalid();
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
vector<long int> NPV::get_inv() const {
    return inv;
}
double NPV::get_irate() const {
    return irate;
}

// Setter
void NPV::set_inv(vector<long int> _inv) {
    inv = _inv;
}
void NPV::set_irate(double _irate) {
    if(_irate >= 0 && _irate <= 1) irate = _irate;
}

// Print
void NPV::print() const {
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

