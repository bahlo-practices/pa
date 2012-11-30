/* 
 * Menu
 * 
 * Created on 30. November 2012, 14:51
 */

#include <iostream>
#include <vector>
#include "vec.h"
#include "menu.h"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

using std::string;
using std::vector;

menu::menu() {
    vec vec;
}

void menu::show(bool error) {
    int i(1);
    int iAction(-1);
    
    if(error)
        cout << endl << "Bitte geben Sie eine gültige Option an!" << endl << endl;
    
    cout << "Sie haben folgende Optionen: " << endl;
    
    vector<string> vOptions;
    vOptions.push_back("Einen Vector mit zufälligen Int-Werten generieren");
    vOptions.push_back("Einen Vector mit zufälligen String-Werten generieren");
    vOptions.push_back("Den Vector mit den Int-Werten anzeigen");
    vOptions.push_back("Den Vector mit den String-Werten anzeigen");
    vOptions.push_back("Das Programm beenden");
    
    for(int i(0); i < vOptions.size(); i++) {
        cout << i+1 << ". " << vOptions.at(i) << endl;   
    }
    
    cout << endl << "Ihre Auswahl: ";
    cin >> iAction;
    cout << endl;
    
    iAction--; // yes.
    if(iAction >= 0 && iAction < vOptions.size()) {
        this->run(iAction);
    } else {
        this->show(true);
    }
}

// Menu
void menu::run(const int iAction) {
    switch(iAction) {
        case 0: {
            int iCount(0);
            
            cout << "Geben Sie die Anzahl der zu generierenden Werte ein: ";
            cin >> iCount;
            
            // Generate Int vector
            vec->generate(iCount, "int");
            
            cout << endl;
            this->show(false);
            break;
        }
        case 1: {
            // Generate String vector
            break;
        }
        case 2: {
            vec->print("int");
            this->show(false);
            break;
        }
        case 3: {
            //vec::print("str")
            this->show(false);
            break;
        }
        default:
           cerr << "Ein Fehler ist aufgetreten.";
    }
}
