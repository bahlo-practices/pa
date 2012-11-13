/*  __ _     
 * /_ | |    
 *  | | |__  
 *  | | '_ \ 
 *  | | |_) |
 *  |_|_.__/ 
 *  
 * Description: Displays a number in text and reverse
 * 
 * Created on 4. November 2012, 12:46
 * 
 */

#include <iostream>
#include <vector>
#include "myError.h"

using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::endl;
using std::cerr;

int main() {

    try {

        // Initialize variables
        string sNumber = "";
        vector<string> vNumbers;
        int i = 0;

        // No idea how to get the vector initialized, so the "ugly" solution:
        vNumbers.push_back("null");
        vNumbers.push_back("eins");
        vNumbers.push_back("zwei");
        vNumbers.push_back("drei");
        vNumbers.push_back("vier");
        vNumbers.push_back("f\x81nf");
        vNumbers.push_back("sechs");
        vNumbers.push_back("sieben");
        vNumbers.push_back("acht");
        vNumbers.push_back("neun");
        vNumbers.push_back("zehn");
        vNumbers.push_back("0");
        vNumbers.push_back("1");
        vNumbers.push_back("2");
        vNumbers.push_back("3");
        vNumbers.push_back("4");
        vNumbers.push_back("5");
        vNumbers.push_back("6");
        vNumbers.push_back("7");
        vNumbers.push_back("8");
        vNumbers.push_back("9");
        vNumbers.push_back("10");

        // Get number
        cout << "Geben Sie eine beliebige Zahl von 0 bis 10 ein (als Ziffern oder als Text): ";
        cin >> sNumber;

        //find match
        while (vNumbers.at(i) != sNumber) {
            i++;
        }


        if (i > 11 && i <= 22) {
            i = i - 11;
            cout << "Zahl: " << vNumbers[i] << endl;
        } else {
            i = i + 11;
            cout << "Ziffer: " << vNumbers[i] << endl;
        }

        return 0;

    } catch (runtime_error& e) {
        cerr << e.what();
        return-3;
    } catch (out_of_range& e) {
        cerr << "Fehler: Element nicht im Vektor vorhanden!";
        return-2;
    } catch (...) {
        cerr << "Unbekannter Fehler!";
        return-1;
    }


}