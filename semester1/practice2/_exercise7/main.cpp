/*    _                         _                         
 *   (_)                       | |                        
 *    _  ___    _   _ _ __   __| |   __ _ _ __ _ __   ___ 
 *   | |/ _ \  | | | | '_ \ / _` |  / _` | '__| '_ \ / _ \
 *   | | (_) | | |_| | | | | (_| | | (_| | |  | | | |  __/
 *   | |\___/   \__,_|_| |_|\__,_|  \__,_|_|  |_| |_|\___|
 *  _/ |                                                  
 * |__/                                                   
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
    // initialize variables
    int iNumber = 0;
    vector<string> vNumbers;
    
    // no idea how to get the vector initialized, so the "ugly" solution:
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
    
    // get number
    cin >> iNumber;
    
    // get value from vectorand cout it
    cout << vNumbers[iNumber] << endl;
    
    return 0;
}

