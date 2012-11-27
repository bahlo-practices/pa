/*  __ 
 * /_ |
 *  | |
 *  | |
 *  | |
 *  |_|
 * 
 * Checks Date for validity
 * 
 * Created on 21. November 2012, 16:44
 * 
 */

#include <cstdlib>
#include <iostream>
#include "date.h"

using namespace std;

int main(int argc, char** argv) {
try {
   Date datum1(2011, Date::Jan, 29);
        datum1.print();
        for (int i = -13; i <= 13;++i) { // unterschiedlich große Inkremente
            datum1.add_month(i);
            datum1.print();
            
        }
       
        cout << endl << endl;
        
        Date datum3(2012, Date::Nov, 23);
        datum3.print();
        for (int i = 0; i <= 5; i++) {
            datum3.inc_day(i);
            //cout << datum3<<endl;
            datum3.print();
        }

        cout << endl << endl;
        
        Date datum4(2001, Date::Jun, 23);
            datum4.print();
            Date datum5(2000, Date::Apr, 6);
            datum5.print();
            int a = datum4.compareTo(datum4, datum5);
            cout << a << endl;
        
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

