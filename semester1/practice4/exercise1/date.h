/* 
 * File:   date.h
 * Author: Tobias
 *
 * Created on 21. November 2012, 16:45
 */

/*
   date.h
   yymmdd-OSk
   Demonstriert Grundzüge einer einfache Klasse für Datumsangaben
 */
#ifndef DATE_H
#define DATE_H

#include <iostream>
using std::ostream;

//--------------------------------
class Date {
  public:
    class Invalid {}; // zeigt Ausnahmen an
    enum Month { Jan=1, Feb, Mrz, Apr, Mai, Jun, Jul, Aug, Sep, Okt, Nov, Dez }; // symbol. Konstanten für die Monate
    Date( ); // Standardkonstruktor
    Date( int year, Month month, int day ); // Konstruktor

    // nur lesender Zugriff: const
    int year( )    const { return y; }
    Month month( ) const { return m; }
    int day( )     const { return d; }

    // auch schreibender Zugriff
    void add_month( int );

    void inc_day( int t );
    
    void print ();
    void inc();
    int compareTo( Date& , Date& );
    
  private:
    int    y; // Jahr
    Month  m; // Monat
    int    d; // Tag
    bool   check( ); // private Methode, liefert true bei gültigem Datum
    void inc_day_modulo (int t, int w);
    bool ist_schaltjahr( int i);
};


const Date& default_date( ); // liefert dem Standardkonstruktor "das" Standarddatum
ostream& operator<<( ostream& os, const Date& d ); // Stream Insertion << Operator Overloading
Date::Month operator++( Date::Month& m ); // Prefix ++ Operator Overloading

#endif 