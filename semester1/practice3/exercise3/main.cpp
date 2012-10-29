/*    _                         _                         
 *   (_)                       | |                        
 *    _  ___    _   _ _ __   __| |   __ _ _ __ _ __   ___ 
 *   | |/ _ \  | | | | '_ \ / _` |  / _` | '__| '_ \ / _ \
 *   | | (_) | | |_| | | | | (_| | | (_| | |  | | | |  __/
 *   | |\___/   \__,_|_| |_|\__,_|  \__,_|_|  |_| |_|\___|
 *  _/ |                                                  
 * |__/                                                   
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
    	for (int ii = 1; i<= 10; i++) {
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
