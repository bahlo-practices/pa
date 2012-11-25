/* 
 * File:   main.cpp
 * Author: jw
 *
 * Created on 13. November 2012, 08:24
 */

#include <iostream>
#include "Token.h"
#include "Token_Stream.h"

using namespace std;

int main() {

    Token_stream T;
    while (cin) {
        Token t = T.get();
        while (t.kind == ';') t = T.get();
        if (t.kind == 'q') return 0;
        T.putback(t);
        cout << "=" << rechenausdruck(T) << endl;

        return 0;
    }

