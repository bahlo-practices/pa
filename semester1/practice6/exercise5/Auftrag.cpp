#include "Auftrag.h"
#include "Kunde.h"

using namespace std;

// Setter
void Auftrag::setKunde(Kunde* k) {
    if(pk == k) return;
    pk = k;
    k->addAuftrag(this);
}

// Getter
Kunde* Auftrag::getKunde() const { // Gibt Zeiger auf Kunden zurück
    return pk;
}

void Auftrag::print() const { // Gibt den Auftrag und dazugehörige Kunden aus.
    cout << "Auftrag: " << name << endl;
    cout << "Kunde: " << getKunde()->getName() << endl << endl;
}

string Auftrag::getName() const  { 
    return name; 
} 