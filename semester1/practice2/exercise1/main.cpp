/*  __       
 * /_ |      
 *  | | __ _ 
 *  | |/ _` |
 *  | | (_| |
 *  |_|\__,_|
 * 
 * Created on 18. Oktober 2012, 21:21
 * 
 * This programm calculates the squareroot of a number
 * 
 */

#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::string;

using std::sqrt;
using std::endl;

int main() {
    // initialize variables
    double dFpn = 0.0; // floating-point number
    double dFpnRoot= 0.0; // suqareroot of float
    
    // prompt the user to make an input
    cout << "Geben Sie eine Gleitkommazahl >= 0 ein: ";
    cin >> dFpn;
    
    // check if smaller 0
    if(dFpn < 0) {
        cout << "\nMan kann keine Wurzel von einer negativen Zahl nehmen!" << endl;
        return -1;
    }
    
    // calculate squareroot
    dFpnRoot = sqrt(dFpn);
    
    // give out the result
    cout << "\nDie Quadratwurzel von " << dFpn << " ist " << dFpnRoot << "\n";
    
    // success
    return 0;
}
