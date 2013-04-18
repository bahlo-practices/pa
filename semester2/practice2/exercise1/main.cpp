//
//  main.cpp
//  exercise1
//

#include <iostream>
#include <vector>

#include "Bas.h"
#include "Pro.h"
#include "Roo.h"

int main() {
    try {
        // Pro
        Pro p0("Test", 1);
        Pro p1("Mac OS X", 10);
        Pro p2("20", 20);
        Pro p3("12", 2);
        Pro p4("IDK", 0);
        
        Bas::list = &p0; // Write first entry in static list
        p0.next = &p1;
        p1.next = &p2;
        p2.next = &p3;
        p3.next = &p4;
        
        // Roo
        Roo r1("1234", "the secretly stored secret");
        Roo r2("the breaking?", "bad");
        Roo r3("", "last but not least!");
        Roo r4("password", "hash");
        Roo r5("or what?", "the secret data");
        
        p4.next = &r1;
        r1.next = &r2;
        r2.next = &r3;
        r3.next = &r4;
        r4.next = &r5;
        
        /* Testfälle
        // Bas test1;
        Roo test2("wasd", "asdasd");
        // r5.next = &test1; // Bas' print() ist leer
        r1.next = 0; // Liste hört nach r1 auf
        p4.next = &test2; // p4 überschrieben, keine nachfolgenden
        // r1.next = -1; // failt, weil falscher Typ
        // test2.next = &Roo("einfach", "e"); // Direkt zuweisen geht nicht
        // test2.next = *Pro("eins", 0); // Mit Pointer logischerweise auch nicht
        // test2->print_all(); // Kein pointer
        // p4.next = &p3; // Endlosschleife
        // */
        
        Bas::list->print_all(); // Print all
        
        return 0;
    } catch(std::runtime_error &e) {
        std::cerr << std::endl << "Exception: " << e.what() << std::endl;
    } catch(...) {
        std::cerr << std::endl << "Ein unbekannter Fehler ist aufgetreten!" << std::endl;
    }
}

