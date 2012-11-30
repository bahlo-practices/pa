/* 
 * 1a
 *
 * Created on 30. November 2012, 13:16
 */

#include <iostream>
#include <vector>
#include "error.h"
#include "vec.h"
#include "menu.h"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

using std::string;
using std::vector;

using std::exception;
using std::swap;

// Helper functions
void swap_if( int& a, int& b ) { 
    if(a>b) swap(a,b); 
}


// Selectiv sort
void selSort(vector<int>& vV, int ui, int oi) {
    int min(0);
    for(int i=ui; i<oi; ++i){
        min = i;
        for(int j=i+1; j<=oi; ++j) {
            if(vV.at(j) < vV.at(min)) {
                min=j; 
                swap(vV.at(i), vV.at(min));
            }
        }
    }
}

// Insertion sort
void insSort( vector<int>& vV, int ui, int oi) {
    int i(0), j(0), tmp(0);
    for (i = oi; i > ui; --i) {
        swap_if(vV.at(i - 1), vV.at(i));
    }
    for (i = ui + 2; i <= oi; ++i) {
        j = i;
        tmp = vV.at(i);
        while (tmp < vV.at(j - 1)) {
            vV.at(j) = vV.at(j - 1);
            --j;
        }
        vV.at(j) = tmp;
    }
}





int main() {
    try {
        // Create objects
        vec vec;
        menu menu;
        
        menu.show(false);
        
        
        /*
        // Selective sort
        vector<int> vRandomSS = vRandomInt;
        selSort(vRandomSS, 0, vRandomSS.size() - 1);
        cout << "Nach dem Sortieren durch direkte Auswahl:" << endl;
        print_v(vRandomSS);
        
        // Insertion sort
        vector<int> vRandomIS = vRandomInt;
        insSort(vRandomIS, 0, vRandomIS.size() - 1);
        cout << "Nach dem Sortieren durch Einf" << getUml('ü') << "gen:" << endl;
        print_v(vRandomIS);
        */
    } catch (exception &e) {
        cerr << "Ausname: " << e.what();
    } catch (...) {
        cerr << "Unbekannter Fehler";
    }
    return 0;
}

