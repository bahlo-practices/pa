/* 
 * File:   Name_values.h
 *
 * Created on 11. November 2012, 12:05
 */

#ifndef NAME_VALUES_H
#define	NAME_VALUES_H

#include <vector>
#include <string>

using namespace std;

class Name_values {
    public: 
        Name_values(); 
        Name_values( string name, vector<int> vValue );
        void add_value( int value );
        void print_all( ) const; 
        string get_name( ) const;
    private: 
        string name; 
        vector<int> values; 
}; 

#endif	/* NAME_VALUES_H */

