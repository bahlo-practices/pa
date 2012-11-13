/* 
 * File:   Name_values.h
 *
 * Created on 12. November 2012, 15:20
 */

#ifndef NAME_VALUES_H
#define	NAME_VALUES_H

#include <vector>
#include <string>

using namespace std;

class Name_values {
    public: 
        Name_values();  // Standardkonstruktor 
        Name_values( string name, vector<int> vValue ); // Konstruktor 
        void add_value( int value );  // weiteren Wert speichern 
        void print_all( ) const;  // alles ausgeben gem. Aufgabe 
        string get_name( ) const;  // Name liefern 
    private: 
        string name; 
        vector<int> values; 
}; 

#endif	/* NAME_VALUES_H */

