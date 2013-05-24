/* 
 * File:   myVec.cpp
 * 
 * Created on 13. Mai 2013, 17:26
 */

#include "myVec.h"
#include <stdexcept>


myVec::myVec() : myVector(), lb(0) {
}

myVec::myVec(int low, int high) : myVector(high - low + 1), lb(low) {
}

int myVec::lo() const {
    return lb;
}

int myVec::hi() const {
    return lb + size() - 1;
}

double& myVec::operator[](int i) {
    return myVector::operator[](i - lb);
}

const double& myVec::operator [](int index) const {
    if (index < 0 || size() <= index) {
        //cout << "myVector::operator[](), bad index";
        throw std::out_of_range("myVector::operator[](), bad index");
    }
    return myVector::operator[](index - lb);
}

double myVec::get(int index)const {
    double fu = myVector::get(index - lb);
    return fu;
}

void myVec::set(int index, double d) {
    myVector::set(index - lb, d);
}