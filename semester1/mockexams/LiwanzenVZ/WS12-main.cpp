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

void populate(vector<Liwanze*> &vL) {
    vL.push_back(new Liwanze("Joey", Liwanze::amer));
    vL.push_back(new Liwanze("Johnny", Liwanze::amer));
    vL.push_back(new Liwanze("DeeDee", Liwanze::amer));
    vL.push_back(new Liwanze("Tommy", Liwanze::emea));
    vL.push_back(new Liwanze("Suzy", Liwanze::apac));
    vL.push_back(new Liwanze("Sheena", Liwanze::amer));
}

void print_LVZMembers(vector<Liwanze*> &vL) {
    for(int i = 0;i<vL.size();i++) {
        vL.at(i)->print();
    }
}

void add_Liwanze(vector<Liwanze*> &vL) {
    string input = " ";
    bool alreadyExists = false;
    
    while(true) {
        cout << "Geben Sie einen gueltigen Namen ein um eine Liwanze zu registrieren (Ende mit q): ";
        cin >> input;
        
        if(!cin) error("Sie haben einen ungueltigen Wert eingegeben!");
        if(input == "q") break;
        if(input == " ") continue;
        
        for(int i = 0;i < vL.size();i++) {
            if(vL.at(i)->get_name() == input) {
                cerr << "Dieser Name ist schon vergeben!" << endl;
                alreadyExists = true;
                break;
            }
        }
        
        if(alreadyExists) continue;
        
        vL.push_back(new Liwanze(input, Liwanze::ndef));
        print_LVZMembers(vL);
    }
} 

// Aufgabe 2
void make_connection(Liwanze* fromLw, Liwanze* toLw) {
    fromLw->add_connTo(toLw);
    toLw->add_connFrom(fromLw);
}
void init_connections(vector<Liwanze*> &vL) {
    // Init pointers
    Liwanze* joey = vL.at(0);
    Liwanze* johnny = vL.at(1);
    Liwanze* deedee = vL.at(2);
    Liwanze* tommy = vL.at(3);
    Liwanze* suzy = vL.at(4);
    Liwanze* sheena = vL.at(5);
    
    make_connection(joey, johnny);
    make_connection(joey, deedee);
    make_connection(joey, suzy);
    make_connection(joey, sheena);
    make_connection(johnny, joey);
    make_connection(johnny, suzy);
    make_connection(deedee, suzy);
    make_connection(tommy, suzy);
    make_connection(sheena, joey);
}
void print_network(vector<Liwanze*> &vL) {
    for(int i = 0;i<vL.size();i++) {
        Liwanze* tempPointer = vL.at(i);
        string connFrom = " ";
        string connTo = " ";
        
        for(int j = 0;j<vL.size();j++) {
            if(j>=vL.size()) break;
            if(vL.at(i)->connects(vL.at(j))) connTo = vL.at(j)->get_name();
            if(vL.at(i)->connected(vL.at(j))) connFrom = vL.at(j)->get_name();
        }
        
        cout << "Name: " << tempPointer->get_name() << ", Ort: " << tempPointer->get_loc() << endl;
        cout << "Direkt verbunden mit: " << connTo;
        cout << " und von: " << connFrom << endl;
    }
}

int main() {
    try {
        vector<Liwanze*> vL;
        populate(vL);
        init_connections(vL);
        //add_Liwanze(vL);
        //print_LVZMembers(vL);
        print_network(vL);
        
        return 0; 
    } catch(exception &e) {
        cerr << e.what() << endl;
        return -1;
    } catch(...) {
        cerr << "Ein unbekannter Fehler ist aufgetreten. Sorry." << endl;
        return -2;
    }
}
