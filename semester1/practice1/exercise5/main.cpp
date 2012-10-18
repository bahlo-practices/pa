/* 
 *                                         | |   (_)      
 *   __ _ _ __ _ __   ___   _   _ _ __   __| |    _  ___  
 *  / _` | '__| '_ \ / _ \ | | | | '_ \ / _` |   | |/ _ \ 
 * | (_| | |  | | | |  __/ | |_| | | | | (_| |   | | (_) |
 *  \__,_|_|  |_| |_|\___|  \__,_|_| |_|\__,_|   | |\___/ 
 *                                              _/ |       
 *                                             |__/    
 *
 * Created on 12. Oktober 2012, 21:17
 * 
 * This programm displays the biggest and smallest value available for variables
 * fromt the type int
 * 
 */

#include <iostream>
#include <limits.h>

using std::cin;
using std::cout;
using std::string;

int main() {
    
    /* ALTERNATE METHOD, NOT PERFOMANT
       ===============================
    int smallest = 0;
    int biggest = 0;

    // calculate biggest
    while (true) {
        if(biggest + 1 > 0) {
            biggest++;
        } else {
            break;
        }
    }

    // calculate smallest
    while (true) {
        if(smallest - 1 < 0) {
            smallest--;
        } else {
            break;
        }
    }
    */
    
    // way better
    cout << "Die gr\x94sste m\x94gliche Wert vom Typ Int ist " << INT_MAX << ", ";
    cout << "\nder kleinste ist " << INT_MIN;
    cout << "\nund der gr\x94te unsigned int ist " << UINT_MAX << "\n";
    
    return 0;
}

