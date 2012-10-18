/* 
 *                                         | |   (_)      
 *   __ _ _ __ _ __   ___   _   _ _ __   __| |    _  ___  
 *  / _` | '__| '_ \ / _ \ | | | | '_ \ / _` |   | |/ _ \ 
 * | (_| | |  | | | |  __/ | |_| | | | | (_| |   | | (_) |
 *  \__,_|_|  |_| |_|\___|  \__,_|_| |_|\__,_|   | |\___/ 
 *                                              _/ |       
 *                                             |__/    
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

int main() {
    // initialize variables
    string opt = ""; // operator
    double opd1 = 0.0; // operand 1
    double opd2 = 0.0; // operand 2
    double res = 0.0; // result
    
    // receive input
    cout << "Operation: ";
    cin >> opt >> opd1 >> opd2;
    
    // check which operator and calculate the result
    if(opt == "+") {
        res = opd1 + opd2;
    } else if(opt == "-") {
        res = opd1 - opd2;
    } else if(opt == "*") {
        res = opd1 * opd2;
    } else if(opt == "/") {
        res = opd1 / opd2;
    }
    
    // display the result
    cout << "\nErgebnis: " << res << "\n";
    
    // success
    return 0;
}
