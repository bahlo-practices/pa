/* 
 * File:   summand.h
 * 
 *
 * Created on 10. November 2012, 23:13
 */

#ifndef SUMMAND_H
#define	SUMMAND_H

#include "tokenStream.h"
#include "faktor.h"

double summand( Token_stream& Ts ) { // "mal" und "geteilt durch" behandeln
    double li = faktor( Ts );
    Token t = Ts.get( );
    while( true ) {
        switch( t.kind ) {
            case '*': li *= faktor( Ts ); t = Ts.get( ); break;
            case '/':
            {
                double d = faktor( Ts );
                if( d==0 ) error( "Div. durch 0!\n" );
                li /= d; t = Ts.get( ); break;
            }
            default: Ts.putback( t ); return li;
        }
    }
}

#endif	/* SUMMAND_H */

