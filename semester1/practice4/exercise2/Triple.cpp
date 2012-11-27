/* 
 * File:   Triple.cpp
 * Author: jw
 * 
 * Created on 27. November 2012, 09:17
 */

#include "Triple.h"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

Triple::Triple() {
}

Triple::Triple(string in) :inhalt(in){
}

void Triple::backwards(string in) {
    int length = in.length();
    for (int i = length - 1; i >= 0; i--) {
        cout << in[i]; //output string backwards
    }
    cout<<endl;
}

void Triple::sortieren(string in) {

    sort(in.begin(), in.end()); //sort vector by value    
    cout<<in<<endl;
}


