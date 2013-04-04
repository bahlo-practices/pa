//
//  Bas.cpp
//  exercise1
//
//  Created by Arne Bahlo on 04.04.13.
//  Copyright (c) 2013 Arne Bahlo. All rights reserved.
//

#include "Bas.h"

Bas::Bas() : deduced() {}

void Bas::add_children(Bas* pointer) {
    deduced.push_back(pointer);
}

void Bas::print_pointers() const {
    for(int i = 0; i < deduced.size(); ++i) {
        std::cout << deduced.at(i) << std::endl;
    }
}