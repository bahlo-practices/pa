/* 
 * Created on 16. Januar 2013, 10:19
 */

#include <iostream>
#include "WS12.h"

using namespace std;

// Setter
Liwanze::Liwanze() : name(" "), loc(Liwanze::ndef), connectsTo(), connectedFrom() {
}
Liwanze::Liwanze(string _name, Region _loc) : name(_name), loc(_loc), connectsTo(), connectedFrom() {
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

// Aufgabe 2
bool Liwanze::connects(Liwanze* srcLiwanze) const {
    return (srcLiwanze->get_name() == connectsTo.at(0));
}
bool Liwanze::connected(Liwanze* srcLiwanze) const {
    return (srcLiwanze->get_name() == connectedFrom.at(0));
}
void Liwanze::print_tierone() const {
    cout << connectsTo.at(0) << endl;
    return;
}
void Liwanze::add_connTo(Liwanze* toLiwanze) {
    connectsTo.push_back(toLiwanze->get_name());
}
void Liwanze::add_connFrom(Liwanze* fromLiwanze) {
    connectedFrom.push_back(fromLiwanze->get_name());
}
