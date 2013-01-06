#ifndef KUNDE_H
#define	KUNDE_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Auftrag;

class Kunde {
public:
    Kunde(string s) : name(s) {};
    ~Kunde() { };
    
    // Assoziations-Operationen & Setter
    void connectWidthAuftrag(Auftrag* auftrag);
    void addAuftrag(Auftrag* auftrag);

    // Getter
    void print() const;
    string getName() const;
    vector<Auftrag*> getAuftraege();
    
    // Anderes
    void cancelAuftrag(Auftrag* auftrag);
private:
    string name;
    vector<Auftrag*> vpa;
};
#endif	/* KUNDE_H */

