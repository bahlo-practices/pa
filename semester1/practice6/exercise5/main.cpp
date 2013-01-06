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
    /**/
    // Anlegen: zwei Kunden und drei Aufträge
    Kunde k1( "Sepplhuber-Finsterwalder" );
    Kunde k2( "Kurz" );
    Auftrag* a1 = new Auftrag( "Decke streichen" );
    Auftrag* a2 = new Auftrag( "Wand tapezieren" );
    Auftrag* a3 = new Auftrag( "Laminat verlegen" );
    // Erste Assoziationsrichtung:
    // aus einem Objekt vom Typ Kunde
    // zu Objekten vom Typ Auftrag
    k1.connectWidthAuftrag( a1 );
    k1.connectWidthAuftrag( a2 );
    k1.print( );
    a1->print( );
    a2->print( );
    // Zweite Assoziationsrichtung:
    // aus einem Objekt vom Typ Auftrag
    // zu einem Objekt vom Typ Kunde
    a3->connectWidthKunde( &k2 );
    k2.print( );
    a3->print( );
    delete a1; delete a2; delete a3;
    /* *//*
    // TESTFÄLLE
    Kunde kunde1("Hans-Meier");
    Auftrag* auftrag1 = new Auftrag("Fenster putzen");
    Auftrag* auftrag2 = new Auftrag("Fenster putzen");
    kunde1.connectWidthAuftrag(auftrag1);
    kunde1.connectWidthAuftrag(auftrag2);
    auftrag1->connectWidthKunde(&kunde1);
    kunde1.cancelAuftrag(auftrag1);
    kunde1.print();*/
} catch(exception &e) {
    cerr << e.what();
} catch(...) {
    cerr << "Ein Fehler trat auf. Das tut uns Leid." << endl;
}
} // main()
