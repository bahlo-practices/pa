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
        //*
        // Anlegen: zwei Kunden und drei Aufträge
        Kunde k1( "Sepplhuber-Finsterwalder" );
        Kunde k2( "Kurz" );
        Auftrag* a1 = new Auftrag( "Decke streichen" );
        Auftrag* a2 = new Auftrag( "Wand tapezieren" );
        Auftrag* a3 = new Auftrag( "Laminat verlegen" );
        // Erste Assoziationsrichtung:
        // aus einem Objekt vom Typ Kunde
        // zu Objekten vom Typ Auftrag
        k1.addAuftrag( a1 );
        k1.addAuftrag( a2 );
        k1.print( );
        a1->print( );
        a2->print( );
        // Zweite Assoziationsrichtung:
        // aus einem Objekt vom Typ Auftrag
        // zu einem Objekt vom Typ Kunde
        a3->setKunde(&k2);
        k2.print( );
        a3->print( );
        delete a1; delete a2; delete a3;
        //*/

        /*
        // TESTFÄLLE
        Kunde kunde1("Hans-Meier");
        Kunde kunde2("Siegfried Mueller");
        Auftrag* auftrag1 = new Auftrag("Fenster putzen");
        Auftrag* auftrag2 = new Auftrag("Fenster ausbauen");
        // 1: Zwei mal der selbe Auftrag
        Auftrag* auftrag3 = new Auftrag("Fenster putzen");
        // 2: Doppelte asoziierung
        kunde1.addAuftrag(auftrag1);
        auftrag1->setKunde(&kunde1);
        kunde1.print();
        // 3: Auftrag mit nicht vorhandenem Kunden verbinden
        //auftrag2->setKunde(&keinkunde);
        // 4: Auftrag mit vorhandenem aber nicht ver&-deten Kunden asoziieren
        //auftrag1->setKunde(kunde1);
        // 5:Einen Auftrag mit mehreren Kunden asoziieren
        auftrag1->setKunde(&kunde2);
        auftrag1->print();
        // 6: Einen Kunden mit einem Kunden asoziieren
        //kunde1.addAuftrag(kunde2);
        // 7: Einen Auftrag mit einem Auftrag asoziieren
        //auftrag1->setKunde(&auftrag2);
        // 8: Einen Auftrag mit einem Kunden vertauschen
        //auftrag1.addAuftrag(&kunde2);
        // 9: Einen bereits gelöschten Auftrag einem Kunden zuordnen
        kunde2.cancelAuftrag(auftrag1);
        kunde1.addAuftrag(auftrag1);
        kunde1.print();
        // 10: Zweimal derselbe Kunde
        Kunde kunde3("Hans-Meier");
        kunde3.print();
        //*/
    } catch(exception &e) {
        cerr << e.what();
    } catch(...) {
        cerr << "Ein Fehler trat auf. Das tut uns Leid." << endl;
    }
} // main()
