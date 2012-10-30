/*  __ _     
 * /_ | |    
 *  | | |__  
 *  | | '_ \ 
 *  | | |_) |
 *  |_|_.__/ 
 * 
 * Created on 15. Oktober 2012, 11:58
 * 
 * Programm nähert sich in acht schritten der quadratwurzel an
 * 
 */

#include <iostream>

using std::cout;
using std::cin;

using std::endl;

int main() {
    // Initialize variables
    double zahl = 0.0;
    double x = 0.0;
    
    // Prompt user for input
    cout << "Bitte Dezimalzahl eingeben, dessen Quadratwurzel berechnet werden soll: ";
    cin >> zahl;
    
    x = zahl;
    
    // check if smaller 0
    if(zahl < 0) {
        cout << "\nMan kann keine Wurzel von einer negativen Zahl nehmen!" << endl;
        return -1;
    }
    
    // Calculate in 8 steps
    x = 0.5 * (x + zahl / x);
    x = 0.5 * (x + zahl / x);
    x = 0.5 * (x + zahl / x);
    x = 0.5 * (x + zahl / x);
    x = 0.5 * (x + zahl / x);
    x = 0.5 * (x + zahl / x);
    x = 0.5 * (x + zahl / x);
    x = 0.5 * (x + zahl / x);
    
    // Cout the results
    cout << "\nWert in achter Berechnung: " << x << endl;
    
    return 0;
}
