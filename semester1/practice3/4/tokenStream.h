/* 
 * File:   tokenStream.h
 * 
 *
 * Created on 10. November 2012, 23:44
 */

#ifndef TOKENSTREAM_H
#define	TOKENSTREAM_H

#include <iostream>
#include "error.h"

using namespace std;

class Token {
    public: 
        char kind; // die 7 Kategorien der Eingabesymbole 
        double value; // Bei Zahlenkategorie: der Wert

        // Memberfunktion: erstelle ein Token aus einem char 
        Token( char ch )
            : kind( ch ), value( 0.0 ) { /* mache nichts sonst */ } 

        // Memberfunktion: erstelle ein Token aus einem char und einem double
        Token( char ch, double val ) 
            : kind( ch ), value( val ) { /* mache nichts sonst */ } 
}; 

class Token_stream {
    public:
        Token_stream( ) : full( false ), buffer( ' ' ) {} // Konstruktor 
        void putback( Token t ) // Token "zurückstellen" 
        {
            if( full ) error( "Token_stream::putback(), Puffer voll" );
            buffer = t; full = true; 
        };
        Token get( ); // Token aus cin erzeugen
    private:
        bool full; // ist buffer voll?
        Token buffer;
};

Token Token_stream::get( ) {
    if( full ) { full = false; return buffer; }
    char ch = ' '; cin >> ch;
    switch( ch ) {
        case ';': // Ende eines Rechenausdrucks 
        case 'q': // Programmende
        case '(': case ')': case '+': case '-': case '*': case '/':
        return Token( ch ); // jedes Zeichen ist sein eigenes Token
        case '.': case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9': // Zahl als Token
        {
            cin.putback( ch ); // der cin Stromkennt auch ein putback()
            double val = 0.0; cin >> val;
            return Token( '9', val );
        }
        default: error( "Token Token_stream::get(), unbekanntes Token" );
    }
}

#endif	/* TOKENSTREAM_H */

