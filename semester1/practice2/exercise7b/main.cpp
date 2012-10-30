/*  ______ _     
 * |____  | |    
 *     / /| |__  
 *    / / | '_ \ 
 *   / /  | |_) |
 *  /_/   |_.__/ 
 * 
 * Created on 22. Oktober 2012, 20:44
 * 
 * Displays a number in text and reverse
 * 
 */

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::string;

using std::vector;
using std::endl;

int main() {
    // Initialize variables
    string sNumber = "";
    vector<string> vNumbers;
    string result = "";
    int i=0;

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
    cout << "Geben Sie eine beliebige Ziffer von 0 bis 10 ein (als Zahl oder als Text): ";
    cin >> sNumber;

    //find match
    while(vNumbers[i]!=sNumber){
        i++;
    }

    if(i>11&&i<=22){
        i = i -11;
        cout << "Zahl: " << vNumbers[i] << endl;
    }
    else{
        i=i+11;
        cout << "Ziffer: " << vNumbers[i] << endl;
    }

    return 0;
}