/*    _                         _                         
 *   (_)                       | |                        
 *    _  ___    _   _ _ __   __| |   __ _ _ __ _ __   ___ 
 *   | |/ _ \  | | | | '_ \ / _` |  / _` | '__| '_ \ / _ \
 *   | | (_) | | |_| | | | | (_| | | (_| | |  | | | |  __/
 *   | |\___/   \__,_|_| |_|\__,_|  \__,_|_|  |_| |_|\___|
 *  _/ |                                                  
 * |__/                                                   
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
using std::find;

int main() {
    // Initialize variables
    string sNumber = "";
    vector<string> vNumbers;
    string result = "";
    
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
    
    // Get number
    cout << "Geben Sie eine beliebige Ziffer von 0 bis 10 ein (als Zahl oder als Text): ";
    cin >> sNumber;
    
    // Get position of string in vector (if there)
    int pos = find(vNumbers.begin(), vNumbers.end(), sNumber) - vNumbers.begin();
    
    // Check if element is in vector and cout the result
    if(pos < vNumbers.size()) {
        // Element is in vector
        cout << pos << endl;
    } else {
        // Element is not in vector => is numeric
        int iNumber = atoi(sNumber.c_str());
        cout << vNumbers[iNumber] << endl;
    }
    
    return 0;
}
