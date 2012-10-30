/*  _____ 
 * | ____|
 * | |__  
 * |___ \ 
 *  ___) |
 * |____/ 
 * 
 * Created on 22. Oktober 2012, 19:39
 * 
 * A simple dictionary
 * 
 */

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::string;

using std::vector;
using std::endl;
using std::sort;

using std::find;

int main() {
    // Initialize variables and vectors
    vector<string> vWords;
    string temp;
    int iDuplicates = 0;
    
    // Prompt for words
    cout << "Geben Sie beliegbig viele W\x94rter ein und beenden Sie Ihre eingaben mit \"quit\":" << endl;

    // Read in words from user and write them in vWords
    while (cin >> temp && temp != "quit") {
        // Check if word is already in list
        if (find(vWords.begin(), vWords.end(), temp) == vWords.end()) {
            // Word is not in vector
            vWords.push_back(temp);
        } else {
            iDuplicates++;
        }
    }

    // Cout the quantity of the words
    cout << "Anzahl: " << vWords.size() << endl;
    cout << "Anzahl Duplikate: " << iDuplicates << endl;

    // Sort words
    sort(vWords.begin(), vWords.end());

    // Cout all words
    for (int i = 0; i < vWords.size(); ++i) {
        cout << vWords[i] << endl;
    }

    return 0;
}
