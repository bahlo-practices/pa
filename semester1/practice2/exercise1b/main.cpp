/*    _                         _                         
 *   (_)                       | |                        
 *    _  ___    _   _ _ __   __| |   __ _ _ __ _ __   ___ 
 *   | |/ _ \  | | | | '_ \ / _` |  / _` | '__| '_ \ / _ \
 *   | | (_) | | |_| | | | | (_| | | (_| | |  | | | |  __/
 *   | |\___/   \__,_|_| |_|\__,_|  \__,_|_|  |_| |_|\___|
 *  _/ |                                                  
 * |__/                                                   
 * 
 * Created on 15. Oktober 2012, 11:58
 * 
 * Programm nähert sich in acht schritten der quadratwurzel an
 * 
 */

#include <iostream>

using std::cout;
using std::cin;

int main() {
    // Initialize variables
    double zahl = 0.0;
    double x0 = 1.0;
    double x1 = 0.0, x2 = 0.0, x3 = 0.0, x4 = 0.0, x5 = 0.0, x6 = 0.0, x7 = 0.0, x8 = 0.0;
    
    // Prompt user for input
    cout << "Bitte Dezimalzahl eingeben, dessen Quadratwurzel berechnet werden soll: ";
    cin >> zahl;
    
    
    // Calculate in 8 steps
    x1 = 0.5 * (x0 + zahl / x0);
    x2 = 0.5 * (x1 + zahl / x1);
    x3 = 0.5 * (x2 + zahl / x2);
    x4 = 0.5 * (x3 + zahl / x3);
    x5 = 0.5 * (x4 + zahl / x4);
    x6 = 0.5 * (x5 + zahl / x5);
    x7 = 0.5 * (x6 + zahl / x6);
    x8 = 0.5 * (x7 + zahl / x7);
    
    // Cout the results
    cout << "\nWert in erster Berechnung: " << x1;
    cout << "\nWert in zweiter Berechnung: " << x2;
    cout << "\nWert in dritter Berechnung: " << x3;
    cout << "\nWert in vierter Berechnung: " << x4;
    cout << "\nWert in fünfter Berechnung: " << x5;
    cout << "\nWert in sechster Berechnung: " << x6;
    cout << "\nWert in siebter Berechnung: " << x7;
    cout << "\nWert in achter Berechnung: " << x8;
    
    return 0;
}

