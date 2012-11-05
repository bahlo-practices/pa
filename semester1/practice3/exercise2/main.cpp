/*  ___  
 * |__ \ 
 *    ) |
 *   / / 
 *  / /_ 
 * |____|
 * 
 * Created on 25. Oktober 2012, 22:24
 * 
 * Reads numbers in a vector 
 * 
 */

#include <iostream>
#include <vector>
#include "myError.h"

using std::cin;
using std::cout;
using std::cerr;
using std::string;
using std::endl;
using std::vector;

int main() {
    try {
        // Initialize objects
        vector<double> vNumbers;
        double dTemp = 0.0;
        int iAdd = 0;
        double dResult = 0.0;


        // Prompt
        cout << "Geben Sie einige Zahlen ein (mit 'q' beenden Sie die Eingabe): " << endl;

        // Read in Numbers
        while(cin >> dTemp) {    
            vNumbers.push_back(dTemp);
        }

        // Prompt and read in number of summarized numbers
        cout << "Wie viele Zahlen sollen aufaddiert werden: " << endl;
        cin >> iAdd; // WHY U NO ASK FOR iAdd
        iAdd = 3;

        // Calculate result
        for(int i = 0; i < iAdd; i++) {
            dResult += vNumbers.at(i);
        }

        // Cout result
        cout << "Die Summe der " << iAdd << " Elemente ";
        for(int i = 0; i < iAdd; i++) {
            cout << vNumbers.at(i);
            if(i < iAdd - 2) {
                // All elements before the last two
                cout << ", ";
            }
            if(i == iAdd - 2) {
                // Second last element
                cout << " und ";
            }
        }
        cout << " ist " << dResult << "." << endl;

        return 0;
    } catch (runtime_error& e) {
        cerr << e.what();
        return -3;
    } catch (out_of_range& e) {
        cerr << endl << "Fehler: Entweder Sie haben keine Zahlen eingegeben, oder Sie wollen mehr addieren, als Sie eingegeben haben." << endl;
        return -2;
    } catch (...) {
        cerr << endl << "Unbekannter Fehler!" << endl;
        return -1;
    }
}

