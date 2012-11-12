/*  _  _   _     
 * | || | | |    
 * | || |_| |__  
 * |__   _| '_ \ 
 *    | | | |_) |
 *    |_| |_.__/ 
 *
 * Created on 12. November 2012, 17:10
 */

#include <iostream>
#include "myError.h"

using std::cin;
using std::cout;
using std::string;
using std::endl;

int main() { // try-catch weggelassen
    int lval = 0;
    int rval = 0;
    char op = ' ';
    cout << "Rechenausdruck (mit +,-,*,/, Ende mit ;) "; // 2+3+4;
    cin >> lval;
    if (!cin) error("Kein erster Operand!\n");
    while (cin >> op) {
        if (op != ';') cin >> rval;
        if (!cin) error("Kein zweiter Operand!\n");
        switch (op) {
            case '+': lval += rval;
                break;
            case '-': lval -= rval;
                break;
            case '*': lval *= rval;
                break;
            case '/': lval /= rval;
                break;
            default: cout << "Ergebnis: " << lval << endl;
                return 0;
        }//switch()
    }// while()
    error("Ausdruck fehlerhaft\n");
}// main()