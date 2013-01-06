#ifndef AUFTRAG_H
#define	AUFTRAG_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Kunde;

class Auftrag {
public:
    Auftrag( string s ) : name(s), pk(0){};       // Kontruktor, Kundenzeiger zeigt auf NULL
    ~Auftrag() { delAufAusKunde(); }            // Dekonstruktor
    
    // Assoziations-Operationen & Setter
    void connectWidthKunde(Kunde* k);
    void setKunde (Kunde* k);
    
    // Getter
    Kunde* getKunde() const;      
    void print() const;
    string getName() const;
    
    // Anderes
    void delAufAusKunde();
private:
    string name;
    Kunde* pk;
};
#endif	/* AUFTRAG_H */

