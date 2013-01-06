/* 
 * 3
 *
 * Created on 4. Dezember 2012, 23:23
 * 
 * Majority-Algorithmus
 * 
 * http://www-i1.informatik.rwth-aachen.de/~algorithmus/algo33.php
 * 
 */

#include <iostream>
#include <vector>
#include "error.h"

using std::cout;
using std::cerr;
using std::endl;

using std::string;
using std::vector;
using std::exception;

int get_majority(const vector<string> vVec) {    
        vector<string> stack;
    
        // PHASE 1
        for(int i(0); i <= vVec.size() - 1; i++) {
            if(stack.size() == 0) {
                stack.push_back(vVec.at(i));
                continue;
            }
            if(stack.at((stack.size() > 0) ? stack.size() - 1 : 0) == vVec.at(i)) { // HACKHACK
                stack.push_back(vVec.at(i));
            } else {
                stack.erase(stack.end());
            }
        }
        if(stack.size() == 0) {
            return -1; // Keine Mehrheit
        } else {
            // PHASE 2
            string elem = stack.at(stack.size() - 1);
            int iCount(0);
            int iPos(-1);
            
            for(int i(0);i <= vVec.size() - 1;i++) {
                if(vVec.at(i) == elem) {
                    iCount++;
                    iPos = i;
                }
            }
            
            if(iCount > (vVec.size() / 2)) {
                return iPos;
            } else {
                return -1; // Keine Mehrheit
            }
        }
} 

// MAIN
int main() {
    try {
        vector<string> names;
        int res;
        
        names.push_back("Arne");
        names.push_back("Johannes");
        names.push_back("Arne");
        names.push_back("Markus");
        names.push_back("Johannes");
        names.push_back("Markus");
        names.push_back("Johannes");
        names.push_back("Arne");
        names.push_back("Johannes");
        names.push_back("Markus");
        names.push_back("Johannes");
        names.push_back("Johannes");
        names.push_back("Johannes");
        
        res = get_majority(names);
        if(res >= 0) {
            cout << "Mehr als die Mehrheit der Stimmen hat " << names.at(res) << "." << endl;
        } else {
            cout << "Keine absolute Mehrheit." << endl;
        }
        
    } catch (exception &e) {
        cerr << "Ausname: " << e.what();
        return -2;
    } catch (...) {
        cerr << "Unbekannter Fehler";
        return -1;
    }
}
