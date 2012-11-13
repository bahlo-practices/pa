/* 
 * File:   faktor.h
 *
 * Created on 10. November 2012, 23:16
 */

#ifndef FAKTOR_H
#define	FAKTOR_H

#include "tokenStream.h"
#include "rechenausdruck.h"

double faktor( Token_stream& Ts ) { // Zahlen und Klammern behandeln
    Token t = Ts.get( );
    switch( t.kind ) {
        case '(':
        {
            double d = rechenausdruck( Ts );
            t = Ts.get( );
            if( t.kind != ')' ) error( ") erwartet!\n" );
                return d;
            }
        case '9': return t.value;
        default: error( "Faktor erwartet!\n" );
    }
}

#endif	/* FAKTOR_H */

