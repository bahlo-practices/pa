/* 
 * File:   main.cpp
 * Author: Johannes Wahl
 * Description: checks Date for validity
 * Created on 21. November 2012, 16:44
 */

#include <cstdlib>
#include "date.h"
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
try {
//        Date datum1( 2011, Date::Jan, 29 );
//        cout << datum1 << endl;
//        for( int i=-13; i<=13; ++i ) { // unterschiedlich große Inkremente
//            datum1.add_month( i );
//            cout << datum1 << endl;
//        }
//        Date datum2;
//        cout << datum2 << endl;
//        Date::Month mt( datum2.month() );
//        for( int i=0; i<=12; ++i ) cout << ++mt << ' ';
//    
//    Date datum3 (2012, Date::Nov, 23);
//    datum3.print();
//    for (int i=0; i<=10; i++){
//        datum3.inc_day(i);
//        cout << datum3<<endl;
//        datum3.print();
//    }
//    Date datum3 (2012, Date::Jan, 25);
//    Date datum4 (2012, Date::Jan, 24);
//    int a = datum3.compareTo(datum3,datum4);
//    cout << a;
    
    Date datum2 (1850, Date::Dez, -15);
    datum2.print();
    
        
        // usw. 
        
        return 0; 
    }
    catch( Date::Invalid ) {
        cerr << "Datum ung" << '\x81' << "ltig" << endl;
        return 1; 
    }
    catch( ... ) {
        cerr << "Ein Fehler";
        return 2; 
    }

}

