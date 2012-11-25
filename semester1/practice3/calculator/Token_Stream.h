/* 
 * File:   Token_Stream.h
 * Author: jw
 *
 * Created on 13. November 2012, 08:47
 */

#ifndef TOKEN_STREAM_H
#define	TOKEN_STREAM_H

#include "myError.h"
#include "Token.h"
#include <iostream>

using namespace std;
class Token_stream {
public:

    Token_stream() : full(false), buffer(' ') {
    } // Konstruktor

    void putback(Token t) // Token "zurückstellen"
    {
        if (full) error("Token_stream::putback(), Puffer voll");
        buffer = t;
        full = true;
    };
    //Token get(); // Token aus cin erzeugen

    Token_stream::get() {
        if (full) {
            full = false;
            return buffer;
        }
        char ch = ' ';
        cin >> ch;
        switch (ch) {
            case ';': // Ende eines Rechenausdrucks
            case 'q': // Programmende
            case '(': case ')': case '+': case '-': case '*': case '/':
                return Token(ch); // jedes Zeichen ist sein eigenes Token
            case '.': case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9': // Zahl als Token
            {
                cin.putback(ch); // der cin Strom kennt auch ein putback()
                double val = 0.0;
                cin >> val;
                return Token('9', val);
            }
            default: error("Token Token_stream::get(), unbekanntes Token");
        }
    }
private:
    bool full; // ist buffer voll?
    Token buffer;
};

#endif	/* TOKEN_STREAM_H */

