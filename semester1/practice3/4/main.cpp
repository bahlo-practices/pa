/* 
 * File:   main.cpp
 *
 * Created on 10. November 2012, 22:23
 */

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
        case '(': case ')': case '+': case '-': case '*': case '/': case '?':
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

double rechenausdruck( Token_stream& Ts );

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
        case '-': return -faktor( Ts );
        case '+': return faktor( Ts );
        default: error( "Faktor erwartet!\n" );
    }
}

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

int main( ) {
    try
    {
        Token_stream T;
        cout << "Bitte geben sie einen Rechenausdruck ein: (? fuer Hilfe)\n";
        while( cin ) { 
            Token t = T.get();
            while( t.kind == ';' )
            {
                t = T.get();
            }
            if( t.kind == '?' )
            {
                cout << "Geben sie einen mathematischen Term ein der ausgerechnet werden soll.\n";
                cout << "Verwendbare Zeichen sind + - * / ( )\n";
                cout << "Verwenden sie * zum multiplizieren und / zum dividieren.\n";
                cout << "Trennen sie mehrere Eingaben mit ;\n";
                cout << "Beenden sie ihre Eingabe mit q.\n";
                continue;
            }
            if( t.kind == 'q' ) 
            {
                return 0;
            }
            T.putback( t );
            cout << "=" << rechenausdruck( T ) << endl;
        }
        return 0;
    }
    catch( exception &e ) {
        cerr << "Ausnahme: " << e.what(); 
        return -2;
    }
    catch( ... ) { // Ausnahmen beliebigen Typs
        cerr << "Unbekannte Ausnahme";
        return -1;
    }
}
