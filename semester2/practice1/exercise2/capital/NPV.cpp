/* 
 * File:   NPV.cpp
 * Author: arne
 * 
 * Created on 3. April 2013, 20:00
 */

#include <iostream>
#include <vector>
#include <stdlib.h>

#include "NPV.h"

NPV::NPV() : inv(0), irate(0.0), capital(0.0) {}

NPV::NPV(vector<long int> inv, double irate) : inv(inv), irate(irate), capital(0.0) {}

// Randomize
void NPV::randomize() {
    // Generate random inv
    for(int i = 0; i < 20; i++) {
        long int number = rand() % 100000;
        if(rand() % 2 == 1) number = number * -1;
        this->inv.push_back(number);
    }
    // Generate random rate
    double rate = rand() % 1000;
    rate = rate / 10000;
    this->irate = rate;
}

// Calculation
void NPV::calculate() {
    for(int i = 0; i < this->inv.size(); i++) {
        this->inv.at(i) * this->irate;
    }
    this->capital = 13.38;
}

// Getter
vector<long int> const NPV::get_inv() {
    return this->inv;
}
double const NPV::get_irate() {
    return this->irate;
}

// Setter
void NPV::set_inv(vector<long int> inv) {
    this->inv = inv;
}
void NPV::set_irate(double irate) {
    this->irate = irate;
}

// Print
void const NPV::print() {
    cout << "Zahlungsreihe: ";
    for(int i = 0; i < this->inv.size(); i++) {
        cout << this->inv.at(i);
        if(i != this->inv.size() - 1) {
            cout << ", ";
        } else {
            cout << endl;
        }
    }
    cout << "Zinssatz: " << this->irate * 100 << " %" << endl;
    cout << "Kapital: " << this->capital << endl;
    cout << "----" << endl;
}

