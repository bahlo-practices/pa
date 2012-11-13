/*  ____  
 * |___ \ 
 *   __) |
 *  |__ < 
 *  ___) |
 * |____/ 
 * 
 * Created on 25. Oktober 2012, 22:24
 * 
 * Calculates the small 1x1
 * 
 */

#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::string;
using std::endl;

// Manipulators
using std::setw;
using std::right;

int main() {
    // Initialize variables
    int tmp = 0;
	
    // Calculation
    for(int i = 1; i <= 10; i++) {
    	for (int ii = 1; ii <= 10; ii++) {
    		tmp = i * ii;
                cout << right << setw(4) << tmp;
    	}
    	cout << endl;
    }
    
    return 0;
}
