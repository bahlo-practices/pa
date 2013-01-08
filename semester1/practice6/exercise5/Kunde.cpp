/* 
 * Created on 6. Januar 2013, 13:12
 */

#include <iostream>
#include "Kunde.h"
#include "Auftrag.h"

using namespace std;

// Assoziations-Operationen & Setter
void Kunde::addAuftrag(Auftrag* auftrag) {
    if(auftrag->getKunde() == this) return;
    vpa.push_back(auftrag);
    auftrag->setKunde(this);
}

// Getter
void Kunde::print() const {
    cout << "Kunde: " << getName() << endl;
    if (vpa.size() == 0) {
        cout << "Dieser Kunde hat keine Auftraege." << endl;
    } else {
        Auftrag* temp;
        for (int i = 0; i < vpa.size(); i++) {
            temp = vpa[i];
            cout << " - " << temp->getName() << endl;
        }
    }
    cout << endl;
}

string Kunde::getName() const {
    return name;
}

vector<Auftrag*> Kunde::getAuftraege() {
    return vpa;
}

// Anderes
void Kunde::cancelAuftrag(Auftrag* auftrag) {
    for (int i = 0; i < vpa.size(); i++) {
        if (auftrag == vpa.at(i))
            vpa.erase(vpa.begin() + i);
    }
}

