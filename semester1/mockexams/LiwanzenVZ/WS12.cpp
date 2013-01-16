/* 
 * Created on 16. Januar 2013, 10:19
 */

#include <iostream>
#include "WS12.h"

using namespace std;

// Setter
Liwanze::Liwanze() : name(" "), loc(Liwanze::ndef) {
}
Liwanze::Liwanze(string _name, Region _loc) : name(_name), loc(_loc) {
}

// Getter
string Liwanze::get_name() const {
    return name;
}
int Liwanze::get_loc() const {
    return loc;
}
void Liwanze::print() const {
    cout << "Name: " << name << ", Ort: ";
    switch(loc) {
        case 1:
            cout << "amer";
            break;
        case 2:
            cout << "apac";
            break;
        case 3:
            cout << "emea";
            break;
        default:
            cout << "ndef";
            break;
    }
    cout << endl;
}