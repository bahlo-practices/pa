/*    __  
 *   / /  
 *  / /_  
 * | '_ \ 
 * | (_) |
 *  \___/ 
 * 
 * Created on 19. Oktober 2012, 20:35
 * 
 * Reads names with values and displays them
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::string;

using std::vector;
using std::endl;
using std::find;

int main() {
    // define vectors
    vector<string> vNames;
    vector<int> vScores;
    
    int i = 0;
    string tmp1 = "";
    int tmp2 = 0;
    while(true) {
        cin >> tmp1 >> tmp2;
        if(tmp1 == "noname" && tmp2 == 0) {
            break;
        } else {
            // check if name exists
            // for-loop because find() didn't work
            for(int ci = 0; ci < vNames.size(); ci++){
                if(vNames[ci] == tmp1) {
                    cout << "Fehler: Das haben Sie bereits eingegeben." << endl;
                    return false;
                }
            }
            
            // push in vectors
            vNames.push_back(tmp1);
            vScores.push_back(tmp2);
            i++;
        }
    }
    
    cout << endl;
    for(int i = 0; i < vNames.size(); i++){
        cout << vNames[i] << " " << vScores[i] << endl;
    }
    
    return 0;
}

