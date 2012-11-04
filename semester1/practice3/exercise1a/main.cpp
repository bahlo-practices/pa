/* 
 * File:   main.cpp
 * Author: Arne Leiblein & Johannes Wahl
 * Description: calculates greatest common divisor
 * Created on 4. November 2012, 10:27
 */

#include <iostream>
#include "myError.h"

using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::string;

int main() {

    try {
        int i1 = 0, i2 = 0, tmp = 0, n = 1;
        bool decision = false;
        char erneut = 'a';

        do {
            cout << "Zwei positive ganze Zahlen eingeben (jeweils getrennt durch Enter) "
                    "um den gr\x94\xe1ten gemeinsamen Teiler zu berechnen: ";
            
            if(!(cin>>i1)) error("Fehler in Eingabe der ersten Zahl. Bitte positive ganze Zahlen eingeben.");
            if(!(cin>>i2)) error("Fehler in Eingabe der zweiten Zahl. Bitte positive ganze Zahlen eingeben");
            

            while (i1 != i2) {
                cout << "\t(" << i1 << "," << i2 << ")" << endl;

                if (i1 < i2) i2 = i2 - i1;
                else {
                    tmp = i1;
                    i1 = i2;
                    i2 = tmp - i1;
                }

                ++n;
            }

            cout << "\t(" << i1 << "," << i2 << ")" << endl;
            cout << n << " Schritte zum ggT\n" << endl;
            cout << "\t M\x94 \bchten Sie das Programm erneut ausf\x81hren (y)es/(q)uit?";
            cin >> erneut;
            cout << endl;
            
            if(erneut=='q') decision=false;
            if(erneut=='y') decision=true;
            if(erneut!='q' && erneut!='y') error("Fehler in der Eingabe: Benutzen Sie entwerder y oder q als Eingabe.");

        } while (decision != false);
        return 0;

    }
    catch(runtime_error& e){
        cerr << e.what( );
        return -2; 
    }
    catch(...){
        cerr << "Unbekannter Fehler!";
        return -1;
    }

}

