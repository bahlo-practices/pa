/*  ______    
 * |____  |   
 *     / /_ _ 
 *    / / _` |
 *   / / (_| |
 *  /_/ \__,_|
 * 
 * Created on 19. Oktober 2012, 21:48
 * 
 * Displays a number in text
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
    int iNumber = 0;
    vector<string> vNumbers;
    
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
    cin >> iNumber;
    
    // Check if number ok
    if(iNumber < 0 || iNumber > 10) {
        cout << "Diese Zahl wird nicht unterstützt!" << endl;
        return -1;
    }
    
    // Get value from vectorand cout it
    cout << vNumbers.at(iNumber) << endl;
    
    return 0;
}

