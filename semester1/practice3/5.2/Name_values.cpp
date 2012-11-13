/* 
 * File:   Name_values.cpp
 * 
 * Created on 12. November 2012, 15:20
 */

#include <iostream>
#include "Name_values.h"

Name_values::Name_values() : name(""), values(0) { }

Name_values::Name_values( string Name, vector<int> vValue ) : name(Name), values(vValue.size()) {
     for( int i = 0; i < vValue.size(); i++ ) {
        values.at(i) = vValue.at(i);
    }
} // Konstruktor 
void Name_values::add_value( int value ){
    values.push_back(value);
}  // weiteren Wert speichern 
void Name_values::print_all( ) const {
    cout << "\n" << name << ": ";
    for(int i = 0; i < values.size(); i++ ) {
        cout << values.at(i) << " ";
    }
}  // alles ausgeben gem. Aufgabe 
string Name_values::get_name( ) const {
    return name;
}  // Name liefern 
