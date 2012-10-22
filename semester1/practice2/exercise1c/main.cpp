/*
 *                                         | |   (_)      
 *   __ _ _ __ _ __   ___   _   _ _ __   __| |    _  ___  
 *  / _` | '__| '_ \ / _ \ | | | | '_ \ / _` |   | |/ _ \ 
 * | (_| | |  | | | |  __/ | |_| | | | | (_| |   | | (_) |
 *  \__,_|_|  |_| |_|\___|  \__,_|_| |_|\__,_|   | |\___/ 
 *                                              _/ |       
 *                                             |__/    
 * 
 * Created on 15. Oktober 2012, 11:58
 * 
 * Programm nähert sich mithilfe einer Schleife der Quadratwurzel an
 * 
 */

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    // Initialize variable
    double dNumber = 0.0;
    int dPrecision = 0;
    double dInterim = 1.0;
    
    // Prompt user for input
    cout << "Bitte Dezimalzahl eingeben, dessen Quadratwurzel berechnet werden soll: ";
    cin >> dNumber;
    cout << "\nGeben Sie die Genauigkeit ein, mit der die Berechnung stattfinden soll (empfohlen: 8): ";
    cin >> dPrecision;
    
    // Prevent failure
    if(dPrecision <= 0) {
        cout << "Fehler: Die Genauigkeit kann nicht 0 oder kleiner sein." << endl;
        return false; // Exit programm
    }
    
    // Calculation
    for(int i = 0; i < dPrecision; i++) {
        dInterim = 0.5 * (dInterim + dNumber / dInterim);
    }
    
    // Cout the result
    cout << "\nDas Ergebnis mit " << dPrecision << "-facher Genauigkeit lautet: " << dInterim;
            
    return 0;
}

