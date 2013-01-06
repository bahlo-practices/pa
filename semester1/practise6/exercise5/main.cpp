/* 
 * Exercise 5
 *
 * Created on 6. Januar 2013, 14:42
 */

#include <iostream>

using namespace std;

int main( ) {
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
    a3->setKunde( &k2 );
    k2.print( );
    a3->print( );
    delete a1; delete a2; delete a3;
  } // main()
