/*  _____ _     
 * | ____| |    
 * | |__ | |__  
 * |___ \| '_ \ 
 *  ___) | |_) |
 * |____/|_.__/ 
 *
 * Created on 12. November 2012, 17:35
 */


#include <iostream>
#include <vector>
#include <sstream>
#include "myError.h"

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::vector;
using std::istringstream;
using std::stringstream;
using std::cerr;
using std::getline;

int main() {
    class Name_values {
        public:
        Name_values(); // Standardkonstruktor
        Name_values( string, vector<int> ); // Konstruktor
        void add_value( int ); // weiteren Wert speichern
        void print_all( ) const; // alles ausgeben gem. Aufgabe
        string get_name( ) const; // Name liefern
        private:
        string name;
        vector<int> values;
    };
    
    vector<Name_values> week;
    bool bRun = true;
    string sTemp = "";
    int iTemp = 0;
    
    
    while (bRun) {
        cin >> sTemp >> iTemp;
        if(sTemp == "q") bRun == false;
        week.push_back(sTemp, iTemp);
    }
    
    
    
    return 0;
}

