/*  ____  
 * |___ \ 
 *   __) |
 *  |__ < 
 *  ___) |
 * |____/ 
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
    cout << "Geben Sie den Operator und die drei Operanden getrennt durch ein Leerzeichen ein und best\x84tigen Sie mit \(Enter\)." << endl;
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
            if(opd2 == 0){
                cout << "Man kann nicht durch 0 teilen!" << endl;
                return false;
            }
            res = opd1 / opd2;
            break;
        default: 
            cout << "Der Operator \"" << opt << "\" wird nicht unterst\x81tzt." << endl;
            return -1;
    }
    
    // display the result
    cout << "\nErgebnis: " << res << "\n";
    
    // success
    return 0;
}
