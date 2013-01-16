/* 
 * Created on 16. Januar 2013, 10:18
 */

#include <iostream>
#include <vector>
#include <stdexcept>
#include "WS12.h"

using namespace std;

void error(string reason) {
    throw runtime_error(reason);
}

void populate(vector<Liwanze> &vL) {
    vL.push_back(Liwanze("Joey", Liwanze::amer));
    vL.push_back(Liwanze("Johnny", Liwanze::amer));
    vL.push_back(Liwanze("DeeDee", Liwanze::amer));
    vL.push_back(Liwanze("Tommy", Liwanze::emea));
    vL.push_back(Liwanze("Suzy", Liwanze::apac));
    vL.push_back(Liwanze("Sheena", Liwanze::amer));
}

void print_LVZMembers(vector<Liwanze> &vL) {
    for(int i = 0;i<vL.size();i++) {
        vL.at(i).print();
    }
}

void add_Liwanze(vector<Liwanze> &vL) {
    string input = " ";
    bool alreadyExists = false;
    
    while(true) {
        cout << "Geben Sie einen gueltigen Namen ein um eine Liwanze zu registrieren (Ende mit q): ";
        cin >> input;
        
        if(!cin) error("Sie haben einen ungueltigen Wert eingegeben!");
        if(input == "q") break;
        if(input == " ") continue;
        
        for(int i = 0;i < vL.size();i++) {
            if(vL.at(i).get_name() == input) {
                cerr << "Dieser Name ist schon vergeben!" << endl;
                alreadyExists = true;
                break;
            }
        }
        
        if(alreadyExists) continue;
        
        vL.push_back(Liwanze(input, Liwanze::ndef));
        print_LVZMembers(vL);
    }
} 

int main() {
    try {
        vector<Liwanze> vL;
        populate(vL);
        add_Liwanze(vL);
        print_LVZMembers(vL);

        return 0; 
    } catch(exception &e) {
        cerr << e.what() << endl;
        return -1;
    } catch(...) {
        cerr << "Ein unbekannter Fehler ist aufgetreten. Sorry." << endl;
        return -2;
    }
}
