/*  
 * Created on 4. Dezember 2012, 00:18
 */



#include "vec.h"
#include "cstdlib"
#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;
using std::left;
using std::rand;

using namespace std;

vec::vec() {
}

bool vec::generate_int(int iCount) {
    vector<int> tmp;
    vInt = tmp; // clear vector

    for (int i(0); i < iCount; i++) {
        vInt.push_back(rand() % 100);
    }
    return true;
}

bool vec::generate_str(int iCount) {
    vector<string> tmp;
    vStr = tmp; // clear vector
    string sWord = "";
    string sCharset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";

    for (int i(0); i < iCount; i++) {
        sWord = "";
        for (int j(0); j < (rand() % 15) + 1; j++) {
            sWord = sWord + sCharset[rand() % (sCharset.size() - 1)];
        }
        vStr.push_back(sWord);
    }
}

void vec::print_int() {
    for (int i(0); i < vInt.size(); i++) {
        cout << left << setw(3) << vInt.at(i);
        if ((i + 1) % 20 == 0 && i > 0) cout << endl;
    }
    cout << endl;
}

void vec::print_str() {
    for (int i(0); i < vStr.size() ; i++) {
        cout << vStr.at(i) << endl;
    }
    cout << endl;
}

vector<int> vec::get_int() {
    return vInt;
}

vector<string> vec::get_str() {
    return vStr;
}

void vec::set_int(vector<int> vIntNew) {
    vInt = vIntNew;
}

void vec::set_str(vector<string> vStrNew) {
    vStr = vStrNew;
}

bool vec::is_int_empty(bool message) {
    bool result = !vInt.size() > 0;
    if (result && message) cout << "Kein intVektor generiert !" << endl;
    return result;
}

bool vec::is_str_empty(bool message) {
    bool result = !vStr.size() > 0;
    if (result && message) cout << "Kein stringVektor generiert !" << endl;
    return result;
}

bool vec::are_both_empty(bool message) {
    bool result = (!vInt.size() > 0 && !vStr.size() > 0);
    if (result && message) cout << "Noch kein Vektor generiert !" << endl << endl;
    return result;
}

bool vec::check_int() {
    for(int i(0); i < vInt.size(); i++) {
        if(vInt.at(i) > vInt.at(i+1)) return false;
    }
    return true;
}

bool vec::check_str() {
    for(int i(0); i < vStr.size(); i++) {
        if(vStr.at(i) > vStr.at(i+1)) return false;
    }
    return true;
}