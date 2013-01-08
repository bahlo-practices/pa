#include "Auftrag.h"
#include "Kunde.h"

using namespace std;

// Setter
void Auftrag::setKunde(Kunde* k) {
    pk = k;
}

// Getter
Kunde* Auftrag::getKunde() const { // Gibt Zeiger auf Kunden zurück
    return pk;
}

void Auftrag::print() const { // Gibt den Auftrag und dazugejörige Kunden aus.
    cout << "Auftrag: " << name << endl;
    cout << "Kunde: " << getKunde()->getName() << endl << endl;
}

string Auftrag::getName() const  { 
    return name; 
} 

// Anderes
void Auftrag::delAufAusKunde() {
    if (pk != 0) {
        pk->cancelAuftrag(this);
        pk = 0;
    }
}
