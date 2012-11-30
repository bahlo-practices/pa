/* 
 * Created on 30. November 2012, 15:19
 */

#include "vec.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;
using std::left;

vec::vec() {
}

bool vec::generate(int iCount, string sWhat) {
    if(sWhat == "int") {
        for(int i(0); i < iCount; i++) {
            vInt.push_back(rand() % 100);
        }
        return true;
    }
    if(sWhat == "str") {
        // Generate string vector
    }
}

void vec::print(string sWhat) {
    if(sWhat == "int") {
        for(int i(0); i < vInt.size();i++) {
            cout << left << setw(3) << vInt.at(i);
            if((i + 1) % 16 == 0 && i > 0) cout << endl;
        }
        cout << endl;
    }
    if(sWhat == "str") {
        for(int i(0); i < vStr.size();i++) {
            cout << vStr.at(i) << endl;
        }
        cout << endl;
    }
}

vector<int> vec::get_int() {
    return this->vInt;
}

vector<int> vec::get_str() {
    return this->vStr;
}