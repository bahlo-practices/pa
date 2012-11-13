/*  _  _   
 * | || |  
 * | || |_ 
 * |__   _|
 *    | |  
 *    |_|  
 *
 * Created on 07. November 2012, 13:23
 * 
 * Nimmt Terme entgegen und liefert das Ergebnis zurück.
 * 
 */

#include <iostream>
#include "myError.h"

using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::string;
using std::exception;

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
            if( full ) error( "Puffer voll" );
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
        case ';': // end term
        case 'q': // exit
        case '(': case ')': case '+': case '-': case '*': case '/': case '?':
        return Token( ch ); 
        case '.': case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        {
            cin.putback( ch );
            double val = 0.0; cin >> val;
            return Token( '9', val );
        }
        default: error( "unbekanntes Token" );
    }
}

double rechenausdruck( Token_stream& Ts );

double faktor( Token_stream& Ts ) {
    // Klammern und Zahlen
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
        default: error( "Operator erwartet!\n" );
    }
}

double summand( Token_stream& Ts ) {
    // Mal und geteilt
    double li = faktor( Ts );
    Token t = Ts.get( );
    while( true ) {
        switch( t.kind ) {
            case '*': li *= faktor( Ts ); t = Ts.get( ); break;
            case '/':
            {
                double d = faktor( Ts );
                if( d==0 ) error( "Teilen durch 0 nicht m\x94glich!\n" );
                li /= d; t = Ts.get( ); break;
            }
            default: Ts.putback( t ); return li;
        }
    }
}

double rechenausdruck( Token_stream& Ts ) {
    // Plus und minus
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
        cout << "Bitte geben Sie den Term ein (f\x81r Hilfe ?):" << endl;
        while( cin ) { 
            Token t = T.get();
            while( t.kind == ';' )
            {
                t = T.get();
            }
            if( t.kind == '?' )
            {
                cout << "Erlaubte Operatoren: + - * / ( )" << endl;
                cout << "Sie können mehrere Terme eingeben, trennen Sie diese mit ;" << endl;
                cout << "Geben Sie \"q\" ein, um das Programm zu beenden.";
                continue;
            }
            if( t.kind == 'q' ) 
            {
                return 0;
            }
            T.putback(t);
            cout << "Das Ergebnis ist: " << rechenausdruck(T) << endl;
        }
        return 0;
    }
    catch( exception &e ) {
        cerr << "Ausnahme: " << e.what(); 
        return -2;
    }
    catch( ... ) {
        cerr << "Unbekannte Ausnahme";
        return -1;
    }
}
