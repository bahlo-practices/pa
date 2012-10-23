/*    _                         _                         
 *   (_)                       | |                        
 *    _  ___    _   _ _ __   __| |   __ _ _ __ _ __   ___ 
 *   | |/ _ \  | | | | '_ \ / _` |  / _` | '__| '_ \ / _ \
 *   | | (_) | | |_| | | | | (_| | | (_| | |  | | | |  __/
 *   | |\___/   \__,_|_| |_|\__,_|  \__,_|_|  |_| |_|\___|
 *  _/ |                                                  
 * |__/                                                   
 * 
 * Created on 18. Oktober 2012, 21:21
 * 
 * This is a simple text calculator
 * 
 */

#include <iostream>

using std::cin;
using std::cout;
using std::string;
using std::endl;

int main() {
    // initialize variables
    char opt = '+'; // operator
    double opd1 = 0.0; // operand 1
    double opd2 = 0.0; // operand 2
    double res = 0.0; // result
    
    // receive input
    cout << "Operation: ";
    cin >> opt >> opd1 >> opd2;
    
    // check which operator and calculate the result
    switch(opt){
        case '+':
            res = opd1 + opd2;
            break;
        case '-':
            res = opd1 - opd2;
            break;
        case '*':
            res = opd1 * opd2;
            break;
        case '/':
            res = opd1 / opd2;
            break;
        default: 
            cout << "Dieser Operator wird nicht unterst\x81tzt." << endl;
            return -1;
    }
    
    // display the result
    cout << "\nErgebnis: " << res << "\n";
    
    // success
    return 0;
}
