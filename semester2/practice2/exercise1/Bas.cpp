//
//  Bas.cpp
//  exercise1
//
//  Created by Arne Bahlo on 04.04.13.
//  Copyright (c) 2013 Arne Bahlo. All rights reserved.
//

#include <iostream>

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
