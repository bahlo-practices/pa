/* 
 * File:   rechenausdruck.h
 * 
 *
 * Created on 10. November 2012, 23:15
 */

#ifndef RECHENAUSDRUCK_H
#define	RECHENAUSDRUCK_H

#include "tokenStream.h"
#include "summand.h"

double rechenausdruck( Token_stream& Ts ) { // "plus" und "minus" behand
    double li = summand( Ts );
    Token t = Ts.get( );
    while( true ) {
        switch( t.kind ) {
            case '+': li += summand( Ts ); t = Ts.get( ); break;
            case '-': li -= summand( Ts ); t = Ts.get( ); break;
            default: Ts.putback( t ); return li;
        }
    }
}

#endif	/* RECHENAUSDRUCK_H */

