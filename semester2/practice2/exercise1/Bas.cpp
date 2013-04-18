//
//  Bas.cpp
//  exercise1
//

#include <iostream>
#include <stdexcept>

#include "Bas.h"

Bas::Bas() : next(0) {}

// Define list
Bas* Bas::list(0);

// Print every object in list
void Bas::print_all() const {
    for(Bas* obj = list; obj; obj = obj->next ) {
        // std::cout << obj << " "; //Print pointer for debugging
        obj->print();
    }
}
