/* 
 * 2
 *
 * Created on 5. Dezember 2012, 20:08
 */

#include "randomValues.h"
#include "myError.h"

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {
    try {

        srand(time(NULL)); //Generate random number set     
        int anzahl = 0;
        int lookingfor = 0;
        string slookingfor = "";
        int result = 0;

        randomValues data;
        vector<int> intData;

        cout << "Wieviele Elemente moechten Sie in dem int Vector zufaellig erstellen lassen? Eingabe: ";
        cin >> anzahl;

//        //fill int vectors with random numbers and print them
        
        
//        //data.intBinSearch(anzahl); //control function
//        //data.printallint(); //control function
//
//        cout << "\nWieviele Elemente moechten Sie in dem string Vector zufaellig erstellen lassen? Eingabe: ";
//        cin >> anzahl;
//
//        //fill string vectors with string values with a length of 5 chars
//        data.fillstring(anzahl);
//        //data.printallstring(); //control function
//
//        cout << "Nach welcher Zahl moechten Sie mit der sequenziellen Suche suchen? Eingabe: ";
//        try {
//            cin >> lookingfor;
//            result = data.intSeqSearch(lookingfor);
//            cout << "\nZahl wurde an Stelle: " << result << " im Vektor gefunden." << endl;
//        } catch (exception &e) {
//            cout << "Das Element wurde nicht gefunden." << endl;
//        }
//
//        cout << "Nach welcher Zahl moechten Sie mit der binaeren Suche suchen? Eingabe: ";
//        try {
//            cin >> lookingfor;
//            result = data.intBinSearch(lookingfor);
//            cout << "\nZahl wurde an Stelle: " << result << " im Vektor gefunden." << endl;
//        } catch (exception &e) {
//            cout << "Das Element wurde nicht gefunden." << endl;
//        }
//
//        cout << "Nach welchem String moechten Sie mit der sequenziellen Suche suchen? Eingabe: ";
//        try {
//            cin >> slookingfor;
//            result = data.stringSeqSearch(slookingfor);
//            cout << "\n Der String wurde an Stelle " << result << " im Vektor gefunden." << endl;
//        } catch (exception &e) {
//            cout << "Das Element wurde nicht gefunden." << endl;
//        }

        

        
      
        
        
        return 0;
    } catch (exception &e) {
        cerr << e.what();
    } catch (...) {
        cerr << "Unbekannter Fehler!";
    }
}


//        vector<int> values;
//        values.push_back(2);
//        values.push_back(8);
//        values.push_back(1);
//        values.push_back(3);
//        values.push_back(5);
//        sort(values.begin(),values.end());
//        int length = values.size();
//        int result2 = 2;
//        
//           result2 = data.binSearch(values, 4, 0, length);
//           cout << "Ergebnis: "<<result2;