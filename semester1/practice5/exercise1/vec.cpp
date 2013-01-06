/*  
 * Created on 4. Dezember 2012, 00:18
 */



#include "cstdlib"
#include <iostream>
#include <iomanip>
#include "vec.h"

using std::cout;
using std::endl;
using std::setw;
using std::left;
using std::rand;

using namespace std;

vec::vec() : vInt(), vStr() {
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
        cout << left << setw(4) << vInt.at(i);
        if ((i + 1) % 16 == 0 && i > 0) cout << endl;
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
    if (result && message) cout << "Kein int Vektor generiert !" << endl;
    return result;
}

bool vec::is_str_empty(bool message) {
    bool result = !vStr.size() > 0;
    if (result && message) cout << "Kein string Vektor generiert !" << endl;
    return result;
}

bool vec::are_both_empty(bool message) {
    bool result = (!vInt.size() > 0 && !vStr.size() > 0);
    if (result && message) cout << "Noch kein Vektor generiert!" << endl << endl;
    return result;
}

bool vec::check_int() {
    for(int i(0); i < vInt.size(); i++) {
        if(vInt.at(i) > vInt.at(i+1)) return false;
    }
    return true;
}

bool vec::check_str() {
    for(int i(0); i < vStr.size() - 1; i++) {
        if(vStr.at(i).compare(vStr.at(i+1)) == 1) return false;
        
        //if(vStr.at(i) > vStr.at(i+1)) return false;
        
        /*if(vStr.at(i).length() > vStr.at(i+1).length()) {
            return false;
        } else {
            for(int j(0); j < vStr.at(i).length(); i++) {
                if(vStr.at(i)[j] > vStr.at(i+1)[j]) return false;
            }
        }*/
    }
    return true;
}