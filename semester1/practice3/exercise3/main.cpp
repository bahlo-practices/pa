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

using std::cin;
using std::cout;
using std::string;
using std::endl;

int main() {
    // Initialize variables
    int tmp = 0;
    string spaces = "";
	
    // Calculation
    for(int i = 1; i <= 10; i++) {
    	for (int ii = 1; ii <= 10; ii++) {
    		tmp = i * ii;
    		if(tmp <= 9) {
    			spaces = "   ";
    		}
    		if(tmp > 9 && tmp <= 99) {
    			spaces = "  ";
    		}
    		if(tmp > 99) {
    			spaces = " ";
    		}
    		cout << spaces << tmp;
    	}
    	cout << endl;
    }
    
    return 0;
}
