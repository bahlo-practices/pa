/* 
 * Exercise 5
 *
 * Created on 6. Januar 2013, 14:42
 */

#include <iostream>
#include "Kunde.h"
#include "Auftrag.h"

using namespace std;

int main( ) {
try {
    // Anlegen: zwei Kunden und drei Aufträge
    Kunde k1( "Sepplhuber-Finsterwalder" );
    Kunde k2( "Kurz" );
    Auftrag* a1 = new Auftrag( "Decke streichen" );
    Auftrag* a2 = new Auftrag( "Wand tapezieren" );
    Auftrag* a3 = new Auftrag( "Laminat verlegen" );
    // Erste Assoziationsrichtung:
    // aus einem Objekt vom Typ Kunde
    // zu Objekten vom Typ Auftrag
    k1.connectWithAuftrag( a1 );
    k1.connectWithAuftrag( a2 );
    k1.print( );
    a1->print( );
    a2->print( );
    // Zweite Assoziationsrichtung:
    // aus einem Objekt vom Typ Auftrag
    // zu einem Objekt vom Typ Kunde
    k2.connectWithAuftrag(a3);
    k2.print( );
    a3->print( );
    delete a1; delete a2; delete a3;
    
    /*
    // TESTFÄLLE
    Kunde kunde1("Hans-Meier");
    Kunde kunde2("Siegfried Mueller");
    Auftrag* auftrag1 = new Auftrag("Fenster putzen");
    Auftrag* auftrag2 = new Auftrag("Fenster ausbauen");
    // 1: Zwei mal der selbe Auftrag
    Auftrag* auftrag3 = new Auftrag("Fenster putzen");
    // 2: Doppelte asoziierung
    kunde1.connectWidthAuftrag(auftrag1);
    auftrag1->connectWidthKunde(&kunde1);
    kunde1.cancelAuftrag(auftrag1);
    kunde1.print();
    // 3: Auftrag mit nicht vorhandenem Kunden verbinden
    auftrag2->connectWidthKunde(&keinkunde);
    // 4: Auftrag mit vorhandenem aber nicht ver&-deten Kunden asoziieren
    auftrag1->connectWidthKunde(kunde1);
    // 5:Einen Auftrag mit mehreren Kunden asoziieren
    auftrag1->connectWidthKunde(&kunde2);
    // 6: Einen Kunden mit einem Kunden asoziieren
    kunde1.connectWidthAuftrag(kunde2);
    // 7: Einen Auftrag mit einem Auftrag asoziieren
    auftrag1->connectWidthKunde(&auftrag2);
    // 8: Einen Auftrag mit einem Kunden vertauschen
    auftrag1.connectWidthAuftrag(&kunde2);
    // 9: 
    // 10:
    //*/
} catch(exception &e) {
    cerr << e.what();
} catch(...) {
    cerr << "Ein Fehler trat auf. Das tut uns Leid." << endl;
}
} // main()
